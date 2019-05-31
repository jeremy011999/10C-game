#include "levels_window.h"

levels_window::levels_window(QWidget *parent) : QMainWindow(parent)
{
    filter1 = new please_work1(this);
    filter2 = new please_work2(this);
    filter3 = new please_work3(this);
    filter4 = new please_work4(this);
    filter5 = new please_work5(this);


    QWidget* centralWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    returnButton = new QPushButton("Return to main screen");
    returnButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));
    connect(returnButton,&QPushButton::clicked,[this](){emit returnToMainWindow();});

    QPushButton* level1Button = new QPushButton("level 1");
    level1Button->setAttribute(Qt::WA_Hover);
    level1Button->installEventFilter(filter1);
    level1Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));
    connect(level1Button,&QPushButton::clicked,[this](){emit goToLevel(1);});

    QPushButton* level2Button = new QPushButton("level 2");
    level2Button->setAttribute(Qt::WA_Hover);
    level2Button->installEventFilter(filter2);
    level2Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));
    connect(level2Button,&QPushButton::clicked,[this](){emit goToLevel(2);});

    QPushButton* level3Button = new QPushButton("level 3");
    level3Button->setAttribute(Qt::WA_Hover);
    level3Button->installEventFilter(filter3);
    level3Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));
    connect(level3Button,&QPushButton::clicked,[this](){emit goToLevel(3);});

    QPushButton* level4Button = new QPushButton("level 4");
    level4Button->setAttribute(Qt::WA_Hover);
    level4Button->installEventFilter(filter4);
    level4Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));
    connect(level4Button,&QPushButton::clicked,[this](){emit goToLevel(4);});

    QPushButton* level5Button = new QPushButton("level 5");
    level5Button->setAttribute(Qt::WA_Hover);
    level5Button->installEventFilter(filter5);
    level5Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));
    connect(level5Button,&QPushButton::clicked,[this](){emit goToLevel(5);});

    QHBoxLayout* overall_layout = new QHBoxLayout;
    picture = new level_pic;
    connect(filter1, SIGNAL(show_pic1()),picture,SLOT(pic1()));
    connect(filter2, SIGNAL(show_pic2()),picture,SLOT(pic2()));
    connect(filter3, SIGNAL(show_pic3()),picture,SLOT(pic3()));
    connect(filter4, SIGNAL(show_pic4()),picture,SLOT(pic4()));
    connect(filter5, SIGNAL(show_pic5()),picture,SLOT(pic5()));
    connect(filter1, SIGNAL(blank1()),picture,SLOT(show_blank()));
    connect(filter2, SIGNAL(blank2()),picture,SLOT(show_blank()));
    connect(filter3, SIGNAL(blank3()),picture,SLOT(show_blank()));
    connect(filter4, SIGNAL(blank4()),picture,SLOT(show_blank()));
    connect(filter5, SIGNAL(blank5()),picture,SLOT(show_blank()));




    mainLayout->addWidget(level1Button);
    mainLayout->addWidget(level2Button);
    mainLayout->addWidget(level3Button);
    mainLayout->addWidget(level4Button);
    mainLayout->addWidget(level5Button);
    mainLayout->addWidget(returnButton);


    overall_layout->addWidget(picture);
    overall_layout->addLayout(mainLayout);

    centralWidget->setStyleSheet(QString("QWidget {background-color: rgb(136, 161, 204);}"));
    centralWidget->setLayout(overall_layout);
    setCentralWidget(centralWidget);
}

level_pic::level_pic()
{
    this->setPixmap(QPixmap(":/IceBreakerBackground.png"));
}

//void level_pic::paintEvent(QPaintEvent *e) {
//    QPainter painter(this);
//    QWidget::paintEvent(e);
//}

void level_pic::pic1()
{
    this->setPixmap(*firstlvlpic);
}

void level_pic::pic2()
{

   this->setPixmap(*scndlvlpic);
}

void level_pic::pic3()
{

    this->setPixmap(*thrdlvlpic);

}

void level_pic::pic4()
{

    this->setPixmap(*frthlvlpic);

}

void level_pic::pic5()
{
    this->setPixmap(*fthlvlpic);
}

void level_pic::show_blank()
{
    this->setPixmap(QPixmap(":/IceBreakerBackground.png"));
}

please_work1::please_work1(QObject *parent) : QObject(parent)
{

}

please_work2::please_work2(QObject *parent) : QObject(parent)
{

}


please_work3::please_work3(QObject *parent) : QObject(parent)
{

}


please_work4::please_work4(QObject *parent) : QObject(parent)
{

}


please_work5::please_work5(QObject *parent) : QObject(parent)
{

}


bool please_work1::eventFilter(QObject *obj, QEvent *event)
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

bool please_work2::eventFilter(QObject *obj, QEvent *event)
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

bool please_work3::eventFilter(QObject *obj, QEvent *event)
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

bool please_work4::eventFilter(QObject *obj, QEvent *event)
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

bool please_work5::eventFilter(QObject *obj, QEvent *event)
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

