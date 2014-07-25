/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on July 24, 2014, 1:52 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

//User Defined Libraries

//Global Constants
const short MNTH_YR = 12;//Months per year

//Function Prototypes
bool repeat();
int charLength(const char[], const int);

//Problem 1 functions
void dltRepeat(char[],int&);

//Problem 2 functions
double stand_devi(double[], int);

//Problem 3 functions
void chRepeat(const int[],const int);

//Problem 4 functions
void sortInt(int[],const int);
void sortOut(const int[],const int);

//Problem 5 functions
void scores(int[],const int,int&);
int perfCount(const int[],const int);

//Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    unsigned short m_choice;
    
    //Seed random number generator
    srand(static_cast<int>(time(0)));
    
    //Enter menu loop
    do {
        cout << "1.  Savitch, 8th Edition, Chapter 7, Problem 3\n";
        cout << "2.  Savitch, 8th Edition, Chapter 7, Problem 4\n";
        cout << "3.  Savitch, 8th Edition, Chapter 7, Problem 5\n";
        cout << "4.  Savitch, 8th Edition, Chapter 7, Problem 6\n";
        cout << "5.  Savitch, 8th Edition, Chapter 7, Problem 7\n";
        cout << "6.  Gaddis,  7th Edition, Chapter 8, Problem 1\n";
        cout << "7.  Gaddis,  7th Edition, Chapter 8, Problem 6\n";
        cout << "8.  Gaddis,  7th Edition, Chapter 8, Problem 7\n";
        cout << "9.  Gaddis,  7th Edition, Chapter 9, Problem 1\n";
        cout << "10. Gaddis,  7th Edition, Chapter 9, Problem 6\n";
        cout << "11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (m_choice) {
            case(1):
            {
                //Problem 1
                //Declare variables
                const int SIZE_MAX = 21;
                char ch_array[SIZE_MAX];//Character array
                int actual_sz;
                
                //Input form user
                cout<<"Enter up to 20 characters: ";
                cin.getline(ch_array, SIZE_MAX);
                
                //Number of characters added to array
                actual_sz = charLength(ch_array, SIZE_MAX);
                actual_sz--;
                cout<<actual_sz<<endl;
                
                //Take away repeated characters from array
                dltRepeat(ch_array, actual_sz);
                
                //Output answs assuming no null delimiter
                cout<<"Array containing no repeated characters: ";
                for(int i = 0;i<actual_sz;i++)
                    cout<<ch_array[i];
                    cout<<endl;
                break;
            }
            case(2):
            {
                //Problem 2
                //Declare variables
                const int SIZE_MAX = 25;//Maximum size of array
                const int NUMB_P_LN = 5;//Number per line
                double examp[SIZE_MAX];//Book says to use double
                int actual_sz = rand()%(SIZE_MAX-NUMB_P_LN+1)+NUMB_P_LN;
                
                //Random number array fill
                for(int i = 0;i<actual_sz;i++)
                    examp[i] = static_cast<double>(rand())/rand();
                
                //Calculate standard deviation
                cout<<"Numbers in the array:\n";
                for(int i = 0;i<actual_sz;i++){
                    cout<<setw(10)<<examp[i];
                    if((i+1)%(NUMB_P_LN+1) == 0)
                        cout<<endl;
                    else
                        cout<<" ";
                }
                cout<<endl;
                cout<<"Standard deviation: "<<stand_devi(examp, actual_sz);
                cout<<endl;
                break;
            }
            case(3):
            {
                //Problem 3
                //Declare variables
                const int SIZE_MAX = 50;//Max size of array
                int int_array[SIZE_MAX];//Array integers
                int real_size;//Real size of array
                char in_choi;//Input choice of file or console supplied by the user
                char file_name[SIZE_MAX];//File name for input
                ifstream int_name;//File containing integers
                
                //Ask the user to read the input by console or by file
                cout<<"Would you like to use the console or a file for input?\n";
                cout<<"Format: [C for console, F for file]: ";
                cin>>in_choi;
                
                //Determine the users choice of input and act accordingly
                if(in_choi == 'c' || in_choi == 'C'){
                    //Read numbers from the console
                    //Simple input validation
                    do{
                        cout<<"How many integers would you like to enter?\n";
                        cout<<SIZE_MAX<<" or less)]: ";
                        cin>>real_size;
                    }while(real_size<0 || real_size>SIZE_MAX);
                    cout<<"Enter "<<real_size<<" integers\n";
                    cout<<"Put a space between each number: ";
                    for(int i = 0;i<real_size;i++)
                        cin>>int_array[i];
                }
                else if(in_choi == 'f' || in_choi == 'F'){
                    //Get the file name
                    cout<<"Please enter the name of the file: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.getline(file_name, SIZE_MAX);
                    //Try to open the file
                    int_name.open(file_name);
                    //If the file not found
                    if(!int_name){
                        cout<<"Error: File not found \""<<file_name<<"\"\n";
                        exit(EXIT_FAILURE);
                    }
                    cout<<"Processing integers, please wait"<<endl;
                    for(real_size = 0;real_size<SIZE_MAX&&int_name>>int_array[real_size];real_size++);
                }
                
                //Sort the array from high to low
                sortInt(int_array, real_size);//Defined in problem 5
                
                //Output
                cout<<"N    Count\n";
                chRepeat(int_array, real_size);
                break;
            }
            case(4):
            {
                //Problem 4
                //Declare variables
                const int SIZE_MAX = 20;//Max size of array
                int exmpl_arr[SIZE_MAX];//Example array used
                
                //Fill the array with random numbers
                for(int i = 0;i<SIZE_MAX;i++)
                    exmpl_arr[i] = rand()%(SIZE_MAX+1);
                
                //Output the unsorted array
                cout<<"Array that's not in order\n";
                sortOut(exmpl_arr, SIZE_MAX);
                
                //Sort the array
                sortInt(exmpl_arr, SIZE_MAX);
                
                //Output the sorted array
                cout<<"Array in order"<<endl;
                sortOut(exmpl_arr, SIZE_MAX);
                break;
            }
            case(5):
            {
                //Problem 5
                //Declare variables
                const int SIZE_MAX = 50;//Max size of array
                int scores[SIZE_MAX];//Scores array
                int real_size;//Actual size of array
                
                //Get the scores from the user
                scores(scores,SIZE_MAX,real_size);
                
                //Output how many scores were perfect
                cout<<"Number of perfect scores out of "<<real_size<<": ";
                cout<<perfCount(scores,real_size)<<endl;
                break;
            }
            
            default:
                cout << "Exiting program\n";
        }
    } while (m_choice > 0 && m_choice <= 10);

    //Exit program
    return 0;
}
//Generally useful functions
//Returns true or false depending if the user wants to repeat the calculation or not
bool repeat(){
    char answer;//Users answer
    
    //Determine if the user wants to repeat the calculation
    cout<<"Want to repeat the calculation?\n";
    cout<<"Enter Y if yes: ";
    cin>>answer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<endl;
    
    return (answer == 'y' || answer == 'Y');
}
//Determine how full an array of characters is
int charLength(const char ch_array[],const int SIZE){
    int actual_sz = 0;
    for(actual_sz;actual_sz<SIZE;actual_sz++){
        if(ch_array[actual_sz] == '\0'){
            actual_sz++;
            break;
        }
    }
    return actual_sz;
}

//Problem 1 functions
//Deletes repeated characters in an array assuming no null terminator and
void dltRepeat(char ch_array[],int& size){
    char same_ch;//Current character to check repeats
    int initl = 0;//Initial index
    
    for(initl;initl<(size-1);initl++){
        same_ch = ch_array[initl];
        for(int i = initl+1;i<size;i++){
            if(same_ch == ch_array[i])
            {
                if(i == size-1)
                    ch_array[i] = '\0';
                //Move characters to the left
                else{
                    for(int j = i, k = i+1;k<size;j++,k++)
                        ch_array[j] = ch_array[k];
                }
                size--;
                i--;
            }
        }
    }
}
//Problem 2 functions
//Calculate the standard deviation for an array
double stand_devi(double num_arr[], int size){
    double avrg = 0;//The average value of all the numbers in the array
    double answ = 0;//Answer of standard deviation
    
    //Calculate the average
    for(int i = 0;i<size;i++)
        avrg += num_arr[i];
    avrg /= size;
    
    for(int i = 0;i<size;i++)
    {
        double x = num_arr[i];
        answ += (x-avrg)*(x-avrg);
    }
        return sqrt(answ/size);
}
//Problem 3 functions
//Count the number of repeated elements in a sorted list and output to the screen
void chRepeat(const int arr[],const int SIZE){
    int curr_num = arr[SIZE-1];
    int count = 1;
    
    for(int i = SIZE-2;i>=0;i--){
        if(curr_num == arr[i])
            count += 1;
        else{
            cout<<setw(5)<<curr_num;
            cout<<setw(7)<<count;
            cout<<endl;
            count = 1;
            curr_num = arr[i];
        }
    }
    cout<<setw(5)<<curr_num;
    cout<<setw(7)<<count;
    cout<<endl;
}
//Problem 4 functions
//Sorts a list according to the insertion sort
void sortInt(int array[],const int SIZE){
    int unsor = 1;//Unsorted portion of the array
    int curr_num;//Current number being sorted
    int swap;//used for swaps
    
    for(unsor;unsor<SIZE;unsor++){
        curr_num = array[unsor];
        
        for(int i = 0;i<=unsor;i++){
            if(curr_num<array[i]){
                swap = array[i];
                array[i] = curr_num;
                curr_num = swap;
            }
            if(i == unsor)
                array[i] = curr_num;
        }
    }
}
void sortOut(const int array[],const int SIZE){
    cout<<"[";
    for(int i = 0;i<SIZE;i++){
        cout<<array[i];
        if(i<SIZE-1)
            cout<<", ";
    }
    cout<<"]\n";
}
//Problem 6 functions
void scores(int score_arr[],const int SIZE,int& real_size){
    const int SCORE_MAX = 100;//Maximum value a score can be
    const int SIZE_MINI = 10;//Minimum number of scores to be entered
    
    do{
        cout<<"Number of scores you want to enter?\n";
        cout<<"Enter number (from 10 to 50): ";
        cin>>real_size;
    }while(real_size<SIZE_MINI || real_size>SIZE);
    
    for(int i = 0;i<real_size;i++){
        do{
            cout<<"Score "<<i+1<<": ";
            cin>>score_arr[i];
        }while(score_arr[i]<0 || score_arr[i]>SCORE_MAX);
    }
}
int perfCount(const int score_arr[], const int SIZE){
    const int PERF_SCR = 100;//Perfect score value
    int perf_numb = 0;//Number of perfect scores
    
    for(int i = 0;i<SIZE;i++){
        if(score_arr[i] == PERF_SCR)
            perf_numb++;
    }
    return perf_numb;
}
