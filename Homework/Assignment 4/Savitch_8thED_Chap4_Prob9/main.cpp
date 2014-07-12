/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 4 Problem 9
 * Annual Tax on New House
 * Created on July 11, 2014, 12:29 PM
 */

#include <iostream>

using namespace std;

//Global Constants
bool repeatYN();
//Function Prototypes
float hatsize(int weight, float height, const float ht_sz_cnst);//Returns size of hat fitted to measurements given

float jcktsize(float height, int weight, const float jkt_sz_cnst);//Returns jacket size fitted to given measurements

float wstsize(int weight, const float wst_sz_cnst);//Returns waist size of pants fitted to given measurements
 //Execution
int main(int argc, char** argv) {
    //Declare variables
    const float ht_sz_cnst=2.9;
    const float jkt_sz_cnst=.125;
    const float wst_sz_cnst=.1;
    bool running= true;
    
    //Input
    int age, weight, height, hat, jacket, waist;
    //Program loop
    while(running)
    {
        cout<<"Enter your height in inches: ";
        cin>>height;
        cout<<"Enter your weight in pounds: ";
        cin>>weight;
        cout<<"Enter your age: ";
        cin>>age;
    //Calculations
        hat= hatsize(weight, height, ht_sz_cnst);
        int count=30;
        while(count<=100)
        {
        jacket= jcktsize(height, weight, jkt_sz_cnst);
        count= count+10;
        }
        count=28;
        while(count<=100)
        {
            waist= wstsize(weight, wst_sz_cnst);
            count=count+2;
        }
    //Output Sizes
        cout<<"The size of a hat fitted to your measurements is "
                <<hat<<endl;
        cout<<"The size of a jacket fitted to your measurements is "
                <<jacket<<endl;
        cout<<"The waist size of a pair of pants fitted to your measurements is "
                <<waist<<endl;
        running=repeatYN();
    }
    return 0;
}

float hatsize(int weight, float height, const float ht_sz_cnst)
{
    return((weight/height)*ht_sz_cnst);
}

float jcktsize(float height, int weight, const float jkt_sz_cnst)
{
    return((height*weight/288)+jkt_sz_cnst);
}

float wstsize(int weight, const float wst_sz_cnst)
{
    return((weight/5.7)+wst_sz_cnst);
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