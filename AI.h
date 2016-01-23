//
//  AI.h
//  TicTacToe Cmd
//
//  Created by Badr AlKhamissi on 1/21/16.
//  Copyright © 2016 Badr AlKhamissi. All rights reserved.
//

#ifndef AI_h
#define AI_h

#include <iostream>
#include <vector>
#include <set>
#include "Board.h"

using namespace std;


class AI{
private:
    struct AIMove{
        int x, y, score;
        AIMove(){}
        AIMove(int _s):score(_s){}
        AIMove(int _x, int _y){x = _x, y = _y;}
    };
public:
    void makeMove(Board&, player);
    AIMove getBestMove(Board&, player);
};

void AI::makeMove(Board& board, player p){
    AIMove bestMove = getBestMove(board, p);
    cout<<"AI Score: "<<bestMove.score*-1<<endl;
    board.setVal(bestMove.x, bestMove.y, p);
}

AI::AIMove AI::getBestMove(Board& board, player playerTurn){
    
    state gameState = board.checkWin(playerTurn);
    if(gameState == win){
        return AIMove(10);
    }else if(gameState == lose){
        return AIMove(-10);
    }else if(gameState == draw){
        return AIMove(0);
    }
    
    vector<AIMove>moves;
    
    for (int i = 0; i<board.getSize(); i++) {
        for (int j = 0; j<board.getSize(); j++) {
            if(board.isEmpty(i,j)){
                AIMove move;
                move.x = i; move.y = j;
                board.setVal(i, j, playerTurn);
                //board.displayMatrix();
         
                if(playerTurn == computer)
                    move.score = getBestMove(board, human).score;
                else
                    move.score = getBestMove(board, computer).score;
                
                moves.push_back(move);
                board.setVal(i,j,empty);
            }
        }
    }
    
    int bestMove = 0;
    if(playerTurn == computer){
        int min = INT_MAX;
        for (int i = 0; i<moves.size(); i++) {
            if(moves[i].score < min) min = moves[i].score, bestMove = i;
        }
    }else{
        int max = INT_MIN;
        for (int i = 0; i<moves.size(); i++) {
            if(moves[i].score > max) max = moves[i].score, bestMove = i;
        }
    }
    
    return moves[bestMove];
}

#endif /* AI_h */
