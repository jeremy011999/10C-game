#include "event_filters.h"

event_filter1::event_filter1(QObject *parent) : QObject(parent)
{

}

event_filter2::event_filter2(QObject *parent) : QObject(parent)
{

}


event_filter3::event_filter3(QObject *parent) : QObject(parent)
{

}


event_filter4::event_filter4(QObject *parent) : QObject(parent)
{

}


event_filter5::event_filter5(QObject *parent) : QObject(parent)
{

}


bool event_filter1::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::HoverEnter)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                                               QPushButton::pressed {min-width: 100px; min-height = 75px; font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}"));
        emit show_pic1();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; \
                                                              border-style: outset; border-width: 3px;border-radius: 10px;\
                                                              border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);}"));
        emit blank1();
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}

bool event_filter2::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::HoverEnter)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                                               QPushButton::pressed {min-width: 100px; min-height = 75px; font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}"));
        emit show_pic2();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; \
                                                              border-style: outset; border-width: 3px;border-radius: 10px;\
                                                              border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);}"));
        emit blank2();
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}

bool event_filter3::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::HoverEnter)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                                               QPushButton::pressed {min-width: 100px; min-height = 75px; font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}"));
        emit show_pic3();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; \
                                                              border-style: outset; border-width: 3px;border-radius: 10px;\
                                                              border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);}"));
        emit blank3();
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}

bool event_filter4::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::HoverEnter)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                                               QPushButton::pressed {min-width: 100px; min-height = 75px; font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}"));
        emit show_pic4();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; \
                                                              border-style: outset; border-width: 3px;border-radius: 10px;\
                                                              border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);}"));
        emit blank4();
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}

bool event_filter5::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::HoverEnter)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                                               QPushButton::pressed {min-width: 100px; min-height = 75px; font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}"));
        emit show_pic5();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        static_cast<QPushButton*>(obj)->setStyleSheet(QString("QPushButton {font-family: Courier; font-size:" + QString::number(static_cast<QPushButton*>(obj)->height()/2.5) + "px; \
                                                              border-style: outset; border-width: 3px;border-radius: 10px;\
                                                              border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);}"));

        emit blank5();
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}
