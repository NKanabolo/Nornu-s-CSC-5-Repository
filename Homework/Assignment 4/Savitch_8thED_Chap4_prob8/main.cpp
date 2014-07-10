/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 4 Problem 8
 * Annual Tax on New House
 * Created on July 10, 2014, 3:13 PM
 */

#include <iostream>
#include <cmath>
using namespace std;

//Global Constants
bool repeatYN();

//Function Prototypes
float savetax(float int_pay, float tax_rate);//Calculate tax savings
float yrlyMort(int intl_bal, float int_pay);//Calculate annual mortgage
float int_pymnt(int intl_bal, float int_rate);//Calculate interest on payment

//Execution
int main(int argc, char** argv) {
    //Declare variables
    const float cnst_tax_rt = 3.5e-1f;//Marginal tax rate
    const float cnst_int_rt = 6e-2f;//Interest rate
    bool running = true;//Status of whether the program should continue running
    int intl_bal;//Initial loan balance
    float int_pay;//Interest payment
    //Inputs
    int dwn_pay;//Down payment on house
    int hou_cost;//The house cost
    //Output
    float annl_cost;//Total annual cost

    //Program loop
    while(running){
        //Get the house price and down payment from user
        cout<<"How much did the house cost?: ";
        cin>>hou_cost;
        cout<<"How much was the down payment?: ";
        cin>>dwn_pay;
        cout<<endl;

        //Calculations
        intl_bal = hou_cost-dwn_pay;//Calculate initial balance
        int_pay = int_pymnt(intl_bal, cnst_int_rt);//Calculate interest payments
        //Total after tax payment is total payment minus tax deductions
        annl_cost = yrlyMort(intl_bal, int_pay)-savetax(int_pay, cnst_tax_rt);

        //Output result
        cout<<"The total after tax cost for your new house for the first year is: $"<<annl_cost<<endl;

        //Re-run program
        cout<<"Do you want to repeat this calculation for another house?\n";
        running = repeatYN();
    }
    return 0;
}

float savetax(float int_pay, float cnst_tax_rt)
{
    return int_pay*cnst_tax_rt;
}

float int_pymnt(int princp, float cnst_int_rt)
{
    return (princp*cnst_int_rt);
}

float yrlyMort(int ln_bal, float int_pay)
{
    
    const float prcpl_cred = 3e-2f;//3% credit toward the principal
    return int_pay+(ln_bal*prcpl_cred);
}

bool repeatYN() {
    char usr_in;//User input
    //Run until there is a returned value
    while(true){
        //Get user input
        cout<<"Please enter Y/N: ";
        cin>>usr_in;
        switch(usr_in) {
            case('Y'):case('y'):
                return true;
                break;
            case('N'):case('n'):
                return false;
                break;
            default:
                cout<<"Invalid input.\n";
        }
    }
}