#include <iostream> 
using namespace std;

int A[10];
int maxSize = 10;
int curSize = 0;

int parent(int i)
{
    return (i - 1) / 2;
}

void insert(int item)
{
    if (curSize == maxSize)
    {
        cout << "Array is full, cannot insert more elements." << endl;
        return;
    }

    A[curSize] = item;
    int newPosition = curSize;
    curSize++;

    while ((newPosition != 0) && (A[newPosition] > A[parent(newPosition)]))
    {
        swap(A[newPosition], A[parent(newPosition)]);
        newPosition = parent(newPosition);
    }
}

int main()
{
    system("cls");

    insert(3);
    insert(7);
    insert(4);
    insert(2);
    insert(8);
    insert(9);
    insert(6);
    insert(5); 
    insert(2); 
    insert(1); 
    // insert(0);  // Array is full, cannot insert more elements.


    // Print the array
    for (int i = 0; i < curSize; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;

    return 0;
}
