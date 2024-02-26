#include <iostream>
using namespace std;
#define SIZE 10

void getEvenOdd(const int ar[], const int n_ar, int *&even, int &n_even, int *&odd, int &n_odd)
{
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n_ar; i++)
    {
        if (ar[i] % 2 == 0)
        {
            n_even++;
        }
        else
        {
            n_odd++;
        }
    }
    int *arrEven = new int[n_even];
    int *arrOdd = new int[n_odd];

    for (int i = 0; i < n_ar; i++)
    {
        if (ar[i] % 2 == 0)
        {
            arrEven[count1] = ar[i];
            count1++;
        }
        else
        {
            arrOdd[count2] = ar[i];
            count2++;
        }
    }
    even = arrEven;
    odd = arrOdd;

    if (n_even == 0)
    {
        even = NULL;
    }
    if (n_odd == 0)
    {
        odd = NULL;
    }
}

int main()
{
    system("cls");

    int arr[10] = {1, 3, 6, 4, 9, 3, 2, 0, 5, 7};
    int *even = NULL;
    int *odd = NULL;
    int evenSize = 0, oddSize = 0;
    getEvenOdd(arr, SIZE, even, evenSize, odd, oddSize);
    if (oddSize == NULL)
    {
        cout << "No odd number found" << endl;
    }
    else
    {
        cout << "Odd Numbers: " << endl;
        for (int i = 0; i < oddSize; i++)
        {
            cout << odd[i] << endl;
        }
    }
    if (evenSize == NULL)
    {
        cout << "No even numbers found" << endl;
    }
    else
    {
        cout << "Even Numbers: " << endl;
        for (int i = 0; i < evenSize; i++)
        {
            cout << even[i] << endl;
        }
    }
    delete[] even;
    delete[] odd;

    return 0;
}