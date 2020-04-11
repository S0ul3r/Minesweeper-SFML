#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H
#include "minesweeperBoard.h"

class MSBoardTextView
{
    minesweeperBoard* board;
    
public:
    MSBoardTextView(minesweeperBoard&);
    void display()const;
};

#endif //SAPER_MSBOARDTEXTVIEW_H
