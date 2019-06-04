#ifndef POWERUPMETER_H
#define POWERUPMETER_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

class powerUpMeter : public QWidget
{
    Q_OBJECT

public:
    powerUpMeter(QWidget *parent = 0);
    ~powerUpMeter();
    void paintEvent(QPaintEvent *e);
    bool is_full();
    bool is_empty();
public slots:
    void update_counter();
    void set_counter(int num);
private:
    int counter = 0;
    QPixmap* emptySnowflake = new QPixmap(":/Game_Media/Pictures/imageedit_7_4838096674.png");
    QPixmap* snowflakeFill1 = new QPixmap(":/Game_Media/Pictures/imageedit_7_8302397809.png");
    QPixmap* snowflakeFill2 = new QPixmap(":/Game_Media/Pictures/imageedit_7_4142580579.png");
    QPixmap* snowflakeFill3 = new QPixmap(":/Game_Media/Pictures/imageedit_7_5130330305.png");
};


#endif // POWERUPMETER_H
