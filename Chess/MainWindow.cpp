#include "MainWindow.h"

MainWindow::MainWindow(GameManager* manager, QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->manager = manager;

    connect(ui.btn_Play, &QPushButton::clicked, this, &MainWindow::StartGame, Qt::QueuedConnection);
    connect(ui.btn_Menu, &QPushButton::clicked, this, &MainWindow::Menu, Qt::QueuedConnection);
    connect(ui.btn_Menu2, &QPushButton::clicked, this, &MainWindow::Menu, Qt::QueuedConnection);
    connect(ui.btn_Queen, &QPushButton::clicked, this, &MainWindow::get, Qt::QueuedConnection);
    connect(ui.btn_Bishop, &QPushButton::clicked, this, &MainWindow::get, Qt::QueuedConnection);
    connect(ui.btn_Rook, &QPushButton::clicked, this, &MainWindow::get, Qt::QueuedConnection);
    connect(ui.btn_Knight, &QPushButton::clicked, this, &MainWindow::get, Qt::QueuedConnection);
    connect(ui.btn_Surrender, &QPushButton::clicked, this, &MainWindow::get, Qt::QueuedConnection);

    for (int i = 1; i <= 64; i++)
    {
        QString buttonname("Cell");
        buttonname += i < 10 ? "0" : "";
        buttonname += QString::number(i);

        QPushButton* button = this->findChild<QPushButton*>(buttonname);

        connect(button, &QPushButton::clicked, this, &MainWindow::get, Qt::QueuedConnection);
    }

    Viewer::Init(this);
}

void MainWindow::StartGame()
{
    Viewer::Init(this);
    ui.Scenes->setCurrentIndex(1);

    std::thread game(&GameManager::Start, manager);
    game.detach();
}

void MainWindow::Menu()
{
    ui.Scenes->setCurrentIndex(0);
}

void MainWindow::get()
{
    QObject* senderWidget = sender();

    auto name = senderWidget->objectName();
    
    if (name == "btn_Queen")
        Viewer::getCurrentPlayer()->setBTNNumber(64);
    else if (name == "btn_Bishop")
        Viewer::getCurrentPlayer()->setBTNNumber(65);
    else if (name == "btn_Rook")
        Viewer::getCurrentPlayer()->setBTNNumber(66);
    else if (name == "btn_Knight")
        Viewer::getCurrentPlayer()->setBTNNumber(67);
    else if (name == "btn_Surrender")
        Viewer::getCurrentPlayer()->setBTNNumber(70);
    else
    {
        int btnNumber = name.right(2).toInt() - 1;
        Viewer::getCurrentPlayer()->setBTNNumber(btnNumber);
    }

    ui.Scenes->setCurrentIndex(1);
}