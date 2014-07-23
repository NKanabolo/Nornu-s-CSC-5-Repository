/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Assignment 5 Problems
 * Created on July 23, 2014, 3:43 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//User Defined Libraries

//Global Constants
const unsigned short HR_DAY = 24;//Hours in a day
const unsigned short MIN_HR = 60;//Minutes in an hour
const float MT_P_FT = 0.3048;//Meters per foot
const short IN_P_FT = 12;//Inches per foot
const short CEN_P_MT = 100;//Centimeters per meter
const short DEC_PERC = 100;//Used for converting between decimal and percentage values
const float EARTH_G = 9.8;//Acceleration due to gravity on earth in m/s^2

//Function Prototypes
//Generally useful functions
bool repeat();
//Used in problem 1
void gettime(int& hr, int& mn);
void miltaout(int time);
//Used in problem 2
void gettime(int& hr, int& mn);
//Used in problem 3
float average(float s1, float s2, float s3, float s4);
float stddevi(float s, float average);
void avgStandDevi(float s1, float s2, float s3, float s4, float& average, float& stand_devi);
//Used in problem 4
void calc_coins(int coin_val, int& numb, int& amount_rem);
//Used in problem 5
void convIn(int& ft, int& in);
void convOut(int ft, int in, int mtr, int ctm);
void fttoMtrCm(int ft, int in, int& mtr, int& ctm);
//Used in problem 6
float perim(float sde_1, float sde_2, float sde_3);
bool validLength(float sde_1, float sde_2, float sde_3);
void areaperim(float sde_1, float sde_2, float sde_3, float& perim, float& area);

//Execution
int main(int argc, char** argv) {
//Declare menu variables
    short m_choice;//Users choice
    //Main menu setup and output
    //Enter menu loop
    do{
        //Set default format for output
        cout.unsetf(ios_base::fixed);
        cout<<noshowpoint<<setprecision(6);
        cout << "1.  Savitch, 8thEd, Chapter 5, Problem 2\n";
        cout << "2.  Savitch, 8thEd, Chapter 5, Problem 3\n";
        cout << "3.  Savitch, 8thEd, Chapter 5, Problem 4\n";
        cout << "4.  Savitch, 8thEd, Chapter 5, Problem 5\n";
        cout << "5.  Savitch, 8thEd, Chapter 5, Problem 6\n";
        cout << "6.  Savitch, 8thEd, Chapter 5, Problem 13\n";
        cout << "7.  Gaddis,  7thEd, Chapter 6, Problem 1\n";
        cout << "8.  Gaddis,  7thEd, Chapter 6, Problem 3\n";
        cout << "9.  Gaddis,  7thEd, Chapter 6, Problem 4\n";
        cout << "10.  Gaddis,  7thEd, Chapter 6, Problem 7\n";
        cout << "11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout << endl;

        switch (m_choice) {
            case(1):
            {
                //Problem 1
                //Declare variables
                int curr_hour, curr_min;//Current hours and minutes
                int wtd_hour, wtd_min;//Hours and minutes waited
                int hour, min;//Hours and minutes after wait
                
                //Program loop
                do{
                    //Inputs from user
                    do{
                        cout<<"Please enter the current time:"<<endl;
                        gettime(curr_hour, curr_min);
                    }while(curr_min  < 0 || curr_min  >= MIN_HR || curr_hour < 0 || curr_hour >= HR_DAY);
                    
                    cout<<"Enter waiting period:"<<endl;
                    gettime(wtd_hour, wtd_min);
                    
                    //Calculate result time
                    min = curr_min+wtd_min;
                    hour = curr_hour+wtd_hour;
                    while(min>=MIN_HR){
                         hour++;
                         min -= MIN_HR;;
                    }
                    hour %= HR_DAY;
                    
                    //Output time
                    cout<<"The time after waiting is: ";
                    miltaout(hour);
                    cout<<":";
                    miltaout(min);
                    cout<<endl;
                    
                }while(repeat());//Repeat the calculation if user wants
                break;
            }
            case(2):
            {
                //Begin problem 2
                //Declare variables
                int curr_hour, curr_min;//Current hours and minutes
                int wtd_hour, wtd_min;//Hours and minutes waited
                int hour, min;//Hours and minutes after wait
                
                //Program loop
                do{
                    //Inputs from user
                    do{
                        cout<<"Please enter the current time:"<<endl;
                        gettime(curr_hour, curr_min);
                    }while(curr_min  < 0 || curr_min  >= MIN_HR || curr_hour < 0 || curr_hour >= HR_DAY);
                    
                    cout<<"Enter waiting period:"<<endl;
                    gettime(wtd_hour, wtd_min);
                    
                    //Calculate result time
                    min = curr_min+wtd_min;
                    hour = curr_hour+wtd_hour;
                    while(min>=MIN_HR){
                         hour++;
                         min -= MIN_HR;;
                    }
                    hour %= HR_DAY;
                    
                    //Output time
                    if (hour>12)
                    {
                        hour= hour-12;
                        cout<<"The time after waiting is: ";
                        cout<<hour;
                        cout<<":";
                        cout<<min;
                        cout<<endl;
                    }
                    else
                    {
                        cout<<"The time after waiting is: ";
                        cout<<hour;
                        cout<<":";
                        cout<<min;
                        cout<<endl;
                    }
                }while(repeat());
                //End problem 2
                cout << endl;
                break;
            }
            case(3):
            {
                //Short problem description
                cout<<"Compute average and standard deviation.\n\n";
                //Begin problem 3
                //Driver program for average and standard deviation function
                //Declare variables
                //Inputs
                float s1, s2, s3, s4;//Input for average and standard deviation
                //Outputs
                float average;//Average of the 4 inputs
                float stand_devi;//Standard deviation of the four inputs
                
                //Program loop
                do{
                    //Input numbers from the user
                    cout<<"Enter four numbers."<<endl;
                    cout<<"Format [s1 s2 s3 s4]: ";
                    cin>>s1;
                    cin>>s2;
                    cin>>s3;
                    cin>>s4;
                    cout<<endl;
                    
                    //Calculate average and standard deviation
                    avgStandDevi(s1, s2, s3, s4, average, stand_devi);
                    
                    //Output answer
                    cout<<"Average of the 4 numbers is: "<<average<<endl;
                    cout<<"The standard deviation is: "<<stand_devi<<endl<<endl;
                    
                }while(repeat());
                cout << endl;
                break;
            }
            case(4):
            {
                //Short problem description
                cout<<"Outputs the type and amount of coins needed to make change\n\n";
                //Begin problem 4
                //Declare variables
                const short QUARTER = 25;//Quarter value
                const short DIME = 10;//Dime value
                const short PENNY = 1;//Penny value
                const short MAX_CHNG = 99;//Max change value
                //Inputs
                int change;
                int numb = 0;
                do{
                    //Input change amount
                    do{
                        cout<<"What is the amount of change that needs to be made?: ";
                        cin>>change;
                    }while(change < 0 || change > MAX_CHNG);
                    
                    //Calculate and output the result
                    cout<<change<<" cents can be given as\n";
                    calc_coins(QUARTER, numb, change);
                    cout<<numb<<" quarter(s) ";
                    calc_coins(DIME, numb, change);
                    cout<<numb<<" dime(s) and ";
                    calc_coins(PENNY, numb, change);
                    cout<<numb<<" penny(pennies)\n\n";
                    
                }while(repeat());
                //End problem 3
                cout << endl;
                break;
            }
            case(5):
            {
                //Short problem description
                cout<<"Convert feet and inches to meters and centimeters.\n\n";
                //Begin problem 5
                //Declare variables
                int ft, inch;
                int meter, cm;//Meters and centimeters
                
                //Program loop
                do{
                    //Get user input
                    convIn(ft, inch);
  
                    //Calculate values
                    fttoMtrCm(ft, inch, meter, cm);
                    
                    //Output result
                    convOut(ft, inch, meter, cm);
                    
                }while(repeat());
                //End problem 4
                cout << endl;
                break;
            }
            case(6):
            {
                //Short problem description
                cout<<"Calculate the area and perimeter of a triangle.\n\n";
                //Begin problem 5
                //Declare variables
                float sd_1, sd_2, sd_3;//Sides of the triangle
                //Outputs
                float perim;//Perimeter of the triangle
                float area;//Area of the triangle
                
                //Get user input
                cout<<"Enter the lengths of three sides of a triangle\n";
                cout<<"Format [a b c]: ";
                cin>>sd_1;
                cin>>sd_2;
                cin>>sd_3;
                areaperim(sd_1, sd_2, sd_3, perim, area);
                
                //Output perimeter and area
                if(area < 0 || perim < 0)
                    cout<<"Not valid lengths, no triangle can be made.\n";
                else{
                    cout<<"Perimeter is: "<<perim<<endl;
                    cout<<"Area is: "<<area<<endl;
                }
                //End problem 5
                cout << endl;
                break;
            }}
            }while(m_choice <= 10 && m_choice > 0);
    
    return 0;
}

bool repeat(){
    //Declare variables
    char answer;
    
    //If the user wants to repeat calculation
    cout<<"Repeat the calculation?"<<endl;
    cout<<"Press Y then Return if yes: ";
    cin>>answer;
    cout<<endl;
    
    return (answer == 'Y' || answer == 'y');
}
//Problem 1 functions

//Function that allows the user to input military time
//Output call by reference
//Input
//  hr = hour
//  mn = minute
//Output
//  hr = hour
//  mn = minute
void gettime(int& hr, int& mn){
    //Inputs from user
    cout<<"Enter time [hour minute]: ";
    cin>>hr;
    cin>>mn;
}
//Correctly prints military time
//Inputs
//  time = some value of time in hours, minutes, or seconds
void miltaout(int time){
    if(time<10)
        cout<<"0";
    cout<<time;
}
//Problem 2 functions
void gettime(int& hr, int& mn){
    //Inputs from user
    cout<<"Enter time [hour minute]: ";
    cin>>hr;
    cin>>mn;
}
//Problem 3 functions

//Calculates the average of four numbers
//Inputs
//  s1, s2, s3, s4 = four numbers
//Outputs
//  the average value of s1, s2, s3, s4
float average(float s1, float s2, float s3, float s4){
    //Calculate and return the average
    return (s1+s2+s3+s4)/4;
}
//Calculates one standard deviation term
//Inputs
//  s = a single number
//  average = the average of four values
//Outputs
//  the standard deviation of s1, s2, s3, s4
float stddevi(float s, float average){
    //Calculate and return one term of the standard deviation
    return (s-average)*(s-average);
}
//Calculate the average and standard deviation of four numbers
//Outputs by reference
//Inputs
//  s1, s2, s3, s4 = four numbers
//Outputs
//  average = average of s1, s2, s3, s4
//  stand_devi = standard deviation of s1, s2, s3, s4
void avgStandDevi(float s1, float s2, float s3, float s4, float& average, float& stand_devi){
    //Calculate average
    average = average(s1, s2, s3, s4);
    //Calculate standard deviation
    stand_devi = sqrt(average(stddevi(s1, average), stddevi(s2, average),
                           stddevi(s3, average), stddevi(s4, average)));
}
//Problem 4 functions

//Computes the number of coins of a certain denomination that can be fit into
//a given amount of change
//Output by reference
//Inputs
    //coin_value = The value of a type of coin
    //num = The number of coins of coin_value that can fit into amount_left
    //amount_left = The amount of change left
//Outputs
    //num
    //amount_left
void calc_coins(int coin_val, int& numb, int& amount_rem){
    //Calculate num and amount_left
    numb = amount_rem/coin_val;
    amount_rem %= coin_val;
}
//Problem 5 functions

//Gets an input of feet and inches from the user
//Output by reference
//No Inputs
//Outputs
//  ft = feet
//  in = inches
void conv4In(int& ft, int& in){
    //Get input from user
    cout<<"Enter length in feet and inches\n";
    cout<<"Length [ft in]: ";
    cin>>ft;
    cin>>in;
    cout<<endl;
}
//Outputs how many meters and centimeters are equivalent to feet and inches
//No outputs
//Inputs
//  ft = feet
//  in = inches
//  m  = meters
//  cm = centimeters
void convOut(int ft, int in, int mtr, int ctm){
    cout<<ft<<" feet and "<<in<<" inches is equivalent to: ";
    cout<<mtr<<" meters and "<<cm<<" centimeters\n\n";
}
//Calculate the meters and centimeters given feet and inches
//Output by reference
//Inputs
//  ft = feet
//  in = inches
//Outputs
// m  = meters
// cm = centimeters
void fttoMtrCm(int ft, int inches, int& mtr, int& ctm){
    //Define variables
    float ft_float = ft;//Feet as a float
    float mtr_float;//Meters as a float
    
    //Calculate values
    ft_float += (static_cast<float>(inches)/IN_P_FT);//Inches to feet
    mtr_float = ft_float*MT_P_FT;//Feet to meters
    mtr = mtr_float;
    ctm = mtr_float*CEN_P_MT;
    mtr_float -= mtr;
    
}
//Problem 5 functions

//Calculate the semi-perimeter of a triangle given the lengths of 3 sides
//Inputs
//  sd_1, sd_2, sd_3 = sides of the triangle
//Outputs
//  s_prtr = semi-perimeter
float perim(float sde_1, float sde_2, float sde_3){
    //Calculate and return the semi-perimeter
    return (sde_1+sde_2+sde_3)/2;
}
//Determines if three lengths can form a triangle
//Formula: Three positive lengths of side a, b, and c, form a triangle iff
//a+b>c, a+c>b, and b+c>a
//Inputs
//  sd_1, sd_2, sd_3 = lengths of three sides
//Outputs
//  bool determining if the lengths can form a triangle
bool validLength(float sde_1, float sde_2, float sde_3){
    return (sde_1>0 && sde_2>0 && sde_3>0 &&
            (sde_1+sde_2)>sde_3 && (sde_1+sde_3)>sde_2 && (sde_2+sde_3)>sde_1);
}
//Calculate the area and perimeter of a triangle given the lengths of 3 sides
//For invalid data (the lengths can't form a triangle), return -1 for both
//the area and perimeter.
//Output by reference
//Inputs
//  sd_1, sd_2, sd_3 = sides of the triangle
//Outputs
//  area = area
//  prtr = perimeter
void areaperim(float sde_1, float sde_2, float sde_3, float& perim, float& area){
    //Declare variables
    float sd_perim;//Semi-perimeter
    
    //Check that the input is valid and calculate results
    if(validLength(sd_1, sd_2, sd_3)){
        sd_perim= perim(sd_1, sd_2, sd_3);
        perim = sde_1+sde_2+sde_3;
        area = sqrt(sd_perim*(sd_perim-sde_1)*(sd_perim-sde_2)*(sd_perim-sde_3));
    }
    else
        perim = area = -1;
}