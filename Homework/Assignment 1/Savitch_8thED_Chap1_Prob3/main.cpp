/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch Chapter 1 Problem 3
 * Modification to Project 2
 * Division sign instead of multiplication
 * Created on June 27, 2014, 12:57 PM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    int number_of_pods, peas_per_pod, total_peas;
    cout<<"Hello\n";
    cout<<"Press return after entering a number.\n";
    cout<<"Enter the number of pods:\n";
    
    cin>>number_of_pods;
    cout<<"Enter number of peas in a pod.\n";
    cin>>peas_per_pod;
    total_peas=number_of_pods/peas_per_pod;
    cout<<"If you have ";
    cout<<number_of_pods;
    cout<<"pea pods.\n";
    cout<<"and ";
    cout<<peas_per_pod;
    cout<<" peas in each pod, then\n";
    cout<<"you have ";
    cout<<total_peas;
    cout<<" peas in all pods.\n";
    cout<<"Goodbye.\n";
    return 0;
}

