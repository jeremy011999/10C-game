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
    mainLayout = new QHBoxLayout();
    returnButton = new QPushButton("Return to main screen");
    connect(returnButton,SIGNAL(clicked()),this,SLOT(returnButtonClicked()));

    mainLayout->addWidget(returnButton);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
}

void InstructionsWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/InstructionsPage.png").scaled(size()));
    QWidget::paintEvent(e);
}


InstructionsWindow::~InstructionsWindow()
{
}

void InstructionsWindow::returnButtonClicked()
{
    emit returnToMainWindow();
}
