#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mergeFiles(const string& inputFile1, const string& inputFile2, const string& outputFile) {
    ifstream file1(inputFile1);
    ifstream file2(inputFile2);
    ofstream output(outputFile);

    if (!file1 || !file2 || !output) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line1, line2;

    if (getline(file1, line1) && getline(file2, line2)) {
        do {
            if (line1.compare(0, line1.find(' '), line2, 0, line2.find(' ')) <= 0) {
                output << line1 << endl;
                if (!getline(file1, line1)) break;  
            }
            else {
                output << line2 << endl;
                if (!getline(file2, line2)) break;  
            }
        } while (true);
    }

    while (getline(file1, line1)) {
        output << line1 << endl;
    }

    while (getline(file2, line2)) {
        output << line2 << endl;
    }

    file1.close();
    file2.close();
    output.close();
}

int main() {

    mergeFiles("file1.txt", "file2.txt", "output.txt");

    cout << "Files merged successfully." << endl;

    return 0;
}