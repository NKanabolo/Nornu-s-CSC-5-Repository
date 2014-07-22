/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * CSC 5 Project 1
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
    //Declare variables
    int choice;
    int hp, start, atk, def, mag, hurt, gatk, gdef, ghurt, gmag, ghp;
    atk = 12;//user attack
    def = 18;//user defense
    mag = 7;//user magic
    gatk = 14;//gremlin attack
    gdef = 18;//gremlin defense
    gmag = 7;//gremlin magic

    //Random seed that determines who starts
    start = rand()%2+1;
    hp = rand()%60+100;//health points user starts with
    ghp = rand()%40+100;//health points gremlin starts with
    
    //User starts
    if (start == 1) 
    {
        cout<<"You attack first and swiftly!";
        cout<<endl;
    
        //User Menu
        while (hp > 0 || ghp > 0) {
        cout<<"Choose what move you want to execute"<<endl;
        cout<<"1 - Strong Attack"<<endl;
        cout<<"2 - Magic Attack"<<endl;
        cout<<"3 - Defensive Move"<<endl;
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
        return 0;
        }
        cout<<"The gremlin now has "<<ghp<<" hp left.";
        cout<<endl;
        hurt = (gatk - mag) - (def/gatk);
        if (hurt < 0) 
        {
            hurt = 0;
        }
        hp = hp - hurt;
        cout<<"The gremlin administered to you "<<hurt<<" damage.";
        cout<<endl;

        //If gremlin defeats user
        if (hp < 1) 
        {
            cout<<"You have been defeated. The gremlin lives with "<<ghp<<" hp remaining.";
            cout<<endl;
        return 0;
        }
        cout<<"You now have "<<hp<<" hp left.\n"<<endl;
        }
        }

    //The gremlin starts
    else 
    {
        cout<<"Gremlin attacked first!"<<endl;
        while (hp > 0 || ghp > 0) {
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

        //If the gremlin kills the user
        if (hp < 1) 
        {
            cout<<"You were killed. The gremlin still has "<<ghp<<" hp left.";
            cout<<endl;
        return 0;
        }
        cout<<"You now have "<<hp<<" hp left.";
        cout<<endl;

        //Next move for user if not killed
        cout<<"Choose what move you want to execute"<<endl;
        cout<<"1 - Strong Attack"<<endl;
        cout<<"2 - Magic Attack"<<endl;
        cout<<"3 - Defensive Move"<<endl;
        do{cin>>choice;}while(choice>3 || choice<1);
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
            break;
        }

        //User hurts gremlin
        ghurt = (atk - gmag) - (gdef/atk);
        if (ghurt < 0) 
        {
            ghurt = 0;
        }
        ghp = ghp - ghurt;
        cout<<"You did "<<ghurt<<" damage to the gremlin!";
        cout<<endl;

        //User wins
        if (ghp < 1) 
        {
            cout<<"You destroyed the gremlin! You are victorious with "<<hp<<" hp remaining!";
            cout<<endl;
        return 0;
        }
        cout<<"The gremlin now has "<<ghp<<" hp left."<<endl;
        cout<<endl;
        }
      }
}

