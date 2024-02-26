#include "iostream"

using namespace std;

class Student
{
    friend class StudentMaxHeap;

private:
    double cgpa;
    int rollNo;

public:
    Student(int rollNo, double cgpa) : rollNo(rollNo), cgpa(cgpa) {}
    Student() {}
};

class StudentMaxHeap
{
private:
    Student *arr;

    int curSize;
    int maxSize;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

public:
    // /*Constructor/
    StudentMaxHeap(int size) : curSize(0), maxSize(size)
    {
        arr = new Student[maxSize];
    }

    // /*Destructor/
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

        int i = curSize;
        arr[i] = Student(rollNo, cgpa);
        curSize++;

        while (i > 0 && (arr[parent(i)].cgpa < arr[i].cgpa || (arr[parent(i)].cgpa == arr[i].cgpa && arr[parent(i)].rollNo > arr[i].rollNo)))
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }

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

        int i = 0;
        while (true)
        {
            int maxIndex = i;
            int l = left(i);
            int r = right(i);

            if (l < curSize && (arr[l].cgpa > arr[maxIndex].cgpa || (arr[l].cgpa == arr[maxIndex].cgpa && arr[l].rollNo < arr[maxIndex].rollNo)))
            {
                maxIndex = l;
            }

            if (r < curSize && (arr[r].cgpa > arr[maxIndex].cgpa || (arr[r].cgpa == arr[maxIndex].cgpa && arr[r].rollNo < arr[maxIndex].rollNo)))
            {
                maxIndex = r;
            }

            if (i != maxIndex)
            {
                swap(arr[i], arr[maxIndex]);
                i = maxIndex;
            }
            else
            {
                break;
            }
        }

        return true;
    }

    void displayStudentList()
    {
        for (int i = 0; i < curSize; i++)
        {
            cout << "Roll No: " << arr[i].rollNo << ", CGPA: " << arr[i].cgpa << endl;
        }
    }

    void levelOrder()
    {
        // Calculate the height of the binary heap
        int h = 0;
        int temp = curSize;
        while (temp >>= 1)
        {
            ++h;
        }

        // Calculate the maximum number of spaces needed based on the height of the binary heap
        int maxSpaces = (1 << (h + 1));

        // Loop through each element in the binary heap
        for (int i = 0; i < curSize; i++)
        {
            // Calculate the number of spaces before the current element
            int spaces = maxSpaces >> (i + 1);
            for (int j = 0; j < spaces; j++)
            {
                // Print spaces before the current element
                cout << " ";
            }

            // Print the value of the current element (assuming arr is a struct or class with a member cgpa)
            cout << arr[i].cgpa;

            // Check if the next element in the binary heap is at a new level
            if (i + 1 < curSize && ((i + 2) & (i + 1)) == 0)
            {
                // If at a new level, move to the next line
                cout << endl;
            }
        }

        // Print a newline character at the end to separate the output from the rest of the program
        cout << endl;
    }
};

void menu()
{
    StudentMaxHeap maxHeap(10); // assuming a maximum capacity of 10 students

    while (true)
    {
        cout << "1. Insert a new student\n"
                "2. Remove (and display) the student with the Max CGPA\n"
                "3. Display the list of students (Descending order of CGPA)\n"
                "4. Display the list of students (Level-order traversal)\n"
                "5. Exit\n"
                "Enter your choice: ";

        int choice;
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
                cout << "Student inserted successfully!\n";
            }
            else
            {
                cout << "Heap is full. Student insertion failed.\n";
            }
            break;
        }
        case 2:
        {
            int rollNo;
            double cgpa;

            if (maxHeap.remove(rollNo, cgpa))
            {
                cout << "Removed student: Roll No: " << rollNo << ", CGPA: " << cgpa << std::endl;
            }
            else
            {
                cout << "Heap is empty. No student to remove.\n";
            }
            break;
        }
        case 3:
            cout << "List of students (Descending order of CGPA):\n";
            maxHeap.displayStudentList();
            break;
        case 4:
            cout << "Level order traversal:\n";
            maxHeap.levelOrder();
            break;
        case 5:
            cout << "Exiting...\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main()
{
    system("cls");
    menu();
    return 0;
}
