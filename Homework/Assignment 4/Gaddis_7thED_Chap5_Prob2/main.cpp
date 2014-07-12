/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis 7th EDition Chapter 5 Problem 1
 * ASCII Characters
 * Created on July 11, 2014, 10:40 PM
 */

#include <iostream>

using namespace std;

//Global COnstants

//Function Prototypes

//Execution
int main(int argc, char** argv) {
    //Declare variables
    const int linebreak = 16;//New line every 16 characters
    const int start = 32;//Start ASCII code 36
    const int end = 127;//End loop when count larger than 127
    int count = start;//Count for the for loop
    //Program loop
    for(count;count<=end;count++){
        //Ensure a new line every 16 characters
        if (((count-start)%linebreak == 0))
            cout<<"\n";
        //Output ASCII character and space
        cout<<static_cast<char>(count)<<" ";
                }
    return 0;
}

