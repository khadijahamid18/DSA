#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    friend class StudentList;

private:
    int id;        /**id of a student*/
    string name;   /**name of a student*/
    float cpga;    /**cgpa of a student*/
    Student *next; /**address of the next available object*/
public:
    Student(int id, string name, float cgpa, Student *next) /**constructor*/
    {
        this->id = id;
        this->name = name;
        this->cpga = cgpa;
        this->next = next;
    }

    void studentDetails() const /**displays the student informaton*/
    {
        cout << "ID: " << id << "Name: " << name << "Cgpa: " << cpga << endl;
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
    }

    ~StudentList() /**destructor*/
    {
        Student *cur = head;
        while (head)
        {
            head = head->next;
            delete cur;
            cur = head;
        }
    }

    void insert(const Student &newStd)
    {
        Student *newNode = new Student(newStd);

        if (head == NULL)
        {
            head = newNode;
            cursor = newNode;
        }
        else
        {
            cursor->next = newNode;
            cursor = newNode;
        }
    }

    void remove(int id)
    {
        // If list is empty
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        // Traversing the list
        Student *cur = head;
        Student *pre = NULL;

        while (cur != NULL && cur->id != id)
        {
            pre = cur;
            cur = cur->next;
        }

        // if id not found
        if (cur == NULL)
        {
            cout << "Given id not found" << endl;
        }

        if (cursor == cur)
        {
            // if cursor is not at last than move the cursor
            if (cursor->next != NULL)
            {
                pre = NULL;
            }
            else
            {
                cursor = head;
            }
        }

        // if id is present at first node
        if (pre == NULL)
        {
            head = head->next;
        }

        // if id is present in somewhere between
        else
        {
            pre->next = cur->next;
        }

        delete cur;
    }

    void search(float cgpa) const
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        // Traversing the list until the list is not empty and the cgpa does not found
        Student *cur = head;
        while (cur != NULL && cur->cpga != cgpa)
        {
            cur = cur->next;
        }

        if (cur != NULL)
        {
            cur->studentDetails();
        }
        else
        {
            cout << "Given cgpa is not found" << endl;
        }
    }

    void replace(const Student &newStd)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Student *newNode = new Student(newStd);

        Student *cur = head;
        Student *pre = NULL;

        // Traversing the list
        while (cur != NULL && cur->id != newStd.id)
        {
            pre = cur;
            cur = cur->next;
        }

        if (cur != NULL)
        {
            if (cur->id == newStd.id)
            {
                cur->id = newStd.id;
                cur->name = newStd.name;
                cur->cpga = newStd.cpga;

                cursor = cur;
            }
            else
            {
                cur->next = newNode;
                // insert(newStd);
            }
        }
    }

    bool isEmpty() const
    {
        if (!head)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void gotoBeginning()
    {
        cursor = head;
    }

    void gotoEnd()
    {
        if (head == NULL)
        {
            head = cursor;
        }
        else
        {
            // Traverse the list till the last
            Student *cur = head;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            cur = cursor;
        }
    }

    bool gotoNext()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Student *cur = head;
        while (cur->next != NULL)
        {
            if (cursor->next != NULL)
            {
                cursor = cur->next;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    bool gotoPrior()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Student *cur = head;
        Student *pre = NULL;

        while (cursor != cur)
        {
            pre = cur;
            cur = cur->next;
            return true;
        }

        cursor = pre;
        return false;
    }

    Student getCursor()
    {
        if (cursor != NULL)
        {
            // iski samaj ni ai copy of cursor ka kya matlb hy?
            return *cursor;
        }
        else
        {
            cout << "Cursor not found" << endl;
        }
    }

    void showStructure() const
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Student *cur = head;
        while (cur != NULL)
        {
            cur->studentDetails();
            cur = cur->next;
        }
    }
};

int main()
{
    system("cls");

    StudentList obj;

    ifstream inputFile("input.txt");

    if (!inputFile)
    {
        cerr << "Error opening the file" << endl;
        exit(0);
    }

    int id;
    string name;
    float cgpa;

    while (inputFile >> id)
    {
        getline(inputFile, name);
        inputFile >> cgpa;

        Student newStudent(id, name, cgpa, NULL);
        obj.insert(newStudent);
    }

    obj.showStructure();

    return 0;
}