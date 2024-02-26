#include <iostream>
using namespace std;
int main()
{
    system("cls");

    int size;
    int sum = 0;

    cout << "Enter the size of an array: ";
    cin >> size;
    cout << endl;

    int *p = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Please enter the array contents: " << i + 1 << ": ";
        cin >> p[i];
    }

    for (int i = 0; i < size; i++)
    {
        sum = sum + p[i];
    }

    cout << "Displaying sum of the elements: " << sum << endl;

    delete[]  p;

    return 0;
}