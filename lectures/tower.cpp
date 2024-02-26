#include <iostream>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    // Base case: Move one disk from source to destination
    if (n == 1)
    {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }

    // Recursive case:
    // Move (n-1) disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the remaining disk from source to destination
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;

    // Move the (n-1) disks from auxiliary to destination peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    system("cls");
    int numDisks = 3;
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}
