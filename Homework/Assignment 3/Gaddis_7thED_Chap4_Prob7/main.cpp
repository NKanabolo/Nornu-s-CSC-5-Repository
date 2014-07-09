/* 
 * File:   main.cpp
 * Author: NornubariKanabolo
 * Gaddis 7th Edition Chapter 4 Problem 7
 * Seconds and Days
 * Created on July 7, 2014, 2:16 PM
 */

//User Defined Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare variables
    const int SECOND_MIN = 60;
    const int SECOND_HR = 3600;
    const int SECOND_DAY = 86400;
    //Input
    int seconds;
    cout<<"Enter a number in seconds: ";
    cin>>seconds;
    cout<<endl;
    //Output
    cout<<fixed;
    if (seconds >= SECOND_DAY)
        cout<<"There are "<<(seconds/SECOND_DAY)<<" days ";
    else if (seconds >= SECOND_HR)
        cout<<"There are "<<(seconds/SECOND_HR)<<" hours ";
    else if (seconds >= SECOND_MIN)
        cout<<"There are "<<(seconds/SECOND_MIN)<<" minutes ";
    return 0;
}

