// Calculate the users age using conditional statements and checking if it's the users birthday or not, as well as determining whether or not a special user is behind the keyboard
#include <iostream>

using namespace std;

int main() {
  int birthYear, birthMonth, birthDay;                    // User's birthday values
  int currentYear, currentMonth, currentDay;              // Current date values
  int yearCalculation, monthCalculation, dayCalculation;  // Calculation values
  int daysInMonths;                                       // Calculation for varying days in months
  bool birthdayChecker;                                   // Boolean to check for birthdays
  bool elHombre;                                          // Special boolean for eso hombre

  // Receiving inputs to later use for calculations
  cout << "Enter the year you were born in: " << endl;
  cin >> birthYear;
  cout << endl;

  cout << "Enter the month you were born in (number): " << endl;
  cin >> birthMonth;
  cout << endl;

  cout << "Enter the day you were born on (number): " << endl;
  cin >> birthDay;
  cout << endl;

  cout << "Enter the current year: " << endl;
  cin >> currentYear;
  cout << endl;

  cout << "Enter the current month (number): " << endl;
  cin >> currentMonth;
  cout << endl;

  cout << "Enter the day (number): " << endl;
  cin >> currentDay;
  cout << endl;

  // Month conversions for age in days
  if (birthMonth == 1) {
    daysInMonths = 31;
  }
  else if (birthMonth == 2) {
    daysInMonths = 28;
  }
  else if (birthMonth == 3) {
    daysInMonths = 31;
  }
  else if (birthMonth == 4) {
    daysInMonths = 30;
  }
  else if (birthMonth == 5) {
    daysInMonths = 31;
  }
  else if (birthMonth == 6) {
    daysInMonths = 30;
  }
  else if (birthMonth == 7) {
    daysInMonths = 31;
  }
  else if (birthMonth == 8) {
    daysInMonths = 31;
  }
  else if (birthMonth == 9) {
    daysInMonths = 30;
  }
  else if (birthMonth == 10) {
    daysInMonths = 31;
  }
  else if (birthMonth == 11) {
    daysInMonths = 30;
  }
  else if (birthMonth == 12) {
    daysInMonths = 31;
  }

  // Year calculations for current age
  if (currentMonth < birthMonth) {
    yearCalculation = (currentYear - birthYear) - 1;
  }
  else if (currentMonth > birthMonth) {
    yearCalculation = currentYear - birthYear;
  }

  // Month calculations for current age
  if (currentMonth == birthMonth) {
    monthCalculation = 0;
  }
  else if (currentMonth < birthMonth && currentDay > birthDay) {
    monthCalculation = (12 - birthMonth) + currentMonth;
  }
  else if (currentMonth < birthMonth && currentDay < birthDay) {
    monthCalculation = ((12 - birthMonth) + currentMonth) - 1;
  }
  else if (currentMonth > birthMonth && currentDay > birthDay) {
    monthCalculation = (currentMonth - birthMonth);
  }
  else if (currentMonth > birthMonth && currentDay < birthDay) {
    monthCalculation = (currentMonth - birthMonth) - 1;
  }

  // Day calculations for current age
  if (currentDay < birthDay) {
    dayCalculation = (daysInMonths - birthDay) + currentDay;
  }
  else if (currentDay > birthDay) {
    dayCalculation = currentDay - birthDay;
  }

  // Birthday checker boolean
  if (currentDay == birthDay && currentMonth == birthMonth) {
    birthdayChecker = true;
  }

  // Birthday checker happy birthday message
  if (birthdayChecker == true) {
    cout << "**********************************************************" << endl;
    cout << "* It appears today is your birthday! Happy birthday~  :) *" << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
  }

  // Check if el hombre is present
  if ((birthYear == 1971) && (birthMonth == 9) && (birthDay == 14)) {
    elHombre = true;
  }

  // El hombre presentation
  if (elHombre == true) {
    cout << "---------------------SPECIAL  MESSAGE---------------------" << endl;
    cout << endl;
    cout << "**********************************************************" << endl;
    cout << "*     It also appears the current user is the father     *" << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "I hope you enjoyed my little program I created thus far." << endl;
    cout << endl;
    cout << endl;
    cout << "It's not often I take a step back and view the big picture, but when I actually do, it really is insightful. It's always been hard for me to realize the privilege I've had growing up until I view it from the outside. I've never really understood how grateful I should be to have a father figure in my life, as some people are not fortunate enough to have one, and in addition to that, a good father figure. You (and mom) constantly motivate me to chase after whatever my heart desires, promising to support me along the way, something I now realize not everyone can say. I've always felt like you guys were there, even if I tend to get distant at times. Even if I don't say the L word as much as other kids might, I definitely love you, mom, and my brothers more than words can describe." << endl;
    cout << endl;
    cout << "You (and mom, of course) have seriously made me into the person (not man, I'm not there yet) I am today. Thank you for all the things you have done and opportunities you have helped create for me in all 18 years of my life. You serve as a tremendous role model to me and to the other brothers, I'm certain. There are many qualities in you that I hope to possess one day." << endl;
    cout << endl;
    cout << "Happy birthday, Dad. I wish I could be there with you, but I hope it's an amazing day regardless! I'll see you soon." << endl;
    cout << endl;
    cout << endl;
    cout << "Now here's the birthday calculation because I'm not going to let these if statements and big brain math go to waste: " << endl;
    cout << endl;
    cout << endl;
  }

  // Age calculation output to screen
  cout << "You are " << yearCalculation << " years old, " << monthCalculation << " months old, and " << dayCalculation << " days old!" << endl;

  return 0;
}
