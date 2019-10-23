// This program will read in a file that contains numbers in it. It will then take all the numbers,
// determine whether they are valid or invalid, add them to the average, and display the final
// results in the console, as well as output to a file called `invalid-values.txt` for the invalid
// values stored.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream inputFile;
  ofstream outputFile;
  string inputFileName,
         outputFileName = "invalid-values.txt";
  double inputFileValue,
         totalValue = 0,
         invalidValue = 0,
         validValue = 0,
         averageValidValue = 0;

  // User input to receive the file name they would like to open, as well as open it (along with
  // the output file)
  cout << "Enter input file name" << endl;
  cin >> inputFileName;
  inputFile.open(inputFileName);
  outputFile.open(outputFileName);



  // If statement to process the input file
  // Includes nested if statement verifying validity of the values given to the compiler
  if (inputFile) {
    cout << "Reading from file \"" << inputFileName << "\"" << endl;
      while (inputFile >> inputFileValue) {
          if (inputFileValue >= 0 && inputFileValue <= 105) {
              validValue++;
              averageValidValue += inputFileValue;
          }
          else {
              invalidValue++;
              outputFile << setprecision(5) << fixed << inputFileValue << endl;
          }
      }
      // Output put into the if statement so we don't have to use `return 0;` in our else statement
      // Math used after the if statement
      totalValue = validValue + invalidValue;
      averageValidValue /= validValue;

      // Output statement code block to display the statistics gathered in the console
      cout << "Total values: " << totalValue << endl;
      cout << "Invalid values: " << invalidValue << endl;
      cout << "Valid values: " << validValue << endl;

      // If statement for displaying average not possible message
      if (validValue > 0) {
        cout << "Average of valid values: " << setprecision(4) << fixed << averageValidValue << endl;
      }
      else {
        cout << "An average cannot be calculated" << endl;
      }
  }

  else {
      cout << "File \"" << inputFileName << "\" could not be opened" << endl;
  }



  // Finalize the program by closing both the input and output files
  inputFile.close();
  outputFile.close();

  return 0;
}
