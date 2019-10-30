// This program will use multiple functions to calculate the change in value of money with interest
// and years. Three of the functions are used for reading, one is for final calculations, one is
// for calling them, and one is for displaying calculations and information.
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function prototype definitions so we can order them after main
double futureValue();
double annualInterest();
int totalYears();
double presentValue(double, double, int);
void displayResults(double, double, double, int);

int main() {
  double getFutureValue;
  getFutureValue = futureValue();

  double getAnnualInterest;
  getAnnualInterest = annualInterest();

  int getTotalYears;
  getTotalYears = totalYears();

  double getPresentValue;
  getPresentValue = presentValue(getFutureValue, getAnnualInterest, getTotalYears);

  displayResults(getPresentValue, getFutureValue, getAnnualInterest, getTotalYears);

  return 0;
}

// Function used to return the future value input
double futureValue () {
  double futureValueInput;

  cout << "Enter future value" << endl;
  cin >> futureValueInput;

  // Input validation
  while (futureValueInput <= 0) {
    cout << "The future value must be greater than zero" << endl;
    cout << "Enter future value" << endl;
    cin >> futureValueInput;
  }

  return futureValueInput;
}

// Function to return the annual interest input
double annualInterest() {
  double annualInterestInput;

  cout << "Enter annual interest rate" << endl;
  cin >> annualInterestInput;

  // Input validation
  while (annualInterestInput <= 0) {
    cout << "The annual interest rate must be greater than zero" << endl;
    cout << "Enter annual interest rate" << endl;
    cin >> annualInterestInput;
  }

  annualInterestInput = annualInterestInput / 100;

  return annualInterestInput;
}

// Function used to return the total years input
int totalYears() {
  int totalYearsInput;

  cout << "Enter number of years" << endl;
  cin >> totalYearsInput;

  // Input validation
  while (totalYearsInput <= 0) {
    cout << "The number of years must be greater than zero" << endl;
    cout << "Enter number of years" << endl;
    cin >> totalYearsInput;
  }

  return totalYearsInput;
}

// Function used to calculate the present value
double presentValue(double futureValue, double interestRate, int numberYears) {
  double presentValue = futureValue / (pow((1 + interestRate), numberYears));

  return presentValue;
}

void displayResults(double presentValue, double futureValue, double interestRate, int numberYears) {
  interestRate *= 100;

  cout << "Present value: $" << setprecision(2) << fixed << presentValue << endl;
  cout << "Future value: $" << setprecision(2) << fixed << futureValue << endl;
  cout << "Annual interest rate: " << setprecision(3) << interestRate << "%" << endl;
  cout << "Years: " << numberYears << endl;
}
