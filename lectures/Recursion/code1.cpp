#include <iostream>

using namespace std;

void print(int n)
{
    if (n > 1)
    {
        print(n - 1);
    }
    cout << n << " ";
}

int main()
{
    system("cls");

    print(5);

    return 0;
}