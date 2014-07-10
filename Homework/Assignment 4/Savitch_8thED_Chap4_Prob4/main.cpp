/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on July 9, 2014, 8:29 PM
 */

#include <iostream>

using namespace std;

//User Defined Libraries

//Global Constants
const unsigned short DEC_PCT = 100;//Conversion factor decimal to percentage value

//Function Prototypes
double rateinfl(float prc_last, float prc_cur);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    bool running= true;
    bool repeatYN();
    
    //Input variables
    float prc_cur;//Price currently
    float prc_last;//Price last year
    
    //while Program loop
    while(running){
        cout<<"How much did the item cost last year?: ";
        cin>>prc_last;
        cout<<"How much does the item cost now?: ";
        cin>>prc_cur;
        cout<<endl;
    //Output values
        cout<<"The inflation rate is approximately: "
            <<rateinfl(prc_last, prc_cur)<<"%\n";
    //Ask to run program again
        cout<<"Calculate the inflation rate of another item?\n";
        running = repeatYN();//Answer with Y for yes or N for no
        cout<<endl;
    }
    return 0;
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


    double rateinfl(float prc_last, float prc_cur) 
    {
    return ((prc_cur-prc_last)/prc_last)*DEC_PCT;
    }
