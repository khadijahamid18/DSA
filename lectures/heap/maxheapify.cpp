#include <iostream>
using namespace std;

const int SIZE = 10;
// int arr[SIZE] = {2, 4, 3, 7, 6, 1, 5, 0, 9, 8};
// int curSize = SIZE;

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

int main()
{
    system("cls");
    int A[10] = {8, 5, 4, 9, 6, 1, 3, 0, 7, 2};

    maxHeapify(A, 1);

    // maxHeapify(A, 0);   // Not working for 0 index

    for (int i = 0; i < SIZE; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
    cout << endl;

    return 0;
}
