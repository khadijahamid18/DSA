// Write a program that asks the user to enter two numbers. The program should use the conditional operator to determine which
// number is the smaller and which is the larger and display them in their ascending order.

#include <iostream>
using namespace std;
int main()
{
    system("cls");
    int num1 = 0;
    int num2 = 0;

    cout << "Please enter the first number : " << endl;
    cin >> num1;

    cout << "Please enter the second number : " << endl;
    cin >> num2;

    if (num1 > num2)
    {
        cout << "First number is larger then the second one " << endl << num2 << endl << num1;
    }
    else
    {
        cout << "Second number is larger then the first one " << endl << num1 << endl << num2;
    }

    return 0;
}