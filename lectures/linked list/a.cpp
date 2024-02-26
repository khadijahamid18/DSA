#include <iostream>

using namespace std;

/** Data element of linked LinkedList */
class Node
{
private:
    int data;   /** holds data in a node */
    Node *next; /** keeps a reference of the next node */

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    friend class LinkedList;
};

/** Manages collection of nodes in a linked LinkedList */
class LinkedList
{
private:
    Node *head; /** holds the first node of the linked LinkedList */

public:
    /** creates an empty LinkedList */
    LinkedList() : head{NULL}
    {
    }

    // destructor, complete its implementation
    /** deallocates linked LinkedList from memory */
    ~LinkedList()
    {
        Node *cur = head;

        while (head)
        {
            head = head->next;

            delete cur;

            cur = head;
        }
    }

    /** LinkedList is empty or not */
    bool isEmpty() const
    {
        return (!head);
    }

    /** insertes an item at the end of linked LinkedList */
    void insertAtEnd(int item)
    {
        Node *newNode = new Node(item);

        if (!head) // if LinkedList is empty
        {
            head = newNode;
        }
        else // if LinkedList contains nodes
        {
            Node *curNode = head;

            // traversing the LinkedList till it found the last node
            while (curNode->next != NULL)
                curNode = curNode->next;

            curNode->next = newNode;
        }

        cout << "Node inserted successfully at the end." << endl;
    }

    // complete its implementation
    /** insertes an item at the beginning of the linked LinkedList */
    void insertAtStart(int item)
    {
        Node *newNode = new Node(item);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void print()
    {
        Node *curNode = head;

        // traversing the LinkedList till it found the last node
        while (curNode != NULL)
        {
            cout << curNode->data << "  ";
            curNode = curNode->next;
        }

        cout << endl;
    }

    void insertBefore(int d, int newData)
    {
        Node *temp = head;
        Node *pre = NULL;
        while (temp != NULL && temp->data != d)
        {
            pre = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            Node *newNode = new Node(newData);
            if (pre == NULL)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                pre->next = newNode;
                newNode->next = temp;
            }
        }
        else
        {
            cout << "Element not found!" << endl;
        }
    }
};

int main()
{
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.insertBefore(30, 35);
    list.insertBefore(10, 5);
    list.insertBefore(45, 35);

    list.print();

    return 0;
}