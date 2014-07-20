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
char choice;
  int hp, init, atk, def, gatk, gdef, hurt, ghurt, agi, gagi, ghp;
  atk = 10;//user attack
  def = 15;//user defense
  agi = 5;//user gagic
  gatk = 10;//gremlin attack
  gdef = 15;//gremlin defense
  gagi = 5;//gremlin gagic
  
  //Random number seeds
  srand((unsigned)time(0));
  init = rand()%2+1;
  ghp = rand()%50 + 60;//health gremlin starts with
  hp = rand()%20 + 80;//health user starts with
  
  //User starts
  if (init == 1) 
  {
  cout<<"You start.\n";
  while (hp > 0 || ghp > 0) 
  {
    cout<<"What do you want to do?"<<endl<<"1 - Strong Attack"<<endl<<"2 - Magic Attack"<<endl"3 - Defensive moves\n";
     do
     {
         cin>>choice;
     }while(choice>3 || choice<1);
     
//User Menu
    switch (choice) {
      case 1:
        atk = rand()%20+10;
	def = rand()%10+10;
	agi = rand()%5;
	break;
      case 2:
        atk = rand()%5+10;
	def = rand()%10+10;
	agi = rand()%15;
        break;
      case 3:
        atk = rand()%10+10;
	def = rand()%20+10;
	agi = rand()%5;
	break;
	}
  }}
    return 0;
}

