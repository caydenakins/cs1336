/*  CS1336 - Poker Program
     Name  : Cayden Akins
     NetID : CRA190000
     Date  : 11/11/2019
*/
// This program mimics a game of poker, dealing as many hands and shuffling
// as many times as the user desires. It utilizes multiple functions, sorting
// functions, and a lot of conditional structures.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

int input();
void shuffleDeck(int[], int, int);
void separate(int[], int, int[], int);
void sort(int[], int);
int select(int[], int[], int[], int, int, int);
void copy(int[], int[], int[], int, int);
void swap(int&, int&);
void count(int[], int, int&, int&, int&, int&, int&, int&, int&, int&, int&);
void display(int[], string[], int[], int);

int main() {
  int handsGenerated,
      timesShuffled,
      rankingCounter = 0;
  const int DECK_SIZE = 52,
            HAND_SIZE = 5,
            SUIT_SIZE = 4,
            MAX_SIZE = 10,
            TOTAL_RANKINGS = 9;
  int deck[DECK_SIZE] = { },
      handSelection[HAND_SIZE] = { },
      pairTester[HAND_SIZE] = { },
      suitTester[SUIT_SIZE] = { },
      handsRanking[MAX_SIZE] = { },
      rankingAmount[TOTAL_RANKINGS] = { };

  string rankingNames[TOTAL_RANKINGS] = { "Straight Flush", "Four of a Kind",
                                          "Full House", "Flush", "Straight",
                                          "Three of a Kind", "Two Pair",
                                          "One Pair", "High Card" };

  cout << "How many hands would you like to generate?" << endl;
  cin >> handsGenerated;

  // Input validation, making sure the user stays between (0 - 10) inclusive
  while (handsGenerated < 1 || handsGenerated > 10) {
    cout << endl;
    cout << "Please select a number greater than between 1 and 10 inclusive"
      << endl;
    cout << "How many hands would you like to generate?" << endl;
    cin >> handsGenerated;
  }

  // For-loop that will loop as many hands as the user generated
  for (int count = 0; count < handsGenerated; count++) {

    // Re-generate the deck every time we begin modifying a new hand
    for (int k = 0; k < DECK_SIZE; k++) {
      deck[k] = k;
    }

    timesShuffled = input();  // Get amount of times the user wants to shuffle

    shuffleDeck(deck, DECK_SIZE, timesShuffled);

    separate(deck, DECK_SIZE, handSelection, HAND_SIZE);

    sort(handSelection, HAND_SIZE);

    copy(handSelection, pairTester, suitTester, HAND_SIZE, SUIT_SIZE);

    int handType = select(handSelection, pairTester, suitTester, HAND_SIZE,
      SUIT_SIZE, rankingCounter);

    cout << "Hand " << count + 1 << " selected." << endl;
    cout << endl;

    handsRanking[count] = handType; // Assign hand rankings
    rankingAmount[handType - 1]++;  // Used later for running count in output
  }

  display(handsRanking, rankingNames, rankingAmount, handsGenerated);

  return 0;
}

// Function that will get the user's input for the amount of times they want
// the deck shuffled
int input() {
  int shuffleAmount = 0;

  cout << endl;
  cout << "How many times do you want to shuffle the deck?" << endl;
  cin >> shuffleAmount;

  // Input validation, making sure the user enters a number 0 or greater
  while (shuffleAmount < 0) {
    cout << endl;
    cout << "Please select a number greater than or equal to 0" << endl;
    cout << "How many times do you want to shuffle the deck?" << endl;
    cin >> shuffleAmount;
  }

  cout << endl;
  cout << "Shuffling the deck..." << endl;
  cout << endl;

  return shuffleAmount;
}

// Function that will take in a shuffle amount and shuffle the deck (mixing/
// replacing elements) that amount of times
void shuffleDeck(int deckArray[], int size, int shuffleValue) {
  srand(time(0));

  for (int i = 0; i < shuffleValue; i++) {
    int randomValueOne = rand() % 52;
    int randomValueTwo = rand() % 52;

    swap(deckArray[randomValueOne], deckArray[randomValueTwo]);
  }
}

// Function that takes the first 5 elements of the deck we shuffled, copies
// those elements, and puts them in a new array: the user's hand
void separate(int deckArray[], int deckSize, int userHand[], int handSize) {
  for (int i = 0; i < handSize; i++) {
    userHand[i] = deckArray[i];
  }
}

// Sorts the deck in ascending order to prepare for the select() function
void sort(int userHand[], int size) {
  int minIndex,
      minValue;

  for (int start = 0; start < (size - 1); start++) {
    minIndex = start;
    minValue = userHand[start];
    for (int index = start + 1; index < size; index++) {
      if (userHand[index] < minValue) {
        minValue = userHand[index];
        minIndex = index;
      }
    }
    swap(userHand[minIndex], userHand[start]);
  }
}

// Function that will be used to calculate the ranking of the user's hand
// containing multiple conditional structures
int select(int userHand[], int pairArray[], int suitArray[], int handTotal,
  int suitTotal, int count) {
  int handType = 0,
      pairCounter = 0;
  bool straightFlush = false,
       fourOfAKind = false,
       fullHouse = false,
       flush = false,
       straight = false,
       threeOfAKind = false,
       twoPair = false,
       onePair = false,
       highCard = false;

  // Flush tests block (We hard code/use element ID's 0, 1, 2, and 3 because we
  // know we have 4 different suits due to % 4 earlier and knowledge of cards)
  if (suitArray[0] == (suitArray[1] && suitArray[2] && suitArray[3]))
    flush = true;

  // Straight tests block
  if ((pairArray[0] + 1 ) == pairArray[1]) {
    if ((pairArray[1] + 1) == pairArray [2]) {
      if ((pairArray[2] + 1) == pairArray[3]) {
        if ((pairArray[3] + 1) == pairArray[4]) {
          straight = true;
        }
      }
    }
  }

  // Pair tests block (One pair, two pair, three of a kind, and four of a kind)
  for (int i = 0; i < handTotal; i++) {
    for (int k = 0; k < handTotal; k++) {
      if (i == k) {
        k++;
        if (i && k == 5) {
          break;
        }
      }
      if (pairArray[i] == pairArray[k]) {
        onePair = true;
        pairCounter++;
      }
    }
  }

  pairCounter /= 2;

  if (pairCounter == 1) {
    onePair = true;
  }

  else if (pairCounter == 2) {
    twoPair = true;
  }

  else if (pairCounter == 3) {
    threeOfAKind = true;
  }

  else if (pairCounter == 6) {
    fourOfAKind = true;
  }

  // If statement for straight flush
  if (flush && straight) {
    flush = false;
    straight = false;
    straightFlush = true;
  }

  // If statement for full house
  if (onePair && threeOfAKind) {
    onePair = false;
    threeOfAKind = false;
    fullHouse = true;
  }

  // If statement when none of the conditions apply, making it a high card
  // ranking (where we would choose the highest card, the last element in the
  // array due to our `sorting()` function earlier)
  if (!straightFlush && !fourOfAKind && !fullHouse && !flush && !straight &&
  !threeOfAKind && !twoPair && !onePair) {
    highCard = true;
  }

  // Code below assigns hand type to the user's generated hand
  if (straightFlush)
    handType = 1;

  else if (fourOfAKind)
    handType = 2;

  else if (fullHouse)
    handType = 3;

  else if (flush)
    handType = 4;

  else if (straight)
    handType = 5;

  else if (threeOfAKind)
    handType = 6;

  else if (twoPair)
    handType = 7;

  else if (onePair)
    handType = 8;

  else
    handType = 9;

  return handType;
}

// Function used to copy the user's hand array into the pair and suit arrays
void copy(int userOne[], int pairOne[], int suitOne[], int handAmount, int
  suitAmount) {
  int tempPair = 0,
      tempSuit = 0;
  bool oddCase = false;

  // Makes a copy of the user's hand array into the pair array, the array that
  // will check for one pair, two pair, three of a kind, and four of a kind
  for (int i = 0; i < 5; i++) {
    pairOne[i] = userOne[i];
    pairOne[i] = (pairOne[i] / 4) + 1;
  }

  // Makes a copy of the user's hand array into the suit array, the array that
  // will check for flushes
  for (int k = 0; k < 5; k++) {
    // Added this odd case condition for the exception when my pairOne[]
    // array was being changed for some reason after line 314 when k = 4 in
    // this for-loop
    if (k == 4 && pairOne[0] == 1) {
      oddCase = true;
    }

    suitOne[k] = userOne[k];

    if (oddCase && pairOne[0] != 1)
      pairOne[0] = 1;

    suitOne[k] = suitOne[k] % suitAmount;
  }
}

// Function we created to make it easier to swap two values, as we would be
// doing so multiple times throughout the program
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

// Function we use to display how many hands fall into each ranking and the
// percentages of total hands in each
void display(int rankings[], string names[], int totalRankings[],
             int handAmount) {
  double percentage = 0;

  cout << "Displaying results (Name, Occurrances, Percentage)..." << endl;
  cout << endl;

  // Top line of output
  cout << setw(37) << setfill('-') << "" << endl;

  for (int i = 0; i < 9; i++) {
    // Percentage calculation
    percentage = (totalRankings[i] / static_cast<double>(handAmount)) * 100;

    // If the percentage is 100.00%, it will mess up the output, so I used if
    // statements to fix (because I'm bad at manipulating my output)
    if (percentage == 100) {
      cout << setw(36) << setfill('.');
      cout << left << "|" << right << "|" << endl;

      cout << "|" << setw(18) << right << names[i] << "  " << totalRankings[i]
      << "  "  << setprecision(2) << fixed << percentage << left << "%" <<
      setw(6) << right << "|" << endl;

      cout << setw(36) << setfill('.');
      cout << left << "|" << right << "|" << endl;
    }

    // If the percentage is 10.00% or above, but less than 100.00%
    if (percentage >= 10 && percentage < 100) {
      cout << setw(36) << setfill('.');
      cout << left << "|" << right << "|" << endl;

      cout << "|" << setw(18) << right << names[i] << "  " << totalRankings[i]
      << "  "  << setprecision(2) << fixed << percentage << left << "%" <<
      setw(7) << right << "|" << endl;

      cout << setw(36) << setfill('.');
      cout << left << "|" << right << "|" << endl;
    }

    // If the percentage is less than 10.00% (basically 0.00%, since we only
    // allow 10 user-generated hands), we add more space
    if (percentage < 10) {
      cout << setw(36) << setfill('.');
      cout << left << "|" << right << "|" << endl;

      cout << "|" << setw(18) << right << names[i] << "  " << totalRankings[i]
      << "  "  << setprecision(2) << fixed << percentage << left << "%" <<
      setw(8) << right << "|" << endl;

      cout << setw(36) << setfill('.');
      cout << left << "|" << right << "|" << endl;
    }
  }

  // Bottom line
  cout << setw(37) << setfill('-')  << "" << endl;
}
