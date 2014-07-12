/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis 7th EDition Chapter 5 Problem 1
 * Rectangle Measurements and Output
 * Created on July 11, 2014, 10:57 PM
 */

#include <iostream>

using namespace std;

//Global COnstants

//Function Prototypes

//Execution
int main(int argc, char** argv) {
    //Declare variables
    unsigned short width;//Width of the rectangle
    unsigned short length;//Length of the rectangle
    
    //Input length and width
    do{
    cout<<"Enter length and width of the rectangle, between 2 and 10: ";
    cin>>length>>width;
    cout<<endl;
    }while(length<2||length>10||width<2||width>10);

    //Swap measurements if width greater than length
    if(width>length){
        unsigned short placekeep = length;//Switching variable
        length = width;
        width = placekeep;
    }

    //Output rectangle onscreen
    for(unsigned short c1 = 0;c1<width;c1++){
        cout<<"     ";
        for(unsigned short c2 = 0;c2<length;c2++){
            cout<<"R";
        }
        cout<<endl;
    }
    return 0;
}

