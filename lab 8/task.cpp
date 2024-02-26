#include "iostream"
#include "fstream"

using namespace std;

// complete the implementation of eraseObject function
void eraseObject(int **ar, int r, int c, int i, int j)
{
    // r = row , c = columm=n, i  and j are dimensions to find

    // Base Case
    if (i < 0 || i >= r || j <= 0 || j >= c || ar[i][j] == 0)
    {
        return;
        // out of bound
    }
    else
    {
        // Erase the current black pixels (means already 1 hy to 0 kr do  )
        ar[i][j] = 0;

        // Recursive calls
        // Up
        eraseObject(ar, r, c, i - 1, j);
        // Down
        eraseObject(ar, r, c, i + 1, j);
        // Left
        eraseObject(ar, r, c, i, j - 1);
        // Right
        eraseObject(ar, r, c, i, j + 1);
    }
}

int main(void)
{
    system("cls");
    // opening file
    ifstream inf("input.txt");

    if (!inf)
    {
        cout << "Failed to open a file" << endl;
        exit(0);
    }

    int ROWS, COLS, p_x, p_y;

    inf >> ROWS >> COLS; // rading size of image from file
    inf >> p_x >> p_y;   // reading coordinates of the pixel from file

    // array of pointers
    int **ar = new int *[ROWS];

    // each location has COLS size int array
    for (int i = 0; i < ROWS; i++)
    {
        ar[i] = new int[COLS];
    }

    // reading image data from file into ar
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            inf >> ar[i][j];
        }
    }

    // closing file
    inf.close();

    // making call to eraseObject function
    eraseObject(ar, ROWS, COLS, p_x, p_y);

    // displaying image data after processing
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    // freeing all the allocated memory
    for (int i = 0; i < ROWS; i++)
    {
        delete[] ar[i];
    }
    delete[] ar;

    return 0;
}