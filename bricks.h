#ifndef BRICKS_H
#define BRICKS_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QObject>

class brick:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    brick(int bwidth, int bheight);
private:
    int brick_width;
    int brick_height;
};

#endif // BRICKS_H

