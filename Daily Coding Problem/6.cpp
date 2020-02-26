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
    int data;
    Node *both;
};

class DLL
{
    int size;
    Node *head;
    Node *tail;

public:
    DLL()
    {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    Node *XOR(Node *a, Node *b)
    {
        return (Node *)((uintptr_t)a ^ (uintptr_t)b);
    }

    void push_back(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->both = XOR(this->tail, NULL);

        if (this->tail)
        {
            this->tail->both = XOR(XOR(this->tail->both, NULL), new_node);
        }
        if (this->head == NULL)
        {
            this->head = new_node;
        }

        this->tail = new_node;
        ++this->size;
    }

    void push_front(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->both = XOR(NULL, this->head);

        if (this->head)
        {
            this->head->both = XOR(new_node, XOR(NULL, this->head->both));
        }
        if (this->tail == NULL)
        {
            this->tail = new_node;
        }

        this->head = new_node;
        ++this->size;
    }

    int get(int idx)
    {
        if (idx + 1 > this->size || idx < 0)
        {
            cout << "index out of bounds!!!";
            return 0;
        }

        Node *it = this->head;
        Node *prev = NULL;
        Node *next = NULL;

        while (idx--)
        {
            next = XOR(it->both, prev);
            prev = it;
            it = next;
        }

        return it->data;
    }

    void delete_node(int idx)
    {
        if (idx + 1 > this->size || idx < 0)
        {
            cout << "index out of bounds!!!";
            return;
        }

        Node *it = this->head;
        Node *prev = NULL;
        Node *next = NULL;

        while (idx--)
        {
            next = XOR(it->both, prev);
            prev = it;
            it = next;
        }

        next = XOR(it->both, prev);
        if (prev)
        {
            prev->both = XOR(XOR(prev->both, it), next);
        }
        else
        {
            this->head = next;
        }
        if (next)
        {
            next->both = XOR(XOR(next->both, it), prev);
        }
        else
        {
            this->tail = prev;
        }

        delete (it);
    }

    void print()
    {
        if (this->head == NULL)
            return;

        Node *it = this->head;
        Node *prev = NULL;
        Node *next = NULL;

        while (it)
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
    dll.push_back(111);
    dll.push_front(7);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_back(111);
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
