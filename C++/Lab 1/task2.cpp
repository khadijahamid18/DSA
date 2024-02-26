#include <iostream>
using namespace std;
void subtractByPointer(double *ptrA, double *ptrB, double *ptrR)
{
    *ptrR = *ptrA - *ptrB;
    
}
int main()
{
    system("cls");
    double num1 = 0;
    double num2 = 0;
    cout << "Please enter the first number: ";
    cin >> num1;

    cout << "Please enter the second number: ";
    cin >> num2;

    double res;

    subtractByPointer(&num1, &num2, &res);

    cout << "The result of subtraction is: " << res << endl;

    return 0;
}