#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    friend class list;
};

class List // Linked list
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return !head; // returns 1 (true) if head is not in the list, means list is empty
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data, NULL);

        if (head == NULL) // means no node is present
        {
            head = newNode;
        }
        else
        {
            // else mn aya means list is not empty
            // head ko move ni krna so make another pointer to store address
            Node *curNode = head;

            while (curNode->next != NULL) // means list ka end ni ata tab tak while loop run krna
            {
                curNode = curNode->next;
            }
            // means end a gya loop khatam then
            curNode->next = newNode;
        }
    }

    void insertAtStart(int data)
    {
        Node *newNode = new Node(data, NULL);

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

    void display() // also named as traverse
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *curNode = head;
            do
            {
                cout << curNode->data << "\t";
                curNode = curNode->next;

            } while (curNode != NULL);
            
        }
    }
};

int main()
{
    system("cls");

    List l1, l2;
    cout << l1.isEmpty() << endl; // 1

    cout << "Data inserted at end" << endl;
    l1.insertAtEnd(5);
    l1.insertAtEnd(4);
    l1.insertAtEnd(3);
    l1.insertAtEnd(2);

    l1.display(); // 5 4 3 2
    cout << endl;

    cout << "Data inserted at start" << endl;
    l2.insertAtStart(1);
    l2.insertAtStart(2);
    l2.insertAtStart(3);
    l2.insertAtStart(4); 

    l2.display(); // 4 3 2 1


    // cout << endl;
    // cout << l1.isEmpty() << endl; // 0

    return 0;
}