/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on July 7, 2014, 9:51 AM
 */

//User Defined Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare Variables
    float a, b, c, d, x1, x2;
    char cont;
    //Inputs
    cout<<"A quadratic equation is given as: aX^2 + bX + c = 0\n";
    cout<<"Enter a: \n";
    cin>>a;
    cout<<"Enter b: \n";
    cin>>b;
    cout<<"Enter c: \n";
    cin>>c;
    
    //Calculations
    d=(b*b)-(4*a*c);
    if(d>=0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        cout<<"\nThe roots of the quadratic equation are : "<<x1<<" and "<<x2;
    }
    else
    {
    d=d*(-1);
    cout<<"The roots are imaginary!\n";
    cout<<"The roots of the quadratic equation are : " <<(-b/(2*a))<<" + "<<(sqrt(d)/(2*a))<<"i and "<<(-b/(2*a))<<" - "<<(sqrt(d)/(2*a))<<"i"<<endl;
    }    
    return 0;
}

