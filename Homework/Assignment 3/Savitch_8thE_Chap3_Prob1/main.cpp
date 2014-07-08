/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Savitch 8th EDition Chapter 3 Problem 1
 * Rock, Paper, Scissors Game
 * Created on July 6, 2014, 1:26 PM
 */

//User Defined Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    cout<<"This is a game of Paper, Rock, Scissors\n";
    cout<<"\n";
    
    //Declare Variables
    string sciss_wins = "Scissors cuts paper, ";
    string rock_wins = "Rock breaks scissors, ";
    string pap_wins = "Paper covers rock, ";
    string p1_wins = "player one wins!\n";
    string p2_wins = "player two wins!\n";
    string nb_wins = "Nobody wins.\n";
    string inval_p1 = "Invalid letter entry for Player 1!\n";
    string inval_p2 = "Invalid letter entry for Player 2!\n";
    
    //Inputs
    char player_one, player_two;
    char over;  
    
    //Game Loop
    bool running=true;
    while (running) {
                    //Get user input
                    cout<<"Enter P for paper, R for rock, or S for scissors.\n";
                    cout<<"Player 1 entry: ";
                    cin>>player_one;
                    cout<<"Player 2 entry: ";
                    cin>>player_two;
                    cout<<endl;
        //Who wins and how the game works                 
        switch (player_one) {
                        case 'S':
                        case 's':
                            switch (player_two) {
                                case 'R':
                                case 'r':
                                    cout<<(rock_wins + p2_wins);
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<(sciss_wins + p1_wins);
                                    break;
                                case 'S':
                                case 's':
                                    cout<<nb_wins;
                                    break;
                                default:
                                    cout<<inval_p2;
                            }
                            break;
                        case 'R':
                        case 'r':
                            switch (player_two) {
                                case 'R':   
                                case 'r':
                                    cout<<nb_wins;
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<(pap_wins + p2_wins);
                                    break;
                                case 'S':
                                case 's':
                                    cout<<(rock_wins + p1_wins);
                                    break;
                                default:
                                    cout<<inval_p2;
                            }
                            break;
                        case 'P':
                        case 'p':
                            switch (player_two) {
                                case 'R':
                                case 'r':
                                    cout<<(pap_wins + p1_wins);
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<nb_wins;
                                    break;
                                case 'S':
                                case 's':
                                    cout<<(sciss_wins + p2_wins);
                                    break;
                                default:
                                    cout<<inval_p2;
                            }
                            break;
                        default:
                            cout<<inval_p1;
                    }
    //Play Again
    bool valid = false; 
                    while (!valid) {
                        cout<<endl;
                        cout<<"Want to play again?[Y/N]: ";
                        cin>>over;
                        switch (over) {
                            case 'Y':
                            case 'y':
                                valid = true;
                                break;
                            case 'N':
                            case 'n':
                                cout<<"Until we meet again.\n";
                                valid = true;
                                running = false;
                                break;
                            default:
                                cout<<"That is not a valid answer.\n";
                        }
                    }
    }
        return 0;
}

