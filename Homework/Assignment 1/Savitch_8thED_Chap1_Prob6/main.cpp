/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch Chapter 1 Problem 6
 * Syntax and Error Messages
 * Created on June 27, 2014, 10:39 PM
 */

//main.cpp:9:45: fatal error:  iostream: No such file or directory #include < iostream>//User Defined Libraries
//main.cpp:23:5: error: 'cout' was not declared in this scope cout<<"Press return after entering a number.\n";^
//main.cpp:26:5: error: 'cin' was not declared in this scope cin>>number_of_pods;^
//make[2]: *** [dist/Debug/Cygwin_4.x-Windows/savitch_8thed_chap1_prob6.exe] Error 1 make[2]: Leaving directory '/cygdrive/c/Users/Nornubari's Laptop/Desktop/Savitch_8thED_Chap1_Prob6' nbproject/Makefile-Debug.mk:59: recipe for target '.build-conf' failed
//main.cpp:25:13: error: expected initializer before 'argc' int mainint argc, char** argv) 
//main.cpp:26:13: error: expected initializer before 'argc' int mainint argc, char** argv {
//main.cpp:28:9: error: expected ';' before string constant cout"Press return after entering a number.\n";
//main.cpp:47:13: error: expected '}' at end of input return 0;

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    int number_of_pods, peas_per_pod, total_peas;
    cout<<"Press return after entering a number.\n";
    cout<<"Enter the number of pods:\n";
    
    cin>>number_of_pods;
    cout<<"Enter number of peas in a pod.\n";
    cin>>peas_per_pod;
    total_peas=number_of_pods*peas_per_pod;
    cout<<"If you have ";
    cout<<number_of_pods;
    cout<<"pea pods.\n";
    cout<<"and ";
    cout<<peas_per_pod;
    cout<<" peas in each pod, then\n";
    cout<<"you have ";
    cout<<total_peas;
    cout<<" peas in all pods.\n";
                
    return 0;

}
