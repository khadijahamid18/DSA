#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }

    void enqueue(int value)
    {
        if (rear < MAX_SIZE - 1)
        {
            arr[++rear] = value;
            if (front == -1)
            {
                front = 0; // Update front if the queue was empty
            }
            std::cout << value << " enqueued to the queue.\n";
        }
        else
        {
            std::cout << "Queue overflow! Cannot enqueue " << value << ".\n";
        }
    }

    void dequeue()
    {
        if (front <= rear && front != -1)
        {
            std::cout << arr[front++] << " dequeued from the queue.\n";
        }
        else
        {
            std::cout << "Queue underflow! Cannot dequeue from an empty queue.\n";
            // Reset front and rear to -1 to represent an empty queue
            front = rear = -1;
        }
    }

    int peek()
    {
        if (front <= rear && front != -1)
        {
            return arr[front];
        }
        else
        {
            std::cout << "Queue is empty. Cannot peek.\n";
            return -1; // Assuming -1 represents an empty queue
        }
    }

    bool isEmpty()
    {
        return front == -1;
    }
};

int main()
{
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
