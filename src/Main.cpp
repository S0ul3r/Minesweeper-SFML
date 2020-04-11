#include "MSSFMLView.h"

int main()
{

	minesweeperBoard board(25, 25, EASY);
	MSSFMLView view(board);

	while (view.window.isOpen())
	{
		view.handleEvent();
		view.display();
	}

	return 0;
}
