#include <iostream>

using namespace std;

void print(int n)
{
    cout << n << " ";
    if (n > 1)
    {
        print(n - 1);
    }
}

int main()
{
    system("cls");

    print(4);

    return 0;
}