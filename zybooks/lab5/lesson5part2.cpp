// This program will differ from the first part of this lab lesson because it does not use the
// switch statement, but it still has a menu. We use if/else statements for this menu. Inside
// the if statements, we have a cin for the seconds traveled in total and calculations will be
// performed to show how far the sound traveled in that time. We format output in this with the
// `iomanip` library.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // We define these values as const doubles because we know they will not change in the program
  const double CARBON_DIOXIDE_METERS_PER_SECOND = 258.0,
               AIR_METERS_PER_SECOND = 331.5,
               HELIUM_METERS_PER_SECOND = 972.0,
               HYDROGEN_METERS_PER_SECOND = 1270.0,
               MAX_SECONDS = 30,
               MIN_SECONDS = 0;

  unsigned int choice;

  double secondsTraveled, carbonDioxideDistance, airDistance, heliumDistance, hydrogenDistance;

  // Used to display the menu the user will pick from, as well as take their choice in the menu
  cout << "Select the medium that sound is traveling through:" << endl;
  cout << "1 Carbon Dioxide" << endl;
  cout << "2 Air" << endl;
  cout << "3 Helium" << endl;
  cout << "4 Hydrogen" << endl;
  cin >> choice;

  // If statements that follow are to direct the user based on his menu choice

  // Choice 1, Carbon Dioxide if statement block
  if (choice == 1) {
    cout << "Enter time (in seconds)" << endl;
    cin >> secondsTraveled;
    carbonDioxideDistance = secondsTraveled * CARBON_DIOXIDE_METERS_PER_SECOND; // Calculation for output

    // If statement to check if the range of the seconds traveled is in the correct range
    if (secondsTraveled <= MAX_SECONDS && secondsTraveled >= MIN_SECONDS) {
      cout << "Carbon Dioxide: " << setprecision(3) << fixed << secondsTraveled << " seconds" << endl;;
      cout << "Traveled " << setprecision(4) << fixed << carbonDioxideDistance << " meters" << endl;
    }

    // Incorrect seconds traveled value gets directed to this block of the code
    else {
      cout << "The time must be between " << setprecision(3) << fixed << MIN_SECONDS << " and " << MAX_SECONDS << " (inclusive)" << endl;
    }
  }

  // Choice 2, Air else if statement block
  else if (choice == 2) {
    cout << "Enter time (in seconds)" << endl;
    cin >> secondsTraveled;
    airDistance = secondsTraveled * AIR_METERS_PER_SECOND;   // Calculation for output

    // If statement to check if the range of the seconds traveled is in the correct range
    if (secondsTraveled <= MAX_SECONDS && secondsTraveled >= MIN_SECONDS) {
      cout << "Air: " << setprecision(3) << fixed << secondsTraveled << " seconds" << endl;
      cout << "Traveled " << setprecision(4) << fixed << airDistance << " meters" << endl;
    }

    // Incorrect seconds traveled value gets directed to this block of the code
    else {
      cout << "The time must be between " << setprecision(3) << fixed << MIN_SECONDS << " and " << MAX_SECONDS << " (inclusive)" << endl;
    }
  }

  // Choice 3, Helium else if statement block
  else if (choice == 3) {
    cout << "Enter time (in seconds)" << endl;
    cin >> secondsTraveled;
    heliumDistance = secondsTraveled * HELIUM_METERS_PER_SECOND;   // Calculation for output

    // If statement to check if the range of the seconds traveled is in the correct range
    if (secondsTraveled <= MAX_SECONDS && secondsTraveled >= MIN_SECONDS) {
      cout << "Helium: " << setprecision(3) << fixed << secondsTraveled << " seconds" << endl;
      cout << "Traveled " << setprecision(4) << fixed << heliumDistance << " meters" << endl;
    }

    // Incorrect seconds traveled value gets directed to this block of the code
    else {
      cout << "The time must be between " << setprecision(3) << fixed << MIN_SECONDS << " and " << MAX_SECONDS << " (inclusive)" << endl;
    }
  }

  // Choice 4, Hydrogen else if statement block
  else if (choice == 4) {
    cout << "Enter time (in seconds)" << endl;
    cin >> secondsTraveled;
    hydrogenDistance = secondsTraveled * HYDROGEN_METERS_PER_SECOND; // Calculation for output

    // If statement to check if the range of the seconds traveled is in the correct range
    if (secondsTraveled <= MAX_SECONDS && secondsTraveled >= MIN_SECONDS) {
      cout << "Hydrogen: " << setprecision(3) << fixed << secondsTraveled << " seconds" << endl;
      cout << "Traveled " << setprecision(4) << fixed << hydrogenDistance << " meters" << endl;
    }

    // Incorrect seconds traveled value gets directed to this block of the code
    else {
      cout << "The time must be between " << setprecision(3) << fixed << MIN_SECONDS << " and " << MAX_SECONDS << " (inclusive)" << endl;
    }
  }

  // If the user does not select a valid input, they will be directed to this portion of the code
  else {
    cout << "The menu value is invalid. Please run the program again." << endl;
  }

  return 0;
}
