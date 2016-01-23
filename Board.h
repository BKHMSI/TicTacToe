//
//  Board.h
//  TicTacToe Cmd
//
//  Created by Badr AlKhamissi on 1/21/16.
//  Copyright © 2016 Badr AlKhamissi. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <iostream>
#include <iomanip>

using namespace std;

enum player{
    human, computer, empty
};

enum state{
    nothing,win,lose,draw
};

class Board{
private:
    int size;
    bool turn;
    int count;
    char matrix[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
public:
    Board(int sz = 3);
    void displayMatrix();
    bool validate(int,int);
    state checkWin(player);
    void setVal(int, int,player);
    bool isEmpty(int x, int y)const{return matrix[x][y] == ' ';};
    int getSize()const{return size;}
    bool getTurn()const{return turn;}
    void clear();
};


Board::Board(int sz){
    size = sz;
    turn = false;
    count = 0;
}

void Board::displayMatrix(){
    //Display the game interface
    for(int i = 0; i<3; i++) cout<<endl;
    for (int i = 0; i<size; i++) {
        for (int j = 0; j<size; j++) {
            cout<<setw(3)<<matrix[i][j]<<setw(3);
            if (j<2) {
                cout<<"|"<<setw(3);
            }
        }
        cout<<endl;
        for (int j = 0; j<3; j++) {
            if (i<2) {
                cout<<setw(3)<<"---"<<setw(3)<<"---"<<setw(3);
            }
        }
        cout<<endl;
    }
}

bool Board::validate(int x, int y){
    //Check first if the element is empty then check if the x and y are in range
    if (matrix[x][y] == ' ') {
        if ((x>=0 && x<3) && (y>=0 && y<3)) {
            return true;
        }else{
            return false;
        }
    }
    return false;
}

void Board::setVal(int x, int y, player p){
    if(p!=empty)
        matrix[x][y] = p == human ? 'X':'O', count++;
    else
        matrix[x][y] = ' ', count--;    
}


state Board::checkWin(player p){
    if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && ' ' != matrix[0][2] ) {
        // First Row
        return p != human ? win:lose;
    }else if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != ' '){
        // Diagonal Row from right to left
        return p != human ? win:lose;
    }else if(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]  && matrix[1][0] != ' '){
        // First Col
        return p != human ? win:lose;
    }else if(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]  && matrix[1][2] !=' '){
        // Third Col
        return p != human ? win:lose;
    }else if(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && matrix[2][1] != ' '){
        // Third Row
        return p != human ? win:lose;
    }else if(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && matrix[1][1] != ' '){
        //Second Col
        return p != human ? win:lose;
    }else if(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][1] != ' '){
        //Second Row
        return p != human ? win:lose;
    }else if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != ' '){
        //Diagonal from right to left
        return p != human ? win:lose;
    }else if(count==9){
        return draw;
    }else{
        return nothing;
    }
}

void Board::clear(){
    count = 0;
    //Display the game interface
    for (int i = 0; i<size; i++)
        for (int j = 0; j<size; j++)
            matrix[i][j] = ' ';
}








#endif /* Board_h */
