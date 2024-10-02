#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

int main() {
  double userInput;
  cout << "Enter a number: ";
  cin >> userInput;

  if (cin.fail()){
    cout << "Invalid Data, input was not a number!\n";
    cin.clear(); // clear error flag
    cin.ignore(INT_MAX, '\n'); // clear wrong input
  }
  else {
    cout << "Input is Valid...!!! Hurray!!!";
    // Range Check
    if (userInput >= 1 && userInput < 100){
      cout << "Number is within range" << endl;
    }
    else{
      cout << "Number is Out-Of-Range" << endl;
    }
  }
  cout << "Program Ended" << endl;
}
