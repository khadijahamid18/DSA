#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book
{
    friend class BookList;

private:
    int id;       /**id of a book.*/
    string title; /**name of a book.*/
    float price;  /**price of a book.*/
    Book *next;   /**address of the next available object.*/
    Book *pre;    /**address of the previous available object.*/

public:
    Book(int id, string title, float price, Book *next, Book *pre) /**constructor*/
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->next = next;
        this->pre = pre;
    }

    void bookDetails() /**displays the book informaton*/
    {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }
};

class BookList
{
private:
    Book *head;   /**first item of the list*/
    Book *cursor; /**current item of the list*/
    Book *last;   /**last item of the list*/

public:
    BookList() /**constructor*/
    {
        head = NULL;
        cursor = NULL;
        last = NULL;
    }

    ~BookList() /**destructor*/
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
        Book *newBook = new Book(newItem.id, newItem.title, newItem.price, newItem.pre, newItem.next);

        if (head == NULL)
        {
            head = newBook;
            cursor = newBook;
            last = newBook;
        }
        else
        {

            // if it is not last node
            if (cursor->next != NULL)
            {
                cursor->next->pre = newBook;
            }
            else
            {
                last = newBook; // at last
            }

            newBook->next = cursor->next;
            newBook->pre = cursor;
            cursor->next = newBook;
            cursor = newBook;
        }
    }

    void remove() // removing last
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

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
        Book *newBook = new Book(newItem.id, newItem.title, newItem.price, newItem.pre, newItem.next);

        if (head != NULL && cursor != NULL)
        {
            cursor->id = newItem.id;
            cursor->title = newItem.title;
            cursor->price = newItem.price;
        }
        cursor = newBook;
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
        if (cursor != NULL && cursor->next != NULL)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        if (cursor != NULL && cursor->pre != NULL)
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
        else
        {
            cout << "No cursor found" << endl;
        }
    }

    void showStructureForward() const
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Book *cur = head;
        while (cur != NULL)
        {
            cur->bookDetails();
            cur = cur->next;
        }
    }

    void showStructureReverse() const
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        Book *cur = last;
        while (cur != NULL)
        {
            cur->bookDetails();
            cur = cur->pre;
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
        exit(0);
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

        Book newBOOk(id, title, price, NULL, NULL);
        bookList.insert(newBOOk);
    }

    Book newBook(13, "computer", 500.00, NULL, NULL);
    bookList.insert(newBook);

    bookList.remove();

    bookList.replace(newBook);

    // Test the functionality of BookList class
    bookList.showStructureForward();

    bookList.search("Visual C");

    // bookList.showStructureReverse();

    inputFile.close();

    return 0;
}