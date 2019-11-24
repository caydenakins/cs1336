#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
  const int ARRAY_NUMBER = 20;
  char student[ARRAY_NUMBER] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
  char answers[ARRAY_NUMBER] = { 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'D', 'D', 'D', 'D', 'A', 'B', 'C', 'D' };
  int count = 0,
      correct = 0,
      incorrect = 0,
      total;
  double grade;

  // for (int i = 0; i < ARRAY_NUMBER; i++) {
  //   if (student[i] == answers[i])
  //     correct++;
  //
  //   if (student[i] != answers[i]) {
  //     incorrect++;
  //     cout << "Question " << (i + 1) << " has incorrect answer \'" << student[i] << "\', the correct answer is \'" << answers[i] << "\'" << endl;
  //   }
  // }


  // sizeof(array)

  while (student[count] != '\0') {
    if (student[count] == answers[count])
      correct++;

    if (student[count] != answers[count]) {
      incorrect++;
      cout << "Question " << (count + 1) << " has incorrect answer \'" << student[count] << "\', the correct answer is \'" << answers[count] << "\'" << endl;
    }
    count++;
  }

  // total = correct + incorrect;
  // grade = (static_cast<double>(correct) / total) * 100;
  //
  // cout << incorrect << " questions were missed out of " << total << endl;
  // cout << "The student grade is " << setprecision(1) << fixed << grade << "%." << endl;
  // if (grade < 70)
  //   cout << "The student failed" << endl;

  return 0;
}
