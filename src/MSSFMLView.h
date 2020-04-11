#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "minesweeperBoard.h"

class MSSFMLView
{
    minesweeperBoard* board;
    sf::Texture t;
    sf::Texture winSource;

    void drawField(int x, int y);
public:
    sf::RenderWindow window;
    MSSFMLView(minesweeperBoard&);
    void render();
    void display();
    void handleEvent();
};

#endif //SAPER_MSSFMLVIEW_H
