#include <iostream>
#include <cstdlib>
#include <ctime>

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

  cout << "Number1: " << number1 << endl;
  cout << "Number2: " << number2 << endl;

  return 0;
}
