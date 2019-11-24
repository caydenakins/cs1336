// This program will use multiple functions to process the user's input file of choice that
// contains grades, calculating the overall average, column average, and smallest values using
// nested for-loops and 2 dimensional arrays.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MAX_COLUMNS = 5;

int readFile(double [][MAX_COLUMNS], int, string);
double average(double [][MAX_COLUMNS], int);
double columnAverage(double [][MAX_COLUMNS], int, int);
double smallestValue(double [][MAX_COLUMNS], int);

int main() {
  string inputFileName;
  const int MAX_ROWS = 30;
  double grades[MAX_ROWS][MAX_COLUMNS];
  cout << setprecision(2) << fixed;

  cout << "Enter input file name" << endl;
  cin >> inputFileName;

  int actualRows = readFile(grades, MAX_ROWS, inputFileName);

  // Quit the program if the file could not be opened
  if (actualRows == -1)
    return 0;

  // Notify the user, then quit the file if it did not contain data, but was able to open
  if (actualRows == 0) {
    cout << "The input file \"" << inputFileName << "\" did not contain any data" << endl;
    return 0;
  }

  cout << "Processing " << actualRows << " rows, and " << MAX_COLUMNS << " columns" << endl;

//  for (int a = 0; a < actualRows; a++) {
//    for (int b = 0; b < 5; b++) {
//      cout << fixed << grades[a][b] << "  ";
//    }
//    cout << endl;
//  }

  // Call the function that will return the average of all the grades
  double gradesAverage = average(grades, actualRows);
  cout << "Average for all values is " << gradesAverage << endl;


  // For-loop containing the call to the column average, outputting each column's average
  for (int column = 0; column < MAX_COLUMNS; column++) {
    double colAverage = columnAverage(grades, column, actualRows);
    cout << "Average for column " << column << " is " << colAverage << endl;
  }


  // For-loop containing the call to the function that finds the smallest value in each row
  for (int row = 0; row < actualRows; row++) {
    double small = smallestValue(grades, row);
    cout << "Smallest value for row " << row << " is " << small << endl;
  }

  return 0;
}

// Function that reads the input file and populates the array
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName) {
  int count = 0;
  ifstream inputFile;
  inputFile.open(inputFileName);

  // Confirm the file opened properly
  if (!inputFile) {
    cout << "File \"" << inputFileName << "\" could not be opened";
    return -1;
  }

  // Assigns each array value from the input file
  for (int i = 0; i < maxRows; i++) {
    for (int k = 0; k < MAX_COLUMNS; k++) {
      inputFile >> values[i][k] && count++;
    }
  }

  // If there is no data in the array, return to the main function
  if (count == 0)
    return 0;

  count /= 5; // Divide by 5 because I get the count every column (each contains 5)

  return count;
}

// Function that will return the average of all numbers
double average(double values[][MAX_COLUMNS], int numberRows) {
  double gradeAverage = 0;
  int totalGrades = 0;

  for (int column = 0; column < MAX_COLUMNS; column++) {
    for (int row = 0; row < numberRows; row++) {
      gradeAverage += values[row][column];
      totalGrades++; // Keeps track of the number of items processed to divide for the average
    }
  }

  gradeAverage /= totalGrades;

  return gradeAverage;
}

// Function that gets the column average column-by-column because of the for-loop calling it
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows) {
  double average = 0;

  // Keeps the column the same, but the row number changing
  for (int rows = 0; rows < numberRows; rows++) {
    average += values[rows][column];
  }

  average /= numberRows;

  return average;
}

// Function that gets the smallest value going row-by-row because of the for-loop calling it
double smallestValue(double values[][MAX_COLUMNS], int numberRow) {
  double smallVal = values[numberRow][0]; // Initialize smallest value for the base

  for (int column = 0; column < MAX_COLUMNS; column++) {
    if (values[numberRow][column] < smallVal)
      smallVal = values[numberRow][column];
  }

  return smallVal;
}
