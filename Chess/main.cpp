#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <thread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameManager manager;
    MainWindow w(&manager);

    /*thread game(&GameManager::Start, &manager);
    game.detach();*/

    w.show();
    return a.exec();
}
