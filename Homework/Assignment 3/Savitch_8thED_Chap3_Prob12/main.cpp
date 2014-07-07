/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 3 Problem 12
 * Approximate Value for Pi
 * Created on July 6, 2014, 4:44 PM
 */

//User Defined Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes

//Execution
int main(int argc, char** argv) {
    //Declare variables
    bool running = true;
    
    //Inputs
    int x_terms;
    char proceed;//If user wants to continue
    //Outputs
    float pi_aproxim;
    while(running) {
        //Starting approximation of pi
        pi_aproxim = 0;
        cout<<"Enter the number of terms you want to approximate pi with: ";
        cin>>x_terms;
        cout<<endl;    
        //Calculate (-1^n)/(2n+1), add it to pi,
        for(x_terms;x_terms>=0;x_terms--) {
            pi_aproxim+=(pow(-1,x_terms))/(2*x_terms+1);
        }
        
        pi_aproxim*=4;
        //Approximate value of pi
        cout<<"The approximate value of pi is: "<<pi_aproxim<<endl;
        
        //Run Again
        cout<<"Want to approximation pi again?\n";
        cout<<"If yes, press Y then Return: ";
        cin>>proceed;
        cout<<endl;
        running=(proceed=='Y'||proceed=='y'); 
    }
    return 0;
}

