 #include <iostream>

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[high]);
    return i + 1;
}

int findKthSmallest(int A[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int partitionIndex = partition(A, low, high);

        if (partitionIndex - low == k - 1)
            return A[partitionIndex];
        if (partitionIndex - low > k - 1)
            return findKthSmallest(A, low, partitionIndex - 1, k);
        return findKthSmallest(A, partitionIndex + 1, high, k - partitionIndex + low - 1);
    }

    // If k is out of range
    return -1;  // You can choose to handle this differently
}

int findKthSmallest(int A[], int n, int k) {
    return findKthSmallest(A, 0, n - 1, k);
}

int main() {
    int A[] = {12, 3, 1, 15, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 3;

    int result = findKthSmallest(A, n, k);

    if (result != -1) {
        std::cout << "The " << k << "th smallest element is: " << result << std::endl;
    } else {
        std::cout << "Invalid value of k." << std::endl;
    }

    return 0;
}

// #include <iostream>
// #include <algorithm>

// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = low - 1;
//     for (int j = low; j <= high - 1; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// int quickselect(int arr[], int low, int high, int k) {
//     if (low <= high) {
//         int pivotIndex = partition(arr, low, high);
//         if (pivotIndex == k - 1) {
//             return arr[pivotIndex];
//         } else if (pivotIndex > k - 1) {
//             return quickselect(arr, low, pivotIndex - 1, k);
//         } else {
//             return quickselect(arr, pivotIndex + 1, high, k);
//         }
//     }
//     return -1; // Error case
// }

// int findKthSmallest(int A[], int n, int k) {
//     if (k > 0 && k <= n) {
//         return quickselect(A, 0, n - 1, k);
//     }
//     return -1; // Error case for invalid k
// }