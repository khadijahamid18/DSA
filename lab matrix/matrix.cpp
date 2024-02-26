#include <iostream>
using namespace std;

class Matrix
{
private:
    int *array;
    int rows;
    int coloumns;

public:
    Matrix(int rows, int coloumns)
    {
        this->rows = rows;
        this->coloumns = coloumns;
        this->array = new int[rows * coloumns];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < coloumns; j++)
            {
                array[i * coloumns + j] = 0;
            }
        }
    }

    ~Matrix()
    {
        delete[] array;
    }

    int get(int i, int j)
    {
        if ((i >= 0 && i < rows) && (j >= 0 && j < coloumns))
        {
            return array[i * coloumns + j];
        }
        else
        {
            cout << "Error: Indexes are out of bound" << endl;
        }
    }

    void set(int i, int j, int v)
    {
        if ((i >= 0 && i < rows) && (j >= 0 && j < coloumns))
        {
            array[i * coloumns + j] = v;
        }
        else
        {
            cout << "Error: Indexes are out of bound" << endl;
        }
    }

    void print()
    {
        cout << "**********MATRIX**********" << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << "| ";
            for (int j = 0; j < coloumns; j++)
            {
                cout << array[i * coloumns + j] << " ";
            }
            cout << " |" << endl;
        }
    }

    void transpose()
    {
        int *transpose;
        int r = coloumns;
        int c = rows;
        transpose = new int[rows * coloumns];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < coloumns; j++)
            {
                transpose[j * rows + i] = array[i * coloumns + j];
            }
        }
        rows = r;  // swaping the values
        coloumns = c;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                array[i * c + j] = transpose[i * c + j];
            }
        }
    }

    void printSubMatrix(int r1, int r2, int c1, int c2)
    {
        if ((r1 >= 0 && r2 < rows) && (c1 >= 0 && c2 < coloumns))
        {
            for (int i = r1; i <= r2; i++)
            {
                cout << "| ";
                for (int j = c1; j <= c2; j++)
                    cout << array[(i * coloumns + j)] << "  ";
                cout << "|" << endl;
            }
        }
    }

    void makeEmpty(int n)
    {
        if (n >= 0 && n <= rows)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < coloumns; j++)
                {
                    array[i * coloumns + j] = 0;
                }
            }
        }
        else
        {
            cout << "This number's rows does not exists in a matrix!" << endl;
        }
    }

    void add(Matrix first, Matrix second)
    {
        if ((first.rows == second.rows) && (first.coloumns == second.coloumns))
        {
            this->rows = first.rows;
            this->coloumns = first.coloumns;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < coloumns; j++)
                {
                    this->array[i * coloumns + j] = first.array[i * coloumns + j] + second.array[i * coloumns + j];
                }
            }
        }

        else
        {
            cout << "ERROR: Sizes of 'First' and 'Second' Matrices are not equal!" << endl;  
        }
    }
};

int main()
{
    system("cls");

    Matrix arr1(3, 3);
    Matrix arr2(3, 3);
    Matrix arr3(3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr1.set(i, j, i * 3 + j);
            arr2.set(i, j, (i * 3 + j) * 2);
            arr3.set(i, j, (i * 3 + j) * 3);
        }
    }

    cout << "Matrix 1: " << endl;
    arr1.print();
    cout << endl;

    cout << "Matrix 2: " << endl;
    arr2.print();
    cout << endl;

    cout << "Matrix 3: " << endl;
    arr3.print(); 
    cout << endl;

    // arr1.set(0, 0, 2);
    // arr1.set(1, 0, 2);
    // arr1.set(2, 3, 2);

    // arr1.print();

    cout << "*****TRANSPOSE*****" << endl;
    arr1.transpose();
    arr1.print();

    cout << "*****Sub Matrix*****" << endl;
    arr1.printSubMatrix(0, 1, 1, 2);
    cout << endl;

    cout << "*****Making the Matrix Empty*****" << endl;
    arr1.makeEmpty(3);
    arr1.print();

    cout << "*****Making the Matrix Empty*****" << endl;
    arr1.add(arr2, arr3);
    arr1.print();

    return 0;
}