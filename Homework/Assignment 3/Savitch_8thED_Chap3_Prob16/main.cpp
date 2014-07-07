/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 3 Problem 16
 * Temperature:Fahrenheit and Celsius
 * Created on July 6, 2014, 10:43 PM
 */

//User defined Libraries
#include <iostream>

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare variables
    int celsius = 100; 
    //Output
    int fahrenheit;
    //Decrease Fahrenheit an Celsius until equal
    do {
    celsius--;
    fahrenheit = ((9*celsius)/5)+32;
    } 
    while(celsius!=fahrenheit);
    {
    cout<<"Celsius and Fahrenheit have the same temperature at: "
        <<celsius<<" degrees.\n";
    }
        return 0;

}
        


