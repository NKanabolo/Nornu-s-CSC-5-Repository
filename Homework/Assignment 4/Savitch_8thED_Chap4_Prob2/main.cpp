/* 
 * File:   main.cpp
 * Author: NornubariKanabolo
 * Savitch 8th EDition Chapter 4 Problem 2
 * MPG
 * Created on July 9, 2014, 11:36 AM
 */

#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants
const float LPG=.264179;//gallons in a liter
bool repeatYN();
//Function Prototypes
float mpg(int mi_one, int litr_one);//Returns the miles per gallon traveled given
                                    //by one vehicle
float mpg_two(int mi_two, int litr_two);//Returns mpg of second car

//Execution
int main(int argc, char** argv) {
    //Declare variables
    bool running= true;
    int mi_one, mi_two, litr_one, litr_two;
    float mi_gal_one, mi_gal_two;
    
    //Input Miles and Gallons
    while(running)
    {
        cout<<"Enter the distance traveled in miles for Car 1: ";
        cin>>mi_one;
        cout<<"Enter the distance traveled in miles for Car 2: ";        
        cin>>mi_two;
        cout<<"\n";
        cout<<"Enter the number of liters consumed in miles for Car 1: ";
        cin>>litr_one;
        cout<<"Enter the number of liters consumed in miles for Car 2: ";   
        cin>>litr_two;
        cout<<"\n";
    
    //Output mpg of both cars
        mi_gal_one= mpg(mi_one,litr_one);//returns value of 1st car miles per gallon
        mi_gal_two= mpg_two(mi_two,litr_two);//returns value 2nd car miles per gallon
        cout<<"Over a "<<mi_one<<" mile distance, Car 1 delivered "<<mi_gal_one<<" miles per gal."<<endl;
        cout<<"\n";
        
        mi_gal_two= mpg(mi_two,litr_two);//returns value miles per gallon
        cout<<"Over a "<<mi_two<<" mile distance, Car 2 delivered "<<mi_gal_two<<" miles per gal."<<endl;
        cout<<"\n";
        if (mi_gal_one>mi_gal_two)
        {
            cout<<"Car 1 is more fuel efficient than Car 2\n";
        }
        else if (mi_gal_one==mi_gal_two)
        {
            cout<<"Both cars have the same fuel efficiency\n";
        }
        else
        {
            cout<<"Car 2 is more fuel efficient than Car 1\n";
        }
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

float mpg(int mi_one, int litr_one)
{
    return mi_one/(litr_one*LPG);
}
float mpg_two(int mi_two, int litr_two)
{
    return mi_two/(litr_two*LPG);
}

