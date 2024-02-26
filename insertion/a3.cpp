#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countWordOccurrences(const string& line, const string& word) {
    int count = 0;
    int pos = 0;
    // pos : position of string
    // npos : no position
    while ((pos = line.find(word, pos)) != string::npos) {
        count++;
        pos += word.length();
    }
    return count;
}

int main() {
    string wordToSearch;
    cout << "Enter the word to search: ";
    cin >> wordToSearch;

    ifstream inputFile("input3.txt"); 
    if (!inputFile) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(inputFile, line)) {
        int occurrences = countWordOccurrences(line, wordToSearch);
        cout << "Line " << lineNumber << ": " << occurrences << endl;
        lineNumber++;
    }

    inputFile.close();
    return 0;
}