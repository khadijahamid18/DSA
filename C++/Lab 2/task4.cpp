#include <iostream>
#include <string>
using namespace std;
int countWords(string str)
{
    int words = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            words++;
        }
    }
    words = words + 1;
    return words;
}
int main()
{
    system("cls");
    string str;
    cout << "Please enter any string: ";
    getline(cin, str);
    int words = countWords(str);
    cout << "Total words in the string are: " << words << endl;

    return 0;
}