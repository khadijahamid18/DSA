#include <iostream>
using namespace std;
void getMinMax(int *ptrArray, int size, int *ptrMin, int *ptrMax)
{
    *ptrMax = *(ptrArray + 0);
    for (int i = 1; i < size; i++)
    {
        if (*(ptrArray + i) > *ptrMax)
        {
            *ptrMax = *(ptrArray + i);
        }
    }
    
    *ptrMin = *(ptrArray + 0);
    for (int i = 1; i < size; i++) 
    {
        if (*(ptrArray + i) < *ptrMin)
        {
            *ptrMin = *(ptrArray + i);
        }
    }
}
int main()
{
    system("cls");
    int arr[10] = {11, 13, 11, 54, 14, 10, 35, 9, 12, 18};
    int min = 0, max = 0;

    getMinMax(arr, 10, &min, &max);

    cout << "The maximum number is: " << max << endl;
    cout << "The minimum number is: " << min << endl;

    return 0;
}