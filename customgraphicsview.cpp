#include "customgraphicsview.h"

#include <QKeyEvent>

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
}

CustomGraphicsView::CustomGraphicsView(QGraphicsScene *scene, paddle* pad_, QWidget *parent)
    : QGraphicsView(scene, parent)
{
    pad1=pad_;
}

void CustomGraphicsView::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Left: { pad1->move_left(); break; }
    case Qt::Key_Right: { pad1->move_right(); break; }
    }
}
