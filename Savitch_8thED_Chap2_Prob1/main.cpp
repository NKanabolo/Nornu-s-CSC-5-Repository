/* 
 * File:   main.cpp
 * Author: Nornubari kanabolo
 * Savitch 8th Edition Chapter 2 Problem 1
 * Cereal Weight
 * Created on June 30, 2014, 8:16 PM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare the variables
    double weight_ounces, weight_tons, one_ton=35273.92, amount_boxes_for_ton;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(7);
    //Input weight from the keyboard
    cout<<"Enter the weight, in ounces, of a cereal box:\n";\
    cin>>weight_ounces;
    //Output weight in tons
    weight_tons=weight_ounces/one_ton;
    cout<<"Weight in tons = "<<weight_tons<<" tons"<<endl;
    //For number of boxes to yield 1 metric ton
    amount_boxes_for_ton=one_ton/weight_ounces;
    cout.precision(3);
    cout<<"Number of cereal boxes to yield 1 metric ton = "
            <<amount_boxes_for_ton<<" cereal boxes"<<endl;
    return 0;
}

