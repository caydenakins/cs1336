// This program will take a set of inputs from the user, converting them to different temperatures,
// displaying fahrenheit, celsius, and kelvin values. It does so by using a for loop and math
// conversions inside the for loop.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double startValue, endValue, incrementValue, temperatureOutput, fahrenheit, celsius, kelvin;

  cin >> startValue;
  cin >> endValue;
  cin >> incrementValue;

  // Input validation to check if the number is within the given range
  while (startValue > endValue || incrementValue <= 0) {
    cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
    cin >> startValue;
    cin >> endValue;
    cin >> incrementValue;
  }

  // First line of output that will be presented to show the categories of the output
  cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << setw(18) << "Kelvin" << endl;

  // For loop begins that will iterate as many times as needed based on the increment, starting,
  // and ending values
  for (temperatureOutput = startValue; temperatureOutput <= endValue; temperatureOutput += incrementValue) {
    // Conversions/assignments for temperatures to correct the value for output
    fahrenheit = temperatureOutput;
    celsius = (temperatureOutput - 32) / 1.8;
    kelvin = celsius + 273.15;



    // Fahrenheit output
    cout << setprecision(4) << fixed << setw(18) << fahrenheit;

    // Celsius output
    cout << setprecision(4) << fixed << setw(18) << celsius;

    // // Kelvin output
    cout << setprecision(4) << fixed << setw(18) << kelvin << endl;
  }

  return 0;
}
