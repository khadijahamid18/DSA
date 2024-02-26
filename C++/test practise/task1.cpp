#include <iostream>
using namespace std;
int main()
{
    system("cls");
    // Normal array
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    cout << "The array you entered: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }

    // // Character Array
    // char a[6] = "";
    // // cin >> a is an error in normal array
    // cin >> a;
    // cout << a;
    

    return 0;
}