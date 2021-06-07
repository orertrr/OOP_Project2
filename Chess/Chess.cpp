#include"Chess.h"


int Chess::preCheckCheck(vector<Chess*>& map, int& targetPosition, int& ThisPosition, int& KingPosition)
{
	int answer = -1;
	Chess* Ctemp = map[targetPosition];
	map[targetPosition] = map[ThisPosition];
	map[ThisPosition] = new NoChess();
	if (!checkCheck(map, KingPosition))
		answer = targetPosition;
	delete map[ThisPosition];
	map[ThisPosition] = map[targetPosition];
	map[targetPosition] = Ctemp;
	return answer;
}
bool Chess::checkCheck(vector<Chess*>& map, int KingPos)
{
	int BOW = map[KingPos]->getMaster();
	
	for (int i = 0; i < 64; i++)
	{
		if (map[i]->getMaster() + BOW == 0)
		{
			for (int p : map[i]->getMoveAble(map, i, KingPos, false))
			{
				if (p == KingPos)
				{
					return true;
				}
			}
		}
	}
	return false;
}
vector<int> Chess::moveStraight(vector<Chess*>& map, int KingPos, int ThisPos, bool needCC)
{
	vector<int> answer;
	int pos[2] = { 0 };
	pos[0] = ThisPos / 8;
	pos[1] = ThisPos % 8;
	int temp[2] = { 0 };

	//move up
	temp[0] = pos[0] - 1;
	temp[1] = pos[1];
	while (temp[0] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}

		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[0]--;
	}
	//move down
	temp[0] = pos[0] + 1;
	temp[1] = pos[1];
	while (temp[0] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}
		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[0]++;
	}
	//move left
	temp[0] = pos[0];
	temp[1] = pos[1] - 1;
	while (temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}
		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[1]--;
	}
	//move right
	temp[0] = pos[0];
	temp[1] = pos[1] + 1;
	while (temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}
		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[1]++;
	}

	return answer;

}
vector<int> Chess::moveDiagonally(vector<Chess*>& map, int KingPos, int ThisPos, bool needCC)
{
	vector<int> answer;
	int pos[2] = { 0 };
	pos[0] = ThisPos / 8;
	pos[1] = ThisPos % 8;
	int temp[2] = { 0 };

	//move LU
	temp[0] = pos[0] - 1;
	temp[1] = pos[1] - 1;
	while (temp[0] >= 0 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}
		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[0]--;
		temp[1]--;
	}
	//move LD
	temp[0] = pos[0] + 1;
	temp[1] = pos[1] - 1;
	while (temp[0] < 8 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}
		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[0]++;
		temp[1]--;
	}
	//move RU
	temp[0] = pos[0] - 1;
	temp[1] = pos[1] + 1;
	while (temp[0] >= 0 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}
		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[0]--;
		temp[1]++;
	}
	//move RD
	temp[0] = pos[0] + 1;
	temp[1] = pos[1] + 1;
	while (temp[0] < 8 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == map[ThisPos]->getMaster())
			break;
		if (needCC)
		{
			int addPos = preCheckCheck(map, targetPos, ThisPos, KingPos);
			if (addPos >= 0)
			{
				answer.push_back(addPos);
			}
		}
		else
		{
			answer.push_back(targetPos);
		}
		if (map[targetPos]->getMaster() + map[ThisPos]->getMaster() == 0)
			break;

		temp[0]++;
		temp[1]++;
	}

	return answer;
}



vector<int> NoChess::getMoveAble(vector<Chess*>& map, int ThisPosition, int KingPosition, bool needCC)
{
	vector<int> answer;
	return answer;
}
vector<int> King::getMoveAble(vector<Chess*>& map, int ThisPosition, int KingPosition, bool needCC)
{
	vector<int> answer;
	int pos[2] = { 0 };
	pos[0] = ThisPosition / 8;
	pos[1] = ThisPosition % 8;
	int temp[2] = { 0 };

	//U
	temp[0] = pos[0] - 1;
	temp[1] = pos[1];
	if (temp[0] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//D
	temp[0] = pos[0] + 1;
	temp[1] = pos[1];
	if (temp[0] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//L
	temp[0] = pos[0];
	temp[1] = pos[1] - 1;
	if (temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//R
	temp[0] = pos[0];
	temp[1] = pos[1] + 1;
	if (temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//LU
	temp[0] = pos[0] - 1;
	temp[1] = pos[1] - 1;
	if (temp[0] >= 0 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//LD
	temp[0] = pos[0] + 1;
	temp[1] = pos[1] - 1;
	if (temp[0] < 8 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//RU
	temp[0] = pos[0] - 1;
	temp[1] = pos[1] + 1;
	if (temp[0] >= 0 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//RD
	temp[0] = pos[0] + 1;
	temp[1] = pos[1] + 1;
	if (temp[0] < 8 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, targetPos);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}

	//KR change

	return answer;
}
vector<int> Queen::getMoveAble(vector<Chess*>& map, int ThisPosition, int KingPosition, bool needCC)
{
	vector<int> answer, temp;
	temp = this->Chess::moveStraight(map, KingPosition, ThisPosition, needCC);
	answer.insert(answer.end(), temp.begin(), temp.end());
	temp = this->Chess::moveDiagonally(map, KingPosition, ThisPosition, needCC);
	answer.insert(answer.end(), temp.begin(), temp.end());
	return answer;
}
vector<int> Bishop::getMoveAble(vector<Chess*>& map, int ThisPosition, int KingPosition, bool needCC)
{
	vector<int> answer, temp;
	temp = this->Chess::moveDiagonally(map, KingPosition, ThisPosition, needCC);
	answer.insert(answer.end(), temp.begin(), temp.end());
	return answer;
}
vector<int> Rook::getMoveAble(vector<Chess*>& map, int ThisPosition, int KingPosition, bool needCC)
{
	vector<int> answer, temp;
	temp = this->Chess::moveStraight(map, KingPosition, ThisPosition, needCC);
	answer.insert(answer.end(), temp.begin(), temp.end());
	return answer;
}
vector<int> Knight::getMoveAble(vector<Chess*>& map, int ThisPosition, int KingPosition, bool needCC)
{
	vector<int> answer;
	int pos[2] = { 0 };
	pos[0] = ThisPosition / 8;
	pos[1] = ThisPosition % 8;
	int temp[2] = { 0 };

	//UUL
	temp[0] = pos[0] - 2;
	temp[1] = pos[1] - 1;
	if (temp[0] >= 0 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//UUR
	temp[0] = pos[0] - 2;
	temp[1] = pos[1] + 1;
	if (temp[0] >= 0 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//RRU
	temp[0] = pos[0] - 1;
	temp[1] = pos[1] + 2;
	if (temp[0] >= 0 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//RRD
	temp[0] = pos[0] + 1;
	temp[1] = pos[1] + 2;
	if (temp[0] < 8 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//DDR
	temp[0] = pos[0] + 2;
	temp[1] = pos[1] + 1;
	if (temp[0] < 8 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//DDL
	temp[0] = pos[0] + 2;
	temp[1] = pos[1] - 1;
	if (temp[0] < 8 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//LLD
	temp[0] = pos[0] + 1;
	temp[1] = pos[1] - 2;
	if (temp[0] < 8 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//LLU
	temp[0] = pos[0] - 1;
	temp[1] = pos[1] - 2;
	if (temp[0] >= 0 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() != map[ThisPosition]->getMaster())
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}


	return answer;
}
vector<int> Pawn::getMoveAble(vector<Chess*>& map, int ThisPosition, int KingPosition, bool needCC)
{
	vector<int> answer;
	int pos[2] = { 0 };
	pos[0] = ThisPosition / 8;
	pos[1] = ThisPosition % 8;
	int temp[2] = { 0 };

	//F
	temp[0] = pos[0] - this->Chess::getMaster();
	temp[1] = pos[1];
	if (temp[0] >= 0 && temp[0] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() == 0)
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//FF	
	if (!MoveOnce && answer.size() == 1)
	{
		temp[0] = pos[0] - this->Chess::getMaster() * 2;
		temp[1] = pos[1];
		if (temp[0] >= 0 && temp[0] < 8)
		{
			int targetPos = temp[0] * 8 + temp[1];
			if (map[targetPos]->getMaster() == 0)
			{
				if (needCC)
				{
					int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
					if (addPos >= 0)
					{
						answer.push_back(addPos);
					}
				}
				else
				{
					answer.push_back(targetPos);
				}
			}
		}
	}
	//FR
	temp[0] = pos[0] - this->Chess::getMaster();
	temp[1] = pos[1] + 1;
	if (temp[0] >= 0 && temp[0] < 8 && temp[1] < 8)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() + map[ThisPosition]->getMaster() == 0)
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	//FL
	temp[0] = pos[0] - this->Chess::getMaster();
	temp[1] = pos[1] - 1;
	if (temp[0] >= 0 && temp[0] < 8 && temp[1] >= 0)
	{
		int targetPos = temp[0] * 8 + temp[1];
		if (map[targetPos]->getMaster() + map[ThisPosition]->getMaster() == 0)
		{
			if (needCC)
			{
				int addPos = preCheckCheck(map, targetPos, ThisPosition, KingPosition);
				if (addPos >= 0)
				{
					answer.push_back(addPos);
				}
			}
			else
			{
				answer.push_back(targetPos);
			}
		}
	}
	
	//FRP
	if (Rpassby)
	{

	}

	//FLP
	if (Lpassby)
	{

	}

	return answer;
}




void Chess::moveChess(vector<Chess*>& map, int fromPos, int toPos)
{
	swap(map[fromPos], map[toPos]);
	if (map[fromPos]->getKind() != 0)
	{
		delete map[fromPos];
		map[fromPos] = new NoChess;
	}
}
void King::moveChess(vector<Chess*>& map, int fromPos, int toPos)
{
	Chess::moveChess(map, fromPos, toPos);
	if (!this->MoveOnce)
	{
		MoveOnce = true;
		if (fromPos == 4)//black
		{
			if (toPos == 2)//0
			{
				Chess::moveChess(map, 0, 3);
				return;
			}
			if (toPos == 6)//7
			{
				Chess::moveChess(map, 7, 5);
				return;
			}
		}
		if (fromPos == 60)//white
		{
			if (toPos == 58)//56
			{
				Chess::moveChess(map, 56, 59);
				return;
			}
			if (toPos == 62)//63
			{
				Chess::moveChess(map, 63, 61);
				return;
			}
		}
		return;
	}
}
void Rook::moveChess(vector<Chess*>& map, int fromPos, int toPos)
{
	Chess::moveChess(map, fromPos, toPos);
	if (!this->MoveOnce)
	{
		this->MoveOnce = true;
	}
}
void Pawn::moveChess(vector<Chess*>& map, int fromPos, int toPos)
{
	Chess::moveChess(map, fromPos, toPos);
	if (!this->MoveOnce)
	{
		this->MoveOnce = true;
	}

	//passby eat
	/*int targetPos = toPos - 8;
	if (map[targetPos]->getKind() != 0)
	{
		delete map[targetPos];
		map[targetPos] = new NoChess;
	}*/
}