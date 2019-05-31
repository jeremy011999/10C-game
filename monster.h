#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlayer>
#include "ball.h"
#include "paddle.h"

class Monster : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Monster(double width);
    void move();
    void killMonster();
    void dyingMonsterAnimation();
    void mute_monster();
    ~Monster();
public slots:
    void updateMonster();
    void updateImage();
signals:
    void update_points(int pnts);
private:
    double x_velocity;
    double y_velocity;
    bool livepic=true;
    QPixmap* deadmonsterpic = nullptr;
    QPixmap* livemonsterpic = nullptr;
    QPixmap* _20pointspic = nullptr;
    QTimer* monsterTimer;
    int flashcount;
    QMediaPlayer* monsterplayer=nullptr;
    double monster_width;
    bool muted = false;
};

#endif // MONSTER_H
