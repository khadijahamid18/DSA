#include <iostream>

using namespace std;

int sum(int n)
{
    if (n < 1)
    {
        return 0;
    }
    return sum(n - 1) + n;
}

int main()
{
    system("cls");

    cout << sum(5);

    return 0;
}
