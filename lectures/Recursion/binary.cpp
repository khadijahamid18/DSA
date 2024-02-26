#include <iostream>
#include <vector>

// Recursive function for binary search
int binarySearch(const std::vector<int> &arr, int target, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return binarySearch(arr, target, mid + 1, right);
        }
        else
        {
            return binarySearch(arr, target, left, mid - 1);
        }
    }

    return -1; // Not found
}

int main()
{
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int result = binarySearch(sortedArray, target, 0, sortedArray.size() - 1);

    if (result != -1)
    {
        std::cout << target << " found at index " << result << std::endl;
    }
    else
    {
        std::cout << target << " not found in the array.\n";
    }

    return 0;
}
