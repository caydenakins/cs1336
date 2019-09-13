#include <iostream>

using namespace std;

int main() {
  int userNum;
  const int CHOICE_ONE = 1,
            CHOICE_TWO = 2,
            CHOICE_THREE = 3;

  cout << "Enter one of the numbers 1, 2, or 3:" << endl;
  cin >> userNum;

  switch (userNum) {
    case CHOICE_ONE:
    cout << "You chose number 1!" << endl;
    break;

    case CHOICE_TWO:
    cout << "You chose number 2!" << endl;
    break;

    case CHOICE_THREE:
    cout << "You chose number 3!" << endl;
    break;

    default:
    cout << "Please restart the program and enter a number within the given range." << endl;
  }

  return 0;
}
