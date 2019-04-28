#include "ball.h"
#include "game.h"
#include "bricks.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game mygame;
    return a.exec();
}
