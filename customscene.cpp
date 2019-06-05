#include "customscene.h"

customScene::customScene()
{

}

void customScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    double mouseX = event->pos().x();
    emit set_paddle_x(mouseX);
}
