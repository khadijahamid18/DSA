

// #include <iostream>
// using namespace std;

// const int SIZE = 10;
// int A[SIZE] = {2, 4, 3, 7, 6, 1, 5, 0, 9, 8};
// int curSize = SIZE;

// void maxHeapify(int *A, int i, int curSize)
// {
//     int l_i = 2 * i + 1;
//     int r_i = 2 * i + 2;
//     int max = i;

//     if (l_i < curSize && A[l_i] > A[max])
//     {
//         max = l_i;
//     }

//     if (r_i < curSize && A[r_i] > A[max])
//     {
//         max = r_i;
//     }

//     if (max != i)
//     {
//         swap(A[max], A[i]);
//         maxHeapify(A, max, curSize);
//     }
// }

// int extractMax(int *A, int &curSize)
// {
//     int max = A[0];
//     A[0] = A[--curSize];
//     maxHeapify(A, 0, curSize);
//     return max;
// }

// void buildMaxHeap(int *A, int curSize)
// {
//     for (int i = (curSize / 2 - 1); i >= 0; i--)
//     {
//         maxHeapify(A, i, curSize);
//     }
// }

// void heapSort(int *A, int curSize)
// {
//     for (int i = curSize - 1; i > 0; i--)
//     {
//         swap(A[0], A[i]);
//         maxHeapify(A, 0, i);
//     }
// }

// int main()
// {
//     system("cls");

//     buildMaxHeap(A, curSize);

//     cout << "Max Heap: \n";
//     for (int i = 0; i < curSize; i++)
//     {
//         cout << A[i] << "\t";
//     }
//     cout << endl;

//     cout << "Sorted Array: \n";
//     heapSort(A, curSize);
//     for (int i = 0; i < SIZE; i++)
//     {
//         cout << A[i] << "\t";
//     }

//     return 0;
// }

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

    if (l_i < curSize && A[l_i] > A[max])
    {
        max = l_i;
    }

    if (r_i < curSize && A[r_i] > A[max])
    {
        max = r_i;
    }

    if (max != i)
    {
        swap(A[max], A[i]);
        maxHeapify(A, max);
    }
}

void buildMaxHeap(int *A)
{
    for (int i = (curSize / 2 - 1); i >= 0; i--)
    {
        maxHeapify(A, i);
    }
}

void heapSort(int *A)
{
    buildMaxHeap(A);

    for (int i = curSize - 1; i > 0; i--)
    {
        swap(A[0], A[i]);
        curSize--;
        maxHeapify(A, 0);
    }
}

int main()
{
    // Commented out the system("cls") line as it might not work on all systems.

    cout << "Original Array: \n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;

    cout << "Max Heap: \n";
    buildMaxHeap(A);
    for (int i = 0; i < SIZE; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;

    heapSort(A);

    cout << "Sorted Array: \n"; 
    for (int i = 0; i < SIZE; i++)
    {
        cout << A[i] << "\t";
    }

    return 0;
}
