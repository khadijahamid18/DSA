#include <iostream>

int fibonacci(int n)
{
    if (n == 0 || n == 1)
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
    system("cls");
    int term = 7;
    std::cout << "Fibonacci term at position " << term << " is: " << fibonacci(term) << std::endl;
    return 0;
}


// Initial call: fibonacci(6)
// Recursive calls are made to fibonacci(5) and fibonacci(4)

// First call: fibonacci(5)
// Recursive calls are made to fibonacci(4) and fibonacci(3)

// Second call: fibonacci(4)
// Recursive calls are made to fibonacci(3) and fibonacci(2)

// Third call: fibonacci(3)
// Recursive calls are made to fibonacci(2) and fibonacci(1)

// Fourth call: fibonacci(2)
// Recursive calls are made to fibonacci(1) and fibonacci(0)

// Base cases are reached:
// fibonacci(1) returns 1
// fibonacci(0) returns 0

// So, fibonacci(2) = fibonacci(1) + fibonacci(0) = 1 + 0 = 1

// Similarly, fibonacci(3) = fibonacci(2) + fibonacci(1) = 1 + 1 = 2
// fibonacci(4) = fibonacci(3) + fibonacci(2) = 2 + 1 = 3
// fibonacci(5) = fibonacci(4) + fibonacci(3) = 3 + 2 = 5

// Finally, the original call fibonacci(6) = fibonacci(5) + fibonacci(4) = 5 + 3 = 8

// Output: Fibonacci term at position 6 is: 8
