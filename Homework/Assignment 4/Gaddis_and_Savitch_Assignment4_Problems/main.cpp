/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis and Savitch Assignment4 Problems
 * Created on July 11, 2014, 11:12 PM
 */

//System Level Libraries 
#include <iostream>
#include<cmath>
#include <cstdlib>
using namespace std;

//User Defined Libraries

//Global Constants
const unsigned short DEC_PCT = 100;//Conversion factor decimal to percentage value
const float LPG = 0.264179;//Conversion from liters to gallons
const float uni_grvty=6.673e-8f;//Universal gravitational constant(in cm^3/(g*sec^2))
//Function Prototypes

//Repeat the calculation with a yes or no answer
bool repeatYN();

//For Problem 1
float mpg(int mile, int litr);//Returns the miles per gallon traveled given

//For Problem 2
float mpg(int mi_one, int litr_one);//Returns the miles per gallon traveled given
                                    //by one vehicle
float mpg_two(int mi_two, int litr_two);//Returns mpg of second car

//For Problem 3
double fractToDeci(int whole, int numera, int denomi);//Returns fraction to decimal value

//For Problem 4
double rateinfl(float prc_last, float prc_cur);

//For Problem 5
//Return Gravitational Force value
float gravForce(float mass_one, float mass_two, float distance);

//For Problem 6
float savetax(float int_pay, float tax_rate);//Calculate tax savings
float yrlyMort(int intl_bal, float int_pay);//Calculate annual mortgage
float int_pymnt(int intl_bal, float int_rate);//Calculate interest on payment

//For Problem 7
float hatsize(int weight, float height, const float ht_sz_cnst);//Returns size of hat fitted to measurements given

float jcktsize(float height, int weight, const float jkt_sz_cnst);//Returns jacket size fitted to given measurements

float wstsize(int weight, const float wst_sz_cnst);//Returns waist size of pants fitted to given measurements

//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while (m_running) {
        cout<<"1.  Savitch, 8thEd, Chapter 4, Problem 1\n";
        cout<<"2.  Savitch, 8thEd, Chapter 4, Problem 2\n";
        cout<<"3.  Savitch, 8thEd, Chapter 4, Problem 3\n";
        cout<<"4.  Savitch, 8thEd, Chapter 4, Problem 4\n";
        cout<<"5.  Savitch, 8thEd, Chapter 4, Problem 7\n";
        cout<<"6.  Savitch, 8thEd, Chapter 4, Problem 8\n";
        cout<<"7.  Savitch, 8thEd, Chapter 4, Problem 9\n";
        cout<<"8.  Gaddis,  7thEd, Chapter 5, Problem 1\n";
        cout<<"9.  Gaddis,  7thEd, Chapter 5, Problem 2\n";
        cout<<"10. Gaddis,  7thEd, Chapter 5, Problem 18\n";
        cout<<"11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        //Begin menu
        switch(m_choice){
            case(1):{
                //Problem 1
                //Declare variables
                const float LPG=.264179;//gallons in a liter
                bool repeatYN();
                float mpg(int mile, int litr);//Returns the miles per gallon traveled given
                bool running= true;           //by the vehicle
                int mile, litr;
                float mi_gal;
                 
                
                //Input Miles and Gallons
                while(running)
                {
                    cout<<"Enter the distance traveled in miles: ";
                    cin>>mile;
                    cout<<"Enter the number of liters consumed over "<<mile<<" miles: ";
                    cin>>litr;

                //Output mpg
                    mi_gal= mpg(mile,litr);//returns value miles per gallon
                    cout<<"Over a "<<mile<<" mile distance, the car delivered "<<mi_gal<<" miles per gal."<<endl;
                    running=repeatYN();
                    cout<<endl;
                }

                //End problem 1
                break;
            }
            case(2):{
                //Problem 2
                bool running= true;
                int mi_one, mi_two, litr_one, litr_two;
                float mi_gal_one, mi_gal_two;

                //Input Miles and Gallons
                while(running)
                {
                    cout<<"Enter the distance traveled in miles for Car 1: ";
                    cin>>mi_one;
                    cout<<"Enter the distance traveled in miles for Car 2: ";        
                    cin>>mi_two;
                    cout<<"\n";
                    cout<<"Enter the number of liters consumed in miles for Car 1: ";
                    cin>>litr_one;
                    cout<<"Enter the number of liters consumed in miles for Car 2: ";   
                    cin>>litr_two;
                    cout<<"\n";

                //Output mpg of both cars
                    mi_gal_one= mpg(mi_one,litr_one);//returns value of 1st car miles per gallon
                    mi_gal_two= mpg_two(mi_two,litr_two);//returns value 2nd car miles per gallon
                    cout<<"Over a "<<mi_one<<" mile distance, Car 1 delivered "<<mi_gal_one<<" miles per gal."<<endl;
                    cout<<"\n";

                    mi_gal_two= mpg(mi_two,litr_two);//returns value miles per gallon
                    cout<<"Over a "<<mi_two<<" mile distance, Car 2 delivered "<<mi_gal_two<<" miles per gal."<<endl;
                    cout<<"\n";
                    if (mi_gal_one>mi_gal_two)
                    {
                        cout<<"Car 1 is more fuel efficient than Car 2\n";
                    }
                    else if (mi_gal_one==mi_gal_two)
                    {
                        cout<<"Both cars have the same fuel efficiency\n";
                    }
                    else
                    {
                        cout<<"Car 2 is more fuel efficient than Car 1\n";
                    }
                    running=repeatYN();
                    cout<<endl;
                }
                break;
            }
            case(3):{
                //Problem 3
                //Declare variables
                bool running = true;//Status of whether the program should continue running
                int numera;//Numerator of the fractional part
                int denomi;//Denominator of the fractional part
                int shar_own;//Number of the shares owned
                int wh_dol;//Whole dollar value of the stock
                double ttl_val;//Total value of the user's holdings
                //Input and While loop
                while(running) {
                    cout<<"Enter the numerator of the fractional part: ";
                    cin>>numera;
                    cout<<"Enter the denominator of the fractional part: ";
                    cin>>denomi;
                    cout<<"Enter number of shares you own: ";
                    cin>>shar_own;
                    cout<<"Enter whole dollar value of the stock: ";
                    cin>>wh_dol;
                    cout<<endl;
                    //Calculate the total value of the users holdings
                    ttl_val = fractToDeci(wh_dol, numera, denomi)*shar_own;
                    //Output the dollar value in decimal form
                    cout<<"The total value of your holdings is: $"<<ttl_val<<endl;
                    //Determine if the user wants to repeat the program
                    cout<<"Would you like to repeat this calculation?\n";
                    running = repeatYN();
                    cout<<endl; 
                }
                break;
            }
            case(4):{
                //Problem 4
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
                break;
            }
            case(5):{
                //Declare variables
                //Inputs
                float distance; //Distance between the two objects(in centimeters)
                float mass_one, mass_two;//Masses of the two objects, in grams
                bool running = true;//Should program continue running

                //Enter program loop
                while(running) {
                    //Input data
                    cout<<"Enter the distance between the two objects in centimeters: ";
                    cin>>distance;
                    cout<<"Enter the mass of the first object in grams: ";
                    cin>>mass_one;
                    cout<<"Enter the mass of the second object in grams: ";
                    cin>>mass_two;
                    cout<<endl;

                    //Output gravitational force
                    cout<<"The gravitational force between the two objects is: "
                        <<gravForce(mass_one, mass_two, distance)<<" dyn.\n";

                    //Run program again decision
                    cout<<"Do you want to new values for the calculation?\n";
                    running = repeatYN();
                    }
                break;
            }
            case(6):{
                //Problem 6
                //Declare variables
                const float cnst_tax_rt = 3.5e-1f;//Marginal tax rate
                const float cnst_int_rt = 6e-2f;//Interest rate
                bool running = true;//Status of whether the program should continue running
                int intl_bal;//Initial loan balance
                float int_pay;//Interest payment
                //Inputs
                int dwn_pay;//Down payment on house
                int hou_cost;//The house cost
                //Output
                float annl_cost;//Total annual cost

                //Program loop
                while(running){
                    //Get the house price and down payment from user
                    cout<<"How much did the house cost?: ";
                    cin>>hou_cost;
                    cout<<"How much was the down payment?: ";
                    cin>>dwn_pay;
                    cout<<endl;

                    //Calculations
                    intl_bal = hou_cost-dwn_pay;//Calculate initial balance
                    int_pay = int_pymnt(intl_bal, cnst_int_rt);//Calculate interest payments
                    //Total after tax payment is total payment minus tax deductions
                    annl_cost = yrlyMort(intl_bal, int_pay)-savetax(int_pay, cnst_tax_rt);

                    //Output result
                    cout<<"The total after tax cost for your new house for the first year is: $"<<annl_cost<<endl;

                    //Re-run program
                    cout<<"Do you want to repeat this calculation for another house?\n";
                    running = repeatYN();
                }
                break;
            }
            case(7):
            {
                //Problem 7
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
                cout<<endl;
                break;
            }
            case(8):
            {
                //Problem 8
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
                cout<<endl;
                break;
            }
            case(9):
            {
                //Problem 9
                //Declare variables
                int numb;//Integer to sum
                unsigned int sum = 0;//The sum

                //Do-while loop
                do
                {
                    cout<<"Please enter an integer of 1 or greater: ";
                    cin>>numb;//Input
                }while(numb<1);

                //Sum to the given integer
                for(numb;numb>=1;numb--)
                    sum+=numb;

                //Output result
                cout<<"The sum is: "<<sum<<endl;
                cout<<endl;
                break;
            }
            case(10): {
                //Problem 10
                //Declare variables
                unsigned short width;//Width of the rectangle
                unsigned short length;//Length of the rectangle

                //Input length and width
                do{
                cout<<"Enter length and width of the rectangle, between 2 and 10: ";
                cin>>length>>width;
                cout<<endl;
                }while(length<2||length>10||width<2||width>10);

                //Swap measurements if width greater than length
                if(width>length){
                    unsigned short placekeep = length;//Switching variable
                    length = width;
                    width = placekeep;
                }

                //Output rectangle onscreen
                for(unsigned short c1 = 0;c1<width;c1++){
                    cout<<"     ";
                    for(unsigned short c2 = 0;c2<length;c2++){
                        cout<<"R";
                    }
                }
                cout<<endl;
                break;
            }
            case(11):
                m_running = false;
                break;
            default:
                cout<<"Unknown input, please try again.\n\n";
        }
    }
    //Exit program
    cout << "Now exiting program\n";
    return 0;
}
//Function definitions
//Repeat Program loop
bool repeatYN() {
    char usr_ipt;//User input
    //Run until there is a returned value
    while(true){
        //Get user input
        cout<<"Please enter Y/N: ";
        cin>>usr_ipt;
        switch(usr_ipt) {
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
    return 0;
}

//Function Definition
//Problem 1
float mpg(int mile, int litr)
{
    return mile/(litr*LPG);
}

//Problem 2
float mpg_one(int mi_one, int litr_one)
{
    return mi_one/(litr_one*LPG);
}
float mpg_two(int mi_two, int litr_two)
{
    return mi_two/(litr_two*LPG);
}

//Problem 3
double fractToDeci(int whole, int numera, int denomi)
{
    return (whole+(static_cast<double>(numera)/denomi));
}

//Problem 4
double rateinfl(float prc_last, float prc_cur) 
    {
    return ((prc_cur-prc_last)/prc_last)*DEC_PCT;
    }

//Problem 5
float gravForce(float mass_one, float mass_two, float distance) 
{
    return (uni_grvty*mass_one*mass_two)/(distance*distance);
}

//Problem 6
float savetax(float int_pay, float cnst_tax_rt)
{
    return int_pay*cnst_tax_rt;
}

float int_pymnt(int princp, float cnst_int_rt)
{
    return (princp*cnst_int_rt);
}

float yrlyMort(int ln_bal, float int_pay)
{
    
    const float prcpl_cred = 3e-2f;//3% credit toward the principal
    return int_pay+(ln_bal*prcpl_cred);
}

//Problem 7
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
