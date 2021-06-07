#pragma once
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

class Player
{
	private:
	bool onClick;
	int clickButton;
	public:
	Player() : onClick(false), clickButton(0) { srand(time(0)); }
	int getBTNNumber() { return this->clickButton; }
	bool getClick() { return this->onClick; }
	void ResetClick() { this->onClick = false; }
	void setBTNNumber(int num);
	virtual int choose(vector<int>) = 0;
};

class RealPlayer : public Player
{
	private:
	public:
	int choose(vector<int>);
};

class ComputerPlayer : public Player
{
	private:
	public:
	int choose(vector<int>);
};