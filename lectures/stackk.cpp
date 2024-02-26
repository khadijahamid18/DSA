#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top < MAX_SIZE - 1)
        {
            arr[++top] = value;
            cout << value << " pushed to the stack.\n";
        }
        else
        {
            cout << "Stack overflow! Cannot push " << value << ".\n";
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            cout << arr[top--] << " popped from the stack.\n";
        }
        else
        {
            cout << "Stack underflow! Cannot pop from an empty stack.\n";
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty. Cannot peek.\n";
            return -1; // Assuming -1 represents an empty stack
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();

    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
