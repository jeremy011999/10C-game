#ifndef EVENT_FILTERS_H
#define EVENT_FILTERS_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QStyle>
#include <QHoverEvent>
#include <QPixmap>
#include <QLabel>



class event_filter1 : public QObject
{
    Q_OBJECT
public:

    /*
    Constructors for event_filters 1 (each filter corresponds to a button on
        levelswindow page)
    @param parent: sets parents to QObject (inherits from QObject)
    */
    explicit event_filter1(QObject *parent = nullptr);
    
    /*
    sets up event filter to take care of hover_enter and hover_leave events
        in order to display level picture when mouse moves over a button
        as well as change stylesheet of button
    @param: obj: lets the event filter know what it is being attached to
    @param event: refers to event that is currently happening to obj
    @return: returns whether or not anything should be done for event (true for yes)
    */
    bool eventFilter(QObject* obj, QEvent* event) override;
    
signals:

    //lets level select window know to show picture of level 1
    void show_pic1();
    
    //lets level select window know to show blank picture when mouse leaves
    void blank1();
};

class event_filter2 : public QObject
{
    Q_OBJECT
public:

    /*
    Constructors for event_filters 2 (each filter corresponds to a button on
        levelswindow page)
    @param parent: sets parents to QObject (inherits from QObject)
    */
    explicit event_filter2(QObject *parent = nullptr);
    
    /*
    sets up event filter to take care of hover_enter and hover_leave events
        in order to display level picture when mouse moves over a button
        as well as change stylesheet of button
    @param: obj: lets the event filter know what it is being attached to
    @param event: refers to event that is currently happening to obj
    @return: returns whether or not anything should be done for event (true for yes)
    */
    bool eventFilter(QObject* obj, QEvent* event) override;
    
signals:

    //lets level select window know to show picture of level 2
    void show_pic2();
    
    //lets level select window know to show blank picture when mouse leaves
    void blank2();
};

class event_filter3 : public QObject
{
    Q_OBJECT
public:

    /*
    Constructors for event_filters 3 (each filter corresponds to a button on
        levelswindow page)
    @param parent: sets parents to QObject (inherits from QObject)
    */
    explicit event_filter3(QObject *parent = nullptr);
    
    /*
    sets up event filter to take care of hover_enter and hover_leave events
        in order to display level picture when mouse moves over a button
        as well as change stylesheet of button
    @param: obj: lets the event filter know what it is being attached to
    @param event: refers to event that is currently happening to obj
    @return: returns whether or not anything should be done for event (true for yes)
    */
    bool eventFilter(QObject* obj, QEvent* event) override;
    
signals:

    //lets level select window know to show picture of level 3
    void show_pic3();
    
    //lets level select window know to show blank picture when mouse leaves
    void blank3();
};

class event_filter4 : public QObject
{
    Q_OBJECT
public:

    /*
    Constructors for event_filters 4 (each filter corresponds to a button on
        levelswindow page)
    @param parent: sets parents to QObject (inherits from QObject)
    */
    explicit event_filter4(QObject *parent = nullptr);
    
    /*
    sets up event filter to take care of hover_enter and hover_leave events
        in order to display level picture when mouse moves over a button
        as well as change stylesheet of button
    @param: obj: lets the event filter know what it is being attached to
    @param event: refers to event that is currently happening to obj
    @return: returns whether or not anything should be done for event (true for yes)
    */
    bool eventFilter(QObject* obj, QEvent* event) override;
    
signals:

    //lets level select window know to show picture of level 4
    void show_pic4();
    
    //lets level select window know to show blank picture when mouse leaves
    void blank4();
};

class event_filter5 : public QObject
{
    Q_OBJECT
public:

    /*
    Constructors for event_filters 5 (each filter corresponds to a button on
        levelswindow page)
    @param parent: sets parents to QObject (inherits from QObject)
    */
    explicit event_filter5(QObject *parent = nullptr);
    
    /*
    sets up event filter to take care of hover_enter and hover_leave events
        in order to display level picture when mouse moves over a button
        as well as change stylesheet of button
    @param: obj: lets the event filter know what it is being attached to
    @param event: refers to event that is currently happening to obj
    @return: returns whether or not anything should be done for event (true for yes)
    */
    bool eventFilter(QObject* obj, QEvent* event) override;
    
signals:

    //lets level select window know to show picture of level 5
    void show_pic5();
    
    //lets level select window know to show blank picture when mouse leaves
    void blank5();
};

#endif // EVENT_FILTERS_H
