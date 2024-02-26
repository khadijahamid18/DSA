#include <iostream>
using namespace std;
int main()  
{
    system("cls");
    int x = 2;
    int y = 8;
    int *ptrx = &x;
    int *ptry = &y;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;

    cout << "Value of ptrx: " << ptrx << endl;
    cout << "Address of ptrx: " << &ptrx << endl;
    cout << "Value of memory location where it points to (x) : " << *ptrx << endl;

    cout << "Value of y: " << y << endl;
    cout << "Address of y: " << &y << endl;

    cout << "Value of ptry: " << ptry << endl;
    cout << "Address of ptry: " << &ptry << endl;
    cout << "Value of memory location where it points to (y) : " << *ptry << endl;

    return 0;
}