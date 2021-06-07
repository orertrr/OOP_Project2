#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <qdebug.h>
#include <string>
#include "ui_MainWindow.h"
#include "GameManager.h"
#include "Viewer.h"
#include <thread>

class MainWindow : public QMainWindow
{
    Q_OBJECT;
    QThread gamethread;

public:
    MainWindow(GameManager* manager, QWidget *parent = Q_NULLPTR);

public:
    Ui::MainWindowClass ui;
    Viewer v;
    GameManager *manager;

private slots:
    void StartGame();
    void Menu();
    void get();
};
