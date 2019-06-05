#ifndef POWERUPMETER_H
#define POWERUPMETER_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

class powerUpMeter : public QWidget
{
    Q_OBJECT

public:

    /*
    Constructor for powerUpMeter object
    @param parent: sets parent of object
    */
    powerUpMeter(QWidget *parent = 0);
    
    //Destrcutor for powerUpMeter that properly cleans up pixmaps
    ~powerUpMeter();
    
    /*
    changes current image for powerUpMeter using counter variable
    @param e: refers to paint event that is currently happening to powerUpMeter object
    */
    void paintEvent(QPaintEvent *e);
    
    /*
    lets powerUpMeter know if its currently showing full picture
    @return: return true if full, false if not
    */
    bool is_full();
    
    /*
    lets powerUpMeter know if its currently showing empty picture
    @return: return true if empty, false if not
    */
    bool is_empty();
    
public slots:

    //increases counter when powerup is earned and then repaints to appropriate image
    void update_counter();
    
    /*
    sets the current counter to a specific value
    @param num: is number to which counter is set to
    */
    void set_counter(int num);
    
private:
    int counter = 0;
    QPixmap* emptySnowflake = new QPixmap(":/Game_Media/Pictures/imageedit_7_4838096674.png");
    QPixmap* snowflakeFill1 = new QPixmap(":/Game_Media/Pictures/imageedit_7_8302397809.png");
    QPixmap* snowflakeFill2 = new QPixmap(":/Game_Media/Pictures/imageedit_7_4142580579.png");
    QPixmap* snowflakeFill3 = new QPixmap(":/Game_Media/Pictures/imageedit_7_5130330305.png");
};


#endif // POWERUPMETER_H
