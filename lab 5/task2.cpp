#include <iostream>
using namespace std;

int findKthSmallest(int A[], int n, int k)
{
    int start = 0; // first element
    int end = n - 1; // last element

    while (start <= end)
    {
        int point = A[end]; // point holds the current element
        int i = start - 1;  // 
        for (int j = start; j < end; j++)
        {
            if (A[j] <= point) 
            {
                i++;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[end]);

        if (i + 1 == k - 1)   
        {
            return A[i + 1]; // Found the kth smallest element
        }
        else if (i + 1 < k - 1) // search in right half
        {
            start = i + 2;
        }
        else
        {
            end = i; // search in left half
        }
    }
    return -1; // Invalid case
}

int main()
{
    system("cls");

    int A[] = {12, 3, 1, 7, 8, 20, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 3;
    int result = findKthSmallest(A, n, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}