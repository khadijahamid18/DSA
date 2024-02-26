#include <iostream>
using namespace std;
float celcius(float far)
{
    float result = (5.0 / 9.0) * (far - 32);
    return result;
}
int main()
{
    system("cls");
    float cel, far;
    float res;
    cout << "*********************************" << endl;
    cout << " Farenhite                Celcius" << endl;
    cout << "**********************************" << endl;
    for (int i = 0; i <= 20; i++)
    {
        res = celcius(i);
        cout << i << "                      ";
        cout << res  << endl;
    }

    return 0;
}