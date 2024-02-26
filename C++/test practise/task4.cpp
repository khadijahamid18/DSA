#include <iostream>
#include <string>

using namespace std;

int main()
{
    system("cls");
    double num;
    string mystr;

    cout << "Please enter a number: " << "\n";
    cin >> num;
    cout << "Your number is: " << num << "\n";
    cin.ignore(256, '\n'); // Why do I need this line?
    cout << "Please enter your name: \n";
    getline (cin, mystr);
    cout << "So your name is " << mystr << "?\n";
    cout << "Have a nice day. \n";

    return 0;

}