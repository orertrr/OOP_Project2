#pragma once
#include"Viewer.h"
#include"Player.h"
#include"Board.h"
#include"Chess.h"
#include<vector>
#include<Qthread>
#include<qmetaobject.h>
using namespace std;

class GameManager
{
	private:
	Board gameBoard;
	Player* blackAndWhite[2];
	vector<int> moveList[64];
	vector<int> moveChoice;
	vector<int> upgrade;
	int KingPosition[2];
	int movePath[2];
	int currentPlayer;
	bool endGame;
	int winner;
	public:
	GameManager();
	void Load(string);
	void Start();
	void RePlay();
	int checkMate();
	void ReSetBoard();
};