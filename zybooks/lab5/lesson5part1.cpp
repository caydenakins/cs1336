// This program will calculate the amount of seconds it will take for sound to travel through
// different mediums. It will first prompt the user to select a choice from the menu displayed
// and use it in a switch statement. From there it will put you in the case chosen and perform
// the calculations for the output.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // Defined as constants because they will not change throughout the program
  // We use double as we are asked to, and it will be consistent if we do so (won't divide doubles
  // and ints).
  const double AIR_FEET_PER_SECOND = 1100,
               WATER_FEET_PER_SECOND = 4900,
               STEEL_FEET_PER_SECOND = 16400;

  unsigned int choice;

  // We can use distance for all cases because we will only use 1 case at most
  double distance, airSeconds, waterSeconds, steelSeconds;

  cout << "Select the medium that sound is traveling through:" << endl;
  cout << "1 Air" << endl;
  cout << "2 Water" << endl;
  cout << "3 Steel" << endl;
  cin >> choice;

  cout << setprecision(4) << fixed;   // Used for formatting outputs to have 4 decimal places

  // Switch statement to answer to the menu choice the user selects
  switch(choice) {
    case 1:
      cout << "Enter distance (in feet)" << endl;
      cin >> distance;

      // If statement for assuring the proper range is achieved from the user's input
      if (distance <= 0) {
        cout << "The distance must be greater than zero" << endl;
      }

      else {
        cout << "Air: " << distance << " ft" << endl;
        airSeconds = distance / AIR_FEET_PER_SECOND;
        cout << "Traveled for " << airSeconds << " seconds" << endl;
      }

      break;

    case 2:
        cout << "Enter distance (in feet)" << endl;
        cin >> distance;

        // If statement for assuring the proper range is achieved from the user's input
        if (distance <= 0) {
          cout << "The distance must be greater than zero" << endl;
        }

        else {
          cout << "Water: " << distance << " ft" << endl;
          waterSeconds = distance / WATER_FEET_PER_SECOND;
          cout << "Traveled for " << waterSeconds << " seconds" << endl;
        }
      break;

    case 3:
        cout << "Enter distance (in feet)" << endl;
        cin >> distance;

        // If statement for assuring the proper range is achieved from the user's input
        if (distance <= 0) {
          cout << "The distance must be greater than zero" << endl;
        }

        else {
          cout << "Steel: " << distance << " ft" << endl;
          steelSeconds = distance / STEEL_FEET_PER_SECOND;
          cout << "Traveled for " << steelSeconds << " seconds" << endl;
        }
      break;

    // Used if the user does not enter a value 1, 2, or 3 for the switch statement input
    default:
      cout << "The menu value is invalid. Please run the program again." << endl;
  }

  return 0;
}
