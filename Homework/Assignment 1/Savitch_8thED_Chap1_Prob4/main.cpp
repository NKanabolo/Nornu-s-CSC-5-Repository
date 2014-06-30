/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch Chapter 1 Problem 4
 * Modification to Project 1
 * Addition sign instead of multiplication
 * Created on June 27, 2014, 1:16 PM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    int number_of_pods, peas_per_pod, total_peas;
    cout<<"Press return after entering a number.\n";
    cout<<"Enter the number of pods:\n";
    
    cin>>number_of_pods;
    cout<<"Enter number of peas in a pod.\n";
    cin>>peas_per_pod;
    total_peas=number_of_pods+peas_per_pod;
    cout<<"If you have ";
    cout<<number_of_pods;
    cout<<"pea pods.\n";
    cout<<"and ";
    cout<<peas_per_pod;
    cout<<" peas in each pod, then\n";
    cout<<"you have ";
    cout<<total_peas;
    cout<<" peas in all pods.\n";
    
    return 0;
}

