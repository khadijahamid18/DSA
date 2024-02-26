#include<iostream>
using namespace std;

int main()
{
    system("cls");
     
    float* ptrX = NULL;
    float* ptrY = NULL;

    float* x = new float(4.5);
    float* y = new float(9.3);

    ptrX = &*x;
    ptrY = &*y;

    // ptrX = x;
    // ptrY = y;

    cout << "Address of ptrX: " << &ptrX << endl;
    cout << "Value of ptrX: " << ptrX << endl;
    cout << "Memory location where it points to: " << *ptrX << endl;

    cout << "Address of ptrY: " << &ptrY << endl;
    cout << "Value of ptrY: " << ptrY << endl;
    cout << "Memory location where it points to: " << *ptrY << endl;
    
    delete x;
    delete y;


    return 0;
}