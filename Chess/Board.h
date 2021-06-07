#pragma once
#include"Chess.h"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Board
{
	private:
	vector<Chess*> gameBoard;
	public:
	Board();
	vector<Chess*>& getBoard() { return this->gameBoard; }
	void loadBoard(string);
	void ReSet();
};