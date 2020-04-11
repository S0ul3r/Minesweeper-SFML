#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

enum GameMode  { DEBUG = 0, EASY  = 1, NORMAL = 2, HARD = 3};
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class minesweeperBoard {
    Field board[100][100];
    int width, height, allMines;
    int numRevealed;
    void placeMines();
    bool checkerXY(int x, int y)const;

public:
    GameState state;

    minesweeperBoard(int height=10, int width=10, GameMode state = GameMode::DEBUG);

    void debugDisplay(int width , int height )const;

    int countMines(int x, int y) const;

    bool hasFlag(int x, int y) const;
    void toggleFlag(int x,int y);
    void changeFlag(int x,int y);

    bool isRevealed(int x, int y) const;
    void revealField(int x,int y);

    char getFieldInfo(int x, int y) const;

    // Getters
    int getBoardWidth() const{return width;}
    int getBoardHeight() const{return height;}
    int getMineCount() const{return allMines;}
    GameState getGameState() const{return state;}
    void revealBombs();
};

#endif //SAPER_MINESWEEPERBOARD_H
