// This will analyze the market of spools for a company. It will utilize multiple functions,
// pass by reference, and the `iomanip` library.
#include <iostream>
#include <iomanip>

using namespace std;

void read(int&, int&, double&);
void display(int, int, double, double);

int main() {
  int spoolsOrdered = 0,
      spoolsStock = 0;
  double spoolsPrice = 104.0,
         shippingCost = 12.99;

  // Call the read function that utilizes pass-by-reference to change values
  read(spoolsOrdered, spoolsStock, shippingCost);

  // Call the display function to complete the program
  display(spoolsOrdered, spoolsStock, shippingCost, spoolsPrice);

  return 0;
}

// Function used for tracking input and changing values with pass-by-reference
void read(int& ordered, int& stock, double& shipping) {
  cout << "Spools to be ordered" << endl;
  cin >> ordered;

  // Spools ordered input validation
  while (ordered < 1) {
    cout << "Spools order must be 1 or more" << endl;
    cout << "Spools to be ordered" << endl;
    cin >> ordered;
  }

  cout << "Spools in stock" << endl;
  cin >> stock;

  // Spools in stock input validation
  while (stock < 0) {
    cout << "Spools in stock must be 0 or more" << endl;
    cout << "Spools in stock" << endl;
    cin >> stock;
  }

  char test;
  cout << "Special shipping and handling (y or n)" << endl;
  cin >> test;

  // Shipping and handling input validation
  if (test == 'y') {
    cout << "Shipping and handling amount" << endl;
    cin >> shipping;

    // Shipping input validation
    while (shipping < 0) {
      cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
      cout << "Shipping and handling amount" << endl;
      cin >> shipping;
    }
  }
}

// Function used for our display
void display(int ordered, int stock, double shipping, double price) {
  // If the spools ordered are greater than or equal to the stock
  if (ordered >= stock) {
    cout << "Spools ready to ship: " << stock << endl;
    int backOrder = ordered - stock;
    cout << "Spools on back-order: " << backOrder << endl;
    cout << "Subtotal ready to ship: $" << setprecision(2) << setw(10) << fixed << (stock * price) << endl;
    cout << "Shipping and handling:  $" << setprecision(2) << setw(10) << fixed << (stock * shipping) << endl;
    cout << "Total shipping charges: $" << setprecision(2) << setw(10) << (stock * price) + (stock * shipping) << endl;
  }

  // If the spools ordered are less than the stock
  if (ordered < stock) {
      cout << "Spools ready to ship: " << ordered << endl;
      cout << "Spools on back-order: 0" << endl;

      cout << "Subtotal ready to ship: $" << setprecision(2) << setw(10) << fixed << (ordered * price) << endl;

      cout << "Shipping and handling:  $" << setprecision(2) << setw(10) << fixed << (ordered * shipping) << endl;

      cout << "Total shipping charges: $" << setprecision(2) << setw(10) << (ordered * price) + (ordered * shipping) << endl;
  }
}
