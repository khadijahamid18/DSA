#include <iostream>

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList
{
private:
    Node *head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new item before the specified old item
    void insertBefore(int oldItem, int newItem)
    {
        // Create a new node with the new item
        Node *newNode = new Node(newItem);

        // If the list is empty, make the new node the head
        if (!head)
        {
            head = newNode;
            return;
        }

        // If the old item is at the head, update the head to the new node
        if (head->data == oldItem)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Traverse the list to find the node with the old item
        Node *current = head;
        while (current->next && current->next->data != oldItem)
        {
            current = current->next;
        }

        // If the old item is not found, do nothing
        if (!current->next)
        {
            std::cout << "Old item not found in the list." << std::endl;
            delete newNode;
            return;
        }

        // Insert the new node before the node with the old item
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the linked list
    void display()
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    // Example usage
    LinkedList myList;

    // Insert elements into the list
    myList.insertBefore(2, 1);
    myList.insertBefore(2, 3);
    myList.insertBefore(1, 0);
    myList.insertBefore(4, 5);

    // Display the modified list
    myList.display();

    return 0;
}
