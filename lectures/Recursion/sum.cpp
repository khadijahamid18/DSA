#include <iostream>

// Recursive function to calculate sum of digits
int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n % 10 + sumOfDigits(n / 10);
    }
}

int main()
{
    int number = 12345;
    std::cout << "Sum of digits in " << number << " is: " << sumOfDigits(number) << std::endl;
    return 0;
}
