#include "ball.h"
#include "bricks.h"
#include "paddle.h"
#include "welcome_window.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>


#ifndef GAME_H
#define GAME_H


class game : public QObject
{
    Q_OBJECT
public:
    game();
    void SetUpBricks(int game_level);
public slots:
    void run_game();
    void setpaddlefocus();
    void update_score_on_brick_hit();
private:
    QLabel* score_label = nullptr;
    welcome_window* welcomewindow = nullptr;
    QWidget* gamewindow = nullptr;
    QGraphicsScene* gamescene = nullptr;
    int points=0;
    paddle* mypaddle = nullptr;
    int game_level = 1;

};

#endif // GAME_H
