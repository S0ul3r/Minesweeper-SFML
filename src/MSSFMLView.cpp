#include "Platform/Platform.hpp"
#include "MSTextController.h"
#include "MSSFMLView.h"

#include <windows.h>

MSSFMLView::MSSFMLView(minesweeperBoard& board) {
	this->board = &board;
	t.loadFromFile("src/images/tiles.jpg");
	window.create(sf::VideoMode(32*this->board->getBoardWidth(), 32*this->board->getBoardHeight()), "Minesweeper");
}

void MSSFMLView::drawField(int x, int y) {
	char c = board->getFieldInfo(x, y);
	int cellSize = 32;
	sf::Sprite cell(t);

	if (c == 'F'){
		cell.setTextureRect(sf::IntRect(cellSize * 11,0, cellSize, cellSize));
	}else if(c == '_'){
		cell.setTextureRect(sf::IntRect(cellSize * 10,0, cellSize, cellSize));
	}else if(c == 'x'){
		cell.setTextureRect(sf::IntRect(cellSize * 9,0, cellSize, cellSize));
	}else {
		cell.setTextureRect(sf::IntRect(cellSize * (int(c)-int('0')),0, cellSize, cellSize));
	}
	cell.setPosition(x* cellSize, y*cellSize);
	window.draw(cell);
}

void MSSFMLView::render() {
	for (int i = 0; i < board->getBoardWidth(); i++){
		for (int j = 0; j < board->getBoardHeight(); j++){
			drawField(i,j);
		}
	}
}

void MSSFMLView::display(){
	window.clear();
	render();
	window.display();

}

void MSSFMLView::handleEvent(){
	sf::Event e;
	while(window.pollEvent(e))
		{
			sf::Vector2f mousePos;

			switch (e.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::MouseButtonPressed:
					if (e.mouseButton.button == sf::Mouse::Left)
					{
						mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

						mousePos.x /= 32;
						mousePos.y /= 32;

						board->revealField((int)mousePos.x, (int)mousePos.y);
					}
					if (e.mouseButton.button == sf::Mouse::Right)
					{
						mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

						mousePos.x /= 32;
						mousePos.y /= 32;

						if (board->isRevealed((int)mousePos.x, (int)mousePos.y)){
							std::cout<<"dupa";
							continue;
						}

						board->changeFlag((int)mousePos.x, (int)mousePos.y);
					}
					break;

				default:
					break;
			}

		}
	if(board->state == GameState::FINISHED_WIN){
		t.loadFromFile("src/images/win.jpg");
		sf::Sprite s(t);
		window.draw(s);
	}else if(board->state == GameState::FINISHED_LOSS){
		t.loadFromFile("src/images/lose.jpg");
		sf::Sprite s(t);
		window.draw(s);
		Sleep(1000);
	}
}