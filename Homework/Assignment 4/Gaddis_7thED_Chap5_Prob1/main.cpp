/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis 7th EDition Chapter 5 Problem 2
 * Sum Numbers
 * Created on July 11, 2014, 8:58 PM
 */

#include <iostream>

using namespace std;

//Global COnstants

//Function Prototypes

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int numb;//Integer to sum
    unsigned int sum = 0;//The sum
    
    //Do-while loop
    do
    {
        cout<<"Please enter an integer of 1 or greater: ";
        cin>>numb;//Input
    }while(numb<1);

    //Sum to the given integer
    for(numb;numb>=1;numb--)
        sum+=numb;

    //Output result
    cout<<"The sum is: "<<sum<<endl;
    return 0;
}

