/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis 7th Edition Chapter 4 Problem 6
 * Weight of Object
 * Created on July 7, 2014, 12:16 PM
 */

//User Defined Libraries
#include <iostream>

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare variables
    const float EARTH_GRAV = 9.8;
    const int WEIGHT_MAX = 1000;
    const int WEIGHT_MIN = 10;
    //Input
    float mass; 
    float weight;
    cout<<"What is the mass of the , in kg?: ";
    cin>>mass;
    cout<<endl;
    //Calculate weight
    weight = mass * EARTH_GRAV;
    //Output
    cout<<"The weight of the object is: "<<weight<<" N\n";
    if (weight > WEIGHT_MAX)
    {
        cout<<"The object is too heavy!\n";
    }
    else 
    {
        cout<<"The object is too light!\n";
    }

    return 0;
}

