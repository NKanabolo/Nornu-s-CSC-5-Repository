/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * CSC 5 Project 2
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Function Prototypes
//Play again
//Keeping score
//user scores called by reference function
void keepScoreUsr(int& usr_score, int& comp_score, int& value_usr);
//gremlin scores called by references function
void keepScoreComp(int& comp_score, int& usr_score, int& value_comp);
//displays map function
void passArr();
//loops program so score is tallied
bool repeat();
//Countdown timer function
void cntDwn(int strt,int freeze);
//Pause function
void pause(int secs);
int timer(int=0);
//Execution
int main(int argc, char** argv){
    //Declare variables
    int choice, usr_point=0, comp_point=0, value_point=0;
    int hp, start, atk, def, mag, hurt, gatk, gdef, ghurt, gmag, ghp;
    atk = 12;//user attack
    def = 18;//user defense
    mag = 7;//user magic
    gatk = 14;//gremlin attack
    gdef = 18;//gremlin defense
    gmag = 7;//gremlin magic
    
    cout<<timer()<<" secs"<<endl;
    do{
        //Random seed that determines who starts
        start = rand()%2+1;
        hp = rand()%60+97;//health points user starts with
        ghp = rand()%40+98;//health points gremlin starts with

        //Project map
        passArr();
        
        //Setup the random number seed
        srand(static_cast<unsigned int>(time(0)));

        //Start the Count Down
        
        //Display health for both characters
        cout<<endl<<endl<<"Wizard health: "<<hp<<endl;
        cout<<"Gremlin health: "<<ghp<<endl<<endl;
        if (start == 1) 
        {
            cout<<"You attack first and swiftly!";
            cout<<endl;
            //User Menu
            while (hp > 0 && ghp > 0) {
            cout<<"Choose what move you want to execute"<<endl;
            cout<<"1 - Strong Attack"<<endl;
            cout<<"2 - Magic Attack"<<endl;
            cout<<"3 - Health Potion + Defensive Move"<<endl;
            do
            {
                cin>>choice;
            }while(choice>3 || choice<1);
            switch (choice) 
            {
            case 1:
                atk = rand()%20+10;
                def = rand()%10+10;
                mag = rand()%5;
                break;
            case 2:
                atk = rand()%5+10;
                def = rand()%10+10;
                mag = rand()%15;
                break;
            case 3:
                atk = rand()%10+10;
                def = rand()%20+10;
                mag = rand()%5;
                hp += 20;
                break;
            }

            //Gremlin Menu decides which move it executes
            choice = rand()%3;
            switch (choice) 
            {
            case 1:
                gatk = rand()%20+10;
                gdef = rand()%10+10;
                gmag = rand()%5;
                break;
            case 2:
                gatk = rand()%5+10;
                gdef = rand()%10+10;
                gmag = rand()%15;
                break;
            case 3:
                gatk = rand()%10+10;
                gdef = rand()%20+10;
                gmag = rand()%5;
                ghp += 40;
                break;
            }

            //Damage to gremlin
            ghurt = (atk - gmag) - (gdef/atk);
            if (ghurt < 0) 
            {
                ghurt = 0;
            }
            ghp = ghp - ghurt;
            cout<<"You did "<<ghurt<<" damage to the gremlin!";
            cout<<endl;

            //If user defeats gremlin
            if (ghp < 1) 
            {
                cout<<"You destroyed the gremlin! You are victorious with "<<hp<<" hp to spare.";
                cout<<endl;
                keepScoreUsr(usr_point, comp_point, value_point);//displays user score

                
            }
            if(ghp>0) {
                cout<<"The gremlin now has "<<ghp<<" hp left.";
                cout<<endl;
            }
            hurt = (gatk - mag) - (def/gatk);
            if (hurt < 0) 
            {
                hurt = 0;
            }
            hp = hp - hurt;
            if (hp>0 && hp<25){
                cout<<"Low health! Use health potion before it's too late!\n";
                timer();
                 cout<<"Timer = "<<timer()<<" secs"<<endl;
            }else{
                timer(3);
                timer(1);
                timer(2);
            }
            if (timer()>10){
                cout<<"Health potion not used in time. Game Over. You lose.\n";
            }
            //If gremlin defeats user
            if (hp < 1) 
            {
                cout<<"You have been defeated. The gremlin lives with "<<ghp<<" hp remaining.";
                cout<<endl;
                keepScoreComp(comp_point, usr_point, value_point);//displays gremlin score
            }
            if (hp>0){
                cout<<"You now have "<<hp<<" hp left.\n"<<endl;
            }
            }
            }

        //The gremlin starts
        else 
        {
            cout<<"Gremlin attacked first!"<<endl;
            
            while (hp > 0 && ghp > 0&&timer()<=10) {
                cout<<"Timer = "<<timer()<<" secs"<<endl;
            choice = rand()%3;
            switch (choice) 
            {
            case 1:
                gatk = rand()%20+10;
                gdef = rand()%10+10;
                gmag = rand()%5;
                break;
            case 2:
                gatk = rand()%5+10;
                gdef = rand()%10+10;
                gmag = rand()%15;
                break;
            case 3:
                gatk = rand()%10+10;
                gdef = rand()%20+10;
                gmag = rand()%5;
                ghp += 40;
                cout<<"Gremlin stole your health potion!\n";
                break;
            }

            //Gremlin does damage to user
            hurt = (gatk - mag) - (def/gatk);
            if (hurt < 0) 
            {
                hurt = 0;
            }
            hp = hp - hurt;
            cout<<"The gremlin hit you for "<<hurt<<" damage.";
            cout<<endl;
            
            if (hp>0 && hp<25){
                cout<<"Low health! Use health potion before it's too late!\n";
                timer();
                 cout<<"Timer = "<<timer()<<" secs"<<endl;
            }else{
                timer(3);
                timer(1);
                timer(2);
            }

            //If the gremlin kills the user
            if (hp < 1) 
            {
                cout<<"You were killed. The gremlin still has "<<ghp<<" hp left.";
                cout<<endl;
                keepScoreComp(comp_point, usr_point, value_point);
            }
            if (hp>0){
                cout<<"You now have "<<hp<<" hp left.";
                cout<<endl;
            }

            //Next move for user if not killed
            cout<<"Choose what move you want to execute"<<endl;
            cout<<"1 - Strong Attack"<<endl;
            cout<<"2 - Magic Attack"<<endl;
            cout<<"3 - Health Potion + Defensive Move"<<endl;
            do{cin>>choice;}while(choice>3 || choice<1&&hp>0&&timer()<=10);
            switch (choice) 
            {
            case 1:
                atk = rand()%20+10;
                def = rand()%10+10;
                mag = rand()%5;
                break;
            case 2:
                atk = rand()%5+10;
                def = rand()%10+10;
                mag = rand()%15;
                break;
            case 3:
                atk = rand()%10+10;
                def = rand()%20+10;
                mag = rand()%5;
                hp+=20;
                break; 
            }
            
            //User hurts gremlin
            ghurt = (atk - gmag) - (gdef/atk);
            if (ghurt < 0) 
            {
                ghurt = 0;
            }
            ghp = ghp - ghurt;
            if (timer()>10){
                cout<<"Health potion not used in time. Game Over. You lose.\n";
            }else{
            cout<<"You did "<<ghurt<<" damage to the gremlin!";
            cout<<endl;
            }
            
            //User wins
            if (ghp < 1) 
            {
                cout<<"You destroyed the gremlin! You are victorious!";
                cout<<endl;
                keepScoreUsr(usr_point, comp_point, value_point);
            }
            if(ghp>0){
                cout<<"The gremlin now has "<<ghp<<" hp left."<<endl;
                cout<<endl;
            }
            }
        }
    }while(repeat());
    return 0;
}

//User score keeping function
//Score keeping function
void keepScoreUsr(int& usr_score, int& comp_score, int& value_usr)
{
    usr_score++;
    usr_score=usr_score+value_usr;
    cout<<endl<<"Your Score: "<<usr_score<<endl;
    cout<<endl<<"Gremlin's Score: "<<comp_score<<endl;
}

//Gremlin score keeping function
void keepScoreComp(int& comp_score, int& usr_score,int& value_comp)
{
    comp_score++;
    comp_score=comp_score+value_comp;
    cout<<endl<<"Gremlin's Score: "<<comp_score<<endl;
    cout<<endl<<"Your Score: "<<usr_score<<endl;
}

//Map displaying function
void passArr(){
    const int SIZE = 45;
    string map [SIZE];\
    fstream file;
    file.open("map.txt");
    
    for(int i=0;i<SIZE;i++)
        getline(file,map[i]);
    
    file.close();
    
    for(int i=0;i<SIZE;i++)
        cout<<map[i]<<endl;
}

//Function to repeat program
bool repeat(){
    char choice;
    do{
        cout<<"Do you want to continue [y/n]?"<<endl;
        cin>>choice;
    }while(choice!='y'&&choice!='n');
    if(choice=='y'){
        return true;
    }
    if(choice=='n'){
        return false;
    }
}
int timer(int flag){
    //Declare Variables
    static int strt=time(0);
    static int secs=time(0);
    static bool stop=false;
    int now=time(0);
    if(stop&&flag!=2){ //Stopped and not reset
        return secs;
    }else if(flag==0){ //Normal timer
        secs=now-strt;
    }else if(flag==3){ //Reset
        strt=time(0);
        secs=now-strt;
    }else if(flag==2){ //Restart
        stop=false;
        strt=now-secs;
    }else{             //When stopped
        stop=true;
        secs=now-strt;
    }
    return secs;
}
void cntDwn(int strt,int freeze){
    //Perform the countdown
    do{
        cout<<strt<<" seconds remaining"<<endl;
        strt-=freeze;
        pause(freeze);
    }while(strt>0);
    cout<<strt<<" seconds"<<endl;
}

void pause(int secs){
    //Start the time
    int stp,wait,strt=time(0);
    do{
        stp=time(0);
        wait=stp-strt;
    }while(wait<=secs);
}
