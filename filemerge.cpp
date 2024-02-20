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

    // Read the first line from each file
    if (getline(file1, line1) && getline(file2, line2)) {
        do {
            // If the key from file 1 is <= the key from file 2
            if (line1.compare(0, line1.find(' '), line2, 0, line2.find(' ')) <= 0) {
                // Write the line from file 1 to the output file
                output << line1 << endl;
                // Read a new line from file 1
                if (!getline(file1, line1)) break;  // Break if end of file 1 is reached
            }
            else {
                // Write the line from file 2 to the output file
                output << line2 << endl;
                // Read a new line from file 2
                if (!getline(file2, line2)) break;  // Break if end of file 2 is reached
            }
        } while (true);
    }

    // Write the remaining lines (if any) from file 1 to the output file
    while (getline(file1, line1)) {
        output << line1 << endl;
    }

    // Write the remaining lines (if any) from file 2 to the output file
    while (getline(file2, line2)) {
        output << line2 << endl;
    }

    // Close the files
    file1.close();
    file2.close();
    output.close();
}

int main() {
    // Replace "file1.txt", "file2.txt", and "output.txt" with your file paths
    mergeFiles("file1.txt", "file2.txt", "output.txt");

    cout << "Files merged successfully." << endl;

    return 0;
}