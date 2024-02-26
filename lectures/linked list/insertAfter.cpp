#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node after the old item
    void insertAfter(int oldItem, int newItem)
    {
        Node *newNode = new Node(newItem);

        // If the linked list is empty, simply make the new node the head
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // Search for the old item in the linked list
        Node *current = head;
        while (current != nullptr && current->data != oldItem)
        {
            current = current->next;
        }

        // If the old item is not found, do nothing
        if (current == nullptr)
        {
            std::cout << "Old item not found in the linked list." << std::endl;
            return;
        }

        // Insert the new node after the old item
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the linked list
    void display()
    {
        Node *current = head;
        while (current != nullptr)
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
    myList.insertAfter(2, 5);   // Insert 5 after 2
    myList.insertAfter(5, 7);   // Insert 7 after 5
    myList.insertAfter(10, 12); // Attempt to insert after an item not in the list

    // Display the modified linked list
    myList.display();

    return 0;
}
