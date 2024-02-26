#include <iostream>

using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sum(n - 1) + n * n;
}

int main()
{
    system("cls");

    cout << sum(5); 

    return 0;
}