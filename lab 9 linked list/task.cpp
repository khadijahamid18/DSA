#include <iostream>
using namespace std;

class Student
{
    friend class StudentList;

private:
    int id;        /**id of a student*/
    string name;   /**name of a student*/
    float cgpa;    /**cgpa of a student*/
    Student *next; /**address of the next available object*/

public:
    Student(int id, string name, float cgpa, Student *next) /**constructor*/
    {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
        this->next = next;
    }

    void studentDetails() const /**displays the student informaton*/
    {
        cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
    }
};

class StudentList
{
private:
    Student *head;   /**start of the list*/
    Student *cursor; /**current item of the list*/

public:
    StudentList() /**constructor*/
    {
        head = NULL;
        cursor = NULL;
    }

    ~StudentList() /**destructor*/
    {
        Student *temp = head;

        while (temp != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void insert(const Student &newStd)
    {
        Student *newNode = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);

        // Empty case
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
        // Moving cursor to newNode
        cursor = newNode;
    }

    void remove(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Student *current = head;
        Student *previous = NULL;

        // At least 1 node is present
        // Iterates untill id is found or end is reached
        while (current != NULL || current->id != id)
        {
            previous = current;
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        }

        // Updating cursor if it is is pointing to the node being removed
        if (cursor == current)
        {
            if (current->next != NULL)
            {
                cursor = current->next;
            }
            else
            {
                cursor = head;
            }
        }
        // remove the node
        if (previous == NULL)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
    }

    void search(float cgpa) const
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
        }

        Student *current = head;
        bool found = false;

        // Iterations over the list till end
        while (current != NULL)
        {
            if (current->cgpa == cgpa)
            {
                current->studentDetails();
                found = true;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "No student found with CGPA " << cgpa << endl;
        }
    }

    void replace(const Student &newStd)
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
        }

        Student *current = head;
        bool found = false;

        while (current != NULL)
        {
            if (current->id == newStd.id)
            {
                current->name = newStd.name;
                current->cgpa = newStd.cgpa;
                found = true;
                cursor = current;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            insert(newStd); // If not found, add the new student at the end
        }
    }

    bool isEmpty() const
    {
        return head == NULL;
    }

    void gotoBeginning()
    {
        cursor = head;
    }

    void gotoEnd()
    {
        if (!head)
        {
            cursor = NULL;
            return;
        }

        while (cursor->next != NULL)
        {
            cursor = cursor->next;
        }
    }

    bool gotoNext()
    {
        if (cursor != NULL && cursor->next != NULL)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        if (head == NULL || cursor == head)
        {
            return false;
        }

        Student *current = head;
        Student *previous = NULL;

        while (current != cursor)
        {
            previous = current;
            current = current->next;
        }

        cursor = previous;
        return true;
    }

    Student getCursor()
    {
        if (cursor != NULL)
        {
            return *cursor;
        }
        else
        {
            return Student(0, "", 0.0, NULL);
        }
    }

    void showStructure() const
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
        }

        Student *current = head;

        while (current != NULL) 
        {
            current->studentDetails();
            current = current->next;
        }
    }
};

int main()
{
    system("cls");

    // ifstream inputFile("input.txt");

    // if (!inputFile.is_open())
    // {
    //     cerr << "Error opening input.txt" << endl;
    //     exit(0);
    // }

    return 0;
}