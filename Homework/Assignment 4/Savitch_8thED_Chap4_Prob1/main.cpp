/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on July 8, 2014, 8:26 PM
 */

#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants
const float LPG=.264179;//gallons in a liter
bool repeatYN();
//Function Prototypes
float mpg(int mile, int litr);//Returns the miles per gallon traveled given
                
                 //by the vehicle
int main(int argc, char** argv) {
    //Declare variables
    bool running= true;
    int mile, litr;
    float mi_gal;
    
    //Input Miles and Gallons
    while(running)
    {
        cout<<"Enter the distance traveled in miles: ";
        cin>>mile;
        cout<<"Enter the number of liters consumed over "<<mile<<" miles: ";
        cin>>litr;
    
    //Output mpg
        mi_gal= mpg(mile,litr);//returns value miles per gallon
        cout<<"Over a "<<mile<<" mile distance, the car delivered "<<mi_gal<<" miles per gal."<<endl;
        running=repeatYN();
        cout<<endl;
    }
    return 0;
}

bool repeatYN() {
    char use_in;//User input
    while(true){
        //Get user input
        cout<<"Enter Y/N: ";
        cin>>use_in;
        switch(use_in) {
            case('Y'):case('y'):
                return true;
                break;
            case('N'):case('n'):
                return false;
                break;
            default:
                cout<<"Not valid input.\n";
        }
    }
}

float mpg(int mile, int litr)
{
    return mile/(litr*LPG);
}
