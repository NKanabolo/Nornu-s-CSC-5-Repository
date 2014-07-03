/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th Edition Chapter 2 Problem 7
 * Weekly Pay
 * Created on July 2, 2014, 2:24 PM
 */


#include <iostream>//User System Libraries
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    const float hr_rate=16.78, overtime_rate=1.5, social_security=.06, federal_income_tax=.14,
            state_income_tax=.05, union_dues_amount=10, health=35;
    float hr_week, hr_week_two, dependents, gross_pay, ss_tax, fed_itax, state_itax, net_tkhome, net_tkhome_two;
    //Input a max capacity in the keyboard
    cout<<"Enter number of hours worked per week:"<<endl;\
    cin>>hr_week;
    //Input number of dependents
    cout<<"Enter the number of dependents:"<<endl;\
    cin>>dependents;
    //Output gross pay
    gross_pay= hr_week*hr_rate;
    cout<<"Gross pay:\n"<<gross_pay<<endl;
    //Output Withheld amounts
    ss_tax=gross_pay*social_security;
    cout<<"Social Security tax amount:\n"<<ss_tax<<endl;
    fed_itax=gross_pay*federal_income_tax;
    cout<<"Federal Income tax amount:\n"<<fed_itax<<endl;
    state_itax=gross_pay*state_income_tax;
    cout<<"State Income tax amount deducted:\n"<<state_itax<<endl;
    //Output net take home pay
    
    if ((dependents>=3)&&(hr_week>=40))
    {
        hr_week_two=hr_week*(overtime_rate*hr_rate);
        net_tkhome=gross_pay-(ss_tax+fed_itax+state_itax+union_dues_amount+health);
        
        cout<<"An employee's take home income for "<<dependents<<" dependents and "<<hr_week<<" hours per week is "<<net_tkhome<<endl;
    }
        else
        {
        net_tkhome_two=gross_pay-(ss_tax+fed_itax+state_itax+union_dues_amount);
        cout<<"An employees take home income for "<<hr_week<<" hours per week is "<<net_tkhome_two<<endl;
        }
    return 0;
}

