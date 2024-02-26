#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *pre;
    Node *next;

public:
    Node(int data, Node *pre, Node *next)
    {
        this->data = data;
        this->pre = pre;
        this->next = next;
    }

    friend class LinkedList;
};

class LinkedList
{
    Node *head;
    Node *last;

public:
    LinkedList()
    {
        head = NULL;
        last = NULL;
    }

    ~LinkedList()
    {
        Node *cur;

        while (head)
        {
            cur = head->next;
            delete head;
            head = cur;
        }
    }

    bool isEmpty() const
    {
        return (!head);
    }

    void insertAtEnd(int item)
    {
        Node *newNode = new Node(item, last, NULL);

        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    void insertAtStart(int item)
    {
        Node *newNode = new Node(item, NULL, head);

        if (head != NULL)
        {
            head->pre = newNode;
        }

        head = newNode;

        if (last == NULL)
        {
            last = newNode;
        }
    }

    void insertBefore(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem, NULL, NULL);

        if (!head)
        {
            cout << "List is empty" << endl;
            delete newNode;
            return;
        }

        if (head->data == oldItem)
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
            if (!head->next)
            {
                last = newNode;
            }
            return;
        }

        Node *cur = head;
        while (cur != NULL && cur->data != oldItem)
        {
            cur = cur->next;
        }

        if (!cur)
        {
            cout << "The element does not exist in the list" << endl;
            delete newNode;
            return;
        }

        newNode->pre = cur->pre;
        newNode->next = cur;
        cur->pre->next = newNode;
        cur->pre = newNode;
    }

    void insertAfter(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem, NULL, NULL);

        if (!head)
        {
            cout << "List is empty" << endl;
            delete newNode;
            return;
        }

        Node *cur = head;
        while (cur != NULL && cur->data != oldItem)
        {
            cur = cur->next;
        }

        if (!cur)
        {
            cout << "The element does not exist in the list" << endl;
            delete newNode;
            return;
        }

        newNode->pre = cur;
        newNode->next = cur->next;

        if (cur->next)
        {
            cur->next->pre = newNode;
        }

        cur->next = newNode;

        if (newNode->next)
        {
            newNode->next->pre = newNode;
        }
        else
        {
            last = newNode;
        }
    }

    void remove(int d)
    {
        Node *temp = head;

        while (temp != NULL && temp->data != d)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << d << " Data not found" << endl;
            return;
        }

        if (temp->pre != NULL)
        {
            temp->pre->next = temp->next;
        }
        else
        {
            head = temp->next;
        }

        if (temp->next != NULL)
        {
            temp->next->pre = temp->pre;
        }
        else
        {
            last = temp->pre;
        }

        delete temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    system("cls");

    LinkedList obj;

    obj.insertAtEnd(4);
    obj.insertAtEnd(6);
    obj.insertAtEnd(3);
    obj.insertAtEnd(8);
    obj.insertAtEnd(1);
    obj.insertAtEnd(7);

    obj.print();

    obj.insertAtStart(5);
    obj.print();

    obj.insertBefore(8, 2);
    obj.print();

    obj.insertAfter(3, 9);
    obj.print();

    // obj.remove(5);
    // obj.print();

    // obj.remove(7);
    // obj.print();

    // obj.remove(3);
    // obj.print();

    return 0;
}
