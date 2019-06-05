#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QMediaPlayer>

class notifications:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    //Constrcutor for notifications object; sets deadcounter=0 and redpic to pixmap
    notifications();
    
    
    //scales and displays lost life message as well as starts timer to flash message on screen
    void display_lost_life();
    
    //displays red screen to show that player has died
    void display_dead();
    
    //destructor for notifications object to properly clean up pixmap objects
    ~notifications();
public slots:

    //connected to timer in order to make life lost message flash on screen
    void lost_life_flash();
    
    //connected to timer in order to slowly increase opacity of red screen to fully red when player dies
    void dying_animation();
private:
    QPixmap* redpic;
    int deadcounter;
    QTimer* dyingtimer = nullptr;
};

#endif // NOTIFICATIONS_H
