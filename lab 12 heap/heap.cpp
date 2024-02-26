#include <iostream>
#include <cmath>
using namespace std;

class Student
{
    friend class StudentMaxHeap;

private:
    double cgpa;
    int rollNo;
};

class StudentMaxHeap
{
private:
    Student *arr;
    int curSize;
    int maxSize;

    void heapifyUp(int index) // when new element is inserted
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[index].cgpa > arr[parent].cgpa ||
                (arr[index].cgpa == arr[parent].cgpa && arr[index].rollNo < arr[parent].rollNo))
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index) // when root(max) element is removed
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < curSize && (arr[leftChild].cgpa > arr[largest].cgpa ||
                                    (arr[leftChild].cgpa == arr[largest].cgpa && arr[leftChild].rollNo < arr[largest].rollNo)))
        {
            largest = leftChild;
        }

        if (rightChild < curSize && (arr[rightChild].cgpa > arr[largest].cgpa ||
                                     (arr[rightChild].cgpa == arr[largest].cgpa && arr[rightChild].rollNo < arr[largest].rollNo)))
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    StudentMaxHeap(int size)
    {
        maxSize = size;
        arr = new Student[maxSize];
        curSize = 0;
    }

    ~StudentMaxHeap()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return curSize == 0;
    }

    bool isFull()
    {
        return curSize == maxSize;
    }

    bool insert(int rollNo, double cgpa)
    {
        if (isFull())
        {
            return false;
        }

        arr[curSize].rollNo = rollNo;
        arr[curSize].cgpa = cgpa;
        heapifyUp(curSize);
        curSize++;

        return true;
    }

    bool remove(int &rollNo, double &cgpa)
    {
        if (isEmpty())
        {
            return false;
        }

        // Store the roll number and CGPA of the student with the maximum CGPA (at the root)
        rollNo = arr[0].rollNo;
        cgpa = arr[0].cgpa;

        // Replace the root with the last element in the heap
        arr[0] = arr[curSize - 1];
        // Reduce the size of the heap
        curSize--;

        // Restore the max heap property by performing a heapify-down operation starting from the root
        heapifyDown(0);

        return true;
    }

    void displayStudentList()
    {
        // Create a temporary max heap to store students in descending order
        StudentMaxHeap tempHeap(maxSize);

        // Extract students from the original max heap in descending order
        while (!isEmpty())
        {
            int rollNo;
            double cgpa;
            // Remove the student with the maximum CGPA from the original max heap
            remove(rollNo, cgpa);
            // Display the roll number and CGPA of the removed student
            cout << "Roll No: " << rollNo << ", CGPA: " << cgpa << endl;
            // Insert the removed student into the temporary max heap
            tempHeap.insert(rollNo, cgpa);
        }

        // Restore the original array by inserting students back into the original max heap
        while (!tempHeap.isEmpty())
        {
            int rollNo;
            double cgpa;
            // Remove the student with the maximum CGPA from the temporary max heap
            tempHeap.remove(rollNo, cgpa);
            // Insert the removed student back into the original max heap
            insert(rollNo, cgpa);
        }
    }

    void levelOrder()
    {
        // Calculate the height of the heap (h)
        int h = ceil(log2(curSize));

        // Outer loop: iterate over each level of the heap
        for (int level = 0; level <= h; level++)
        {
            // Inner loop: iterate over each element in the current level
            for (int i = 0; i < pow(2, level) && i + pow(2, level) - 1 < curSize; i++)
            {
                // Calculate the index of the current element in the heap
                int index = i + pow(2, level) - 1;

                // Print the CGPA value of the student at the current index
                cout << arr[index].cgpa << " ";
            }

            // Move to the next line after printing all elements in the current level
            cout << endl;
        }
    }
};

// i < pow(2, level)
// This condition ensures that the loop doesn't exceed the number of elements at the current level.
// The expression pow(2, level) calculates the maximum number of elements that can be present at the
// current level.

// i + pow(2, level) - 1 < curSize
// This condition ensures that the loop doesn't access elements beyond the current size of the heap (curSize).
// It prevents accessing elements that may not exist in the last level of the heap.

// i + pow(2, level) - 1
// This part of the expression sums the loop variable i (offset within the current level)
//  with the number of elements in the current level (pow(2, level)), and then subtracts 1.
// The subtraction by 1 is necessary because indexing in the heap typically starts from 0.
// So, by subtracting 1, the expression ensures that the indexing starts from 0 at the leftmost
// element of the current level.

void menu(StudentMaxHeap &maxHeap)
{
    int choice;
    do
    {
        cout << endl;
        cout << "1. Insert a new student" << endl;
        cout << "2. Remove (and display) the student with the Max CGPA" << endl;
        cout << "3. Display the list of students (Descending order of CGPA)" << endl;
        cout << "4. Display the list of students (Level-order traversal)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            int rollNo;
            double cgpa;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            if (maxHeap.insert(rollNo, cgpa))
            {
                cout << "Student inserted successfully!" << endl;
            }
            else
            {
                cout << "Heap is full. Cannot insert more students." << endl;
            }
            break;
        }
        case 2:
        {
            if (!maxHeap.isEmpty())
            {
                int rollNo;
                double cgpa;
                if (maxHeap.remove(rollNo, cgpa))
                {
                    cout << "Student with Max CGPA removed - Roll No: " << rollNo << ", CGPA: " << cgpa << endl;
                }
                else
                {
                    cout << "Error removing student." << endl;
                }
            }
            else
            {
                cout << "Heap is empty. No student to remove." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "List of students (Descending order of CGPA):" << endl;
            maxHeap.displayStudentList();
            break;
        }
        case 4:
        {
            cout << "Heap: Level order traversal:" << endl;
            maxHeap.levelOrder();
            break;
        }
        case 5:
        {
            cout << "Exiting program." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);
}

int main()
{
    system("cls");

    int maxSize;
    cout << "Enter the maximum size of the heap: ";
    cin >> maxSize;
    cout << endl;

    StudentMaxHeap maxHeap(maxSize);
    menu(maxHeap);

    return 0;
}
