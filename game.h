#include "ball.h"
#include "bricks.h"
#include "greensnowflake.h"
#include "paddle.h"
#include "welcome_window.h"
#include "powerupmeter.h"
#include <QStackedWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QProgressBar>
#include "monster.h"
#include "snowflakes.h"
#include "lives_meter.h"
#include "notifications.h"
#include <QMediaPlaylist>
#include <QDebug>


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
    bool some_power_up_is_active();
    void run_powerup_bar_flash_animation();
    void no_more_lives();
    ~game();
public slots:
    void run_game(int lvl);
    void itemGenerator();
    void nextLevel();
    void setpaddlefocus();
    void update_score_on_brick_hit(int pnts);
    void update_score_on_monster_hit(int pnts);
    void a_ball_hit_ground();
    ball* generateNewBall();
    void reset_game();
    void clean_up_board();
    void quitGame();
    void mute_sound();
    void killedByMonster();
    void monsterGenerator();
    void blueSnowflakesGenerator();
    void greenSnowflakesGenerator();
    void powerup_meter_flash_helper();
    void update_meter_on_snowflake_capture();
    void update_lives_on_green_snowflake_capture();
    void decrease_brick_count();
    void change_time();
    void difficulty(int x);
signals:
    void time_to_exit_game_screen();
    void time_to_enter_results_screen(int totalpoints);
    void just_beat_level(int lvl);
    void go_to_game_won_window(int totalpoints);
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
    int ballcount = 0;
    bool muted = false;
    QMediaPlayer* music = nullptr;
    QTimer* fallingObjectsTimer = nullptr;
    QTimer* flash_animation_timer = nullptr;
    powerUpMeter* snowflakeMeter = nullptr;
    QLabel* lives_label;
    int lives=3;
    int brick_count;
    QMediaPlayer* lostLifeSound = nullptr;
    QMediaPlayer* gameOverSound = nullptr;
    QLabel* power_up_timer;
    int power_time;
    QTimer* power_up_time;
    QMediaPlayer* snowflakeCaptureSound = nullptr;
    double game_difficulty = 0;
    double monster_prob, life_prob, snow_prob;
};

#endif // GAME_H
