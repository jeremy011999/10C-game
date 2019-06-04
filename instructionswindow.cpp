#include "instructionswindow.h"
#include "ui_instructionswindow.h"


/*
Constructor for InstructionsWindow object
    sets up UI and stackedwidget for each page
@param parent: sets parent to QMainWindow
*/
InstructionsWindow::InstructionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructionsWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setStyleSheet("QLabel {color: rgb(255, 255, 255);}");
    ui->stackedWidget->setStyleSheet("QPushButton { background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}");
    ui->centralWidget->setStyleSheet("QStackedWidget { background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);}");
}

/*
destructor for instructionswindow that
cleans up UI
*/
InstructionsWindow::~InstructionsWindow()
{
    delete ui;
}

/*
Slot that sets the current stacked widget to the enemy instructions page
(works for next button)
*/
void InstructionsWindow::on_NextPageEnemy_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/*
Slot that sets the current stacked widget to the powerup instructions page
(works for next button)
*/
void InstructionsWindow::on_NextPagePowerups_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

/*
Slot that emits signal to let gui know to go back to main menu
*/
void InstructionsWindow::on_ReturnToMainMenu_clicked()
{
    emit returnButtonClicked();
}

/*
Slot that sets current stacked widget to first instructions page
(works for back button)
*/
void InstructionsWindow::on_PrevPageHowToPlay_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
Slot that sets the current stacked widget to the enemy instructions page
(works on back button)
*/
void InstructionsWindow::on_PrevPageEnemies_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/*
Slot that emits signal to let gui know to go back to main menu
*/
void InstructionsWindow::on_MainMenuButton_clicked()
{
    emit returnButtonClicked();
}
