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

int getMax()
{
    int max = A[0];
    A[0] = A[--curSize];
    maxHeapify(A, 0);
    return max;
}

void buildMaxHeap(int A[])
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

    // Print the max heap
    for (int i = 0; i < curSize; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
    cout << endl;

    cout << "Maximum: " << getMax() << endl;

    cout << endl;

    // Print the array after extracting the maximum
    for (int i = 0; i < curSize; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;

    return 0;
}
