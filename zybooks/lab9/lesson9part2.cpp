// This program will utilize multiple functions and fstream to create a program that will
// read in text/values from an input file and calculate future value using a formula. It will
// then output the results to an output file, but will also alert the user if they have any
// incorrect inputs.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double futureValue(double, double, int);
unsigned int readValue(ofstream&, double, double, int);
void excelOutput(ofstream&, double, double, int, double);

int main() {
  ofstream outputFile;
  ifstream inputFile;
  string inputFileName;
  int monthsAmount;
  double currentValue, monthlyInterest;

  cout << "Enter input file name" << endl;
  cin >> inputFileName;

  inputFile.open(inputFileName);

  // If the input file doesn't open, do this
  if (!inputFile) {
    cout << "File \"" << inputFileName << "\" could not be opened" << endl;
    return 0;
  }

  outputFile.open("output.xls");

  // If the output file doesn't open, do this
  if (!outputFile) {
    inputFile.close();
    cout << "File \"output.xls\" could not be opened" << endl;
    return 0;
  }

  // We only output this once so it doesn't repeat when we loop through our values
  outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;

  // While we have values flowing in, assign them to the below variables and call readValue()
  while (inputFile >> currentValue >> monthlyInterest >> monthsAmount) {
    readValue(outputFile, currentValue, monthlyInterest, monthsAmount);
  }

  inputFile.close();
  outputFile.close();

  return 0;
}

// Our readValue function does majority of the logic and differentiates between the
// futureValueCalculation function and the excelOutput function
unsigned int readValue(ofstream& output, double presentValue, double interestRate, int months) {
  interestRate /= 100;// Convert percentage to a decimal prior to calling futureValue function

  // Return 2 if the input values are less than 0
  if ((presentValue <= 0) || (interestRate <= 0) || (months <= 0)) {
    cout << setprecision(2) << fixed << presentValue << " " << setprecision(3) << fixed
         << (interestRate * 100) << " " << months << endl;
    cout << "One or more of the above values are not greater than zero" << endl;
    return 2;
  }

  // Call function and assign it a value we will later pass the read() function
  double futureValueCalculation = futureValue(presentValue, interestRate, months);

  interestRate *= 100;            // Reset the decimal to a percentage to be printed out


  excelOutput(output, presentValue, interestRate, months, futureValueCalculation);

  return 1;                       // Return 1 if the data is all valid
}

// Calculate the futureValue with this function
double futureValue(double presentValue, double interestRate, int months) {
  double futureValue = presentValue * pow((1 + interestRate), months);
  return futureValue;
}

// Simply our output function
void excelOutput(ofstream& outputFile, double presentValueOutput, double interestRateOutput,
                 int monthsOutput, double futureValueOutput) {
  outputFile << setprecision(2) << fixed << futureValueOutput << "\t" << presentValueOutput
             << "\t" << setprecision(3) << fixed << interestRateOutput << "\t" << monthsOutput << endl;
}
