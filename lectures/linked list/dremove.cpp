#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *pre, *next;
};

class DoublyLinkedList
{
private:
    Node *head, *last;

public:
    DoublyLinkedList() : head(nullptr), last(nullptr) {}

    // Function to add a node at the end of the list
    void append(int data)
    {
        Node *newNode = new Node{data, nullptr, nullptr};

        if (head == nullptr)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            newNode->pre = last;
            last->next = newNode;
            last = newNode;
        }
    }

    // Function to remove a node with a specific value
    void remove(int d)
    {
        Node *temp = head;

        // Find the node with the given data
        while (temp != nullptr && temp->data != d)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << d << " Data not found" << endl;
        }
        else
        {
            // Data is present at the first node
            if (temp->pre == nullptr)
            {
                head = temp->next;

                if (head != nullptr)
                {
                    head->pre = nullptr;
                }
                else
                {
                    // If the list becomes empty, update 'last'
                    last = nullptr;
                }
            }
            // Data is present at the last node
            else if (temp->next == nullptr)
            {
                last = temp->pre;
                last->next = nullptr;
            }
            // Data is present somewhere between the list
            else
            {
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
            }

            delete temp;
        }
    }

    // Function to display the contents of the list
    void display()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList myList;

    // Adding nodes to the list
    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.append(40);
    myList.append(50);
    myList.append(60);

    // Displaying the initial list
    cout << "Original List: ";
    myList.display();

    // Removing a node
    myList.remove(30);

    // Displaying the list after removal
    cout << "List after removal: ";
    myList.display();

    myList.remove(10); 
    myList.display();

    myList.remove(60);
    myList.display();

    return 0;
}
