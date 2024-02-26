#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    friend class StudentList;

private:
    int id;
    string name;
    float cgpa;
    Student *next;

public:
    Student(int id, const string &name, float cgpa, Student *next);
    void studentDetails() const;
};

class StudentList
{
private:
    Student *head;
    Student *cursor;

public:
    StudentList();
    ~StudentList();

    void insert(const Student &newStd);
    void remove(int id);
    void search(float cgpa) const;
    void replace(const Student &newStd);
    bool isEmpty() const;
    void gotoBeginning();
    void gotoEnd();
    bool gotoNext();
    bool gotoPrior();
    Student getCursor();
    void showStructure() const;
};

// Implementation of Student class
Student::Student(int id, const string &name, float cgpa, Student *next)
    : id(id), name(name), cgpa(cgpa), next(next) {}

void Student::studentDetails() const
{
    cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
}

// Implementation of StudentList class
StudentList::StudentList() : head(nullptr), cursor(nullptr) {}

StudentList::~StudentList()
{
    while (head != nullptr)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
    }
}

void StudentList::insert(const Student &newStd)
{
    Student *newNode = new Student(newStd.id, newStd.name, newStd.cgpa, nullptr);

    if (isEmpty())
    {
        head = newNode;
    }
    else
    {
        newNode->next = cursor->next;
        cursor->next = newNode;
    }

    cursor = newNode;
}

void StudentList::remove(int id)
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
        return;
    }

    Student *current = head;
    Student *previous = nullptr;

    while (current != nullptr && current->id != id)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }

    if (cursor == current)
    {
        if (current->next != nullptr)
        {
            cursor = current->next;
        }
        else
        {
            cursor = head;
        }
    }

    if (previous == nullptr)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;
}

void StudentList::search(float cgpa) const
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
        return;
    }

    Student *current = head;
    bool found = false;

    while (current != nullptr)
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

void StudentList::replace(const Student &newStd)
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
        return;
    }

    Student *current = head;
    bool found = false;

    while (current != nullptr)
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

bool StudentList::isEmpty() const
{
    return head == nullptr;
}

void StudentList::gotoBeginning()
{
    cursor = head;
}

void StudentList::gotoEnd()
{
    if (isEmpty())
    {
        cursor = nullptr;
        return;
    }

    while (cursor->next != nullptr)
    {
        cursor = cursor->next;
    }
}

bool StudentList::gotoNext()
{
    if (cursor != nullptr && cursor->next != nullptr)
    {
        cursor = cursor->next;
        return true;
    }
    return false;
}

bool StudentList::gotoPrior()
{
    if (isEmpty() || cursor == head)
    {
        return false;
    }

    Student *current = head;
    Student *previous = nullptr;

    while (current != cursor)
    {
        previous = current;
        current = current->next;
    }

    cursor = previous;
    return true;
}

Student StudentList::getCursor()
{
    if (cursor != nullptr)
    {
        return *cursor;
    }
    else
    {
        // You may want to handle this differently based on your requirements.
        // Returning a default-constructed Student object for simplicity.
        return Student(0, "", 0.0, nullptr);
    }
}

void StudentList::showStructure() const
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
        return;
    }

    Student *current = head;

    while (current != nullptr)
    {
        current->studentDetails();
        current = current->next;
    }
}

int main()
{
    // Open the input file
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    StudentList studentList;

    int id;
    string name;
    float cgpa;

    while (inputFile >> id)
    {
        inputFile.ignore();            // Ignore the semicolon
        getline(inputFile, name); // Read the name
        inputFile >> cgpa;             // Read the cgpa

        Student newStudent(id, name, cgpa, nullptr);
        studentList.insert(newStudent);

        inputFile.ignore(); // Ignore the blank line
    }

    inputFile.close();

    // Example usage of StudentList functions
    studentList.showStructure();
    studentList.search(3.5);
    studentList.remove(2);
    studentList.showStructure();
    studentList.gotoNext();
    studentList.replace(Student(4, "John Doe", 3.8, nullptr));
    studentList.showStructure();

    return 0;
}