#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *data;
    int top;
    const int MAX_SIZE;

public:
    // Constructor
    Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
    {
        data = new T[MAX_SIZE];
        top = -1;
    }

    ~Stack()
    {
        delete[] data;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(T newItem)
    {
        if (!isFull())
        {
            data[++top] = newItem;
        }
        else
        {
            cout << "Stack is full" << endl;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    T getTop()
    {
        if (top >= 0)
        {
            return data[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            exit(-1);
        }
    }

    void clear()
    {
        top = -1;
    }

    void showStructures()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
        }
        else
        {
            cout << "Stack(top to bottom): " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << data[i] << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    system("cls");

    Stack<int> stack(5);

    stack.push(5);
    stack.push(8);
    stack.push(6);
    stack.showStructures();
    stack.pop();
    stack.showStructures();

    return 0;
}