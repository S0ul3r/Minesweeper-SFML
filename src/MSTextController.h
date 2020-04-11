#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H
#include <utility>

#include "MSBoardTextView.h"

class MSTextController
{
    minesweeperBoard* board;
    MSBoardTextView* view;
    
    std::pair<int, int> takeInput();
    //int boardSize();

public:
    MSTextController(minesweeperBoard&, MSBoardTextView&);
    void play();
};

#endif //SAPER_MSTEXTCONTROLLER_H