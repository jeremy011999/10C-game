#include "ball.h"
#include "game.h"
#include "bricks.h"
#include "mygui.h"
#include "welcome_window.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myGUI mygui;
    QObject::connect(&mygui,SIGNAL(quitAppSignal()),&a,SLOT(quit()));
    return a.exec();
}
