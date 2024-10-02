#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(){
  //Declare Variables
  const int MAX_NUM = 9;
  int number1, number2, correctAns , studentAns;
  char studentName[10];

  // Initialize the random generator
  srand((unsigned int)time(NULL));

  // Generate the random numbers
  number1 = 1 + rand() % MAX_NUM;
  number2 = 1 + rand() % MAX_NUM;
  correctAns = number1 + number2;

  // cout << "Number1: " << number1 << endl;
  // cout << "Number2: " << number2 << endl;
  // **********************************************

  cout << "Welcome to the Math Tutor program!" << endl;
  cout << "Hi Student! Please enter your name: ";
  cin.getline(studentName, 10);
  cout << "Hi " << studentName << ". Let\'s do some Math!" << endl;
  cout << "What is " << Number1 << " + " << Number2 << " = ";
  cin >> studentAns;
  // Range Check
  if (studentAns >= 2 && studentAns <= 18){
    cout << "Your answer is within the range" << endl;
    if (fabs(studentAns-correctAns) == 0) {
      cout << "Your answer was correct" << endl;
    }
    else {
      cout << "Your answer was wrong" << endl;
    }
  }
  else {
    cout << "Out-Of-Range Answer!" << endl;
  }

  return 0;
}
