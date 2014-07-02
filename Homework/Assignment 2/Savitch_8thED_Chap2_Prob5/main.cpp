/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th Edition Chapter 2 Problem 5
 * Loans and Interest
 * Created on July 2, 2014, 12:55 PM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare Variables
    double customer_need, interest_rate, duration_of_loan, face_value, monthly_payment;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    //Input amount customer needs
    cout<<"Amount customer needs:\n";
    cin>>customer_need;
    //Input interest rate
    cout<<"Interest rate:\n";
    cin>>interest_rate;
    //Input duration of loan
    cout<<"Duration of loan:\n";
    cin>>duration_of_loan;
    //Output face value required
    cout.precision(2);
    face_value = customer_need / (1.0 - interest_rate*(duration_of_loan/12.0));
    cout<<"Face value required for customer to receive loan:\n"<<"$"<<face_value<<endl;
    //Output monthly payment
    monthly_payment=face_value/duration_of_loan;
    cout<<"Monthly payment on loan:\n"<<"$"<<monthly_payment<<endl;
    
    return 0;
}

