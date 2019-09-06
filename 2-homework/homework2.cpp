#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  //Define ticket variables
  int aPrice, bPrice, cPrice;
  double aAmount, bAmount, cAmount, aIncome, bIncome, cIncome, totalIncome, averageIncome;

  //Ticket prices
  aPrice = 13;
  bPrice = 11;
  cPrice = 7;

  //User input section
  cout << "How many tickets in Class A were sold?" << endl;
  cin >> aAmount;

  cout << "How many tickets in Class B were sold?" << endl;
  cin >> bAmount;

  cout << "How many tickets in Class C were sold?" << endl;
  cin >> cAmount;

  //Math calculations
  aIncome = aAmount * aPrice;
  bIncome = bAmount * bPrice;
  cIncome = cAmount * cPrice;
  totalIncome = aIncome + bIncome + cIncome;
  averageIncome = totalIncome / 3;

  //Output statements
  cout << endl;
  cout << "Calculating..." << endl;
  cout << endl;
  cout << "Income per ticket:" << endl;
  cout << "Class A: $" << aIncome << endl;
  cout << "Class B: $" << bIncome << endl;
  cout << "Class C: $" << cIncome << endl;

  cout << endl;

  cout << "Total ticket sale income: $" << totalIncome << endl;

  cout << endl;

  cout << fixed << setprecision(2) << "Average income per ticket: $" << averageIncome << endl;

  return 0;
}
