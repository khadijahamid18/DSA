#include <iostream>
#include <fstream>

using namespace std;

class Student
{
    friend class StudentBST;

private:
    int id;         /**student identifier (unique).*/
    string name;    /**student name.*/
    float fee;      /**student fee.*/
    Student *left;  /**left subtree of a node.*/
    Student *right; /**right subtree of a node.*/

public:
    Student(int id, string name, float fee)
    {
        this->id = id;
        this->name = name;
        this->fee = fee;
        this->left = NULL;
        this->right = NULL;
    }
};
class StudentBST
{
private:
    Student *root; /**root of the tree.*/

    void destroy(Student *stree)
    {
        if (stree != NULL)
        {
            destroy(stree->left);
            destroy(stree->right);
            delete stree;
        }
    }

    void inOrder(Student *stree) // L N R
    {
        if (stree != NULL)
        {
            inOrder(stree->left);
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
            inOrder(stree->right);
        }
    }

    void preOrder(Student *stree) // N L R
    {
        if (stree != NULL)
        {
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
            preOrder(stree->left);
            preOrder(stree->right);
        }
    }

    void postOrder(Student *stree) // L R N
    {
        if (stree != NULL)
        {
            preOrder(stree->left);
            preOrder(stree->right);
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
        }
    }

public:
    StudentBST() /**constructor.*/
    {
        root = NULL;
    }
    ~StudentBST()
    {
        destroy(root); 
    }

    bool insert(int id, string name, float fee)
    {
        Student *newStudent = new Student(id, name, fee);

        if (!root)
        {
            root = newStudent;
            return true;
        }

        Student *current = root;
        Student *parent = NULL;

        while (current)
        {
            parent = current;

            if (id == current->id)
            {
                // Duplicate ID, cannot insert
                delete newStudent;
                return false;
            }
            else if (id < current->id)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (id < parent->id)
        {
            parent->left = newStudent;
        }
        else
        {
            parent->right = newStudent;
        }

        return true;
    }

    bool search(int id)
    {
        Student *current = root;

        while (current)
        {
            if (id == current->id)
            {
                cout << "Student found: ID=" << current->id << ", Name=" << current->name << ", Fee=" << current->fee << endl;
                return true;
            }
            else if (id < current->id)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        cout << "Student with ID " << id << " not found." << endl;
        return false;
    }

    void inOrder()
    {
        inOrder(root);
    }

    void preOrder()
    {
        preOrder(root);
    }

    void postOrder()
    {
        postOrder(root);
    }

    void remove(int id)
    {
        if (root == NULL)
        {
            cout << "Empty Tree" << endl;
            return;
        }

        if (!search(id))
        {
            cout << "No such ID found" << endl;
            return;
        }

        Student *pre = NULL;
        Student *cur = root;

        while (cur->id != id)
        {
            pre = cur;
            if (cur->id > id)
            {
                cur = cur->left;
            }
            else if (cur->id < id)
            {
                cur = cur->right;
            }
        }

        // Degree 2
        if (cur->left != NULL && cur->right != NULL)
        {
            Student *temp = cur;
            pre = cur;
            cur = cur->right;         // get RST(right sub tree)
            while (cur->left != NULL) // find min of RST in left
            {
                pre = cur;
                cur = cur->left;
            }
            temp->id = cur->id;
            temp->name = cur->name;
            temp->fee = cur->fee;
        }

        // Degree 1 with left sub tree
        if (cur->left != NULL && cur->right == NULL)
        {
            if (cur->id > pre->id)
            {
                pre->right = cur->left;
            }
            else if (cur->id < pre->id)
            {
                pre->left = cur->left;
            }
            delete cur;
            return;
        }

        // Degree 1 with right sub tree
        if (cur->left == NULL && cur->right != NULL)
        {
            if (cur->id > pre->id)
            {
                pre->right = cur->right;
            }
            else if (cur->id < pre->id)
            {
                pre->left = cur->right;
            }
            delete cur;
            return;
        }

        // Degree 0
        if (cur->left == NULL && cur->right == NULL)
        {
            if (cur->id > pre->id)
            {
                pre->right = NULL;
            }
            else if (cur->id < pre->id)
            {
                pre->left = NULL;
            }
            delete cur;
            return;
        }
    }
};

int main()
{
    system("cls");

    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cout << "Error opening input file." << endl;
        exit(0);
    }

    StudentBST studentTree;

    int id;
    string name;
    float fee;

    while (inputFile >> id >> name >> fee)
    {
        studentTree.insert(id, name, fee);
    }

    inputFile.close();

    cout << "In-order traversal:" << endl;
    studentTree.inOrder();

    cout << "\nPre-order traversal:" << endl;
    studentTree.preOrder();

    cout << "\nPost-order traversal:" << endl;
    studentTree.postOrder();

    int searchId = 8; // Replace with an actual ID to search for
    cout << "\nSearching for student with ID " << searchId << ":" << endl;
    studentTree.search(searchId);

    int deleteId = 11; // Replace with an actual ID to delete
    cout << "\nDeleting student with ID " << deleteId << ":" << endl;
    studentTree.remove(deleteId);

    cout << "\nIn-order traversal after deletion:" << endl;
    studentTree.inOrder();

    return 0;
}