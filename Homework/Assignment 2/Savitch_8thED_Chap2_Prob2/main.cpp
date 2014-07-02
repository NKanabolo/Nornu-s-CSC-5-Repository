/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th Edition Chapter 2 Problem2
 * Death from Soda Pop 
 * Created on July 1, 2014, 12:04 PM
 */

#include<iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Declare the variables
    const double artificial_sweetener_grams =.001, pounds_to_grams=453.592;
    double bottles_to_kill_man, sweetener_kill_mouse, weight_mouse, ending_dieter_weight, sweetener_kill_man;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    //Input amount of sweetener to kill a mouse from the keyboard
    cout<<"Enter the the amount of sweetener needed to kill a mouse, in grams:\n";
    cout<<"\n";
    cin>>sweetener_kill_mouse;
    //Input weight of mouse
    cout<<"Enter weight of mouse, in pounds:\n";
    cin>>weight_mouse;
    cout<<"\n";
    //Input ending weight of dieter
    cout<<"Enter ending weight of my friend, in pounds:\n";
    cin>>ending_dieter_weight;
    cout<<"\n";
    //Output sweetener amount to kill man
    sweetener_kill_man=(sweetener_kill_mouse*(ending_dieter_weight*pounds_to_grams))/(pounds_to_grams*weight_mouse);
    cout<<"Amount of sweetener to kill my friend \n"<<sweetener_kill_man<<" grams"<<endl;
    cout<<"\n";
    //Number of bottles man can drink without dying
    bottles_to_kill_man=sweetener_kill_man/(1000000*artificial_sweetener_grams);
    cout<<"The number of bottles my friend can drink before dying, if each bottle is 1000 grams\n"
            <<bottles_to_kill_man<<endl;
    return 0;
}

