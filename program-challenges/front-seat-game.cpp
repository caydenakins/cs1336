#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main() {
  int randomNumber;
  char confirmRandomization = 'y';

  do {
    cout << "Enter 'y' to start the program or 'n' to exit the program." << endl;
    cin >> confirmRandomization;

    srand(time(0));
    randomNumber = rand() % 4 + 1;

    if (confirmRandomization == 'y') {
      if (randomNumber == 1) {
        cout << "Front seat: Erin" << endl;
      }
      else if (randomNumber == 2) {
        cout << "Front seat: Sanjay" << endl;
      }
      else if (randomNumber == 3) {
        cout << "Front seat: Ankha" << endl;
      }
      else if(randomNumber == 4) {
        cout << "Front seat: Colton" << endl;
      }
    }
  } while (confirmRandomization != 'n');

  cout << "Exiting..." << endl;

  return 0;


}
