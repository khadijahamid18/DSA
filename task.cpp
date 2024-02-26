#include <iostream>
using namespace std;

struct Point3D
{
    float x, y, z;
};

class PointList
{
    Point3D *arr;
    int maxSize;
    int curSize;
    int cursor;

public:
    PointList(int maxSize)
    {
        this->maxSize = maxSize;
        this->curSize = 0;
        this->cursor = -1;

        this->arr = new Point3D[maxSize];

        for (int i = 0; i < maxSize; i++)
        {
            this->arr[i].x = 0;
            this->arr[i].y = 0;
            this->arr[i].z = 0;
        }
    }

    ~PointList()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (curSize == 0)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (cursor == maxSize)
        {
            return true;
        }
        return false;
    }

    void insert(Point3D newPoint)
    {
        if (!isFull())
        {
            cursor = curSize;

            arr[curSize].x = newPoint.x;
            arr[curSize].y = newPoint.y;
            arr[curSize].z = newPoint.z;
            curSize++;
        }
        else
        {
            cout << "List is Full";
        }
    }

    void showSturcture()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < curSize; i++)
            {
                cout << "arr " << i << ": (" << arr[i].x << ", " << arr[i].y << ", " << arr[i].z << ")" << endl;
            }
        }
    }

    Point3D getCursor()
    {
        if (!isEmpty())
        {
            return arr[cursor];
        }
        else
        {
            cout << "Error, because list is empty" << endl;
            return Point3D{-1, -1, -1};
        }
    }

    void gotoBeginning()
    {
        if (!isEmpty())
        {
            cursor = 0;
        }
    }

    void gotoEnd()
    {
        if (!isEmpty())
        {
            cursor = curSize;
        }
    }

    bool gotoNext()
    {
        if (!isEmpty() && cursor < curSize - 1)
        {
            cursor++;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        if (!isEmpty() && cursor != 0)
        {
            cursor--;
            return true;
        }
        return false;
    }

    void clear()
    {
        curSize = 0;
        cursor = -1;

        for (int i = 0; i < maxSize; i++)
        {
            arr[i].x = 0;
            arr[i].y = 0;
            arr[i].z = 0;
        }
    }

    bool replace(Point3D newPoint)
    {
        if (!isEmpty())
        {
            arr[cursor].x = newPoint.x;
            arr[cursor].y = newPoint.y;
            arr[cursor].z = newPoint.z;
            return true;
        }
        return false;
    }

    void remove()
    {
        if (!isEmpty())
        {
            arr[cursor].x = arr[curSize].x;
            arr[cursor].y = arr[curSize].y;
            arr[cursor].z = arr[curSize].z;

            arr[curSize].x = 0;
            arr[curSize].y = 0;
            arr[curSize].z = 0;

            curSize--;

            if (!isEmpty())
            {
                if (cursor + 1 == curSize)
                {
                    cursor = 0;
                }
            }
        }
    }
};

int main()
{
    system("cls");
    PointList p1(5);
    cout << p1.isEmpty() << endl;
    cout << p1.isFull() << endl;

    p1.showSturcture();

    p1.gotoBeginning();

    struct Point3D newPoint1;
    newPoint1.x = 1.1;
    newPoint1.y = 2.2;
    newPoint1.z = 3.3;

    p1.insert(newPoint1);

    struct Point3D newPoint2;
    newPoint2.x = 4.1;
    newPoint2.y = 5.2;
    newPoint2.z = 6.3;

    p1.insert(newPoint2);

    struct Point3D newPoint3;
    newPoint3.x = 7.2;
    newPoint3.y = 8.3;
    newPoint3.z = 9.1;

    p1.insert(newPoint3);

    p1.showSturcture();

    p1.remove();

    p1.showSturcture();

    return 0;
}
