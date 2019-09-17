// This program will prompt the user to input a temperature in Fahrenheit, then taking that
// value and using it to calculate whether a list of substances are solid, liquid, or gas.
// It is achieved by chaining `if statements` together, utilizing the `if else` feature.
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  double temperatureInput;
  const double MAX_TEMP = 3000,          // Min/max inputs to bind the user to certain values
               MIN_TEMP = -459.67;
  const double WATER_BOILING = 212,      // We use constant variables because we know the
            WATER_FREEZING = 32,         // boiling/freezing points will not change
            LEAD_BOILING = 3180,
            LEAD_FREEZING = 621.5,
            ALCOHOL_BOILING = 173.1,
            ALCOHOL_FREEZING = -173.5,
            NITROGEN_BOILING = -320.4,
            NITROGEN_FREEZING = -346,
            MERCURY_BOILING = 674.1,
            MERCURY_FREEZING = -37.89,
            CHLORINE_BOILING = -29.27,
            CHLORINE_FREEZING = -150.7;

  // Input section to store the temperature the user chooses
  cout << "What is the temperature (in Fahrenheit)?" << endl;
  cin >> temperatureInput;
  cout << endl;

  // Code to terminate the program should the user not be within the range bound
  if ((temperatureInput > MAX_TEMP) || (temperatureInput < MIN_TEMP)) {
    cout << "Please stay within the range of '" << MIN_TEMP << "°F and " << MAX_TEMP << "°F' and try again." << endl;
    return 0;
  }

  // Provide a buffer between the input and the output while maintaining design
  cout << "Calculating matter with a temperature of " << temperatureInput << "°F..." << endl;
  cout << endl;

  // Water tests
  if (temperatureInput >= WATER_BOILING) {
    cout << setw(12) << setfill(' ') << left << "Water: " << "Gas" << endl;
    cout << endl;
  }
    else if ((temperatureInput < WATER_BOILING) && (temperatureInput > WATER_FREEZING)) {
      cout << setw(12) << setfill(' ') << left << "Water: " << "Liquid" << endl;
      cout << endl;
    }
      else if (temperatureInput <= WATER_FREEZING) {
        cout << setw(12) << setfill(' ') << left << "Water: " << "Solid" << endl;
        cout << endl;
      }

  // Lead tests
  if (temperatureInput >= LEAD_BOILING) {
    cout << setw(12) << setfill(' ') << left << "Lead: " << "Gas" << endl;
    cout << endl;
  }
    else if ((temperatureInput < LEAD_BOILING) && (temperatureInput > LEAD_FREEZING)) {
      cout << setw(12) << setfill(' ') << left << "Lead: " << "Liquid" << endl;
      cout << endl;
    }
      else if (temperatureInput <= LEAD_FREEZING) {
        cout << setw(12) << setfill(' ') << left << "Lead: " << "Solid" << endl;
        cout << endl;
      }

  // Alcohol tests
  if (temperatureInput >= ALCOHOL_BOILING) {
    cout << setw(12) << setfill(' ') << left << "Alcohol: " << "Gas" << endl;
    cout << endl;
  }
    else if ((temperatureInput < ALCOHOL_BOILING) && (temperatureInput > ALCOHOL_FREEZING)) {
      cout << setw(12) << setfill(' ') << left << "Alcohol: " << "Liquid" << endl;
      cout << endl;
    }
      else if (temperatureInput <= ALCOHOL_FREEZING) {
        cout << setw(12) << setfill(' ') << left << "Alcohol: " << "Solid" << endl;
        cout << endl;
      }

  // Nitrogen tests
  if (temperatureInput >= NITROGEN_BOILING) {
    cout << setw(12) << setfill(' ') << left << "Nitrogen: " << "Gas" << endl;
    cout << endl;
  }
    else if ((temperatureInput < NITROGEN_BOILING) && (temperatureInput > NITROGEN_FREEZING)) {
      cout << setw(12) << setfill(' ') << left << "Nitrogen: " << "Liquid" << endl;
      cout << endl;
    }
      else if (temperatureInput <= NITROGEN_FREEZING) {
        cout << setw(12) << setfill(' ') << left << "Nitrogen: " << "Solid" << endl;
        cout << endl;
      }

  // Mercury tests
  if (temperatureInput >= MERCURY_BOILING) {
    cout << setw(12) << setfill(' ') << left << "Mercury: " << "Gas" << endl;
    cout << endl;
  }
    else if ((temperatureInput < MERCURY_BOILING) && (temperatureInput > MERCURY_FREEZING)) {
      cout << setw(12) << setfill(' ') << left << "Mercury: " << "Liquid" << endl;
      cout << endl;
    }
      else if (temperatureInput <= MERCURY_FREEZING) {
        cout << setw(12) << setfill(' ') << left << "Mercury: " << "Solid" << endl;
        cout << endl;
      }

  // Chlorine tests
  if (temperatureInput >= CHLORINE_BOILING) {
    cout << setw(12) << setfill(' ') << left << "Chlorine: " << "Gas" << endl;
    cout << endl;
  }
    else if ((temperatureInput < CHLORINE_BOILING) && (temperatureInput > CHLORINE_FREEZING)) {
      cout << setw(12) << setfill(' ') << left << "Chlorine: " << "Liquid" << endl;
      cout << endl;
    }
      else if (temperatureInput <= CHLORINE_FREEZING) {
        cout << setw(12) << setfill(' ') << left << "Chlorine: " << "Solid" << endl;
        cout << endl;
      }


  return 0;
}
