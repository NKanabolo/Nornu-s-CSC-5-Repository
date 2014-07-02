/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th Edition Chapter 2 Problem 6
 * Maximum Room Capacity
 * Created on July 2, 2014, 2:24 PM
 */


#include <iostream>//User System Libraries
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    int max_capacity, people_attending, fullness, added_people, subtracted_people;
    //Input a max capacity in the keyboard
    cout<<"Enter the Maximum Room Capacity:"<<endl;\
    cin>>max_capacity;
    //Input number of people attending in keyboard
    cout<<"Enter the number of people attending:"<<endl;\
    cin>>people_attending;
    //Output condition of meeting being held
    if (people_attending<=max_capacity)
    {
        added_people=max_capacity-people_attending;
        cout<<"Since the room is not full, "<<added_people<<" people can be legally added\n";
    }
        else
        {
        subtracted_people=(people_attending-max_capacity);
        cout<<"Since the room is over capacity, the meeting can go as planned only if "<<subtracted_people<<" people are excluded from the meeting,\n";
        cout<<"in order to meet fire safety regulations.\n";
        }
    return 0;
}

