/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Twitter.
 * You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:
 *      -> record(order_id): adds the order_id to the log
 *      -> get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
 * You should be as efficient with time and space as possible.
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

class LogBase
{
    vector<size_t> log; // assuming order id to be unsigned
    size_t size;        // size can be very large and unsigned

public:
    LogBase(size_t size)
    {
        this->log = {};
        this->size = size;
    }

    void print()
    {
        for (auto e : this->log)
            cout << e << " ";
    }

    void record(size_t order_id)
    {
        if (this->log.size() >= 2 * this->size)
        {
            for (size_t i = 0; i < this->size - 1; ++i)
            {
                this->log[i] = this->log[this->log.size() - (this->size - 1) + i];
            }
            this->log.resize(this->size - 1);
        }

        this->log.push_back(order_id); // ammortized O(1)
    }

    size_t get_last(size_t i)
    {
        if (i <= this->size && this->log.size() - i >= 0)
            return this->log[this->log.size() - i]; // O(1)

        return -1;
    }
};

int main()
{
    LogBase lb(3);

    lb.record(12);
    lb.record(99);
    lb.record(84);
    // current state of log: [12, 99, 84]
    cout << "\nCurrent state: ";
    lb.print();
    cout << "\n--------------------------------------------\n";
    cout << "\nFirst record from last: " << lb.get_last(1);  // get the first record from last
    cout << "\nSecond record from last: " << lb.get_last(2); // get the second record from last
    cout << "\nThird record from last: " << lb.get_last(3);  // get the third record from last

    // inserting more elements beyond capacity
    lb.record(17);
    lb.record(66);
    lb.record(11);

    cout << "\n\n";

    cout << "\nCurrent state: ";
    lb.print();
    cout << "\n--------------------------------------------\n";

    cout << "\nFirst record from last: " << lb.get_last(1);  // get the first record from last
    cout << "\nSecond record from last: " << lb.get_last(2); // get the second record from last
    cout << "\nThird record from last: " << lb.get_last(3);  // get the third record from last

    // adding an element to update vector and perform resizing
    lb.record(213);
    lb.record(113);
    cout << "\n\n";

    cout << "\nCurrent state: ";
    lb.print();
    cout << "\n--------------------------------------------\n";

    return 0;
}
