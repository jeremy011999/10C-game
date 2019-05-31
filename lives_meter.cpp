#include "lives_meter.h"

lives_meter::lives_meter()
{
    QHBoxLayout* whole_layout = new QHBoxLayout;

    QWidget* life1widget = new QWidget;
    QPixmap* life1pic = new QPixmap(":/imageedit_21_9525227244.png");
    QLabel* life1label = new QLabel();
    QHBoxLayout* life1layout = new QHBoxLayout();
    life1layout->addWidget(life1label);
    life1widget->setLayout(life1layout);


    QWidget* life2widget = new QWidget;
    QPixmap* life2pic = new QPixmap(":/imageedit_21_9525227244.png");
    QLabel* life2label = new QLabel(); life2label->setPixmap((*life2pic).scaled(life2label->size()));
    QHBoxLayout* life2layout = new QHBoxLayout();
    life2layout->addWidget(life2label);
    life2widget->setLayout(life2layout);


    QWidget* life3widget = new QWidget;
    QPixmap* life3pic = new QPixmap(":/imageedit_21_9525227244.png");
    QLabel* life3label = new QLabel(); life3label->setPixmap((*life3pic).scaled(life3label->size()));
    QHBoxLayout* life3layout = new QHBoxLayout();
    life3layout->addWidget(life3label);
    life3widget->setLayout(life3layout);


    life1widget->setMaximumSize(60,60);
    life2widget->setMaximumSize(60,60);
    life3widget->setMaximumSize(60,60);

    life1widget->setMinimumSize(60,60);
    life2widget->setMinimumSize(60,60);
    life3widget->setMinimumSize(60,60);

    whole_layout->addWidget(life1widget);
    whole_layout->addWidget(life2widget);
    whole_layout->addWidget(life3widget);

    life1label->setPixmap((*life1pic).scaled(life1label->size()));
    life2label->setPixmap((*life2pic).scaled(life2label->size()));
    life3label->setPixmap((*life3pic).scaled(life3label->size()));

    setLayout(whole_layout);
}
