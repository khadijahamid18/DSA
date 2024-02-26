#include <iostream>
using namespace std;

int f(int a, int b)
{
    if (a <= 0)
    {
        return b;
    }
    else
    {
        int temp = f(a - 2, b * 2);
        temp = temp - a;
        cout << temp << " ";
        return temp;
    }
    
    
}

int main()
{
    system("cls");

    f(5, 4);

    return 0;
}

// DEBUG

// Initial call: f(5, 4)
// a is not less than or equal to 0, so it goes to the else part.
// Calls f(3, 8) (since a - 2 and b * 2).
// a is not less than or equal to 0, so it goes to the else part.
// Calls f(1, 16) (since 3 - 2 and 8 * 2).
// a is not less than or equal to 0, so it goes to the else part.
// Calls f(-1, 32) (since 1 - 2 and 16 * 2).
// a is less than or equal to 0, so it returns b (which is 32) and backtracks.
// temp is now 32 - 1 = 31, and it prints 31.
// temp is now 31 - 3 = 28, and it prints 28.
// temp is now 28 - 5 = 23, and it prints 23.
// Output:
// The output of the code will be:
// 31 28 23