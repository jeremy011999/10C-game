#ifndef BRICKS_H
#define BRICKS_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QObject>
#include <QPointF>

class game;

class brick:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    brick(int bwidth, int bheight, int bricklevel);
    void update_hit_brick();
    void destroy_brick();
signals:
    void update_points(int pnts);
private:
    int brick_width;
    int brick_height;
    int brick_level;
    friend class game;
};

#endif // BRICKS_H
