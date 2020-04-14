#include "MSSFMLView.h"

int main()
{

	minesweeperBoard board(15, 15, NORMAL);
	MSSFMLView view(board);

	while (view.window.isOpen())
	{
		view.handleEvent();
		view.display();
	}
	return 0;
}
