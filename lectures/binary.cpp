#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &arr, int target, int low, int high)
{
    if (low > high)
    {
        return -1; // Base case: element not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid; // Base case: element found
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, target, mid + 1, high); // Recursive case: search in the right half
    }
    else
    {
        return binarySearch(arr, target, low, mid - 1); // Recursive case: search in the left half
    }
}

int main()
{
    system("cls");
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;
    int result = binarySearch(sortedArray, target, 0, sortedArray.size() - 1);

    if (result != -1)
    {
        std::cout << "Element found at index " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}

// Initial call: binarySearch({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, 0, 9)

// First call: binarySearch({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, 0, 9)
// Mid = (0 + 9) / 2 = 4, arr[4] = 5 (less than target)
// Recursive call: binarySearch({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, 5, 9)

// Second call: binarySearch({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, 5, 9)
// Mid = (5 + 9) / 2 = 7, arr[7] = 8 (greater than target)
// Recursive call: binarySearch({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, 5, 6)

// Third call: binarySearch({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, 5, 6)
// Mid = (5 + 6) / 2 = 5, arr[5] = 6 (equal to target, base case)
// Element found at index 5

// Output: Element found at index 5
