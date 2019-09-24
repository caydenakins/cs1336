// This program will ask the user to input a value and it will be transformed into a shape. The program is organized
// in a do while loop in order to assure the user stays in the correct range for their inputs. Inside the do while
// loop, there are nested if statements and while loops that check ranges and whether the input is positive or
// negative. The for loops are the key to building the shapes, as they set out the right amount of characters.
#include <iostream>

using namespace std;

int main() {
  double numberInput;    // Define the value we will use through the entirety of the program
  int count = 0;         // For our later reminder message

  // Put initial code inside of do while loop to constantly notify user to be in range, as well as only exit
  // the program on a 0 input
  do {
    // We use count to inform the user of the range we are trying to stay between, prompting them with the reminder
    // message starting after one incorrect try
    if (count < 1) {
      cout << "Enter a number to display a custom shape (Enter a 0 to exit):" << endl;
      cin >> numberInput;
      cout << endl;
    }

    else if (count >= 1) {
      cout << "Please stay within the range -20 and 20 and try again!" << endl;
      cout << "Enter a number to display a custom shape (Enter a 0 to exit):" << endl;
      cin >> numberInput;
      cout << endl;
    }

    count++;

    // If the user successfully inputs a number within the range, it passes through this while statement that will
    // print the shapes based on whether or not it is a positive or negative value
    while (numberInput >= -20 && numberInput <= 20 && numberInput != 0) {

      // Square if statement for positive values
      if (numberInput > 0) {
        for (int i = 0; i < numberInput; i++) {
          for (int j = 0; j < numberInput; j++) {
            cout << "X";
          }
          cout << endl;
        }
      }

      // Isosceles right triangle if statement for negative values
      else if (numberInput < 0) {
        numberInput *= -1;                         // Line to get absolute value of input
        for (int i = 0; i < numberInput; i++) {    // i = row, j = column
          for (int j = i; j >= 0; j--) {
            cout << "X";
          }
          cout << endl;
        }
      }

      // When the user approaches the end of this while loop, they will be asked for more inputs, continuing until
      // a 0 is reached, they go out of the range where they will return to the original do while, or the program
      // is closed manually
      cout << endl;
      cout << "Enter a number to display a custom shape (Enter a 0 to exit):" << endl;
      cin >> numberInput;
      cout << endl;
    }
  } while (numberInput < -20 || numberInput > 20);

  // If statement used to terminate the code should the user enter a 0
  if (numberInput == 0) {
    cout << "Exiting..." << endl;
    return 0;
  }

  return 0;
}
