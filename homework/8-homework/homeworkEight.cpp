/* CS1336 - Hotel Occupancy Program
     Name  : Cayden Akins
     NetID : CRA190000
     Date  : 10/23/2019
*/
// This program will calculate the total rooms in a hotel, occupied rooms, unoccupied rooms, and
// percentages of the rooms occupied. It includes the usage of if() and while() statements for
// input validation and multiple iterations required based on floors.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int totalFloors,
      baseFloor,
      roomsPerFloor,
      occupiedRooms,
      totalRooms = 0,
      totalOccupiedRooms = 0,
      totalUnoccupiedRooms = 0,
      percentageOccupied;

  cout << "How many floors does the hotel have?" << endl;
  cin >> totalFloors;
  cout << endl;

  // Input validation, assuring the user is not able to reach the if statement until a floor
  // greater than 0 is entered
  while (totalFloors < 1) {
    cout << "Please enter a floor number greater than 1 and try again." << endl;
    cout << "How many floors does the hotel have?" << endl;
    cin >> totalFloors;
  }

  // For loop to begin the process of iterating based on the amount of floors the user inputs
  for (baseFloor = 1; baseFloor <= totalFloors; baseFloor = (baseFloor == 12 ? baseFloor + 2 : baseFloor + 1)) {
    // Last step in for loop used to skip the 13th floor once we arrive
    // New submission due to replacing `if (baseFloor == 13) baseFloor = 14` with updated statement

    cout << "How many rooms are on floor " << baseFloor << "?" << endl;
    cin >> roomsPerFloor;
    cout << endl;

    // Rooms per floor input validation
    while (roomsPerFloor < 10) {
      cout << "Please enter a number of rooms that is greater than 10 and try again." << endl;
      cout << "How many rooms are on floor " << baseFloor << "?" << endl;
      cin >> roomsPerFloor;
      cout << endl;
    }

    cout << "How many of the " << roomsPerFloor << " are occupied?" << endl;
    cin >> occupiedRooms;
    cout << endl;

    // Occupied rooms input validation
    while (occupiedRooms > roomsPerFloor) {
      cout << "Please enter a number of occupied rooms less than or equal to " << roomsPerFloor << " and try again." << endl;
      cout << "How many of the " << roomsPerFloor << " are occupied?" << endl;
      cin >> occupiedRooms;
      cout << endl;
    }

    // Math used to calculate the totals at the end of each iteration, allowing them to be printed out
    // at any given time once we exit the loop
    totalRooms += roomsPerFloor;
    totalOccupiedRooms += occupiedRooms;
    totalUnoccupiedRooms += (totalRooms - totalOccupiedRooms);
    percentageOccupied = (static_cast<double>(totalOccupiedRooms) / totalRooms) * 100;

  }

  // Print statements that will be used for displaying the desired output
  cout << "Total rooms in the hotel: " << totalRooms << endl;
  cout << "Total occupied rooms in the hotel: " << totalOccupiedRooms << endl;
  cout << "Total unoccupied rooms in the hotel: " << totalUnoccupiedRooms << endl;
  cout << "Total percentage of rooms occupied: " << percentageOccupied << "%" << endl;

  return 0;
}
