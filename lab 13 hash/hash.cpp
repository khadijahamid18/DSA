#include <iostream>
#include <string>

using namespace std;

class HashTable
{
private:
    string *table; // Dynamic array of strings to hold names
    int size;      // Total number of slots in the table
    int curSize;   // Current number of elements present in the table

    // Hash function to calculate the sum of ASCII values of characters in a string
    int value(string name)
    {
        int temp = 0;
        for (int i = 0; i < name.length(); i++)
        {
            temp = temp + name[i];
        }
        return temp;
    }

public:
    HashTable(int size)
    { // Constructor
        this->size = size;
        table = new string[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = "EMPTY";
        }
        curSize = 0;
    }

    ~HashTable()
    { // Destructor
        delete[] table;
    }

    bool isEmpty()
    { // Checks whether the hash table is empty or not
        return curSize == 0;
    }

    bool isFull()
    { // Checks whether the hash table is full or not
        return curSize == size;
    }

    double loadFactor()
    { // Calculates and returns the load factor of the hash table (curSize/size)
        return static_cast<double>(curSize) / size;
    }

    bool insert(string name)
    { // Inserts a name into the hash table
        if (isFull())
        {
            return false; // Hash table is full
        }

        int index = value(name) % size;

        while (table[index] != "EMPTY")
        {
            index = (index + 1) % size; // Linear probing
        }

        table[index] = name;
        curSize++;
        return true;
    }

    bool search(string name)
    { // Searches for a name in the hash table
        int index = value(name) % size;

        while (table[index] != "EMPTY")
        {
            if (table[index] == name)
            {
                return true; // Name found
            }
            index = (index + 1) % size; // Linear probing
        }

        return false; // Name not found
    }

    bool remove(string name)
    { // Removes a name from the hash table
        if (isEmpty())
        {
            return false; // Hash table is empty
        }

        int index = value(name) % size;

        while (table[index] != "EMPTY")
        {
            if (table[index] == name)
            {
                table[index] = "EMPTY";
                curSize--;
                return true; // Name found and removed
            }
            index = (index + 1) % size; // Linear probing
        }

        return false; // Name not found
    }

    void display()
    { // Displays the contents of the hash table
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";
            if (table[i] == "EMPTY")
            {
                cout << "EMPTY";
            }
            else
            {
                cout << table[i];
            }
            cout << endl;
        }
    }

    // Menu-based driver function
    void menu()
    {
        int choice;
        string name;

        do
        {
            cout << endl;
            cout << "1. Insert a name" << endl;
            cout << "2. Search for a name" << endl;
            cout << "3. Remove a name" << endl;
            cout << "4. Display the table" << endl;
            cout << "5. Display the load factor of the table" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 1:
                cout << "Enter the name to insert: ";
                cin >> name;
                if (insert(name))
                {
                    cout << "Name inserted successfully." << endl;
                }
                else
                {
                    cout << "Hash table is full. Unable to insert." << endl;
                }
                break;

            case 2:
                cout << "Enter the name to search: ";
                cin >> name;
                if (search(name))
                {
                    cout << "Name found in the hash table." << endl;
                }
                else
                {
                    cout << "Name not found in the hash table." << endl;
                }
                break;

            case 3:
                cout << "Enter the name to remove: ";
                cin >> name;
                if (remove(name))
                {
                    cout << "Name removed successfully." << endl;
                }
                else
                {
                    cout << "Name not found in the hash table. Unable to remove." << endl;
                }
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Load factor of the table: " << loadFactor() << endl;
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
        } while (choice != 6);
    }
};

int main()
{
    system("cls");

    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    HashTable hashTable(size);
    hashTable.menu();

    return 0;
}
