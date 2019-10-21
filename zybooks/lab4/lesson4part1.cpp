// This program will be taking a selected input of mass in kilograms and converting it to newtons
// in different environments (Earth, Moon, and Venus). This program will use the `iomanip` library
// to format the different required outputs, as well as contain a few if statements for special
// values achieved.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // Constant variable declarations due to them not changing throughout the program
  const double EARTH_GRAVITY = 9.81,
               MOON_GRAVITY = 1.62,
               VENUS_GRAVITY = 8.87;

  const int    LIGHT_WEIGHT = 5,
               HEAVY_WEIGHT = 1500;

  double mass;

  // Prompt the user to input the mass they want to work with
  cout << "Enter the mass in kg" << endl;
  cin >> mass;

  // Remind the user the mass they selected
  cout << "The mass is " << setprecision(4) << fixed << mass << " kg" << endl;

  // Notify the user the mass must be greater than 0 and terminate the program afterwards
  if (mass <= 0) {
    cout << "The mass must be greater than zero" << endl;
    return 0;
  }

  // Newton weight calculations
  double newtonWeightEarth = mass * EARTH_GRAVITY,
         newtonWeightMoon = mass * MOON_GRAVITY,
         newtonWeightVenus = mass * VENUS_GRAVITY;

  // Print statements using setw() and setprecision() to get the desired outputs
  cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)" << endl;
  cout << setw(8) << left << "Earth" << setw(14) << right << setprecision(4) << fixed << newtonWeightEarth << endl;
  cout << setw(8) << left << "Moon" << setw(14) << right << setprecision(4) << fixed << newtonWeightMoon << endl;
  cout << setw(8) << left << "Venus" << setw(14) << right << setprecision(4) << fixed << newtonWeightVenus << endl;

  // Two if statements for determining heavy and light objects
  if (newtonWeightEarth > HEAVY_WEIGHT) {
    cout << "The object is heavy" << endl;
  }

  else if (newtonWeightEarth < LIGHT_WEIGHT) {
    cout << "The object is light" << endl;
  }

  return 0;
}
