#include "game.h"

game::game()
{
    //Make Scene and View
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView(scene);

    //Fix the size of the view and set the scene size to it
    view->setFixedSize(400,500);
    scene->setSceneRect(0,0,400,500);

    //Make ball and add to scene
    ball* myball = new ball;
    scene->addItem(myball);

    //set position of the ball in the scene
    myball->setPos(scene->width()/2,scene->height()-30);

    //add bricks to the scene
    for(int j=0;j<4;j++)
    {
        for (int i=0;i<9;i++)
        {
            brick* brick_to_add = new brick(scene->width()/9,25);
            scene->addItem(brick_to_add);

            //set position of new brick in the scene
            brick_to_add->setPos(45*i,25*j);
        }
    }

    //show the scene
    view->show();
}
