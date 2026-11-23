#include "ConcreteChessPieces.h"
#include "Gameboard.h"
#include "Blocker.h"
#include "Point.h"
#include <sstream>

// Initialize name (owned by the derived class: ChessPiece) to "king"
King::King(Color col)
	: ChessPiece{"King", col}
{
	std::cout << "King.ctor()\n";
}

King::~King()
{
	std::cout << "King.dtor()\n";
}

std::vector<Point> King::getValidMoves() const
{

	const std::vector<Point> offsets = 
	{ 
		{ -1, -1 },
		{ 0, -1 },
		{ 1, -1 },
		{ 1, 0 },
		{ 1, 1 },
		{ 0, 1 },
		{ -1, 1 },
		{ -1, 0 }
	};
	
	std::vector<Point> validMoves{convertOffsetsToValidMoves(offsets)};

	return validMoves;
}


 //Initialize name (owned by the derived class: ChessPiece) to "knight"
Knight::Knight(Color col )
	: ChessPiece{"Knight", col}
{	
}

std::vector<Point> Knight::getValidMoves() const
{
	const std::vector<Point> offsets = 
	{ 
		{ -2, -1 },
		{ -1, -2 },
		{ 1, -2 },
		{ 2, -1 },
		{ 2, 1 },
		{ 1, 2 },
		{ -1, 2 },
		{ -2, 1 }
	};
	
	std::vector<Point> validMoves{convertOffsetsToValidMoves(offsets)};

	return validMoves;
}

