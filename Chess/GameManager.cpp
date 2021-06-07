#include"GameManager.h"

GameManager::GameManager()
{
	this->blackAndWhite[0] = nullptr;
	this->blackAndWhite[1] = nullptr;
	this->moveChoice.reserve(64);
	this->upgrade = { 1,2,3,4 };
	this->KingPosition[0] = 4;
	this->KingPosition[1] = 60;
	this->currentPlayer = 0;
	this->movePath[0] = -1;
	this->movePath[1] = -1;
	this->endGame = false;
	this->winner = 0;
}
void GameManager::Load(string fileName) {}
void GameManager::Start(/*bool P1Kind, bool P2Kind*/)
{
	this->KingPosition[0] = 4;
	this->KingPosition[1] = 60;
	this->currentPlayer = 0;
	this->movePath[0] = -1;
	this->movePath[1] = -1;
	this->endGame = false;
	this->winner = 0;

	/*if (P1Kind)
		this->blackAndWhite[0] = new RealPlayer;
	else
		this->blackAndWhite[0] = new ComputerPlayer;
	if (P2Kind)
		this->blackAndWhite[1] = new RealPlayer;
	else
		this->blackAndWhite[1] = new ComputerPlayer;*/

	this->blackAndWhite[0] = new RealPlayer;
	this->blackAndWhite[1] = new RealPlayer;

	int playerAnswer = -1;
	this->moveChoice.clear();
	for (int i = 0; i < 64; i++)
	{
		moveList[i] = gameBoard.getBoard()[i]->getMoveAble(gameBoard.getBoard(), i, this->KingPosition[this->currentPlayer], true);
		if (gameBoard.getBoard()[i]->getMaster() == this->currentPlayer * 2 - 1)
		{
			if (moveList[i].size() > 0)
				this->moveChoice.push_back(i);
		}
	}

	bool showCheckKing = false;

	do
	{
		Viewer::ReflashBoard(gameBoard.getBoard());
		Viewer::ReflashColor();
		if (showCheckKing)
			Viewer::Check(KingPosition[this->currentPlayer]);
		Viewer::setPlayer(blackAndWhite[currentPlayer]);
		bool inchoice = false;

		while (!inchoice)
		{
			playerAnswer = this->blackAndWhite[this->currentPlayer]->choose(this->moveChoice);
			if (playerAnswer > 64)
			{
				switch (playerAnswer)
				{
				case 70://surrender
					endGame = true;
					winner = (this->currentPlayer + 1) % 2 * 2 - 1;
					break;
				default:
					break;
				}
				break;
			}
			for (auto& i : this->moveChoice)
			{
				if (playerAnswer == i)
				{
					inchoice = true;
					break;
				}
			}
		}

		if (endGame)
		{
			break;
		}
		movePath[0] = playerAnswer;
		inchoice = false;

		Viewer::ReflashMoveable(this->moveList[movePath[0]]);
		while (!inchoice)
		{
			playerAnswer = this->blackAndWhite[this->currentPlayer]->choose(this->moveList[movePath[0]]);
			if (playerAnswer >= 64)
			{
				switch (playerAnswer)
				{
				case 70://surrender
					endGame = true;
					winner = (this->currentPlayer + 1) % 2 * 2 - 1;
				default:
					break;
				}
			}
			for (auto& i : this->moveList[movePath[0]])
			{
				if (playerAnswer == i)
				{
					inchoice = true;
					break;
				}
			}
			if (!inchoice)
			{
				break;
			}
		}
		if (!inchoice)
		{
			continue;
		}
		if (endGame)
		{
			break;
		}
		movePath[1] = playerAnswer;
		gameBoard.getBoard()[movePath[0]]->moveChess(gameBoard.getBoard(), movePath[0], movePath[1]);

		//pawn upergade
		if (gameBoard.getBoard()[movePath[1]]->getKind() == 6 && (movePath[1] < 8 || movePath[1] > 55))
		{
			Viewer::ReflashBoard(gameBoard.getBoard());
			Viewer::ReflashColor();
			if (showCheckKing)
				Viewer::Check(KingPosition[this->currentPlayer]);
			Viewer::Upgrade();
			playerAnswer = this->blackAndWhite[this->currentPlayer]->choose(upgrade);
			int pwanBOW = gameBoard.getBoard()[movePath[1]]->getMaster();
			delete gameBoard.getBoard()[movePath[1]];
			switch (playerAnswer)
			{
			case 64:
				gameBoard.getBoard()[movePath[1]] = new Queen(pwanBOW);
				break;
			case 65:
				gameBoard.getBoard()[movePath[1]] = new Bishop(pwanBOW);
				break;
			case 67:
				gameBoard.getBoard()[movePath[1]] = new Knight(pwanBOW);
				break;
			case 66:
				gameBoard.getBoard()[movePath[1]] = new Rook(pwanBOW, true);
				break;
			default:
				break;
			}

			Viewer::ReflashBoard(gameBoard.getBoard());
			Viewer::ReflashColor();
			if (showCheckKing)
				Viewer::Check(KingPosition[this->currentPlayer]);
		}

		++this->currentPlayer %= 2;//change player
		playerAnswer = -1;
		this->moveChoice.clear();
		for (int i = 0; i < 64; i++)
		{
			moveList[i] = gameBoard.getBoard()[i]->getMoveAble(gameBoard.getBoard(), i, this->KingPosition[this->currentPlayer], true);
			if (gameBoard.getBoard()[i]->getMaster() == this->currentPlayer * 2 - 1)
			{
				if (moveList[i].size() > 0)
					this->moveChoice.push_back(i);
			}
		}


		switch (checkMate())
		{
		case 1:
			endGame = true;
			++this->currentPlayer %= 2;
			winner = this->currentPlayer * 2 - 1;
			break;
		case 2:
			endGame = true;
			winner = 0;
			break;
		case 3:
			showCheckKing = true;
			Viewer::Check(KingPosition[this->currentPlayer]);
			break;
		default:
			showCheckKing = false;
			break;
		}
	} while (!endGame);
	Viewer::endGame(winner);
	this->ReSetBoard();
	delete this->blackAndWhite[0];
	delete this->blackAndWhite[1];
}
void GameManager::RePlay() {}
int GameManager::checkMate()
{
	bool check = Chess::checkCheck(gameBoard.getBoard(), KingPosition[this->currentPlayer]);
	bool noMoveable = moveChoice.size() == 0;
	if (check && noMoveable)
	{
		return 1;
	}
	if (!check && noMoveable)
	{
		return 2;
	}
	if (check)
	{
		return 3;
	}
	return 0;

}

void GameManager::ReSetBoard()
{
	this->gameBoard.ReSet();
}