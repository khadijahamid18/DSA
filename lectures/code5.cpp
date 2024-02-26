#include <iostream>

using namespace std;

double sum(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return 1 + a * sum(a, n - 1);
}

int main()
{
    system("cls");

    cout << sum(2.5, 4);

    return 0;
}