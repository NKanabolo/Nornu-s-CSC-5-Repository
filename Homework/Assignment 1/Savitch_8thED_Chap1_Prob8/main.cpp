/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch Chapter 1 Problem 8
 * Quarters, Dimes, and Nickels
 * Created on June 29, 2014, 12:42 PM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    int number_of_quarters, number_of_nickels, number_of_dimes, Monetary_worth_Quarters, Monetary_worth_Nickels, Monetary_worth_Dimes, Total_Monetary_Worth;
    cout<<"Press return after entering number.\n";
    cout<<"Enter number of Quarters\n";
    cin>>number_of_quarters;
    cout<<"Enter number of Nickels\n";
    cin>>number_of_nickels;
    cout<<"Enter number of Dimes\n";
    cin>>number_of_dimes;
    
    Monetary_worth_Quarters=number_of_quarters*25;
    Monetary_worth_Nickels=number_of_nickels*5;
    Monetary_worth_Dimes=number_of_dimes*10;
    Total_Monetary_Worth=Monetary_worth_Quarters+Monetary_worth_Nickels+Monetary_worth_Dimes;
    
    cout<<"If you have ";
    cout<<number_of_quarters;
    cout<<"quarters, ";
    cout<<number_of_nickels;
    cout<<"nickels, and ";
    cout<<number_of_dimes;
    cout<<"dimes then,\n";
    cout<<"you have ";
    cout<<Total_Monetary_Worth;
    cout<<"cents";       
    return 0;
}

