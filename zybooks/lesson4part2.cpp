// This program will take a selected second input and convert that second value to the amount out of
// days, hours, minutes, and seconds. We will declare long long ints and const ints that will be
// used in the calculations later on. The program uses modulus/division for the calculations and an
// if else statement for the range check.
#include <iostream>

using namespace std;

int main() {
  // Define all variables required for the calculations that will be performed
  long long int days,
                hours,
                minutes,
                seconds,
                totalSeconds;

  const int     SECONDS_IN_DAY = 86400,
                SECONDS_IN_HOUR = 3600,
                SECONDS_IN_MINUTE = 60;

  // Gather input from the user for seconds that will be converted into different units
  cout << "Enter seconds" << endl;
  cin >> totalSeconds;

  cout << "Total seconds: " << totalSeconds << endl;
  cout << endl;

  // Calculations for all requested values in the program using modulus and division for remainders
  days = totalSeconds / SECONDS_IN_DAY;
  hours = (totalSeconds % SECONDS_IN_DAY) / SECONDS_IN_HOUR;
  minutes = ((totalSeconds % SECONDS_IN_DAY) % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
  seconds = ((totalSeconds % SECONDS_IN_DAY) % SECONDS_IN_HOUR) % SECONDS_IN_MINUTE;

  // Should the user enter 0 or less, the program will notify the user of invalidity and exit
  if (totalSeconds <= 0) {
    cout << "Total seconds must be greater than zero" << endl;
  }

  // We use an if else statement to make sure the range is correct
  // Inside the else, we have if statements, making sure we only print if the number is > 0
  else {
    if (days > 0) {
      cout << days << " day(s)" << endl;
    }
    if (hours > 0) {
      cout << hours << " hour(s)" << endl;
    }
    if (minutes > 0) {
      cout << minutes << " minute(s)" << endl;
    }
    if (seconds > 0) {
      cout << seconds << " second(s)" << endl;
    }
  }

  return 0;
}
