#include"Player.h"


void Player::setBTNNumber(int num)
{
	this->clickButton = num;
	this->onClick = true;
}

int RealPlayer::choose(vector<int>)
{
	this->Player::ResetClick();
	
	while (!this->Player::getClick()) {}
	this->Player::ResetClick();
	return this->Player::getBTNNumber();
}

int ComputerPlayer::choose(vector<int> options)
{
	int answer = rand() % options.size();
	return options[answer];
}