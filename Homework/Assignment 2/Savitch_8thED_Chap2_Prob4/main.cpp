/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th Edition Chapter 2 Problem 4
 * New Retroactive Salary
 * Created on July 2, 2014, 11:29 AM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare Variables
    const float pay_increase=.076;
    float previous_annual_salary, new_annual_salary, new_monthly_salary, retroactive_pay, 
            retroactive_pay_any_months, months_of_retro_pay;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //Input Previous Annual Salary
    cout<<"Enter employee's previous salary, in dollars, and press Return:\n";
    cin>>previous_annual_salary;
    //Retroactive pay due to employee
    retroactive_pay=((previous_annual_salary*(1+pay_increase))/2);
    cout<<"Retroactive pay due to employee:\n"<<retroactive_pay<<endl;
    //Output New Salary
    new_annual_salary=previous_annual_salary*(1+pay_increase);
    cout<<"Employee's new Annual Salary is:\n"<<"$"<<new_annual_salary<<endl;
    //Output new Monthly Salary
    new_monthly_salary=new_annual_salary/12;
    cout<<"Employee's new Monthly Salary is:\n"<<"$"<<new_monthly_salary<<endl;
    //Output retroactive pay for any number of months
    cout<<"Enter number of months for retroactive pay:\n";
    cin>>months_of_retro_pay;
    retroactive_pay_any_months=new_monthly_salary*months_of_retro_pay;
    cout<<"Retroactive pay for any number of months:\n"<<retroactive_pay_any_months<<endl;
    return 0;
}

