/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 3 Problem 2
 * Interest Payment on Credit Card
 * Created on July 6, 2014, 3:26 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout<<"Calculate the amount due, interest due, and minimum "
                    <<"payment due for an account with a given balance.\n\n";
    //Declare variables
    const float INTEREST_THOUS = 1.5e-2;//Interest up to $1000
    const float INTEREST_OVER = 1e-2;//Interest over $1000
    const float PAY_MULT = 1e-1;//Payment multiplier
    float CURRENCY_PCN;
    const int DUE_THRESH = 10;//Due threshold
    const int BAL_THRESH = 1000;//Balance threshold for normal interest
    
    //Input
    float balance;//Balance on the account
    //Output
    float interest_due;//Interest due
    float total_due;//Total due
    float min_pay;//Minimum payment
    char cont = 'y';//Condition to keep running the program
    //Program loop
    while (cont == 'y' || cont == 'Y') {
        //Get balance from user
        cout<<"What is the balance for your account?: $";
        cin>>balance;
        //Calculate interest due
        interest_due = balance * INTEREST_THOUS; //Interest on first $1000
        if (balance >= BAL_THRESH) //Is the balance greater than $1000?
            interest_due += ((balance - BAL_THRESH) * INTEREST_OVER); //Interest on the rest
        //Calculate total amount due
        total_due = balance + interest_due;
        //Calculate minimum payment
        if (total_due <= DUE_THRESH)
            min_pay = total_due;
        else
            min_pay = total_due * PAY_MULT;
        //Currency Output
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(CURRENCY_PCN);
        //Output result
        cout<<"Balance:          $"<<balance<<endl;
        cout<<"Interest due:     $"<<interest_due<<endl;
        cout<<"Total amount due: $"<<total_due<<endl;
        cout<<"Minimum payment:  $"<<min_pay<<endl;
        //Repeat the calculation?
        cout<<"Would you like to repeat the calculation?\n";
        cout<<"If yes, enter y: ";
        cin>>cont;
                }
    return 0;
}

