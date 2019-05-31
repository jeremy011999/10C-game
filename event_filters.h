#ifndef EVENT_FILTERS_H
#define EVENT_FILTERS_H

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

//event filters are gross im sorry



class event_filter1 : public QObject
{
    Q_OBJECT
public:
    explicit event_filter1(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic1();
    void blank1();
};

class event_filter2 : public QObject
{
    Q_OBJECT
public:
    explicit event_filter2(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic2();
    void blank2();
};

class event_filter3 : public QObject
{
    Q_OBJECT
public:
    explicit event_filter3(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic3();
    void blank3();
};

class event_filter4 : public QObject
{
    Q_OBJECT
public:
    explicit event_filter4(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic4();
    void blank4();
};

class event_filter5 : public QObject
{
    Q_OBJECT
public:
    explicit event_filter5(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic5();
    void blank5();
};

#endif // EVENT_FILTERS_H
