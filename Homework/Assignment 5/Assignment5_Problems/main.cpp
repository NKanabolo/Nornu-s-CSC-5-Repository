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
float average(float n1, float n2, float n3, float n4);
float stddevi(float s, float average);
void avgStandDevi(float n1, float n2, float n3, float n4, float& average, float& stand_devi);
//Used in problem 4
void calc_coins(int coin_val, int& numb, int& amount_rem);
//Used in problem 5
void convIn(int& ft, int& in);
void convOut(int ft, int in, int mtr, int ctm);
void fttoMtrCm(int ft, int in, int& mtr, int& ctm);
//Used in problem 6
float perime(float sde_1, float sde_2, float sde_3);
bool validLength(float sde_1, float sde_2, float sde_3);
void areaperim(float sde_1, float sde_2, float sde_3, float& perime, float& area);
//Used in problem 7
float calcRetl(float whole_prc, float markup);
//Used in Problem 8
float fallDist(int time);
//Used in problem 9
float kineticE(float mtr, float veloc);
//Used in problem 10
void score(int& score);
int fndLow(int scr1, int scr2, int scr3, int scr4, int scr5);
void calcAvrg(int scr1, int scr2, int scr3, int scr4, int scr5);

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
                //Problem 2
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
                //Problem 3
                //Driver program for average and standard deviation function
                //Declare variables
                //Inputs
                float n1, n2, n3, n4;//Input for average and standard deviation
                //Outputs
                float avrg;//Average of the 4 inputs
                float stand_devi;//Standard deviation of the four inputs
                
                //Program loop
                do{
                    //Input numbers from the user
                    cout<<"Enter four numbers."<<endl;
                    cout<<"n1: ";
                    cin>>n1;
                    cout<<"n2: ";
                    cin>>n2;
                    cout<<"n3: ";
                    cin>>n3;
                    cout<<"n4: ";
                    cin>>n4;
                    cout<<endl;
                    
                    //Calculate average and standard deviation
                    avgStandDevi(n1, n2, n3, n4, avrg, stand_devi);
                    
                    //Output answer
                    cout<<"Average of the 4 numbers is: "<<avrg<<endl;
                    cout<<"The standard deviation is: "<<stand_devi<<endl<<endl;
                    
                }while(repeat());
                cout << endl;
                break;
            }
            case(4):
            {
                //Problem 4
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
                //Problem 5
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
                //Problem 6
                //Declare variables
                float sd_1, sd_2, sd_3;//Sides of the triangle
                //Outputs
                float perim;//Perimeter of the triangle
                float area;//Area of the triangle
                
                //Get user input
                cout<<"Enter the lengths of three sides of a triangle\n";
                cout<<"Side 1: ";
                cin>>sd_1;
                cout<<"Side 2: ";
                cin>>sd_2;
                cout<<"Side 3: ";
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
            }
            case(7):
            {
                //Problem 7
                //Declare variables
                float whole_prc;//Wholesale price
                float markup;//Mark up percent
                float retail;//Retail price
                
                //Input whole sale and markup percentage
                do{
                    cout<<"Enter wholesale price and markup percentage\n";
                    cout<<"Wholesale price: ";
                    cin>>whole_prc;
                    cout<<"Markup percentage: ";
                    cin>>markup;
                    cout<<endl;
                }while(whole_prc<0 || markup<0);
                
                //Calculate retail price
                retail = calcRetl(whole_prc, markup);
                                
                //Output result
                cout<<fixed<<showpoint<<setprecision(2);
                cout<<"Retail price: $"<<retail<<endl;
                cout<<endl;
            }
            case(8):
            {
                //Problem 8
                //Declare variables
                int time = 1;//Seconds object has been falling
                const int MAX_T = 10;//Maximum time object falls
                
                //Output the distance traveled for time intervals of one second
                for(time=1;time<=MAX_T;time++){
                    cout<<"Distance object has fallen in "<<time<<" seconds: ";
                    cout<<fallDist(time)<<" meters\n";
                }
            }
            case(9):
            {
                //Declare variables
                float mass;//Mass in kilograms
                float velocity;//Velocity in meter/second
                float kin_engy;//Kinetic energy in joules
                
                //Input mass and velocity
                cout<<"Enter the mass and velocity of an object"<<endl;
                cout<<"Mass: ";
                cin>>mass;
                cout<<"Velocity: ";
                cin>>velocity;
                cout<<endl;
                 
                //Calculate
                kin_engy = kineticE(mass, velocity);
                
                //Output
                cout<<"Kinetic energy of this object: "<<kin_engy<<" joules\n";
            }
            case(10):
            {
                //Declare variables
                int scr1, scr2, scr3, scr4, scr5;//Scores
                
                //Get input from user
                cout<<"Please enter 5 scores\n";
                score(scr1);
                score(scr2);
                score(scr3);
                score(scr4);
                score(scr5);
                
                //Calculate and display the average of the four highest scores
                calcAvrg(scr1, scr2, scr3, scr4, scr5);
            }}
            }while(m_choice <= 10 && m_choice > 0);
    
    return 0;
}

bool repeat()
{
    //Declare variables
    char answer;
    
    //If the user wants to repeat calculation
    cout<<"Repeat the calculation?"<<endl;
    cout<<"Press Y then Return if yes: ";
    cin>>answer;
    cout<<endl;
    
    return (answer == 'Y' || answer == 'y');
}
//Problem 1 and 2 functions
//Function that allows the user to input military time
void gettime(int& hr, int& mn)
{
    cout<<"Enter time [hour minute]: ";
    cin>>hr;
    cin>>mn;
}
//Correctly prints military time
void miltaout(int time)
{
    if(time<10)
        cout<<"0";
    cout<<time;
}
//Problem 3 functions
//Calculates the average of four numbers
float average(float n1, float n2, float n3, float n4)
{
    //Return average
    return (n1+n2+n3+n4)/4;
}
//Calculates one standard deviation term
float stddevi(float s, float avrg)
{
    //Return one term of standard deviation
    return (s-avrg)*(s-avrg);
}
//Calculate the average and standard deviation of four numbers
void avgStandDevi(float n1, float n2, float n3, float n4, float& avrg, float& stand_devi)
{
    avrg = average(n1, n2, n3, n4);
    stand_devi = sqrt(average(stddevi(n1, avrg), stddevi(n2, avrg),
                           stddevi(n3, avrg), stddevi(n4, avrg)));
}
//Problem 4 functions
//Computes the number of coins of a certain denomination that can be fit into
void calc_coins(int coin_val, int& numb, int& amount_rem)
{
    numb = amount_rem/coin_val;
    amount_rem %= coin_val;
}
//Problem 5 functions
//Gets an input of feet and inches from the user
void convIn(int& ft, int& in)
{
    cout<<"Enter length in feet and inches\n";
    cout<<"Length [ft in]: ";
    cin>>ft;
    cin>>in;
    cout<<endl;
}
//Outputs how many meters and centimeters are equivalent to feet and inches
void convOut(int ft, int in, int mtr, int ctm)
{
    cout<<ft<<" feet and "<<in<<" inches is equivalent to: ";
    cout<<mtr<<" meters and "<<ctm<<" centimeters\n\n";
}
//Calculate the meters and centimeters given feet and inches
void fttoMtrCm(int ft, int inches, int& mtr, int& ctm)
{
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
float perime(float sde_1, float sde_2, float sde_3)
{
    //Return half perimeter
    return (sde_1+sde_2+sde_3)/2;
}
//Determines if three lengths can form a triangle
//Bool determines if lengths can form a triangle
bool validLength(float sde_1, float sde_2, float sde_3)
{
    return (sde_1>0 && sde_2>0 && sde_3>0 &&
            (sde_1+sde_2)>sde_3 && (sde_1+sde_3)>sde_2 && (sde_2+sde_3)>sde_1);
}
//Calculate the area and perimeter of a triangle given the lengths of 3 sides
void areaperim(float sde_1, float sde_2, float sde_3, float& perim, float& area)
{
    float sd_perime;
    
    //Calculate results
    if(validLength(sde_1, sde_2, sde_3)){
        sd_perime= perime(sde_1, sde_2, sde_3);
        perim = sde_1+sde_2+sde_3;
        area = sqrt(sd_perime*(sd_perime-sde_1)*(sd_perime-sde_2)*(sd_perime-sde_3));
    }
    else
        perim = area = -1;
}
//Problem 7 functions
///Calculate retail price
float calcRetl(float whole_prc, float markup)
{
    //Return retail price
    return whole_prc+((whole_prc*markup)/DEC_PERC);
}
//Problem 8 functions
//Calculate distance fallen
float fallDist(int time)
{
    //Return the distance fallen
    return (0.5)*EARTH_G*time*time;
}
//Problem 9 functions
//Calculate kinetic energy
float kineticE(float mtr, float veloc)
{
    //Return kinetic energy
    return (0.5)*mtr*veloc*veloc;
}
//Problem 10 functions

//Find the lowest out of five scores
int fndLow(int scr1, int scr2, int scr3, int scr4, int scr5)
{
    int low = scr1;
    low = min(low, scr2);
    low = min(low, scr3);
    low = min(low, scr4);
    return min(low, scr5);
}
void score(int& score)
{
    const short MAX_SCORE = 100;//Maximum score
    do{
        cout<<"Enter score(0-100): ";
        cin>>score;
        if(score<0 || score>MAX_SCORE)
            cout<<"Invalid score, try again"<<endl;
    }while(score<0 || score>MAX_SCORE);
}
//Calculate and output the average of four scores, dropping one out of five scores
void calcAvrg(int scr1, int scr2, int scr3, int scr4, int scr5)
{
    float avg = (scr1+scr2+scr3+scr4+scr5-fndLow(scr1, scr2, scr3, scr4 ,scr5))/static_cast<float>(4.0);
    cout<<"The average is: "<<avg<<endl;
}