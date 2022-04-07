#include <iostream>
#include <fstream>

using namespace std;

int main() {

    const unsigned int COMMENT_NONE = 0;
    const unsigned int COMMENT_LINE = 1;
    const unsigned int COMMENT_BLOCK = 2;

    fstream input;
    input.open("input", ios::in);

    string currentLine;
    unsigned int commented = COMMENT_NONE;
    while (getline(input, currentLine)) {
        for (int i=0; i<currentLine.size(); i++) {

            if (currentLine[i] == '/' && i+1 < currentLine.size()) {
                if (currentLine[i+1] == '/') {
                    commented = COMMENT_LINE;
                }
                if (currentLine[i+1] == '*') {
                    commented = COMMENT_BLOCK;
                }
            }

            if (i-2 >= 0 && (currentLine[i-1] == '/' && currentLine[i-2] == '*')) {
                if (i-3 >= 0) {
                    if (currentLine[i-2] != '/') {
                        commented = COMMENT_NONE;
                    }
                }
                else {
                    commented = COMMENT_NONE;
                }
            }

            if (!commented) {
                cout << currentLine[i];
            }
        }

        if (commented == 1) {
            commented = COMMENT_NONE;
        }

        if (!commented) cout << endl;
    }

    return 0;
}
