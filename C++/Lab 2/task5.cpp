#include <iostream>
#include <string>
using namespace std;
int main()
{
    system("cls");
    string str;
    int upper, lower, digit;
    upper = lower = digit = 0;
    cout << "The password should meet the following criteria: " << endl;
    cout << "The password should be at least six characters long." << endl;
    cout << "The password should contain at least one uppercase and at least one lowercase letter." << endl;
    cout << "The password should have at least one digit." << endl;

    do
    {
        cout << "Please enter your password: ";
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (isupper(str[i]))
            {
                upper++;
            }
            if (islower(str[i]))
            {
                lower++;
            }
            if (isdigit(str[i]))
            {
                digit++;
            }
        }
        if (upper == 0)
        {
            cout << "Password should contain at least one upper character!" << endl;
        }
        if (lower == 0)
        {
            cout << "Password should contain at least one lower character!" << endl;
        }
        if (digit == 0)
        {
            cout << "Password should contain at least one digit!" << endl;
        }
        if (str.length() < 6)
        {
            cout << "Your password should be at least 6 characters long!" << endl;
        }

    } while (upper == 0 || lower == 0 || digit == 0 || str.length() < 6);

    cout << "Your password is verified!" << endl << str << endl;

    return 0;
}