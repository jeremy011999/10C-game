#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScale>
#include "paddle.h"

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomGraphicsView(QWidget *parent = nullptr);
    CustomGraphicsView(QGraphicsScene *scene, paddle* pad_, QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    paddle* pad1;
};

#endif // CUSTOMGRAPHICSVIEW_H
