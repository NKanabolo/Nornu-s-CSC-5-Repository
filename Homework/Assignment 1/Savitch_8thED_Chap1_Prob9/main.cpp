/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch Chapter 1 Problem 9
 * Free Falling Body
 * Created on June 29, 2014, 3:25 PM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution
int main(int argc, char** argv) {
    int Time, Distance;
    cout<<"Enter number of seconds\n";
    cin>>Time;
    Distance=(32*(Time*Time))/2;
    cout<<"If an object is falling for ";
    cout<<Time;
    cout<<" seconds then,\n";
    cout<<"it has fallen ";
    cout<<Distance;
    cout<<" feet.\n";
    return 0;
}

