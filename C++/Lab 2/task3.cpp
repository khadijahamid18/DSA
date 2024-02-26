#include <iostream>
using namespace std;
void getData(int arr[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << "Please enter the elements for rows " << row << " and coloums " << col << endl;
            cin >> arr[row][col];
        }
    }
}
void display(int arr[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[row][col] << "    ";
        }
        cout << endl;
    }
}
void sumArray(int arr1[3][3], int arr2[3][3], int sum[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            sum[row][col] = arr1[row][col] + arr2[row][col];
        }
        cout << endl;
    }
    cout << "Sum of two arrays is" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << sum[row][col] << "    ";
        }
        cout << endl;
    }
}
int main()
{
    system("cls");
    int arr1[3][3];
    int arr2[3][3];
    int sum[3][3];
    getData(arr1);
    cout << endl;
    getData(arr2);
    system("cls");
    cout << "First Array is " << endl;
    display(arr1);
    cout << endl;
    cout << "Second array is" << endl;
    display(arr2);
    sumArray(arr1, arr2, sum);

    return 0;
}