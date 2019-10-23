// This file will work with the file stream library and take input from a text file that contains
// store numbers and sales values. These will be printed to an output file, where it will display
// a bar graph based on the value of the sales values.
// NOTE: If you want this to work on your console, replace the `outputFile >>` statements in the
// while loop with cout.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ifstream inputFile;
    ofstream outputFile;
    unsigned int storeNumber;
    long long int salesValue, starOutput;
    string inputFileName;
    int count = 0; // Used so we only output the headers to the output file one time
    int incrementValue = 5000;

    // Get the name of the input file the user wants to open
    cout << "Enter input file name" << endl;
    cin >> inputFileName;
    inputFile.open(inputFileName);

    // Verifies the input file correctly opens
    if (inputFile) {
    }
    else {
        cout << "File \"" << inputFileName << "\" could not be opened"  << endl;
        return 0;
    }

    outputFile.open("saleschart.txt");

    // Verifies the output file correctly opens
    if (outputFile) {
    }
    else {
        cout << "Output file could not open correctly. Quitting the program." << endl;
        inputFile.close();
        return 0;
    }

    // While loop to iterate as many times as the input file can provide data to the program
    // Also checks for valid inputs with if statements
    while (inputFile >> storeNumber >> salesValue) {
        if (storeNumber < 1 || storeNumber > 99) {
            cout << "The store number " << storeNumber << " is not valid" << endl;
        }
        else if (salesValue < 0) {
            cout << "The sales value for store " << storeNumber << " is negative" << endl;
        }
        else {
            // If statement for making sure the header is only printed one time
            if (count == 0) {
                outputFile << "SALES BAR CHART" << endl;
                outputFile << "(Each * equals 5,000 dollars)" << endl;
                count++;
            }

            outputFile << "Store " << setw(2) << storeNumber << ": ";
            starOutput = salesValue / incrementValue;

            for (int i = 0; i < starOutput; i++) {
                    outputFile << "*";
            }
            outputFile << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
