#include "wingamewindow.h"
#include <QPaintEvent>
#include <QPainter>

winGameWindow::winGameWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    returnButton = new QPushButton("Return to main screen");
    connect(returnButton,&QPushButton::clicked,[this](){emit goToMainWindow();});
    returnButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));

    levelLabel = new QLabel("CONGRATULATIONS! \n\n You won the game!");
    levelLabel->setAlignment(Qt::AlignCenter);
    levelLabel->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 50px; color: rgb(255, 255, 255);}"));


    mainLayout->addStretch();
    mainLayout->addWidget(levelLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(returnButton);

    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
}

void winGameWindow::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/finishedGameScreen.png").scaled(size()));
    QWidget::paintEvent(e);
}

