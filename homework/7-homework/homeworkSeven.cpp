/* CS1336 - Geometry Program
     Name  : Cayden Akins
     NetID : CRA190000
     Date  : 10/16/19
*/
// This program will take a user input in degrees and convert it to radians. It uses the math header
// to include the sin() and cos() functions. With the radian values the program receives, it
// calculates 6 trig functions at that radian value and displays them in a tabular format.
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  const double pi = 3.1415926535897932384;
  double radians,
         degrees,
         sine,
         cosine,
         secant,
         cosecant,
         tangent,
         cotangent,
         radiansConversion = pi / 180;

  // Do while function to prompt the user at least one time, continuing to prompt until a negative
  // value is reached.
  do {
  cout << "Enter an angle (in degrees): " << endl;
  cin >> degrees;
  cout << endl;

  // Conversions for all trig values for outputs
  radians = degrees * radiansConversion;
  sine = sin(radians);
  cosine = cos(radians);
  secant = 1 / cos(radians);
  cosecant = 1 / sin(radians);
  tangent = sin(radians) / cos(radians);
  cotangent = cos(radians) / sin(radians);


  // Split up output lines for readability

  // Top categories in tabular format
  cout << setw(15) << "Degrees" << setw(15) << "Radians";
  cout << setw(15) << "Sine" << setw(15) << "Cosine";
  cout << setw(15) << "Secant" << setw(15) << "Cosecant";
  cout << setw(15) << "Tangent" << setw(15) << "Cotangent" << endl;

  // Bottom categories for displaying the values from calculations
  cout << setw(15) << setprecision(4) << degrees;
  cout << setw(15) << setprecision(4) << radians;
  cout << setw(15) << setprecision(4) << sine;
  cout << setw(15) << setprecision(4) << cosine;
  cout << setw(15) << setprecision(4) << secant;
  cout << setw(15) << setprecision(4) << cosecant;
  cout << setw(15) << setprecision(4) << tangent;
  cout << setw(15) << setprecision(4) << cotangent;

  cout << endl;
  cout << endl;

  } while (degrees >= 0);

  return 0;
}
