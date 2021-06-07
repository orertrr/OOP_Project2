#include"Board.h"



Board::Board()
{
	//black first line
	this->gameBoard.reserve(64);
	Chess* temp = new Rook(-1, false);
	this->gameBoard.push_back(temp);
	temp = new Knight(-1);
	this->gameBoard.push_back(temp);
	temp = new Bishop(-1);
	this->gameBoard.push_back(temp);
	temp = new Queen(-1);
	this->gameBoard.push_back(temp);
	temp = new King(-1, false);
	this->gameBoard.push_back(temp);
	temp = new Bishop(-1);
	this->gameBoard.push_back(temp);
	temp = new Knight(-1);
	this->gameBoard.push_back(temp);
	temp = new Rook(-1, false);
	this->gameBoard.push_back(temp);
	//black pawn
	for (int i = 0; i < 8; i++)
	{
		temp = new Pawn(-1, false);
		this->gameBoard.push_back(temp);
	}
	//no chess
	for (int i = 0; i < 32; i++)
	{
		temp = new NoChess;
		this->gameBoard.push_back(temp);
	}
	//white pawn
	for (int i = 0; i < 8; i++)
	{
		temp = new Pawn(1, false);
		this->gameBoard.push_back(temp);
	}
	//white first line
	temp = new Rook(1, false);
	this->gameBoard.push_back(temp);
	temp = new Knight(1);
	this->gameBoard.push_back(temp);
	temp = new Bishop(1);
	this->gameBoard.push_back(temp);
	temp = new Queen(1);
	this->gameBoard.push_back(temp);
	temp = new King(1, false);
	this->gameBoard.push_back(temp);
	temp = new Bishop(1);
	this->gameBoard.push_back(temp);
	temp = new Knight(1);
	this->gameBoard.push_back(temp);
	temp = new Rook(1, false);
	this->gameBoard.push_back(temp);
}


void Board::loadBoard(string bosrdFileName)
{
	ifstream loadRecord;
	string temp;
	int kind, bow;
	bool lpassby, rpassby, once;
	loadRecord.open(bosrdFileName);
	for (int i = 0; i < 64; i++)
	{
		//bow kind once lpassby rpassby
		loadRecord >> temp;
		delete this->gameBoard[i];
		//bow
		if (temp[0] == '0')
		{
			this->gameBoard[i] = new NoChess;
			continue;
		}
		else if (temp[0] == 'b')
		{
			bow = -1;
		}
		else
		{
			bow = 1;
		}

		//kind and other
		switch (temp[1])
		{
			case '1':
				kind = 1;
				once = temp[2] == 'T' ? true : false;
				this->gameBoard[i] = new King(bow, once);
				break;
			case '2':
				kind = 2;
				this->gameBoard[i] = new Queen(bow);
				break;
			case '3':
				kind = 3;
				this->gameBoard[i] = new Bishop(bow);
				break;
			case '4':
				kind = 4;
				this->gameBoard[i] = new Knight(bow);
				break;
			case '5':
				kind = 5;
				once = temp[2] == 'T' ? true : false;
				this->gameBoard[i] = new Rook(bow, once);
				break;
			case '6':
				kind = 6;
				once = temp[2] == 'T' ? true : false;
				lpassby = temp[3] == 'T' ? true : false;
				rpassby = temp[4] == 'T' ? true : false;
				this->gameBoard[i] = new Pawn(bow, once, lpassby, rpassby);
				break;
			default:
				kind = 0;
				break;
		}
	}
	loadRecord.close();
	return;
}

void Board::ReSet()
{
	for (auto& i : this->gameBoard)
	{
		delete i;
	}
	this->gameBoard.clear();
	//black first line
	this->gameBoard.reserve(64);
	Chess* temp = new Rook(-1, false);
	this->gameBoard.push_back(temp);
	temp = new Knight(-1);
	this->gameBoard.push_back(temp);
	temp = new Bishop(-1);
	this->gameBoard.push_back(temp);
	temp = new Queen(-1);
	this->gameBoard.push_back(temp);
	temp = new King(-1, false);
	this->gameBoard.push_back(temp);
	temp = new Bishop(-1);
	this->gameBoard.push_back(temp);
	temp = new Knight(-1);
	this->gameBoard.push_back(temp);
	temp = new Rook(-1, false);
	this->gameBoard.push_back(temp);
	//black pawn
	for (int i = 0; i < 8; i++)
	{
		temp = new Pawn(-1, false);
		this->gameBoard.push_back(temp);
	}
	//no chess
	for (int i = 0; i < 32; i++)
	{
		temp = new NoChess;
		this->gameBoard.push_back(temp);
	}
	//white pawn
	for (int i = 0; i < 8; i++)
	{
		temp = new Pawn(1, false);
		this->gameBoard.push_back(temp);
	}
	//white first line
	temp = new Rook(1, false);
	this->gameBoard.push_back(temp);
	temp = new Knight(1);
	this->gameBoard.push_back(temp);
	temp = new Bishop(1);
	this->gameBoard.push_back(temp);
	temp = new Queen(1);
	this->gameBoard.push_back(temp);
	temp = new King(1, false);
	this->gameBoard.push_back(temp);
	temp = new Bishop(1);
	this->gameBoard.push_back(temp);
	temp = new Knight(1);
	this->gameBoard.push_back(temp);
	temp = new Rook(1, false);
	this->gameBoard.push_back(temp);
}