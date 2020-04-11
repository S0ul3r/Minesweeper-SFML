#include <iostream>
#include <ctime>

#include "minesweeperBoard.h"

//constructor, creating board and placing mines with placeMines()
minesweeperBoard::minesweeperBoard(int height, int width, GameMode difficulty){
    this->width = width;
    this->height = height;
    allMines = (width * height) * (difficulty * 0.1);
    //Predefined allMines for DEBUG
    if (difficulty == 0){
        allMines = (width * height)/4;
    }
    for (int row=0; row<width; row++){
        for (int col=0; col<height; col++){
            this->board[row][col].hasMine = 0;
            this->board[row][col].hasFlag = 0;
            this->board[row][col].isRevealed = 0;
        }
    }
    placeMines();
    numRevealed = 0;
    state = GameState::RUNNING;
}

 //Display admin board
void minesweeperBoard::debugDisplay(int width, int height)const{
    for (int row=0; row<width; row++) {
        for (int col= 0; col<height;col++) {
            std::cout << "[";
            if (board[row][col].hasMine == 0){
                std::cout << ".";
            }
            else {
                std::cout << "M";
            }
            if (board[row][col].isRevealed == 0){
                std::cout << ".";
            }
            else {
                std::cout << "o";
            }
            if (board[row][col].hasFlag == 0){
                std::cout << ".";
            }
            else{
                std::cout << "f";
            }
            std::cout << "]";
        }
        std::cout << "\n";
    }
}

//Check for x,y used in some functions
bool minesweeperBoard::checkerXY(int x, int y)const{
    return y<width && y >=0 && x<height && x>=0;
}

//Place mines in random way
void minesweeperBoard::placeMines(){
    srand(time(NULL));
    for(int i = 0 ; i<allMines; ++i){
        while(true){
            int row = rand()%height;
            int col = rand()%width;
            if(board[row][col].hasMine == 0){
                board[row][col].hasMine = 1;
                break;
            }
        }
    }
}

// Count mines around (x,y) position
int minesweeperBoard::countMines(int x, int y)const {
    int count = 0;
    if(x>0 && y>0 )count += board[x-1][y-1].hasMine;
    if(x>0 )count += board[x-1][y].hasMine;
    if(x>0 && y<width-1 )count += board[x-1][y+1].hasMine;
    if(y>0 )count += board[x][y-1].hasMine;
    if(y<width-1)count += board[x][y+1].hasMine;
    if(x<height-1 && y > 0 )count += board[x+1][y-1].hasMine;
    if(x<height-1  )count += board[x+1][y].hasMine;
    if(x<height-1 && y < width-1)count += board[x+1][y+1].hasMine;
    return count;
}

// Operations on flags
bool minesweeperBoard::hasFlag(int x, int y)const{
    if(checkerXY(x,y))return board[x][y].hasFlag;
    else return 0;
}
void minesweeperBoard::toggleFlag(int x, int y){
    if(state == GameState::RUNNING && checkerXY(x,y) && board[x][y].isRevealed == 0)board[x][y].hasFlag = 1;
}

void minesweeperBoard::changeFlag(int x,int y){
    if(board[x][y].hasFlag == 1)board[x][y].hasFlag = 0;
    else board[x][y].hasFlag = 1;
}
// Check/reveal fields
bool minesweeperBoard::isRevealed(int x, int y)const{
    if(checkerXY(x,y))return board[x][y].isRevealed;
    else return 0;
}
void minesweeperBoard::revealField(int x, int y){
    if(state == GameState::RUNNING && checkerXY(x,y) && board[x][y].isRevealed == 0 && board[x][y].hasFlag == 0){
        board[x][y].isRevealed = 1;
        if(board[x][y].hasMine== 1){
            revealBombs();
            state = GameState::FINISHED_LOSS;
            return;
        }
        numRevealed ++;
        if(width*height - allMines == numRevealed){
            state = GameState::FINISHED_WIN;
        }
        if(countMines(x,y)==0){
            revealField(x-1,y-1);
            revealField(x-1,y);
            revealField(x-1,y+1);
            revealField(x,y-1);
            revealField(x,y+1);
            revealField(x+1,y-1);
            revealField(x+1,y);
            revealField(x+1,y+1);
        }

    }
}

// Convenience function - returns useful information about field in one function call
char minesweeperBoard::getFieldInfo(int x, int y) const{
    if(!(checkerXY(x,y)))return '#';
    if(board[x][y].isRevealed == 0 && board[x][y].hasFlag == 1)return 'F';
    if(board[x][y].isRevealed == 0 && board[x][y].hasFlag == 0)return '_';
    if(board[x][y].isRevealed == 1 && board[x][y].hasMine == 1)return 'x';
    if(board[x][y].isRevealed == 1 && countMines(x,y) == 0)return '0';
    if(board[x][y].isRevealed == 1 && countMines(x,y) > 0)return char(countMines(x,y)+'0');
    else return 't';
}

void minesweeperBoard::revealBombs(){
    for (int row=0; row<width; row++) {
        for (int col= 0; col<height;col++) {
            if(board[row][col].isRevealed == 0 && board[row][col].hasMine == 1){
                board[row][col].isRevealed = 1;
            }
        }
    }
}
