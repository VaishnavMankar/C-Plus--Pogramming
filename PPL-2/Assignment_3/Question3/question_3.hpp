#include <iostream>
#include <fstream>
#include <string>

class question_3 {
    private:
    int lineCount;
    int wordCount;
    int charCount;
    int sentenceCount;

public:
    void calculateStats(const string &filename);
    void displayStats();
};