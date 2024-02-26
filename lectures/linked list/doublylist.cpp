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
    }

    ~LinkedList()
    {
        Node *cur;

        while (head)
        {
            head = head->next;
            delete cur;
            cur = head;
        }
    }

    bool isEmpty() const
    {
        return (!head);
    }

    void insertAtEnd(int item)
    {
        Node *newNode = new Node(item, NULL, NULL);

        // if inserted node is the first node
        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }

        // node is inserting at last
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

        // If the list was empty, set last to the new node
        if (last == NULL)
        {
            last = newNode;
        }
    }

    void insertBefore(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem, NULL, head);

        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        // if only one node exists which is oldItem itself
        if (head->data == oldItem)
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
            if (!head->next) // If there was only one node, update last
            {
                last = newNode;
            }
            return;
        }

        Node *cur = head;
        while (cur->next != NULL && cur->next->data != oldItem)
        {
            cur = cur->next;
        }

        if (!cur->next)
        {
            cout << "The element does not exist in the list" << endl;
            delete newNode; // Delete the new node as it won't be used
            return;
        }

        // oldItem is present somewhere between
        newNode->pre = cur->pre;
        newNode->next = cur;
        cur->pre->next = newNode;
        cur->pre = newNode;
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

    // void remove(int d)
    // {
    //     Node *temp = head;
    //     while (temp != NULL && temp->data != d)
    //     {
    //         temp = temp->next;
    //     }

    //     if (temp == NULL)
    //     {
    //         cout << d << " Data not found" << endl;
    //     }
    //     else
    //     {
    //         // data is present at first node
    //         if (temp->pre == NULL)
    //         {
    //             head = head->next;
    //             head->pre = NULL;
    //         }

    //         // data is present at last node
    //         else if (temp->next == NULL)
    //         {
    //             last = last->pre;
    //             last->next = NULL;
    //         }

    //         // data is present some where between the list
    //         else
    //         {
    //             temp->pre->next = temp->next;
    //             temp->next->pre = temp->pre;
    //         }
    //         delete temp;
    //     }
    // }

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

        // Adjust pointers for the previous node
        if (temp->pre != NULL)
        {
            temp->pre->next = temp->next;
        }
        else
        {
            // If the node to be removed is the first node, update head
            head = temp->next;
        }

        // Adjust pointers for the next node
        if (temp->next != NULL)
        {
            temp->next->pre = temp->pre;
        }
        else
        {
            // If the node to be removed is the last node, update last
            last = temp->pre;
        }

        // Delete the node
        delete temp;
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

    // cout << "Removing first node" << endl;
    // obj.remove(4);
    // obj.print();

    // cout << "Removing last node" << endl;
    // obj.remove(8);
    // obj.print();

    // cout << "Removing mid node" << endl;
    // obj.remove(3);
    // obj.print();

    return 0;
}