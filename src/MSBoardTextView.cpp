#include <iostream>

#include "MSBoardTextView.h"

//display player board
void MSBoardTextView::display()const{
    for (int row=0; row<board->getBoardHeight(); row++) {
        for (int col= 0; col<board->getBoardWidth();col++) {
            char c = board->getFieldInfo(row,col);
            std::cout << "[";
            std::cout << c;
            std::cout << "]";
        }
        std::cout<<"\n";
    }
}

//constructor for view
MSBoardTextView::MSBoardTextView(minesweeperBoard& gameBoard){
    board = &gameBoard;
}
