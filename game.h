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
    void SetUpBricks(int game_level);
    QWidget* getGamePlayWindow();
    void runPowerup();
public slots:
    void run_game();
    void setpaddlefocus();
    void update_score_on_brick_hit(int pnts);
    void died();
    void quitGame();
signals:
    void time_to_exit_game_screen();
    void time_to_enter_results_screen(int totalpoints);
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
    QTimer* focustimer = nullptr;
    int ballcount = 1;
};

#endif // GAME_H
