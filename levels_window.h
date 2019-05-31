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
private:
    QVBoxLayout* mainLayout = nullptr;
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
    //QPainter* painter;
    //void paintEvent(QPaintEvent *e);
signals:
public slots:
    void pic1();
    void pic2();
    void pic3();
    void pic4();
    void pic5();
    void show_blank();
private:
};

#endif // LEVELS_WINDOW_H
