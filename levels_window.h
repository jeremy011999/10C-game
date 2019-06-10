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

class level_pic; //forward declaration of level_pic

class levels_window : public QMainWindow
{
    Q_OBJECT
public:

    /**
     * Constructor for levels_window, sets up buttons and pixmap for level preview
     *
     * @param parent: sets parent of levels_window (defaulted to nullptr)
     */
    explicit levels_window(QWidget *parent = nullptr);
    
    /**
     * handles mouse hover events to preview picture of level that is being hovered over
     *
     * @param e: refers to any hover event that is currently being performed on level select buttons
     */
    void hoverEvent(QHoverEvent* e);
    
signals:

    //lets gui know to go back to main welcome window
    void returnToMainWindow();
    
    /**
     * lets game know to start and what level to start at
     *
     * @param lvl: refers to level number that game will start at (1-5)
     */
    void goToLevel(int lvl);
    
public slots:

    /**
     * resizes window to either large or small icons
     *
     * @param sizeFactor: ranges from 1-2 and lets window know whether icons should be small(1) or large(2)
     */
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
    
    //Constructor for level pic object that holds the current preview image of level
    level_pic();
    
    //Destructor for level pic object to properly clean up pixmap objects
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
public slots:

    //sets current picture to picture of first level
    void pic1();
    
    //sets current picture to picture of second level
    void pic2();
    
    //sets current picture to picture of third level
    void pic3();
    
    //sets current picture to picture of fourth level
    void pic4();
    
    //sets current picture to picture of fifth level
    void pic5();
    
    //sets current picture to picture of blank image
    void show_blank();
    
private:
    QPixmap* blanklvlpic = new QPixmap(":/Game_Media/Pictures/blank.png");
    QPixmap* firstlvlpic = new QPixmap(":/Game_Media/Pictures/first.png");
    QPixmap* scndlvlpic = new QPixmap(":/Game_Media/Pictures/rows.png");
    QPixmap* thrdlvlpic = new QPixmap(":/Game_Media/Pictures/diamond.png");
    QPixmap* frthlvlpic = new QPixmap(":/Game_Media/Pictures/smiley.png");
    QPixmap* fthlvlpic = new QPixmap(":/Game_Media/Pictures/10_C_image.png");
};

#endif // LEVELS_WINDOW_H
