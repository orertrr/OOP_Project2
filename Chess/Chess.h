#pragma once
#include<vector>
using namespace std;

/*
 kind : 
	0 : NoChess
	1 : King
	2 : Queen
	3 : Bishop
	4 : Knight
	5 : Rook
	6 : Pawn
 BlackOrWhite : 
	-1 : black
	 0 : NULL
	 1 : white
*/
class Chess
{
	private:
	int kind, BlackOrWhite;
	public:
	Chess(int k, int bow) : kind(k), BlackOrWhite(bow) {}
	int getMaster() { return this->BlackOrWhite; }
	int getKind() { return this->kind; }
	static int preCheckCheck(vector<Chess*>& map, int& targetPosition, int& ThisPosition, int& KingPosition);
	static bool checkCheck(vector<Chess*>& map, int KingPos);
	static vector<int> moveStraight(vector<Chess*>& map, int KingPos, int ThisPos, bool needCC);
	static vector<int> moveDiagonally(vector<Chess*>& map, int KingPos, int ThisPos, bool needCC);
	virtual vector<int> getMoveAble(vector<Chess*>&, int, int, bool) = 0;
	virtual void moveChess(vector<Chess*>&, int, int);
};



class NoChess : public Chess
{
	private:
	public:
	NoChess() : Chess(0, 0) {}
	vector<int> getMoveAble(vector<Chess*>&, int, int, bool);
};

class King : public Chess
{
	private:
	bool MoveOnce;
	public:
	King(int bow, bool mo) : Chess(1, bow), MoveOnce(mo) {}
	vector<int> getMoveAble(vector<Chess*>&, int, int, bool);
	void moveChess(vector<Chess*>&, int, int);
};

class Queen : public Chess
{
	private:
	public:
	Queen(int bow) : Chess(2, bow) {}
	vector<int> getMoveAble(vector<Chess*>&, int, int, bool);
};

class Bishop : public Chess
{
	private:
	public:
	Bishop(int bow) : Chess(3, bow) {}
	vector<int> getMoveAble(vector<Chess*>&, int, int, bool);
};

class Knight : public Chess
{
	private:
	public:
	Knight(int bow) : Chess(4, bow) {}
	vector<int> getMoveAble(vector<Chess*>&, int, int, bool);
};

class Rook : public Chess
{
	private:
	bool MoveOnce;
	public:
	Rook(int bow, bool mo) : Chess(5, bow), MoveOnce(mo) {}
	vector<int> getMoveAble(vector<Chess*>&, int, int, bool);
	void moveChess(vector<Chess*>&, int, int);
};

class Pawn : public Chess
{
	private:
	bool MoveOnce, Lpassby, Rpassby;
	public:
	Pawn(int bow, bool mo) : Chess(6, bow), MoveOnce(mo), Lpassby(false), Rpassby(false) {}
	Pawn(int bow, bool mo, bool lp, bool rp) : Chess(6, bow), MoveOnce(mo), Lpassby(lp), Rpassby(rp) {}

	vector<int> getMoveAble(vector<Chess*>&, int, int, bool);
	void moveChess(vector<Chess*>&, int, int);
	void LPassBy() { this->Lpassby ^= true; }//call my gamemanager
	void RPassBy() { this->Rpassby ^= true; }//call my gamemanager
};