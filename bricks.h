#ifndef BRICKS_H
#define BRICKS_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QObject>
#include <QPointF>

class brick:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    brick(int bwidth, int bheight, int bricklevel);
    void update_hit_brick();
private:
    int brick_width;
    int brick_height;
    int brick_level;
};

#endif // BRICKS_H
