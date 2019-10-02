#include <iostream>

using namespace std;

int main() {
  int value;
  double totalValue;

  for (int i = 1; i <= 7; i++) {
    cout << "Enter a number to be calculated over a 7 value total: " << endl;
    cin >> value;

    totalValue += value;
  }

  cout << "The total of the values is: " << totalValue << endl;

}
