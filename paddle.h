#ifndef PADDLE_H
#define PADDLE_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include "ball.h"

class paddle:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    /*
    Constructor for paddle object
    @param width: sets width of paddle
    */
    paddle(double width);
    
    //moves paddle left by fraction of gamescene width
    void move_left();
    
    //moves paddle right by fraction of gamescene wdith
    void move_right();
    
    /*
    gets where the middle of the paddle is in terms of a qreal point
    @return: returns where middle of paddle is in gamescene in terms of x coordinates
    */
    qreal getMiddleXCoord();
    
    /*
    returns width of paddle
    @return: width of paddle
    */
    int getwidth();
    
    //elongates paddle and starts timer to know when to send back to regular size
    //also sets is_powered_paddle to true
    void power_up_paddle();
    
    /*
    checks if paddle is currently being powered up
    @return: true or false based on is_powered_paddle private variable
    */
    bool power_up_paddle_active();
    
    /*
    Handles movement of paddle through the arrow keys as well as releasing ball with spacebar press
    @param event: the key event that currently occurred on the paddle
    */
    void keyPressEvent(QKeyEvent* event);
    
    //emits signal to game that paddle died and needs cleaned up/game is over
    void paddleDied();
    
    //emits to game to release ball from paddle once space has been pressed
    void space_press();
    
    //sets the bool stick_ball to true
    void stick_ball_to_paddle();
    
    /**
     * check if ball is stuck to paddle
     *
     * @return bool true if ball is stuck to paddle
     */
    bool ball_is_stuck() const;
    
    /**
     * set lives of paddle
     *
     * @param lives in game
     */
    void set_lives(int life);
    
    /**
     * gets lives of paddle
     *
     * @return lives in game
     */
    int get_lives();
signals:

    //connect to game to know that game is over and to clean up paddle
    void paddleDead();
    
    //lets game know to release ball since spacebar has been pressed
    void space_bar_pressed();
public slots:

    //sets paddle back to regular size and is_powered_paddle to false
    void back_to_regular_paddle();
    
private:
    int paddle_width;
    int paddle_height;
    bool is_powered_paddle;
    bool stick_ball = false;
    int lives;
};

#endif // PADDLE_H
