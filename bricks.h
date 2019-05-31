#ifndef BRICKS_H
#define BRICKS_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QObject>
#include <QPointF>
#include <QGraphicsPixmapItem>

class game;

class brick:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    brick(int bwidth, int bheight, int bricklevel);
    void update_hit_brick();
    void destroy_brick();
    double getRightX();
    double getBottomY();
    double getLeftX();
    double getTopY();
    double getMiddleX();
    double getMiddleY();
    void set_brick_level(int level);

    ~brick();
signals:
    void update_points(int pnts);
    void decrease_brick_count();
private:
    int brick_width;
    int brick_height;
    int brick_level;
    int brick_type;
    friend class game;
    double scale;
    QPixmap* darkbrick = nullptr;
    QPixmap* darkcrack = nullptr;
    QPixmap* darkcrack2 = nullptr;
    QPixmap* mediumbrick = nullptr;
    QPixmap* mediumcrack = nullptr;
    QPixmap* lightbrick = nullptr;

};

#endif // BRICKS_H
