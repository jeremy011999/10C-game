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
        emit show_pic1();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
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
        emit show_pic2();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
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
        emit show_pic3();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
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
        emit show_pic4();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
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
        emit show_pic5();
        return true;
    }
    if (event->type()==QEvent::HoverLeave)
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        emit blank5();
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}
