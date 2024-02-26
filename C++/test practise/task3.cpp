#include<iostream>
#include<string>
using namespace std;
int main()
{
    system("cls");
    string str;
    cout << "Enter any string: " << endl;
    cin >> str;
    cout << str;
    getline(cin, str); 
    cout << str; 


    return 0;
}