/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 4 Problem 3
 * Price of Stock
 * Created on July 9, 2014, 1:54 PM
 */

#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants
bool repeatYN();
//Function Prototypes
double fractToDeci(int whole, int numera, int denomi);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    bool running = true;//Status of whether the program should continue running
    int numera;//Numerator of the fractional part
    int denomi;//Denominator of the fractional part
    int shar_own;//Number of the shares owned
    int wh_dol;//Whole dollar value of the stock
    double ttl_val;//Total value of the user's holdings
    //Input and While loop
    while(running) {
        cout<<"Enter the numerator of the fractional part: ";
        cin>>numera;
        cout<<"Enter the denominator of the fractional part: ";
        cin>>denomi;
        cout<<"Enter number of shares you own: ";
        cin>>shar_own;
        cout<<"Enter whole dollar value of the stock: ";
        cin>>wh_dol;
        cout<<endl;
        //Calculate the total value of the users holdings
        ttl_val = fractToDeci(wh_dol, numera, denomi)*shar_own;
        //Output the dollar value in decimal form
        cout<<"The total value of your holdings is: $"<<ttl_val<<endl;
        //Determine if the user wants to repeat the program
        cout<<"Would you like to repeat this calculation?\n";
        running = repeatYN();
        cout<<endl; 
    }
    return 0;
}

double fractToDeci(int whole, int numera, int denomi)
{
    return (whole+(static_cast<double>(numera)/denomi));
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