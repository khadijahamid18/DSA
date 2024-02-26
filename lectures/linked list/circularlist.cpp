#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    void print()
    {
        cout << "Item" << data << endl;
    }

    friend class LinkedList;
};

class LinkedList
{
    Node *head;

public:
    LinkedList() : head{NULL}
    {
    }

    ~LinkedList()
    {
    }

    bool isEmpty() const
    {
        return (!head);
    }

    void insertAtEnd(int data)
    {
        Node *temp = new Node(data, NULL);

        // if no node
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }

        // List traversing
        Node *cur = head;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;

        cout << "Element added at the end of the list successfully" << endl;
    }

    void insertAtStart(int data)
    {
        Node *temp = new Node(data, NULL);

        if (head == NULL)
        {
            head = temp;
            head->next = head; // self referencing (head k next mn head ka hi address hy)
        }

        // List Traversing
        Node *cur = head;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        temp->next = head;
        head = temp;
        cur->next = head;

        cout << "Element added at the start successfully" << endl;
    }

    void insertBefore(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem, NULL);

        // no node
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }

        Node *cur = head;
        while (cur->next != head && cur->next->data != oldItem)
        {
            cur = cur->next;
        }

        // 1 node which is head itself
        if (head->data == oldItem)
        {
            head->next = newNode;
            head = newNode;
            cur->next = head;
            return;
        }

        if (cur == NULL)
        {
            cout << "Old item not found" << endl;
            delete newNode;
            return;
        }

        newNode->next = cur->next;
        cur->next = newNode;

        cout << "Element added before the old item successfully" << endl;
    }

    void insertAfter(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem, NULL);

        // no node
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }

        Node *cur = head;
        while (cur->next != head && cur->data != oldItem)
        {
            cur = cur->next;
        }

        // 1 node which is head itself
        if (head->data == oldItem)
        {
            head->next = newNode;
            head = newNode;
            cur->next = head;
            return;
        }

        if (cur == NULL)
        {
            cout << "Old item not found" << endl;
            delete newNode;
            return;
        }

        newNode->next = cur->next;
        cur->next = newNode;

        cout << "Element added after the old item successfully" << endl;
    }

    void removeLast()
    {
        // 0 node
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        // // 1 node
        // else if (head->next = head)
        // {
        //     delete head;
        //     head = NULL;
        // }

        else
        {
            // List traversing
            Node *pre = head;       // holds 1st node
            Node *cur = head->next; // holds 2nd node

            while (cur->next != head)
            {
                pre = cur;
                cur = cur->next;
            }

            delete cur;
            pre->next = head;

            cout << "Last node removed successfully" << endl;
        }
    }

    void removeFirst()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            Node *cur = head;
            while (cur->next != head)
            {
                cur = cur->next;
            }

            cur->next = head->next;
            Node *temp = head;
            head = head->next;

            delete temp;

            cout << "First node removed successfully" << endl;
        }
    }

    void removeItem(int item)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Node *cur = head;

        Node *pre = NULL;
        while (cur->next != head && cur->next->data != item)
        {
            pre = cur;
            cur = cur->next;
        }

        if (cur == NULL)
        {
            cout << "Item is not found" << endl;
        }

        do
        {
            if (cur->data == item)
            {
                // If the item is found, update the next pointer of the previous node
                if (pre != nullptr)
                {
                    pre->next = cur->next;
                }
                // If the item is in the first node, update the head
                else
                {
                    head = cur->next;
                }

                // Delete the node with the specified item
                delete cur;
                return;
            }

            pre = cur;
            cur = cur->next;
        } while (cur != head);

        cout << "Given node removed successfully" << endl;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
        }

        Node *cur = head;
        // while (cur->next != head)
        // {
        //     cout << cur->data << "\t";
        //     cur = cur->next;
        // }
        // cout << cur->data << "\t";

        do
        {
            cout << cur->data << "\t";
            cur = cur->next;

        } while (cur != head);
    }
};

int main()
{
    system("cls");

    LinkedList obj;

    // obj.insertBefore(3, 7);
    // obj.display();
    // cout << endl;

    obj.insertAtEnd(1);
    obj.insertAtEnd(2);
    obj.insertAtEnd(3);
    obj.insertAtEnd(4);
    // cout << endl;
    // obj.display(); // 1 2 3 4
    cout << endl;

    obj.insertAtStart(5);
    obj.insertAtStart(6);
    obj.insertAtStart(7);
    obj.insertAtStart(8);
    obj.display(); // 8 7 6 5 1 2 3 4
    cout << endl;

    obj.insertBefore(6, 9);
    obj.display(); // 8 7 9 6 5 1 2 3 4
    cout << endl;

    obj.insertAfter(6, 10);
    obj.display(); // 8 7 9 6 10 5 1 2 3 4
    cout << endl;

    obj.removeLast();
    obj.display(); // 8 7 9 6 10 5 1 2 3
    cout << endl;

    obj.removeFirst();
    obj.display(); // 7 9 6 10 5 1 2 3
    cout << endl;

    obj.removeItem(10);
    obj.display(); // 7 9 6 5 1 2 3
    cout << endl;

    return 0;
}