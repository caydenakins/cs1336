#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // Define essential variables, as well as set constant values to be used for later calculations
  int totalPeople;
  double sliceArea, pi, pizzaDiameter, pizzaRadius, pizzaArea, sliceAmount, requiredSlices, requiredPizzas;
  const double SLICE_AREA = 14.125;
  const double PI = 3.14159;

  // Obtain input values for finding out the slices per pizza and pizza amount required
  cout << "How many people are at the party?" << endl;
  cin >> totalPeople;
  cout << endl;

  cout << "What is the diameter of the pizza in inches?" << endl;
  cin >> pizzaDiameter;
  cout << endl;

  cout << "Calculating..." << endl;
  cout << endl;

  // Calculations to achieve the slices amount per pizza based on diameter and people given
  pizzaRadius = pizzaDiameter / 2;
  pizzaArea = PI * (pizzaRadius * pizzaRadius);
  sliceAmount = pizzaArea / SLICE_AREA;

  // Slice amount per pizza while meeting default slice area
  cout << "Amount of slices per pizza: " << fixed << setprecision(1) << sliceAmount << endl;
  cout << endl;

  // Calculations assuming each person desires four slices
  requiredSlices = totalPeople * 4;
  requiredPizzas = requiredSlices / sliceAmount;

  // Amount of pizzas required if everyone attending wants four slices
  cout << fixed << setprecision(1) << "Required pizzas if every person eats four slices: " << requiredPizzas << endl;

  return 0;
}
