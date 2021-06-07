#include "Viewer.h"

QVector<QPushButton*> Viewer::buttons;
QMainWindow* Viewer::mainwindow;
QStackedWidget* Viewer::stackedwidget;
QLabel* Viewer::lbl_win;
Player* Viewer::currentPlayer = NULL;

const QString unicode[12] =
{
	// White
	QCoreApplication::translate("MainWindowClass", "\342\231\232", nullptr), //King    0
	QCoreApplication::translate("MainWindowClass", "\342\231\225", nullptr), //Queen   1
	QCoreApplication::translate("MainWindowClass", "\342\231\226", nullptr), //Rook    2
	QCoreApplication::translate("MainWindowClass", "\342\231\227", nullptr), //Bishop  3
	QCoreApplication::translate("MainWindowClass", "\342\231\230", nullptr), //Knight  4
	QCoreApplication::translate("MainWindowClass", "\342\231\231", nullptr), //Pawn    5

	// Black
	QCoreApplication::translate("MainWindowClass", "\342\231\224", nullptr), //King    6
	QCoreApplication::translate("MainWindowClass", "\342\231\233", nullptr), //Queen   7
	QCoreApplication::translate("MainWindowClass", "\342\231\234", nullptr), //Rook    8
	QCoreApplication::translate("MainWindowClass", "\342\231\235", nullptr), //Bishop  9
	QCoreApplication::translate("MainWindowClass", "\342\231\236", nullptr), //Knight  10
	QCoreApplication::translate("MainWindowClass", "\342\231\237", nullptr)  //Pawn    11
};

bool Viewer::buttonsort(QPushButton* a, QPushButton* b)
{
	return a->objectName() < b->objectName();
}

void Viewer::Init(QMainWindow* window)
{
	mainwindow = window;
	stackedwidget = window->findChild<QStackedWidget*>("Scenes");
	lbl_win = window->findChild<QLabel*>("lbl_Win");

	buttons.clear();
	for (int i = 1; i <= 64; i++)
	{
		QString buttonname("Cell");
		buttonname += i < 10 ? "0" : "";
		buttonname += QString::number(i);

		QPushButton* button = window->findChild<QPushButton*>(buttonname);

		buttons.push_back(button);
	}
	std::sort(buttons.begin(), buttons.end(), buttonsort);

	buttons[0]->setText(unicode[2]);
	buttons[1]->setText(unicode[4]);
	buttons[2]->setText(unicode[3]);
	buttons[3]->setText(unicode[1]);
	buttons[4]->setText(unicode[0]);
	buttons[5]->setText(unicode[3]);
	buttons[6]->setText(unicode[4]);
	buttons[7]->setText(unicode[2]);
	buttons[8]->setText(unicode[5]);
	buttons[9]->setText(unicode[5]);
	buttons[10]->setText(unicode[5]);
	buttons[11]->setText(unicode[5]);
	buttons[12]->setText(unicode[5]);
	buttons[13]->setText(unicode[5]);
	buttons[14]->setText(unicode[5]);
	buttons[15]->setText(unicode[5]);

	buttons[48]->setText(unicode[11]);
	buttons[49]->setText(unicode[11]);
	buttons[50]->setText(unicode[11]);
	buttons[51]->setText(unicode[11]);
	buttons[52]->setText(unicode[11]);
	buttons[53]->setText(unicode[11]);
	buttons[54]->setText(unicode[11]);
	buttons[55]->setText(unicode[11]);
	buttons[56]->setText(unicode[8]);
	buttons[57]->setText(unicode[10]);
	buttons[58]->setText(unicode[9]);
	buttons[59]->setText(unicode[7]);
	buttons[60]->setText(unicode[6]);
	buttons[61]->setText(unicode[9]);
	buttons[62]->setText(unicode[10]);
	buttons[63]->setText(unicode[8]);
}

void Viewer::ReflashBoard(std::vector<Chess*> chesses)
{
	for (int i = 0; i < 64; i++)
	{
		switch (chesses[i]->getKind())
		{
		case 1:
			if (chesses[i]->getMaster() == -1)
				buttons[i]->setText(unicode[6]);
			else
				buttons[i]->setText(unicode[0]);
			break;

		case 2:
			if (chesses[i]->getMaster() == -1)
				buttons[i]->setText(unicode[1]);
			else
				buttons[i]->setText(unicode[7]);
			break;

		case 3:
			if (chesses[i]->getMaster() == -1)
				buttons[i]->setText(unicode[3]);
			else
				buttons[i]->setText(unicode[9]);
			break;

		case 4:
			if (chesses[i]->getMaster() == -1)
				buttons[i]->setText(unicode[4]);
			else
				buttons[i]->setText(unicode[10]);
			break;

		case 5:
			if (chesses[i]->getMaster() == -1)
				buttons[i]->setText(unicode[2]);
			else
				buttons[i]->setText(unicode[8]);
			break;

		case 6:
			if (chesses[i]->getMaster() == -1)
				buttons[i]->setText(unicode[5]);
			else
				buttons[i]->setText(unicode[11]);
			break;

		case 0:
			buttons[i]->setText("");
			break;
		}
	}
}

void Viewer::ReflashColor()
{
	for (int i = 0; i < 64; i++)
	{
		if ((i + i / 8) % 2 == 0)
			QMetaObject::invokeMethod(buttons[i], "setStyleSheet", Qt::AutoConnection, Q_ARG(QString, QString::fromUtf8("background-color: rgb(0, 170, 0);")));
		
		else
			QMetaObject::invokeMethod(buttons[i], "setStyleSheet", Qt::AutoConnection, Q_ARG(QString, QString::fromUtf8("background-color: rgb(255, 255, 255);")));
	}
}

void Viewer::ReflashMoveable(std::vector<int> pos)
{
	for (int& cellnum : pos)
	{
		QMetaObject::invokeMethod(buttons[cellnum], "setStyleSheet", Qt::AutoConnection, Q_ARG(QString, QString::fromUtf8("background-color: rgb(200, 200, 255);")));
	}
}

void Viewer::Check(int pos_king)
{
	QMetaObject::invokeMethod(buttons[pos_king], "setStyleSheet", Qt::AutoConnection, Q_ARG(QString, QString::fromUtf8("background-color: rgb(153, 0, 0);")));
}

void Viewer::Upgrade()
{
	QMetaObject::invokeMethod(stackedwidget, "setCurrentIndex", Qt::AutoConnection, Q_ARG(int, 2));
}

void Viewer::endGame(int win_type)
{
	QMetaObject::invokeMethod(stackedwidget, "setCurrentIndex", Qt::AutoConnection, Q_ARG(int, 3));

	if (win_type == 0)
		QMetaObject::invokeMethod(lbl_win, "setText", Qt::AutoConnection, Q_ARG(QString, "Draw"));
	if (win_type == 1)
		QMetaObject::invokeMethod(lbl_win, "setText", Qt::AutoConnection, Q_ARG(QString, "Black Win"));
	else
		QMetaObject::invokeMethod(lbl_win, "setText", Qt::AutoConnection, Q_ARG(QString, "White Win"));
}

void Viewer::setPlayer(Player* p)
{
	currentPlayer = p;
}

Player* Viewer::getCurrentPlayer()
{
	return currentPlayer;
}
