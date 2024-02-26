#include <iostream>
using namespace std;
#define SIZE 10

int *getPositiveNumbers(const int ar[], const int size, int &newArraySize)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (ar[i] >= 0)
        {
            newArraySize++;
        }
    }

    if (newArraySize == 0)
    {
        return NULL;
    }

    int *arr1 = new int[newArraySize];

    for (int i = 0; i < size; i++)
    {
        if (ar[i] > 0)
        {
            arr1[count] = ar[i];
            count++;
        }
    }
    return arr1;
}

int main()
{
    system("cls");

    int arr[SIZE];
    int newSize = 0;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter any number" << i + 1 << ": " << endl;
        cin >> arr[i];
    }
    int *newArray = getPositiveNumbers(arr, SIZE, newSize);

    if (newArray == NULL)
    {
        cout << "No positive number found" << endl;
    }
    else
    {
        cout << "Positive numbers in array :\n";
        for (int i = 0; i < newSize; i++)
        {
            cout << *(newArray + i) << "\t";
        }
    }
    delete[] newArray;

    return 0;
}