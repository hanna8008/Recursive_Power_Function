/*
Programmer: Hanna Zelis
Date: 18 November 2021
Program: Program 3 - Recursive Power Function
Filename: ZelisProgram3.cpp

Description: This program outputs the result of an integer to an integer value (power), where the two integer values will be given by the user 
            and solved by a recursive function. Before the function is called in the main function, the program checks to see if the input
            will cause an overflow or underflow. If either of these two things would occur with the user's input values, then the user is warned
            and asked to input different values. 

Assistance received from: Dr. Suchan (helped me check my output with certain integer values)

How to compile: g++ ZelisProgram3.cpp -o ZelisProgram3.out

How to execute: ./ZelisProgram3.out 
*/



#include <iostream>
#include <cmath>



using namespace std;



//prototype for the recursive function
int Repower (int, int);





int main()
{

   //telling the user what this program is and possible warnings
   cout << "Hello user," << endl;
   cout << "Today, you will be asked to input two integers (any whole number, no decimals)." << endl;
   cout << "The first input will be a, the number being raised to a power.";
   cout << "The second input will be b, the power that a will be raised too." << endl;
   cout << "Please do not type in any decimal places, only integers." << endl;
   cout << "If you would like to quit, please enter 0 when asked for a new a value." << endl;
   cout << endl;
   cout << "WARNING" << endl; 
   cout << "Due to computer limitations, there are two warnings: " << endl;
   cout << "1) Overflow: if the answer of your inputs exceeds a maximum value." << endl;
   cout << "2) Underflow: if the answer of your inputs exceeds a minimum value.";
   


   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;



   //variable declarations
   int a = 1, b;

  //while loop to continue asking the user to input numbers until they enter 0 to stop
   while (a != 0)
   {

      //asking the user for input and stopping the program if they enter 0 for a
      cout << "Enter a non-zero number for a (enter 0 to exit ): "; 
      cin >> a;

         if (a == 0)
            break;
               //stops the program

      cout << "Enter a non-negative number for b: ";
      cin >> b;



      //Will tell the user that their b input is incorrect
      if (b < 0)
      {
         cout << "Cannot take this number to a negative power." << endl;  
      
            cout << "Please re-enter b: ";
            cin >> b;
       }





     double overFlowWarning = pow(2, 31) - 1;
        //variable created whose range is more than the max 
        //        storage of an int so it can be determined 
        //        if the result of the ints would be greater than the int max value

     double underFlowWarning = pow(-2, 31);
        //variable created whose range is more than the min 
        //        storage of an int so it can be determined 
        //        if the result of the ings would be lower than the int min value





      //giving prior warning message to the user that their inputs will cause an overflow
      //      which is when the result is greater than max int value
      if (pow(a, b) > overFlowWarning)
       {
         cout << "Overflow Warning: your inputs will result in an overflow!" << endl;
         cout << "Please enter in new numbers." << endl;

         cout << endl;
         cout << endl;
       }
     




      //giving prior warning message to the user that their unputs will cause an underflow
      //      which is when the result is less then the min int value
      else if (pow(a,b) < underFlowWarning)
       {
         cout << "Underflow Warning: your inputs will result in an underflow!" << endl;
         cout << "Please enter in new numbers." << endl;

         cout << endl;
         cout << endl;

       }





      //outputs the result of Repower based on the user's values
      else 
      {
         cout << a << " to the power of " << b << " = " << Repower(a, b) << endl;

         cout << endl;
         cout << endl;

      }
   
   }


   return 0;
}








//definition for recursive function
int Repower (int a, int b)
{

   //calculate a to the b when b = 0
   if (b == 0)
      return 1;
           
   //calculate a to the b when b = 1
   if (b == 1)
      return a;

   //calculate a to the b when b > 1
   if (b > 1)
      return a * Repower(a, b - 1);

   return a * Repower(a, b - 1);

}
