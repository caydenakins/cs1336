// This program will take input from a user and assist in providing calculations about the stock purchased and what kind of costs, income, net gain/loss, and more were run into along the way
// The code includes a few different blocks of code and functions in the order as follows: one section defining variables, one getting user input, one calculating, and one for displaying
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
  string companyName;
  int stockShares;
  static double COMMISSION = 0.035;   // Static commission percentage (3.5%) because it will not change
  double purchasePrice,               // Variables in first section of output
         stockCost,
         commissionCostPurchase,
         totalCost;
  double salePrice,                   // Variables in second section of output
         stockIncome,
         commissionCostSale,
         totalIncome;
  double netGainLoss;                 // Variables in third section of output



  // Block of code that will retrieve the data from the user to use in later calculations that include the cost of purchasing stock, commission for purchasing, income gained from the stock, commission for selling, total income from selling, and net gain or loss.
  cout << "Enter the name of the company" << endl;
  getline(cin, companyName);

  cout << "Enter shares of stock" << endl;
  cin >> stockShares;

  cout << "Enter purchase price" << endl;
  cin >> purchasePrice;

  cout << "Enter sale price" << endl;
  cin >> salePrice;

  cout << endl;

  // Calculations that are required to display information the user requests
  stockCost = purchasePrice * stockShares;
  commissionCostPurchase = stockCost * COMMISSION;
  totalCost = stockCost + commissionCostPurchase;

  stockIncome = salePrice * stockShares;
  commissionCostSale = stockIncome * COMMISSION;
  totalIncome = stockIncome - commissionCostSale;

  netGainLoss = totalIncome - totalCost;

  // Set of display/print statements that will be showing and formatting the information we processed in earlier calculations
  cout << setprecision (2) << fixed << showpoint;   // Format the decimal output for money

  cout << "Company: " << companyName << endl;
  cout << "Shares: " << stockShares << endl;
  cout << endl;

  cout << "Purchase/share: $" << purchasePrice << endl;
  cout << "Cost of stock: $" << stockCost << endl;
  cout << "Cost of commission: $" << commissionCostPurchase << endl;
  cout << "Total cost: $" << totalCost << endl;
  cout << endl;

  cout << "Sale/share: $" << salePrice << endl;
  cout << "Income from stock: $" << stockIncome << endl;
  cout << "Cost of commission: $" << commissionCostSale << endl;
  cout << "Total income: $" << totalIncome << endl;
  cout << endl;

  cout << "Gain or loss: $" << netGainLoss << endl;

  return 0;
}
