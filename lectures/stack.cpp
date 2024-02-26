#include <iostream>
#include <stack>

using namespace std;

int main()
{
    system("cls");
    stack<int> s1;

    // Always check empty condition before top ans pop
    if (!s1.empty()) // conditon false 
    {
        cout << "Value at top of stack is: " << s1.top() << endl; // not run
    }

    cout << "Stack Size: " << s1.size() << endl;               // 0
    cout << "Check if stack is empty: " << s1.empty() << endl; // 1 (true)

    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(9);

    cout << "Stack Size: " << s1.size() << endl;               // 4
    cout << "Check if stack is empty: " << s1.empty() << endl; // 0 (false, not empty)

    // Always check empty condition before top ans pop

    if (!s1.empty()) // condition true
    {
        cout << "Value at top of stack is: " << s1.top() << endl; // 9
    }

    if (!s1.empty())
    {
        s1.pop(); // 9 removed
    }

    cout << "Stack Size: " << s1.size() << endl; // 3

    if (!s1.empty()) // condition true
    {
        cout << "Value at top of stack is: " << s1.top() << endl; // 6
    }

    if (!s1.empty())
    {
        s1.pop(); // 6 removed
    }

    cout << "Stack Size: " << s1.size() << endl; // 2

    return 0;
}