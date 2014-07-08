/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 3 Problem 15
 * Buoyancy
 * Created on July 6, 2014, 7:18 PM
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
    const float Y=62.4, PI=4.0*atan(1.0);
    float radius, weight, volume, b_force;
    
    cout<<"Find out whether or not the sphere will sink or float.\n"<<"\n";
    
    //Inputs
    
    cout<<"Enter radius of sphere, in feet:";
    cin>>radius;
    cout<<"\n";
    cout<<"Enter weight of sphere, in pounds:";
    cin>>weight;
    cout<<"\n";
    
    //Calculations
    volume=4*(pow(radius,3)*PI)/3;
    b_force=volume*Y;
    
    //Output
    if (b_force>=weight)
    {
        cout<<"At a volume of "<<volume<<" the sphere will float\n";
    }
    else
    {
        cout<<"At a volume of "<<volume<<" the sphere will sink\n";  
    }
    return 0;
}

