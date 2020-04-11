#include <iostream>
#include <climits>

#include "MSTextController.h"

//constructor for view
MSTextController::MSTextController(minesweeperBoard& board, MSBoardTextView& display){
    this->board = &board;
    this->view = &display;
   
    // std::cout<<"Define board size x then y (max 100x100)"<<"\n";
    // std::cin>> x >> y;
    // while (!std::cin.good() || x > 100 || x < 0 || y > 100 || y < 0){
    //     std::cin.clear();
    //     std::cin.ignore(INT_MAX, '\n');
    //     std::cout<<"Wrong input. Define board size x then y (max 100x100)"<<"\n";
    //     std::cin>> x >> y;
    // }

}

// int MSTextController::boardSize(){
//     int diff;
//     std::cout<<"Select difficulty (write a number)"<<"\n";
//     std::cout<<"1 - Easy"<<"\n"<<"2 - Normal"<<"\n"<<"3 - Hard"<<"\n";
//     std::cin>>diff;
//     while (!std::cin.good() || diff > 3 || diff < 1){
//         std::cin.clear();
//         std::cin.ignore(INT_MAX, '\n');
//         std::cout<<"Wrong input. Select difficulty (write a number)"<<"\n";
//         std::cout<<"1 - Easy"<<"\n"<<"2 - Normal"<<"\n"<<"3 - Hard"<<"\n";
//         std::cin>>diff;
//     }
//     switch(diff) {
//         case 1: minesweeperBoard board(10, 10, EASY);
//         case 2: minesweeperBoard board(20, 20, NORMAL);
//         case 3: minesweeperBoard board(30, 30, HARD);
//     }
//     return 0;
// }

std::pair<int, int> MSTextController::takeInput() {
    int x,y;
    std::cout<<"Choose row and column: ";
    std::cin>> x >> y;
    while (!std::cin.good() || x > board->getBoardHeight() || x < 0 || y > board->getBoardWidth() || y < 0){
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"Wrong input. Choose row and then column: ";
        std::cin>> x >> y;
    }
    return std::make_pair(x,y);
}

void MSTextController::play(){
    view->display();
    while(true){
        std::pair<int, int> coords = takeInput();
        board->revealField(coords.first,coords.second);
        view->display();
        std::cout<<"\n\n";
    }
}