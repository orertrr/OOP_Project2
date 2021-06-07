#pragma once

#include "Chess.h"
#include "Player.h"
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qstackedwidget.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qlabel.h>
#include <algorithm>

class Viewer
{
private:
	static QVector<QPushButton*> buttons;
	static QMainWindow* mainwindow;
	static QStackedWidget* stackedwidget;
	static QLabel* lbl_win;
	static Player* currentPlayer;

	static bool buttonsort(QPushButton* a, QPushButton* b);

public:
	static void Init(QMainWindow* window);

	static void ReflashBoard(std::vector<Chess*> chesses);
	static void ReflashColor();
	static void ReflashMoveable(std::vector<int> pos);
	static void Check(int pos_king);
	static void Upgrade(); // 傳回要升級的棋子種類

	static void endGame(int win_type);
	static void setPlayer(Player* p);
	static Player* getCurrentPlayer();
};