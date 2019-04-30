#include "welcome_window.h"
#include "ui_welcome_window.h"
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QStyle>
#include <QPainter>
#include <QPaintEvent>

welcome_window::welcome_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::welcome_window)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QPixmap bkgnd("/Users/danyaelgebaly/Desktop/IceBreakerBackground.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QWidget* centralWidget = new QWidget();
    QHBoxLayout* mainLayout = new QHBoxLayout();

    QPushButton* GameButton = new QPushButton("Start Game");
    GameButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(100, 0, 170); color: rgb(255, 255, 255);}"));

    QPushButton* InstructionButton = new QPushButton("Instructions");
    InstructionButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}"));

    QPushButton* QuitButton = new QPushButton("Quit Game");
    QuitButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 20, 140); color: rgb(255, 255, 255);}"));

    mainLayout->addWidget(GameButton);
    mainLayout->addWidget(InstructionButton);
    mainLayout->addWidget(QuitButton);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
}

void welcome_window::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("/Users/danyaelgebaly/Desktop/IceBreakerBackground.png").scaled(size()));
    QWidget::paintEvent(e);
}


welcome_window::~welcome_window()
{
    delete ui;
}
