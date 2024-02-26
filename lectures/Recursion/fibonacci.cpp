#include <iostream>

// Recursive function to generate Fibonacci series
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int num = 6;
    std::cout << "Fibonacci series up to " << num << " terms is: ";
    for (int i = 0; i < num; ++i)
    {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
