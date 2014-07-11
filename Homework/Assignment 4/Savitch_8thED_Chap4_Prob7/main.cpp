/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on July 10, 2014, 4:59 PM
 */

#include <iostream>

using namespace std;

//Global Constants
const float uni_grvty=6.673e-8f;//Universal gravitational constant(in cm^3/(g*sec^2))
bool repeatYN();
//Function Prototypes
float gravForce(float mass_one, float mass_two, float distance);

 //Execution
int main(int argc, char** argv) {
    //Declare variables
    //Inputs
    float distance; //Distance between the two objects(in centimeters)
    float mass_one, mass_two;//Masses of the two objects, in grams
    bool running = true;//Should program continue running

    //Enter program loop
    while(running) {
        //Input data
        cout<<"Enter the distance between the two objects in centimeters: ";
        cin>>distance;
        cout<<"Enter the mass of the first object in grams: ";
        cin>>mass_one;
        cout<<"Enter the mass of the second object in grams: ";
        cin>>mass_two;
        cout<<endl;

        //Output gravitational force
        cout<<"The gravitational force between the two objects is: "
            <<gravForce(mass_one, mass_two, distance)<<" dyn.\n";

        //Run program again decision
        cout<<"Do you want to new values for the calculation?\n";
        running = repeatYN();
        }
    return 0;
}

float gravForce(float mass_one, float mass_two, float distance) 
{
    return (uni_grvty*mass_one*mass_two)/(distance*distance);
}

bool repeatYN() {
    char usr_in;//User input
    //Run until there is a returned value
    while(true){
        //Get user input
        cout<<"Please enter Y/N: ";
        cin>>usr_in;
        switch(usr_in) {
            case('Y'):case('y'):
                return true;
                break;
            case('N'):case('n'):
                return false;
                break;
            default:
                cout<<"Invalid input.\n";
        }
    }
}