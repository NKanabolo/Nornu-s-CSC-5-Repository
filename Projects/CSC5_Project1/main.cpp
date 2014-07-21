/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on July 19, 2014, 10:59 PM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables
    char choice;
    int hp, init, atk, def, gatk, gdef, hurt, ghurt, mag, gmag, ghp;
    atk = 10;//user attack
    def = 15;//user defense
    mag = 5;//user magic
    gatk = 15;//gremlin attack
    gdef = 20;//gremlin defense
    gmag = 10;//gremlin magic

    //Random number seeds
    srand((unsigned)time(0));
    init = rand()%2+1;
    ghp = rand()%50 + 60;//health gremlin starts with
    hp = rand()%20 + 80;//health user starts with
  
    //User starts
    if (init == 1) 
    {
    cout<<"You start."<<endl;
    while (hp > 0 || ghp > 0) 
    {
    cout<<"What is your first move?"<<endl<<"1 - Strong Attack"<<endl<<"2 - Magic Attack"<<endl"3 - Defensive moves"<<endl;
     do
     {
         cin>>choice;
     }while(choice>3 || choice<1);
     
    //User Menu
    switch (choice) {
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
    
  //Gremlin Menu
    choice = rand()%3;
    switch (choice) {
      case 1:
        gatk = rand()%20+15;
	gdef = rand()%10+20;
	gmag = rand()%5;
	break;
      case 2:
        gatk = rand()%5+15;
	gdef = rand()%10+20;
	gmag = rand()%15;
        break;
      case 3:
        gatk = rand()%10+15;
	gdef = rand()%20+20;
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
    cout<<"You did "<<ghurt<<" damage to the gremlin!"<<endl;
    cin.get();
    
    //User damages gremlin
    if (ghp < 1) {
      cout<<"You destroyed the gremlin! You are victorious with "<<hp<<" hp to spare."<<endl;
      cin.get();
      }
    cout<<"The gremlin now has "<<ghp<<" hp left."<<endl;
    hurt = (gatk - mag) - (def/gatk);
    if (hurt < 0) {
      hurt = 0;
    }
    hp = hp - hurt;
    cout<<"The gremlin administered to you "<<hurt<<" damage."<<endl;
    
    //Gremlin damages user
    if (hp < 1) {
      cout<<"You died. The beast still has "<<ghp<<" hp remaining."<<endl;
      cin.get();
      }
    cout<<"You now have "<<hp<<" hp left."<<endl;
    cout<<endl;
     }
     }
    //The gremlin starts
    else 
    {
    cout<<"Gremlin start."<<endl;
    while (hp > 0 || ghp > 0) 
    {
    choice = rand()%3;
    switch (choice) 
    {
      case 1:
        gatk = rand()%20+15;
	gdef = rand()%10+20;
	gmag = rand()%5;
	break;
      case 2:
        gatk = rand()%5+15;
	gdef = rand()%10+20;
	gmag = rand()%15;
        break;
      case 3:
        gatk = rand()%10+15;
	gdef = rand()%20+20;
	gmag = rand()%5;
	break;
    }
    //Gremlin does damage to user
    hurt = (gatk - mag) - (def/gatk);
    if (hurt < 0) {
      hurt = 0;
    }
    hp = hp - hurt;
    cout<<"The gremlin hit you for "<<hurt<<" damage."<<endl;
    //User killed by gremlin
    if (hp < 1) {
      cout<<"You died. The gremlin still has "<<ghp<<" hp left."<<endl;
      cin.get();
      return 0;
      }
    }
    }
    return 0;
}

