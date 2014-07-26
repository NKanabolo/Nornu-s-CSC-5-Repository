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
int length(char []);
bool digitAdd(char,char,char &,bool=false);
int sizeResult(char [],char []);
bool numberAdd(char [],char [],char []);

//Problem 6 functions
void score(int[],const int,int&);
int perfCount(const int[],const int);

//Problem 7 functions
void lottOut(const int[],const int,const int);

//Problem 8 functions
void data(double[],const string[],const short);
double ttlRain(const double[],const short);
double avrgRain(const double);
double lowRain(const double[],const short,int&);
double highRain(const double[],const short,int&);

//Problem 10 functions
void eleOut(const string[],const int,const int);
void sortSlct(string[],const int);

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
                
                //Output
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
                
                cout<<"Use keyboard or a file for input?(K for keyboard, F for file)"<<endl;
                cin>>in_choi;
                
                //Input
                if(in_choi == 'k' || in_choi == 'K'){
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
                
                //Unsorted array
                cout<<"Array that's not in order\n";
                sortOut(exmpl_arr, SIZE_MAX);
                
                sortInt(exmpl_arr, SIZE_MAX);
                
                //Output sorted array
                cout<<"Array in order"<<endl;
                sortOut(exmpl_arr, SIZE_MAX);
                break;
            }
            case(5):
            {
                const int SIZE_MAX=20;
                char number1[SIZE_MAX];
                char number2[SIZE_MAX];
                
                char numb1, numb2;
                char result[sizeResult(number1,number2)];
                
                //Input numbers
                cout<<"Enter a maximum of 20 numbers each to add."<<endl;
                cin>>numb1;
                cout<<endl;
                cin>>numb2;
                //Add the numbers
                int width=22;
                cout<<right;
                cout<<setw(width)<<number1<<endl;
                cout<<"+"<<setw(width-1)<<number2<<endl;
                bool x=numberAdd(number1,number2,result);
                if(x)cout<<"overflow"<<endl;
                else cout<<setw(width)<<result<<endl;

            }
            case(6):
            {
                //Problem 6
                //Declare variables
                const int SIZE_MAX = 50;//Max size of array
                int scores[SIZE_MAX];//Scores array
                int real_size;//Actual size of array
                
                //Scores from user
                score(scores,SIZE_MAX,real_size);
                
                //Output how many scores were perfect
                cout<<"Number of perfect scores out of "<<real_size<<": ";
                cout<<perfCount(scores,real_size)<<endl;
                break;
            }
            case(7):
            {
                //Problem 7
                //Declare variables
                const int SIZE_LOTT = 5;//Number of lottery numbers
                int winnerNumb[SIZE_LOTT];//The winning digits
                int player[SIZE_LOTT];//The players digits
                int match = 0;//The number of matching digits
                
                //Input
                cout<<"Input your five lottery digits"<<endl;
                for(int i = 0;i<SIZE_LOTT;i++){
                    //Make random lottery digit
                    winnerNumb[i] = rand()%10;
                    do{
                        cout<<"Put in a lottery digit "<<i+1<<"between 0 and 9: ";
                        cin>>player[i];
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }while(player[i]<0 || player[i]>9);
                    if(winnerNumb[i] == player[i])
                        match++;
                }
                
                cout<<"The winning digits: ";
                lottOut(winnerNumb,SIZE_LOTT,SIZE_LOTT);
                cout<<"Your digits:    ";
                lottOut(player,SIZE_LOTT,SIZE_LOTT);
                cout<<"Number of digits that matched yours is: "<<match<<endl;
                cout << endl;
            }
            case(8):
            {
                //Problem 8
                //Declare variables
                const int FRST_YR = 1900;
                const int FINAL_YR = 2014;
                const string month[MNTH_YR] = {"January", "February", "March", "April", "May", "June", "July", 
                "August", "September", "October", "November", "December"};
                unsigned short year;//Current year
                string location;//Where data was taken
                double rn_array[MNTH_YR];//Array for rain data
                double total;//Total rainfall for the year
                int wet_mnth = 0;//Wettest month
                int dry_mnth = 0;//Driest month
                double mini;//Minimum rain
                double maxi;//Max rain
                double avrg;//Average rainfall
                
                //Get user input on the year of the rainfall data
                do{
                    cout<<"Year was the rainfall data taken?"<<endl;
                    cin>>year;
                }while(year<FRST_YR || year>FINAL_YR);
                
                //Where the rainfall data was taken
                cout<<"From where was the data taken?: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, location);
                
                data(rn_array, month, MNTH_YR);
                
                //Calculate rain statistics
                total = ttlRain(rn_array, MNTH_YR);
                avrg = avrgRain(total);
                mini = lowRain(rn_array, MNTH_YR, dry_mnth);
                maxi = highRain(rn_array, MNTH_YR, wet_mnth);
                
                //Output statistics
                cout<<year<<" Rain Report from "<<location<<endl;
                cout<<endl;
                cout<<"Total rainfall: "<<total<<" inches\n";
                cout<<"Average monthly rainfall: "<<avrg<<" inches\n";
                cout<<"Least amount of rain fell in "<<month[dry_mnth]<<" with "<<mini<<" inches.\n";
                cout<<"Most amount of rain fell in "<<month[wet_mnth]<<" with "<<maxi<<" inches.\n";
                cout<<endl;
            }
            case(9):
            {
                //Problem 9
                //Declare variables
                const int SIZE_MAX = 19;//Max size of array
                int acc_array[SIZE_MAX];//Account number array
                int user_acc;//User account number
                bool match = false;//Flag to determine if there is a match
                ifstream acc_file;//File of account numbers given by the book
                
                //Open file
                acc_file.open("account_numbers.txt");
                if(!acc_file){
                    cout<<"Fatal error: \"account_numbers.txt\" not found\n";
                    exit(EXIT_FAILURE);
                }
                
                for(int i = 0;i<SIZE_MAX;i++)
                    acc_file>>acc_array[i];
                
                //Input
                cout<<"Enter your 7 digit account number"<<endl;
                cin>>user_acc;
                
                //Make sure account is in the list
                for(int i = 0;i<SIZE_MAX;i++){
                    if(user_acc == acc_array[i]){
                        match = true;
                        break;
                    }
                }
                
                //Output if a match
                cout<<"The account number you have provided is ";
                if(match)
                    cout<<"valid"<<endl;
                else
                    cout<<"not valid"<<endl;
            }
            case(10):
            {
                //Problem 10
                //Declare variables
                const int ELMNT_P_LNE = 4;//Number of elements per line to be output
                const int SIZE = 20;//Maximum size of the array by the book definition
                string name[SIZE] = //From book to test the program
                {"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
                "Sanchez, Manny", "Whitman, Jean", "Moretti, Bella", "Wu, Hong", 
                "Patel, Renee", "Harrison, Rose", "Smith, Cathy", "Conroy, Pat", 
                "Kelly, Sean", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
                "Allison, Jeff", "Moreno, Juan", "Wolfe, Bill" "Holland, Beth"};
                
                //Unsorted array
                cout<<"Array unsorted"<<endl;
                cout<<"--------------"<<endl;
                eleOut(name, SIZE, ELMNT_P_LNE);
                
                sortSlct(name, SIZE);
                
                //Output sorted array
                cout<<"Array sorted"<<endl;
                cout<<"------------"<<endl;
                eleOut(name, SIZE, ELMNT_P_LNE);
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
    cout<<"]"<<endl;
}

//Problem 5 functions
bool numberAdd(char number1[],char number2[],char result[]){
    //Initialize the result array
    result[sizeResult(number1,number2)-1]='\0';
    for(int i=0;i<=sizeResult(number1,number2)-2;i++){
        result[i]='0';
    }
    //Start the counters
    int rcnt=sizeResult(number1,number2)-2;
    int number1cnt=length(number1)-1;
    int number2cnt=length(number2)-1;
    //Added the first digit
    bool c=digitAdd(number1[number1cnt--],number2[number2cnt--],result[rcnt--]);
    do{
    if(number1cnt<0&&number2cnt<0)return c;
    else if(number1cnt<0)c=digitAdd('0',number2[number2cnt--],result[rcnt--],c);
    else if(number2cnt<0)c=digitAdd(number1[number1cnt--],'0',result[rcnt--],c);
    else c=digitAdd(number1[number1cnt--],number2[number2cnt--],result[rcnt--],c);
    }while(true);
}

int sizeResult(char number1[], char number2[]){
    int size1=length(number1);
    int size2=length(number2);
    if(size1>size2)return size1+1;
    return size2+1;
}

bool digitAdd(char number1,char number2,char &d,bool c){
    int i1=number1-48,i2=number2-48;
    int sum=i1+i2+c;
    d=sum%10+48;
    return sum/10;
}

int length(char a[]){
    int cnt=0;
    do{}while(a[cnt++]!='\0');
    return cnt-1; 
}
//Problem 6 functions
void score(int score_arr[],const int SIZE,int& real_size){
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
    
    for(int i = 0;i<SIZE;i++)
    {
        if(score_arr[i] == PERF_SCR)
            perf_numb++;
    }
    return perf_numb;
}

//Problem 7 functions
//Output elements of integer array to screen
void lottOut(const int array[],const int SIZE,const int ELMNT_P_LNE){
    for(int i = 0;i<SIZE;i++){
        cout<<array[i]<<" ";
        if((i+1)%(ELMNT_P_LNE+1) == 0)
            cout<<endl;
    }
    cout<<endl;
}

//Problem 8 functions
//Get rainfall data for the year
void data(double rn_array[],const string months[],const short SIZE){
    cout<<"Please enter rainfall data in inches\n";
    for(int i = 0;i<SIZE;i++){
        do{
        cout<<"What was the rainfall for "<<months[i]<<"?: ";
        cin>>rn_array[i];
        }while(rn_array[i]<0);
    }
}
//Calculate total rainfall in a year
double ttlRain(const double rn_array[],const short SIZE){
    double total = 0;//Amount of total rainfall
    for(int i = 0;i<SIZE;i++)
        total += rn_array[i];
    return total;
}
//Calculate the average rainfall data
double avrgRain(const double total){
    return total/MNTH_YR;
}
//Get the lowest rainfall of the year
double lowRain(const double rn_array[],const short SIZE, int& dry_mnth){
    for(int i = 1;i<SIZE;i++)
    {
        if(rn_array[dry_mnth]>rn_array[i])
            dry_mnth = i;
    }
    return rn_array[dry_mnth];
}
//Get the highest rainfall of the year
double highRain(const double rn_array[],const short SIZE,int& wet_mnth){
    double max = rn_array[0];
    for(int i = 1;i<SIZE;i++)
    {
        if(rn_array[wet_mnth]<rn_array[i])
            wet_mnth = i;
    }
    return rn_array[wet_mnth];
}

//Problem 10 functions
//Output string array elements
void eleOut(const string array[],const int SIZE,const int ELMNT_P_LNE){
    for(int i = 0;i<SIZE;i++)
    {
        cout<<array[i]<<" | ";
        if((i+1)%(ELMNT_P_LNE+1) == 0)
            cout<<endl;
    }
    cout<<endl;
}
//Selection sort for strings
void sortSlct(string strng_arr[],const int SIZE){
    int init_ind;//Initial index
    int minval_ind;//Minimum value index
    string val_mini;//The minimum value
    for(init_ind = 0;init_ind<(SIZE-1);init_ind++)
    {
        minval_ind = init_ind;
        val_mini = strng_arr[init_ind];
        for(int i = (init_ind+1);i<SIZE;i++)
        {
            if(val_mini.compare(strng_arr[i])>0)
            {
                val_mini = strng_arr[i];
                minval_ind = i;
            }
        }
        strng_arr[init_ind] = val_mini;
        strng_arr[minval_ind] = strng_arr[init_ind];
        
    }
}