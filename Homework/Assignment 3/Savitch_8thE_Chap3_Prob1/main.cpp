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
    string PAPER_WINS = "Paper covers rock, ";
    string ROCK_WINS = "Rock breaks scissors, ";
    string SCISSOR_WINS = "Scissors cuts paper, ";
    string PLAYER_ONE_WINS = "player one wins!\n";
    string PLAYER_TWO_WINS = "player two wins!\n";
    string NOBODY_WINS = "Nobody wins.\n";
    string INVALID_LTTR_P1 = "Invalid letter entry for Player 1!\n";
    string INVALID_LTTR_P2 = "Invalid letter entry for Player 2!\n";
    
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
                        case 'R':
                        case 'r':
                            switch (player_two) {
                                case 'R':   
                                case 'r':
                                    cout<<NOBODY_WINS;
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<(PAPER_WINS + PLAYER_TWO_WINS);
                                    break;
                                case 'S':
                                case 's':
                                    cout<<(ROCK_WINS + PLAYER_ONE_WINS);
                                    break;
                                default:
                                    cout<<INVALID_LTTR_P2;
                            }
                            break;
                        case 'P':
                        case 'p':
                            switch (player_two) {
                                case 'R':
                                case 'r':
                                    cout<<(PAPER_WINS + PLAYER_ONE_WINS);
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<NOBODY_WINS;
                                    break;
                                case 'S':
                                case 's':
                                    cout<<(SCISSOR_WINS + PLAYER_TWO_WINS);
                                    break;
                                default:
                                    cout<<INVALID_LTTR_P2;
                            }
                            break;
                        case 'S':
                        case 's':
                            switch (player_two) {
                                case 'R':
                                case 'r':
                                    cout<<(ROCK_WINS + PLAYER_TWO_WINS);
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<(SCISSOR_WINS + PLAYER_ONE_WINS);
                                    break;
                                case 'S':
                                case 's':
                                    cout<<NOBODY_WINS;
                                    break;
                                default:
                                    cout<<INVALID_LTTR_P2;
                            }
                            break;
                        default:
                            cout<<INVALID_LTTR_P1;
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

