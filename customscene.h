#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

class customScene : public QGraphicsScene
{
    Q_OBJECT
public:
    customScene();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
signals:
    void set_paddle_x(double x_coord);
};

#endif // CUSTOMSCENE_H
