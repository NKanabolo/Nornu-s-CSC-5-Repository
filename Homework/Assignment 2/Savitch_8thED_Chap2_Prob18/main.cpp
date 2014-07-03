/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th Edition Chapter 2 Problem 18
 * Finding BMR
 * Created on July 2, 2014, 9:16 PM
 */

#include <iostream>//User Defined Libraries

using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
//Declare Variables
    unsigned short BarCal=230;
    unsigned short wtLbs;      
    unsigned short ageYrs;     
    unsigned short htInch;     
    char sex;                  
    float bmr;                 
    float nBars;              
    
    //Inputs
    cout<<"Calculate how many candy bars a day you can eat!!!"<<endl;
    cout<<"What is your sex M/F"<<endl;
    cin>>sex;
    cout<<"What is your weight in lbs?"<<endl;
    cin>>wtLbs;
    cout<<"What is your height in inches?"<<endl;
    cin>>htInch;
    cout<<"What is age in years?"<<endl;
    cin>>ageYrs;
    
    //Calculate BMR
    if(sex=='F'||sex=='f'){
        bmr=6.55e2f+4.3e0f*wtLbs+4.7e0f*htInch-4.7e0f*ageYrs;
    }else if(sex=='M'||sex=='m'){
        bmr=6.6e1f+6.3e0f*wtLbs+1.29e1f*htInch-6.8e0f*ageYrs;
    }else{
        cout<<"You mistyped M/F"<<endl;
    }
    nBars=bmr/BarCal;
    
    //Output
    if(sex=='F'||sex=='f'||sex=='M'||sex=='m'){
        cout<<"Your BMR = "<<bmr<<endl;
        cout<<"The number of candy bars you can eat = "<<
          nBars<<endl;
    }else{
        cout<<"Unable to Calculate"<<endl;
    }
    return 0;
}

