/*************************
Date created: July 4, 2022
Project number: 1
Context: I was doing the exercise 1.11 in Lippman's C++ Primer Textbook, "Write  a  program  that  prompts  the  
user  for  two  integers.Print each number in the range specified by those two integers," and I decided to I add a couple of 
features: (1) When the first number entered by the user is greater than the second number, the program will count backwards, 
starting from the first number up to the second. And (2), When the numbers entered by the user are the same (e.g., 10 10), 
the program will prompt the user that, "The numbers cannot be the same," the it will repeat the program again by calling
the main function.

*************************/

#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    if (num1 < num2){
        for (int i = num1; i <= num2; ++i){
            cout << i << endl;
        }
    } else if (num1 > num2){
        for (int i = num1; i >= num2; --i){
            cout << i << endl;
        }
    } else {
        cout << "The numbers cannot be the same." << endl;
        main();
    }
    return 0;
}
