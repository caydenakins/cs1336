// This program will take the input of three numbers and calculate the greatest number and lowest number.
#include <iostream>

using namespace std;

int main() {
  double numberOne, numberTwo, numberThree;  // Input variables

  // Input portion of code that will take and store the values of all three numbers defined previously
  cout << "What is the first number?" << endl;
  cin >> numberOne;
  cout << endl;

  cout << "What is the second number?" << endl;
  cin >> numberTwo;
  cout << endl;

  cout << "What is the third number?" << endl;
  cin >> numberThree;
  cout << endl;

  // Greatest value if statement testing
  if (numberOne > numberTwo && numberOne > numberThree) {
    cout << "The greatest value you entered is: " << numberOne << endl;
    cout << endl;
  }
  else if (numberTwo > numberOne && numberTwo > numberThree) {
    cout << "The greatest value you entered is: " << numberTwo << endl;
    cout << endl;
  }
  else if (numberThree > numberOne && numberThree > numberTwo) {
    cout << "The greatest value you entered is: " << numberThree << endl;
    cout << endl;
  }

  // Least value if statement testing
  if (numberOne < numberTwo && numberOne < numberThree) {
    cout << "The lowest value you entered is: " << numberOne << endl;
    cout << endl;
  }
  else if (numberTwo < numberOne && numberTwo < numberThree) {
    cout << "The lowest value you entered is: " << numberTwo << endl;
    cout << endl;
  }
  else if (numberThree < numberOne && numberThree < numberTwo) {
    cout << "The lowest value you entered is: " << numberThree << endl;
    cout << endl;
  }

  // Middle value if statement testing (not needed for the homework, just uploading to repo for practice)
  if ((numberOne > numberTwo && numberOne < numberThree) || (numberOne < numberTwo && numberOne > numberThree)) {
    cout << "The middle value you entered is: " << numberOne << endl;
  }
  else if ((numberTwo > numberOne && numberTwo < numberThree) || (numberTwo < numberOne && numberTwo > numberThree)) {
    cout << "The middle value you entered is: " << numberTwo << endl;
  }
  else if ((numberThree > numberOne && numberThree < numberTwo) || (numberThree < numberOne && numberThree > numberTwo)) {
    cout << "The middle value you entered is: " << numberThree << endl;
  }

  return 0;
}
