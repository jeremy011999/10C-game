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

    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
}

void InstructionsWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap image(":/InstructionsPage.png");
    painter.drawPixmap(0, 0, image.scaled(size()));
    QWidget::paintEvent(e);
}


InstructionsWindow::~InstructionsWindow()
{
}
