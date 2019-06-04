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
    
    /* move() is responsible for moving the monsters by a certain x and y velocity
    @param none
    @return void
    */
    void move();
    
    /* killMonster() is responsible for ending timer of Monster and displaying necessary animation when monster is killed
    @param none
    @return void
    */
    void killMonster();
    
    /* dyingMonsterAnimation() is responsible for managing timing and pixmap of the dyingMonster animation (the red monster appears when hit) 
    @param none
    @return void
    */
    void dyingMonsterAnimation();
    
    /* mute_monster() is responsible for muting the monster by adjusting the volume
    @param none
    @return void
    */
    void mute_monster();
    ~Monster();
public slots:
    /* updateMonster() is a slot that emits necessary signals to manage the functionality of enemies
    @param none
    @return void
    */
    void updateMonster();
    
    /* updateImage() is responsible for updating the images when the monster is alive, dead, and hit
    @param none
    @return void
    */
    void updateImage();
signals:
    /* update_points(int pnts) is a signal emitted to update number of points when monster is hit  
    @param int pnts - number of points to be emitted 
    @return void
    */
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
