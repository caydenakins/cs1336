// This program will output characters that will be converted to ASCII values (32 -> 126). We use
// a loop to iterate through the input characters, cycling up in value one by one until the lower
// value reaches the upper value.
#include <iostream>

using namespace std;

int main() {
  unsigned int lowerValue,
               upperValue;

  cout << "Enter lower and upper values" << endl;
  cin >> lowerValue;
  cin >> upperValue;

  // While loop that verifies if the range of the values the user entered is correct
  while ((upperValue > 126 || lowerValue > 126) || (upperValue < 32 || lowerValue < 32) || (lowerValue > upperValue)) {
    cout << "Values must be in range 32 to 126 inclusive" << endl;
    cout << "Enter lower and upper values" << endl;

    cin >> lowerValue;
    cin >> upperValue;
  }

  cout << "Characters for ASCII values between " << lowerValue << " and " << upperValue << endl;

  cout << "----+----+----+----+" << endl;

  // For loop that is responsible for checking the ASCII values in and converting the data type to
  // a character each time it prints.
  unsigned int asciiCharacter = lowerValue;
  for (; asciiCharacter <= upperValue; asciiCharacter++) {
    cout << char(asciiCharacter);
    if ((asciiCharacter - lowerValue) % 20 == 19) {   // To insert line break every 20 characters
      cout << endl;
    }
  }

  // If statement to make sure an addition line is printed if the modulus if function was not used
  // after the last character printed
  if (((asciiCharacter - lowerValue) % 20) != 0) {
    cout << endl;
  }

  cout << "----+----+----+----+" << endl;

  return 0;
}
