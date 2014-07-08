/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th Edition Chapter 2 Problem 12
 * Babylonian Algorithm
 * Created on July 2, 2014, 8:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime> 

using namespace std;

//Global Constant

//Function prototypes

//Execution

int main(int argc, char** argv) {
    //Declare variables
    float n,guess,r;
    
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));  
    
    //Input [10,121]
    n=rand()%120+11;
    
    //First Pass Babylonian Approximation
    guess=n/2;
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output first pass results
    cout<<"Number to find the square root of = "
        <<n<<endl;
    cout<<"First pass guess = "<<guess<<endl;
    
    //Second Pass Babylonian Approximation
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output Second pass results
    cout<<"Second pass guess = "<<guess<<endl;
    
    //Third Pass Babylonian Approximation
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output Third pass results
    cout<<"Third pass guess = "<<guess<<endl;
    
    //Fourth Pass Babylonian Approximation
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output Fourth pass results
    cout<<"Fourth pass guess = "<<guess<<endl;
    return 0;
}

