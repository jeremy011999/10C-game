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
    
    /**
     * update_hit_brick() emits the signal to update the number of points and adjusts the brick color relative
     * its strength
     */
    void update_hit_brick();
    
    /**
     * destroy_brick() emits signal to update points depending on which brick you hit and removes the item from the scene when hit
     */
    void destroy_brick();
    
    /**
     * get right X coordinate of the brick
     *
     * @return right X coordinate of brick
     */
    double getRightX();
    
    /**
     * get bottom y coordinate of the brick
     *
     * @return bottom Y coordinate of brick
     */
    double getBottomY();
    
    /**
     * get left X coordinate of the brick
     *
     * @return left X coordinate of brick
     */
    double getLeftX();
   
    /**
     * get top y coordinate of the brick
     *
     * @return top y coordinate of brick
     */
    double getTopY();
    
    /**
     * get middle x coordinate of the brick
     *
     * @return middle x coordinate of brick
     */
    double getMiddleX();
    
    /**
     * get middle y coordinate of the brick
     *
     * @return middle y coordinate of brick
     */
    double getMiddleY();

    ~brick();
signals:
    /* update_points(int pnts) is a signal that is emitted to adjust the points when the bricks are hit
    @param int pnts - number of points to emit in the signal
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
