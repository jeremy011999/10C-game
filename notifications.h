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
    notifications();
    void display_lost_life();
    void display_dead();
    ~notifications();
public slots:
    void lost_life_flash();
    void dying_animation();
private:
    QPixmap* redpic;
    int deadcounter;
    QTimer* dyingtimer = nullptr;
};

#endif // NOTIFICATIONS_H
