/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis 7th Edition Chapter 4 Problem 4
 * Rectangles
 * Created on July 7, 2014, 12:55 PM
 */

//User Defined Libraries
#include <iostream>

using namespace std;

//Global Constants

//Function Prototypes

//Execution


int main(int argc, char** argv) {
    //Declare variables
    float length_1, length_2, width_1, width_2;
    float area_1, area_2;
    //Input
    cout<<"What are the dimensions of the first rectangle?\n";
    cout<<"Enter width, press spacebar, then length: ";
    cin>>width_1>>length_1;
    cout<<"What are the dimensions of the second rectangle?\n";
    cout<<"Enter width, press spacebar,then length: ";
    cin>>width_2>>length_2;
    cout<<endl;
    //Calculate Area
    area_1 = width_1 * length_1;
    area_2 = width_2 * length_2;
    
    //Output
    if (area_1 == area_2)
        cout<<"Areas for each rectangle are the same, which is: "<<area_1<<endl;
    else if (area_1 > area_2)
        cout<<"The first rectangle has a larger area, and is: "
            <<area_1<<endl;
    else
        cout<<"The second rectangle has larger area, and is: "<<area_2<<endl;
    return 0;
}

