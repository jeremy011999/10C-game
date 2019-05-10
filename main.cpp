#include "ball.h"
#include "game.h"
#include "bricks.h"
#include "welcome_window.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Initialize the welcome window
    welcome_window w;

    //Initialize game
    game mygame;

    /*
     * Connect the welcome window to game class to start a game
     * startGame() is a signal called from welcome_window when the start game button is pressed
     * run_game() is a slot in game class that starts the game
     */
    QObject::connect(&w,SIGNAL(startGame()),&mygame,SLOT(run_game()));
    w.show();
    return a.exec();
}
