#include "question_3.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void question_3::calculateStats(const string &filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    lineCount = wordCount = charCount = sentenceCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        charCount += line.length() + 1; // +1 for newline character

        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            wordCount++;
            char lastChar = word[word.length() - 1];
            if (lastChar == '.' || lastChar == '?' || lastChar == '!') {
                sentenceCount++;
            }
        }
    }

    file.close();
}

void question_3::displayStats() {
    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of characters: " << charCount << endl;
    cout << "Number of sentences: " << sentenceCount << endl;
}
