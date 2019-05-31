#include "instructionswindow.h"
#include "ui_instructionswindow.h"

InstructionsWindow::InstructionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructionsWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setStyleSheet("QLabel {color: rgb(255, 255, 255);}");
    ui->stackedWidget->setStyleSheet("QPushButton { background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}");
    ui->centralWidget->setStyleSheet("QStackedWidget { background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);}");
}

InstructionsWindow::~InstructionsWindow()
{
    delete ui;
}

void InstructionsWindow::on_NextPageEnemy_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void InstructionsWindow::on_NextPagePowerups_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void InstructionsWindow::on_ReturnToMainMenu_clicked()
{
    emit returnButtonClicked();
}

void InstructionsWindow::on_PrevPageHowToPlay_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void InstructionsWindow::on_PrevPageEnemies_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void InstructionsWindow::on_MainMenuButton_clicked()
{
    emit returnButtonClicked();
}
