//
//  Game.h
//  TicTacToe Cmd
//
//  Created by Badr AlKhamissi on 1/21/16.
//  Copyright © 2016 Badr AlKhamissi. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "Board.h"
#include "AI.h"


class Game{
private:
    Board board;
    AI aiPlayer, aiPlayer_2;
    bool turn;
    bool isMultiplyer;
    int choice;
public:
    Game();
    void newGame();
    void begin();
    void printInstructions()const;
    bool finishGame(state);
};

Game::Game(){
    turn = true;
    isMultiplyer = false;
    cout<<endl<<"Welcome to XO Command Line:-"<<endl<<endl;
    printInstructions();
}

void Game::newGame(){
    board.clear();
    cout<<"(0)Single (1) Multiplayer (2)Computer Vs. Computer: ";
    cin>>choice;
    cout<<endl;
}

void Game::begin(){
    bool play = true;
    int x = 0, y = 0;
    state current = nothing;
    newGame();

    while (play) {
        while (true) {
            //Instructions for which player to enter
            if(choice == 1){
                if(!turn){
                    cout<<"Player O: ";
                    cin>>x>>y; //Location of the X/O in the game
                }else{
                    cout<<"Player X: ";
                    cin>>x>>y; //Location of the X/O in the game
                }
            }else if(choice == 0){
                if (!turn) {
                    cout<<"Computer:- ";
                    aiPlayer.makeMove(board,computer);
                    turn = !turn;
                    break;
                }else{;
                    cout<<"Player: ";
                    cin>>x>>y; //Location of the X/O in the game
                }
            }else{
                if (!turn) {
                    aiPlayer.makeMove(board,computer);
                }else{
                    aiPlayer_2.makeMove(board,human);
                }
                turn = !turn;
                break;
            }
   
            cout<<endl;
            
            //Validate input is correct
            if (board.validate(x, y)) {
                board.setVal(x, y, turn ? human:computer);
                turn = !turn; // Switch turns
                break;
            }else{
                if(x>=0 && x<3 && y>=0 && y<3)
                    cerr<<"Error! Location is Taken"<<endl;
                else
                    cerr<<"Error! Location do not exist"<<endl;
            }
        }
        
        board.displayMatrix();

        current = board.checkWin(turn ? human:computer);
        
        //Terminate game
        if (current != nothing) {
            if(!finishGame(current)){
                play = false;
            }else{
                newGame();
            }
        }
        for (int i = 0; i<3; i++) cout<<endl;
    }
}

void Game::printInstructions()const{
    cout<<"Instructions:-"<<endl;
    cout<<"Input format 2 digits seperated by space -- Location (0,0) top left and (2,2) bottom right"<<endl<<endl;
}

bool Game::finishGame(state current){
    switch (current) {
        case win:
            if(isMultiplyer) cout<<"X Wins!!\n";
            else cout<<"You Win!!\n";
            break;
        case lose:
            if(isMultiplyer) cout<<"O Wins!!\n";
            else cout<<"Computer Wins!!\n";
            break;
        case draw:
            cout<<"Draw"<<endl;
        default:
            break;
    }
    
    bool again = false;
    cout<<"Play Again: (0)No (1)Yes : ";
    cin>>again;
    
    return again;
}

#endif /* Game_h */
