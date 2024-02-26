#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book
{
    friend class BookList;

private:
    int id;
    string title;
    float price;
    Book *next;
    Book *pre;

public:
    Book(int id, string title, float price, Book *next, Book *pre)
        : id(id), title(title), price(price), next(next), pre(pre) {}

    void bookDetails()
    {
        cout << "ID: " << id << "\nTitle: " << title << "\nPrice: " << price << endl;
    }
};

class BookList
{
private:
    Book *head;
    Book *cursor;
    Book *last;

public:
    BookList() : head(NULL) , cursor(NULL) , last(NULL)  {}

    ~BookList()
    {
        while (head != NULL) 
        {
            Book *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const Book &newItem)
    {
        Book *newBook = new Book(newItem.id, newItem.title, newItem.price, NULL,  NULL) ;

        if (isEmpty())
        {
            head = newBook;
            cursor = newBook;
            last = newBook;
        }
        else
        {
            newBook->pre = cursor;
            newBook->next = cursor->next;

            if (cursor->next != NULL) 
            {
                cursor->next->pre = newBook;
            }
            else
            {
                last = newBook;
            }

            cursor->next = newBook;
            cursor = newBook;
        }
    }

    void remove()
    {
        if (!isEmpty())
        {
            Book *temp = cursor;

            if (cursor->pre != NULL) // not at head
            {
                cursor->pre->next = cursor->next; // before cursor element = after cursor element
            }
            else // at head
            {
                head = cursor->next; 
            }

            if (cursor->next != NULL) // not at last 
            {
                cursor->next->pre = cursor->pre;
            }
            else // at last
            {
                last = cursor->pre;
            }

            cursor = cursor->pre;
            delete temp;
        }
    }

    void search(string title)
    {
        Book *current = head;
        bool found = false;

        while (current != NULL) 
        {
            if (current->title == title)
            {
                current->bookDetails();
                found = true;
            }

            current = current->next;
        }

        if (!found)
        {
            cout << "Book not found." << endl;
        }
    }

    void replace(const Book &newItem)
    {
        if (!isEmpty() && cursor != NULL) 
        {
            cursor->id = newItem.id;
            cursor->title = newItem.title;
            cursor->price = newItem.price;
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
        cursor = last;
    }

    bool gotoNext()
    {
        if (cursor != NULL  && cursor->next != NULL) 
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        if (cursor != NULL  && cursor->pre != NULL) 
        {
            cursor = cursor->pre;
            return true;
        }
        return false;
    }

    Book getCursor()
    {
        if (cursor != NULL) 
        {
            return *cursor;
        }
        throw runtime_error("Cursor is not pointing to a valid book.");
    }

    void showStructureForward() const
    {
        Book *current = head;

        while (current != NULL) 
        {
            current->bookDetails();
            current = current->next;
        }

        if (isEmpty())
        {
            cout << "Empty list" << endl;
        }
    }

    void showStructureReverse() const
    {
        Book *current = last;

        while (current != NULL) 
        {
            current->bookDetails();
            current = current->pre;
        }

        if (isEmpty())
        {
            cout << "Empty list" << endl;
        }
    }
};

int main()
{
    system("cls");

    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    BookList bookList;
    int id;
    string title;
    float price;

    while (inputFile >> id)
    {
        inputFile.ignore(); // Ignore the newline character
        getline(inputFile, title);
        inputFile >> price;
        inputFile.ignore(); // Ignore the blank line

        Book newBook(id, title, price, NULL,  NULL) ;
        bookList.insert(newBook);
    }

    // Test the functionality of BookList class
    bookList.showStructureForward();

    inputFile.close();
    return 0;
}