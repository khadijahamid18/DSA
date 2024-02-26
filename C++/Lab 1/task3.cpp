#include <iostream>
using namespace std;
void arrayByPointer(float *ptrArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Memory Address " << (ptrArray + i) << "\t\tContent "  << *(ptrArray + i) << endl;
    }
}
int main()
{
    system("cls");
    float arr[10] = {0.2, 1.4, 2.1, 3.7, 4.8, 5.2, 6.0, 7.3, 8.4, 3.7};

    arrayByPointer(arr, 10);

    return 0;
}