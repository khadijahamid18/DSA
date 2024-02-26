#include <iostream>

int intersection1(int A[], int B[], int C[], int n) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                C[count++] = A[i];
                break;  // Break to avoid duplicates in C
            }
        }
    }
    
    return count;
}

int intersection2(int A[], int B[], int C[], int n) {
    int count = 0;
    int i = 0, j = 0;
    
    while (i < n && j < n) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            C[count++] = A[i];
            i++;
            j++;
        }
    }
    
    return count;
}

int main() {
    int A[] = {1, 2, 4, 6, 8};
    int B[] = {2, 5, 6, 7, 8};
    int C1[5], C2[5];
    
    int size1 = intersection1(A, B, C1, 5);
    int size2 = intersection2(A, B, C2, 5);
    
    std::cout << "Intersection1: ";
    for (int i = 0; i < size1; i++) {
        std::cout << C1[i] << " ";
    }
    
    std::cout << "\nIntersection2: ";
    for (int i = 0; i < size2; i++) {
        std::cout << C2[i] << " ";
    }
    
    return 0;
}