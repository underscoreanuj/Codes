/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * An XOR linked list is a more memory efficient doubly linked list.
 * Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
 * If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.
 * 
 * 
*/

#include <bits/stdc++.h>
#include <inttypes.h>

using namespace std;

struct Node
{
    int data;   // to store data
    Node *both; // common pointer for previous and next node
};

class DLL
{
    int size;
    Node *head; // points to head (start)
    Node *tail; // point to tail (end)

public:
    DLL()
    {
        this->size = 0; // initialize with a size of 0
        this->head = NULL;
        this->tail = NULL;
    }

    Node *XOR(Node *a, Node *b)
    {
        // uintptr_t is an unsigned integer pointer data type
        // which is generally used when we intend to perform integeral operation on a pointer
        // (like in this case XOR operation)
        return (Node *)((uintptr_t)a ^ (uintptr_t)b);
    }

    // insert data at end
    void push_back(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->both = XOR(this->tail, NULL);

        if (this->tail) // if a tail already exists, its "both" must be updated
            this->tail->both = XOR(XOR(this->tail->both, NULL), new_node);
        if (this->head == NULL) // if this is the first node head must also be updated
            this->head = new_node;

        this->tail = new_node;
        ++this->size; // increment size of list
    }

    //insert data at the begining
    void push_front(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->both = XOR(NULL, this->head);

        if (this->head) // if a head already exists, its "both" must be updated
            this->head->both = XOR(new_node, XOR(NULL, this->head->both));
        if (this->tail == NULL) // if this is the first node tail must also be updated
            this->tail = new_node;

        this->head = new_node;
        ++this->size; // increment size of list
    }

    // fetch the data at given index [0, this->size-1]
    int get(int idx)
    {
        if (idx + 1 > this->size || idx < 0) // check for invalid index
        {
            cout << "index out of bounds!!!";
            return 0;
        }

        Node *it = this->head;
        Node *prev = NULL;
        Node *next = NULL;

        while (idx--) // iterate over list
        {
            next = XOR(it->both, prev);
            prev = it;
            it = next;
        }

        return it->data;
    }

    // delete the node at given index [0, this->size-1]
    void delete_node(int idx)
    {
        if (idx + 1 > this->size || idx < 0) // check for invalid index
        {
            cout << "index out of bounds!!!";
            return;
        }

        Node *it = this->head;
        Node *prev = NULL;
        Node *next = NULL;

        while (idx--) // iterate over list
        {
            next = XOR(it->both, prev);
            prev = it;
            it = next;
        }

        next = XOR(it->both, prev);

        if (prev) // node has a previous node which needs to be updated
            prev->both = XOR(XOR(prev->both, it), next);
        else // node has no previous node, i.e. head node is being deleted
            this->head = next;
        if (next) // node has a next node which needs to be updated
            next->both = XOR(XOR(next->both, it), prev);
        else // node has no next node, i.e. tail node is being deleted
            this->tail = prev;

        delete (it); // remove the node
    }

    // print the list
    void print()
    {
        if (this->head == NULL) // check if empty
            return;

        Node *it = this->head;
        Node *prev = NULL;
        Node *next = NULL;

        while (true) // iterate till end
        {
            cout << it->data << " ";
            if (it == this->tail)
                break;
            next = XOR(it->both, prev);
            prev = it;
            it = next;
        }

        return;
    }
};

int main()
{
    DLL dll;
    dll.push_back(78);
    dll.push_front(7);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_back(15);
    dll.push_front(1);
    dll.push_back(17);
    dll.print();
    cout << "\n****** getting the element at first index *******\n";
    cout << dll.get(1);
    cout << "\n****** deleting node at 3rd index *******\n";
    dll.delete_node(3);
    dll.print();
    cout << "\n****** deleting node at 5th index *******\n";
    dll.delete_node(5);
    dll.print();
    cout << "\n****** deleting node at 0th index *******\n";
    dll.delete_node(0);
    dll.print();
    cout << "\n****** deleting node at 1st index *******\n";
    dll.delete_node(1);
    dll.print();
    return 0;
}
