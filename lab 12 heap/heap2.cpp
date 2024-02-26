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

    void heapify(int index, bool isInsertion)
    {
        int parent;

        if (isInsertion)
        {
            while (index > 0)
            {
                parent = (index - 1) / 2;
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
        else
        {
            int leftChild, rightChild, largest;

            while (true)
            {
                leftChild = 2 * index + 1;
                rightChild = 2 * index + 2;
                largest = index;

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
                    index = largest;
                }
                else
                {
                    break;
                }
            }
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
        heapify(curSize, true);
        curSize++;

        return true;
    }

    bool remove(int &rollNo, double &cgpa)
    {
        if (isEmpty())
        {
            return false;
        }

        rollNo = arr[0].rollNo;
        cgpa = arr[0].cgpa;

        arr[0] = arr[curSize - 1];
        curSize--;

        heapify(0, false);

        return true;
    }

    void displayStudentList()
    {
        StudentMaxHeap tempHeap(maxSize);

        while (!isEmpty())
        {
            int rollNo;
            double cgpa;
            remove(rollNo, cgpa);
            cout << "Roll No: " << rollNo << ", CGPA: " << cgpa << endl;
            tempHeap.insert(rollNo, cgpa);
        }

        while (!tempHeap.isEmpty())
        {
            int rollNo;
            double cgpa;
            tempHeap.remove(rollNo, cgpa);
            insert(rollNo, cgpa);
        }
    }

    void levelOrder()
    {
        int h = ceil(log2(curSize));
        for (int level = 0; level <= h; level++)
        {
            for (int i = 0; i < pow(2, level) && i + pow(2, level) - 1 < curSize; i++)
            {
                int index = i + pow(2, level) - 1;
                cout << arr[index].cgpa << " ";
            }
            cout << endl;
        }
    }
};

void menu(StudentMaxHeap &maxHeap)
{
    int choice;
    do
    {
        cout << "1. Insert a new student" << endl;
        cout << "2. Remove (and display) the student with the Max CGPA" << endl;
        cout << "3. Display the list of students (Descending order of CGPA)" << endl;
        cout << "4. Display the list of students (Level-order traversal)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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

    StudentMaxHeap maxHeap(maxSize);
    menu(maxHeap);

    return 0;
}
