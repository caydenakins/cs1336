#include <iostream>

using namespace std;

int main() {
  const int SIZE = 10;
  int array[SIZE] = { 82, 84, 90, 93, 78, 62, 99, 98, 91, 73 };
  int value = 99;

  // LINEAR SEARCH
  int index = 0;
  int position = -1;
  bool found = false;

  while (!found && index < SIZE) {
    if (array[index] == value) {
      found = true;
      position = index;
    }
    index++;
  }

  // BINARY SEARCH
  int first = 0,
      last = SIZE - 1,
      middle;
  bool found = false;
  int position = -1;

  while (!found && first <= last) {
    middle = (first + last) / 2;
    if (array[middle] == value) {
      found = true;
      position = middle;
    }
    else if (array[middle] > value)
      last = middle - 1;
    else
      first = middle + 1;
  }

  // BUBBLE SORT
  int maxElement, index;

  for (maxElement = SIZE - 1; maxElement > 0; maxElement--) {
    for (index = 0; index < maxElement; index++) {
      if (array[index] > array[index + 1]) {
        int temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
      }
    }
  }

  //BUBBLE SORT - RAZO VERSION (n^2)
  int data[] = { 2, 6, 3, 8 };
  bool swap = false;
  int size = sizeof(data) / sizeof(data[0]);

  do {
    swap = false;
    for (int i = 0; i < arraySize - 1; i++) {
      if (data[i] > data[i + 1]) {
        int temp = data[i];
        int data[i] = data[i + 1];
        int data[i + 1] = int temp;
        swap = true;
      }
    }
  } while (swap)

  // SELECTION SORT
  int minValue, minIndex;

  for (int start = 0; start < SIZE - 1; start++) {
    minValue = array[start];
    minIndex = start;
    for (int index = start + 1; index < SIZE; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    int temp = array[minIndex];
    array[minIndex] = array[start];
    array[start] = temp;
  }

  return 0;
}
