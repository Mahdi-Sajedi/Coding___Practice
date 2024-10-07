// %cpp
// M4Coffee_Sajedi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int amount = 0; // based on examples, we only allow integer amounts 
    double ppp = 12.99, discount, total; //price per pound
    cout << "Enter Amount of coffee (in pounds): ";
    cin >> amount;

    // bunch of if/else to figure out the discount rate
    if (amount <= 0) {
        cout << "ERROR!........BYE!!"; // error message
        return 1; // if return missed -> error -> 'main':function must return a value
    }
    else if (amount < 5){
        discount = 0;
    }
    else if (amount <= 9) {
        discount = 0.05;
    }
    else if (amount <= 19) {
        discount = 0.10;
    }
    else if (amount <= 29) {
        discount = 0.15;
    }
    else {
        discount = 0.20;
    }

    // let's do the math 
    total = amount * ppp * (1 - discount);
    cout << fixed << setprecision(2) << "Your total is: $" << total << endl;
    return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
/**
Option 3: Use AWS Cloud9 IDE
If you're using AWS, Cloud9 is an IDE that supports multiple languages, including C++. You can directly paste and run C++ code there.

Option 2: Use Jupyter Notebook with xeus-cling (C++ Kernel)
If you are using a Jupyter Notebook environment with a C++ kernel installed (like xeus-cling), you can use:

%cpp
#include <iostream>
#include <iomanip>

// Your C++ code here

Option 1: Run in Google Colab with Shell Commands
To execute C++ code in Google Colab, you can use shell commands to compile and run the code. Add the following command on top of a cell:

%%shell
g++ -o M4Coffee_Sajedi M4Coffee_Sajedi.cpp
./M4Coffee_Sajedi
Then paste the C++ code in a subsequent cell, or upload it as a .cpp file, and refer to that file in the g++ command.
*/
