#ifndef BRICKS_H
#define BRICKS_H

#include <QWidget>
#include <QPointF>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>


class game;

class brick:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    brick(int bwidth, int bheight, int bricklevel);
    
    /* update_hit_brick() emits the signal to update the number of points and adjusts the brick color relative to its strength
    @param No parameters 
    @return void, does not return anything
    */
    void update_hit_brick();
    
    /* destroy_brick() emits signal to update points depending on which brick you hit and removes the item from the scene when hit
    @param No parameters
    @return void, does not return anything
    */
    void destroy_brick();
    
    /* Description about the function
    @param No parameters
    @return void, does not return anything
    */
    double getRightX();
    
    /* Description about the function
    @param No parameters
    @return void, does not return anything
    */
    double getBottomY();
    
    /* Description about the function
    @param No parameters
    @return void, does not return anything
    */
    double getLeftX();
   
    /* Description about the function
    @param No parameters
    @return void, does not return anything
    */
    double getTopY();
    
    /* Description about the function
    @param No parameters
    @return void, does not return anything
    */
    double getMiddleX();
    
    /* Description about the function
    @param No parameters
    @return void, does not return anything
    */
    double getMiddleY();

    ~brick();
signals:
    /* update_points(int pnts) is a signal that is emitted to adjust the points when the bricks are hit
    @param int pnts - number of points to emit in the signal
    @return
    */
    void update_points(int pnts);
    
    /* decrease_brick_count() is a signal that is emitted to lessen the number of breaks, ultimately removing the breaks from the scene when they are broken
    @param No parameters
    @return void, does not return anything
    */
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
