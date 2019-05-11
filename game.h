#include "ball.h"
#include "bricks.h"
#include "paddle.h"
#include "welcome_window.h"
#include <QStackedWidget>
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
    void setUpGraphicsView();
    void SetUpBricks(int game_level);
    void goToGamePlayWindow();
    void goToWelcomeWindow();
public slots:
    void run_game();
    void setpaddlefocus();
    void update_score_on_brick_hit();
    void died();
private:
    QLabel* score_label = nullptr;
    welcome_window* welcomewindow = nullptr;
    QWidget* gamePlayWindow = nullptr;
    QGraphicsScene* gamescene = nullptr;
    QGraphicsView* view = nullptr;
    int points=0;
    QVBoxLayout* gamePlayLayout=nullptr;
    paddle* mypaddle = nullptr;
    int game_level = 1;
    QStackedWidget* stackedWidget = nullptr;
    welcome_window* welcomeWindow = nullptr;
};

#endif // GAME_H
