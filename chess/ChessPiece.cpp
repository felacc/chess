#include "ChessPiece.h"
#include "Constants.h"
#include "Point.h"
#include "Gameboard.h"

ChessPiece::ChessPiece(const std::string& name, Color col) 
	: GameboardItem{ name }, color(col) {
	loadImage(getImageFilepath());
}


std::string ChessPiece::getImageFilepath() {
	std::stringstream ss;
	ss << Constants::pathToImages;
	// the color forms part of the filename we want to load (of the chess piece).
	if (color == Color::white) {
		ss << "w";
	}
	else {
		ss << "b";
	}
	ss << "_" << name << ".png";
	return ss.str();
}

bool ChessPiece::isValidMove(Point& p) const
{
	std::cout << "point p: " << p << '\n';
	for (auto move : getValidMoves())
	{
		std::cout << "move: " << move << '\n';
		if (move == p)
			return true;
	}

	return false;
}

std::vector<Point> ChessPiece::convertOffsetsToValidMoves(const std::vector<Point>& offsets) const
{
	
	std::vector<Point> validMoves{};

	if (pBoard) // if chess piece is on the board
	{
		for (const Point& p : offsets)
		{
			Point destination = p + getPosition();

			if (!(pBoard->isValid(destination)))
				continue;

			if (pBoard->containsBlockerAt(destination))
				continue;

			if (pBoard->containsChessPieceOfColorAt(destination, color))
				continue;

			validMoves.push_back(destination);
		}
	}

	return validMoves;
}

