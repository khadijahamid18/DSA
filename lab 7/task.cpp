#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

bool delimitersOk(const string &expression)
{
    stack<char> stack1;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            stack1.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (stack1.top() == '(')
            {
                stack1.pop();
            }
            else
            {
                return false;
            }
        }
        else if (expression[i] == '}')
        {
            if (stack1.top() == '{')
            {
                stack1.pop();
            }
            else
            {
                return false;
            }
        }
        else if (expression[i] == ']')
        {
            if (stack1.top() == '[')
            {
                stack1.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return stack1.empty();
}

int main()
{

    ifstream file; 
    int size;
    string str;
    file.open("input.txt");
    if (!file)
    {
        cerr << "Error: file could not be opened" << endl;
        exit(0);
    }

    file >> size;

    getline(file, str);
    for (int i = 0; i < size; i++)
    {
        getline(file, str);
        if (delimitersOk(str))
        {
            cout << "Valid" << endl;
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }
    file.close();

    return 0;
}