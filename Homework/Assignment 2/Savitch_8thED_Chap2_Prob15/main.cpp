/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on July 2, 2014, 10:49 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare Variables
    float velocity, start_temp, end_temp;
    
    //Input Temperatures
    cout<<"Enter starting temperature:\n";
    cin>>start_temp;
    cout<<"Enter ending temperature:\n";
    cin>>end_temp;
    //Output velocity
    start_temp=-273;
    while (start_temp!=end_temp)
    {
        cout<<"At "<<start_temp<<" degrees Celsius the velocity of sound in "<<velocity<<" m/s\n";
        start_temp=start_temp+1;
        
        velocity=331.3+.61*start_temp;
    }
    return 0;
}

