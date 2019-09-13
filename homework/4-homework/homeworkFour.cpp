// This program will take the input of three numbers and calculate the greatest number and lowest number.
#include <iostream>
#include <string>

using namespace std;

int main() {
  double numberOne, numberTwo, numberThree;
  double greatestValue, leastValue, middleValue;

  //Input portion of code that will take and store the values of all three numbers defined previously
  cout << "What is the first number?" << endl;
  cin >> numberOne;

  cout << "What is the second number?" << endl;
  cin >> numberTwo;

  cout << "What is the third number?" << endl;
  cin >> numberThree;

  //Greatest value if statement testing
  if (numberOne > numberTwo && numberOne > numberThree) {
    cout << endl;
    cout << "The greatest value you entered is: " << numberOne << endl;
  }
  else if (numberTwo > numberOne && numberTwo > numberThree) {
    cout << endl;
    cout << "The greatest value you entered is: " << numberTwo << endl;
  }
  else if (numberThree > numberOne && numberThree > numberTwo) {
    cout << endl;
    cout << "The greatest value you entered is: " << numberThree << endl;
  }

  cout << endl;

  //Least value if statement testing
  if (numberOne < numberTwo && numberOne < numberThree) {
    cout << endl;
    cout << "The lowest value you entered is: " << numberOne << endl;
  }
  else if (numberTwo < numberOne && numberTwo < numberThree) {
    cout << endl;
    cout << "The lowest value you entered is: " << numberTwo << endl;
  }
  else if (numberThree < numberOne && numberThree < numberTwo) {
    cout << endl;
    cout << "The lowest value you entered is: " << numberThree << endl;
  }

  return 0;
}
