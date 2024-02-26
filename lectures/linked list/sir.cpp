#include <iostream>

using namespace std;

/** Data element of linked list */
class Node
{
private:
    int data;   /** holds data in a node */
    Node *next; /** keeps a reference of the next node */

public: 
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    void print() const
    {
        cout << "Item: " << data << endl;
    }

    friend class List;
};

/** Manages collection of nodes in a linked list */
class List
{
private:
    Node *head; /** holds the first node of the linked list */

public:
    /** creates an empty list */
    List() : head{NULL}
    {
    }

    // destructor, complete its implementation
    /** deallocates linked list from memory */
    ~List()
    {
        Node *cur = head;

        while (head)
        {
            head = head->next;

            delete cur;

            cur = head;
        }
    }

    /** list is empty or not */
    bool isEmpty() const
    {
        return (!head);
    }

    /** insertes an item at the end of linked list */
    void insertAtEnd(int item)
    {
        Node *newNode = new Node(item, NULL);

        if (!head) // if list is empty
        {
            head = newNode;
        }
        else // if list contains nodes
        {
            Node *curNode = head;

            // traversing the list till it found the last node
            while (curNode->next != NULL)
                curNode = curNode->next;

            curNode->next = newNode;
        }

        cout << "Node inserted successfully at the end." << endl;
    }

    // complete its implementation
    /** insertes an item at the beginning of the linked list */
    void insertAtStart(int item)
    {
        Node *newNode = new Node(item, NULL);

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

    // complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
    /** inserts a newItem before the oldItem */

    void insertBefore(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem, NULL);

        // Empty case
        if (head == NULL)
        {
            head = newNode;
        }

        // 1 node which is head itself
        if (head->data == oldItem)
        {
            head->next = newNode;
            head = newNode;
            return;
        }

        // Traversing the list to until it find the old item
        Node *current = head;
        while (current->next && current->next->data != oldItem)
        {
            current = current->next;
        }

        // if old iem is not found
        if (!current->next)
        {
            cout << "Old item is not found so deleting new node" << endl;
            delete newNode;
            return;
        }

        // Inserting new node before the node with old item
        newNode->next = current->next;
        current->next = newNode;

        cout << "New node is successfully inserted before the old node" << endl;
    }

    // complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
    /** inserts a newItem after the oldItem. */
    void insertAfter(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem, NULL);

        // Empty case
        if (!head)
        {
            cout << "List is empty" << endl;
            head = newNode;
        }

        // Traversing the list
        Node *cur = head;
        while (cur != NULL && cur->data != oldItem)
        {
            cur = cur->next;
        }

        // If old item not found
        if (cur == NULL)
        {
            cout << "Old item not found" << endl;
            delete newNode;
        }

        // Inserting new node after the node with old item
        newNode->next = cur->next;
        cur->next = newNode;

        cout << "New node is successfully inserted after the old node" << endl;
    }

    /** removes the last item from the linked list */
    void removeLast()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
        }
        else
        {
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node *preNode = head;       // holds first node
                Node *curNode = head->next; // holds second node, if any

                while (curNode->next != NULL)
                {
                    preNode = curNode;
                    curNode = curNode->next;
                }

                delete curNode;
                preNode->next = NULL;
            }

            cout << "Last node removed successfully." << endl;
        }
    }

    // complete its implementation
    /** removes the first node of the linked list */
    void removeFirst()
    {
        if (head == NULL)
        {
            cout << "Listis empty" << endl;
        }

        Node *temp = head;
        Node *cur = head;
        head = head->next;
        cur->next = head;
        delete temp;

        cout << "First node removed successfully." << endl;
    }

    // complete its implementation. Give appropriate error message item does not exist.
    /** removes an item of the linked list. */
    void removeItem(int item)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        // Traversing the list
        Node *cur = head;
        Node *pre = NULL;
        while (cur != NULL && cur->data != item)
        {
            pre = cur;
            cur = cur->next;
        }

        // If item not found
        if (cur == NULL)
        {
            cout << "The item does not exist" << endl;
        }

        // remove the node
        if (pre == NULL)
        {
            head = cur->next;
        }
        else
        {
            pre->next = cur->next;
        }

        delete cur;

        cout << "Item removed successfully" << endl;
    }

    /** display the contents of entire list */
    void display() const
    {
        if (!head)
            cout << "List is empty." << endl;
        else
        {
            Node *curNode = head;

            while (curNode != NULL)
            {
                cout << curNode->data << "\t";
                curNode = curNode->next;
            }
        }
    }

    // complete its implementation.
    /** finds an item in the linked list and returns its address, returns NULL, otherwise */
    Node *find(int item) const
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Node *cur = head;
        bool found = false;

        while (cur != NULL)
        {
            if (cur->data == item)
            {
                cur->print();
                found = true;
                cout << "Item Found" << endl;
            }

            cur = cur->next;
        }

        if (!found)
        {
            cout << "Element does not exist in the list" << endl;
        }
    }
};

int main()
{
    List obj;

    obj.insertAtEnd(1);
    obj.insertAtEnd(2);
    obj.insertAtEnd(3);
    cout << endl;

    // obj.display(); // 1 2 3
    // cout << endl;

    obj.insertAtStart(5);
    obj.insertAtStart(7);
    obj.insertAtStart(8);

    obj.display(); // 8 7 5 1 2 3
    cout << endl;

    obj.removeLast();
    cout << endl;

    obj.display(); // 8 7 5 1 2
    cout << endl;

    obj.insertBefore(5, 6);
    obj.display(); // 8 7 6 5 1 2
    cout << endl;

    obj.insertAfter(2, 3);
    obj.display(); // 8 7 6 5 1 2 3
    cout << endl;

    obj.removeFirst();
    obj.display(); //  7 6 5 1 2 3
    cout << endl;

    obj.removeItem(5);
    obj.display(); //  7 6 1 2 3
    cout << endl;

    obj.find(1);

    return 0;
}