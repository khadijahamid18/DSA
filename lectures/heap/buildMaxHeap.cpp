#include <iostream>
using namespace std;

const int SIZE = 10;
int A[SIZE] = {2, 4, 3, 7, 6, 1, 5, 0, 9, 8}; 
int curSize = SIZE; 

void maxHeapify(int *A, int i)
{
    int l_i = 2 * i + 1;
    int r_i = 2 * i + 2;
    int max = i;
    int curSize = SIZE;

    if (l_i < curSize && A[max] < A[l_i])
    {
        max = l_i;
    }

    if (r_i < curSize && A[max] < A[r_i])
    {
        max = r_i;
    }

    if (max != i)
    {
        swap(A[max], A[i]);
        maxHeapify(A, max);
    }
}

int buildMaxHeap(int A[])
{
    for (int i = (curSize / 2 - 1); i >= 0; i--)
    {
        maxHeapify(A, i);   
    }
}

int main()
{
    system("cls");

    buildMaxHeap(A);

    // Print the array
    for (int i = 0; i < SIZE; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;

    return 0;
}
