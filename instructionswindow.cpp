#include "instructionswindow.h"
#include <QLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

InstructionsWindow::InstructionsWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget();
    QHBoxLayout* mainLayout = new QHBoxLayout();
    QPushButton* returnToMainScreen = new QPushButton("Return to main screen");

    centralWidget->setLayout(mainLayout);
    mainLayout->addWidget(returnToMainScreen);
    this->setCentralWidget(centralWidget);
}

void InstructionsWindow::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("/InstructionsPage.png").scaled(size()));
    QWidget::paintEvent(e);
}


InstructionsWindow::~InstructionsWindow()
{
}
