#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor
    ~CircularLinkedList() {
        if (head == nullptr) {
            return; // List is already empty
        }

        Node* current = head;
        Node* temp;

        do {
            temp = current->next;
            delete current;
            current = temp;
        } while (current != head);

        head = nullptr; // Set head to null after deallocating all nodes
    }

    // Function to add a node to the circular linked list
    void addNode(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself in a circular list
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;
    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);

    cout << "Circular Linked List: ";
    myList.display();

    // Destructor will be automatically called when myList goes out of scope
    return 0;
}
