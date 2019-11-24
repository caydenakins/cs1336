// This program will use the file stream library to take input files containing student-chosen
// answers and correct answers, comparing the two with implementation of multiple functions to
// display the answers the student incorrectly chose.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
int read(char [], ifstream &);
void display(char [], char [], int);

int main() {
  const int ARRAY_SIZE = 30;
  char choice[ARRAY_SIZE];
  char correct[ARRAY_SIZE];
  ifstream studentAnswers, correctAnswers;
  string choiceFileName, answerFileName;
  int firstRead = 0, secondRead = 0;

  // Getting user input to determine which file they want to open for the student's answers
  cout << "Enter student answers file name" << endl;
  cin >> choiceFileName;
  studentAnswers.open(choiceFileName);

  // Affirming the input file opened correctly/exists
  if (!studentAnswers) {
    cout << "File \"" << choiceFileName << "\" could not be opened" << endl;
    return 0;
  }

  firstRead = read(choice, studentAnswers); // First call to the read() function

  // Getting user input to determine which file they want to open for the correct answers
  cout << "Enter correct answer file name" << endl;
  cin >> answerFileName;
  correctAnswers.open(answerFileName);

  // Affirming the input file opened correctly/exists
  if (!correctAnswers) {
    cout << "File \"" << answerFileName << "\" could not be opened" << endl;
    return 0;
  }

  secondRead = read(correct, correctAnswers); // Second call to the read() function

  // Testing to make sure the amount of values are not different, else it will quit the program
  if (firstRead != secondRead) {
    if (firstRead == -1)
      firstRead = 0;
    if (secondRead == -1)
      secondRead = 0;
    cout << "The student answers file has " << firstRead << " entries and the correct answers file has " << secondRead << " entries" << endl;
    cout << "Grading cannot be done if they are not the same" << endl;
    return 0;
  }

  if (firstRead == -1)
    firstRead = 0;
  if (secondRead == -1)
    secondRead = 0;

  // Testing to see if the amount of values are both 0, because if so, the program will quit
  if (firstRead == 0 && secondRead == 0) {
    cout << "The number of student answers and correct answers are both 0" << endl;
    cout << "No grade can be calculated" << endl;
    return 0;
  }

  display(choice, correct, firstRead); // Call the display function if you pass all pre-tests

  studentAnswers.close();
  correctAnswers.close();

  return 0;
}

// Function used for reading in the amount of values in each input file and store them in arrays
int read(char stored[], ifstream &input) {
  int count = 0;

  while (input >> stored[count]) {
    count++;
  }

  if (count == 0)
    return -1;

  if (count > 30)
    return 30;

  return count;
}

// Function used for calculating missed answers and displaying them
void display(char studentValues[], char correctValues[], int totalQuestions) {
  int correct = 0,
      incorrect = 0,
      total = 0;
  double grade;

  // I passed in the value we got from calling the read() function the first time, as I knew if
  // it passed the tests leading up to the function, the 2 arrays had the same amount of values
  for (int i = 0; i < totalQuestions; i++) {
    if (studentValues[i] == correctValues[i])
      correct++;

    if (studentValues[i] != correctValues[i]) {
      incorrect++;
      cout << "Question " << (i + 1) << " has incorrect answer \'" << studentValues[i]
           << "\', the correct answer is \'"
           << correctValues[i] << "\'" << endl;
    }
  }

  // Assigning total and grade values
  total = correct + incorrect;
  grade = (static_cast<double>(correct) / total) * 100;

  // Print statements for the end of the function
  cout << incorrect << " questions were missed out of " << total << endl;
  cout << "The student grade is " << setprecision(1) << fixed << grade << "%" << endl;
  if (grade < 70)
    cout << "The student failed" << endl;
  else
    cout << "The student passed" << endl;
}
