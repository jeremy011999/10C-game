#ifndef LEVELS_WINDOW_H
#define LEVELS_WINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QStyle>
#include <QHoverEvent>
#include <QPixmap>
#include <QLabel>
#include "event_filters.h"

class level_pic;

class levels_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit levels_window(QWidget *parent = nullptr);
    void hoverEvent(QHoverEvent* e);
signals:
    void returnToMainWindow();
    void goToLevel(int lvl);
public slots:
    void resizeWindow(int sizeFactor);
private:
    QVBoxLayout* mainLayout = nullptr;
    QLabel* directions1;
    QLabel* directions2;
    QPushButton* level1Button;
    QPushButton* level2Button;
    QPushButton* level3Button;
    QPushButton* level4Button;
    QPushButton* level5Button;
    QPushButton* returnButton = nullptr;
    level_pic* picture;
    event_filter1* filter1;
    event_filter2* filter2;
    event_filter3* filter3;
    event_filter4* filter4;
    event_filter5* filter5;

};

class level_pic : public QLabel
{
    Q_OBJECT
public:
    level_pic();
    ~level_pic()
    {
        delete blanklvlpic;
        delete firstlvlpic;
        delete scndlvlpic;
        delete thrdlvlpic;
        delete frthlvlpic;
        delete fthlvlpic;
        blanklvlpic    = nullptr;
        firstlvlpic    = nullptr;
        scndlvlpic     = nullptr;
        thrdlvlpic     = nullptr;
        frthlvlpic     = nullptr;
        fthlvlpic      = nullptr;
    }
signals:
public slots:
    void pic1();
    void pic2();
    void pic3();
    void pic4();
    void pic5();
    void show_blank();
private:
    QPixmap* blanklvlpic = new QPixmap(":/Game_Media/Pictures/blank.png");
    QPixmap* firstlvlpic = new QPixmap(":/Game_Media/Pictures/first.png");
    QPixmap* scndlvlpic = new QPixmap(":/Game_Media/Pictures/rows.png");
    QPixmap* thrdlvlpic = new QPixmap(":/Game_Media/Pictures/diamond.png");
    QPixmap* frthlvlpic = new QPixmap(":/Game_Media/Pictures/smiley.png");
    QPixmap* fthlvlpic = new QPixmap(":/Game_Media/Pictures/pasted image 0.png");
};

#endif // LEVELS_WINDOW_H
