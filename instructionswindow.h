#ifndef INSTRUCTIONSWINDOW_H
#define INSTRUCTIONSWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class InstructionsWindow;
}

class InstructionsWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*
    Constructor for InstructionsWindow object
        sets up UI and stackedwidget for each page
    @param parent: sets parent to QMainWindow
    */
    explicit InstructionsWindow(QWidget *parent = nullptr);
    
    /*
    destructor for instructionswindow that
    cleans up UI
    */
    ~InstructionsWindow();

private slots:

    /*
    Slot that sets the current stacked widget to the enemy instructions page
    (works for next button)
    */
    void on_NextPageEnemy_clicked();
    
    /*
    Slot that sets the current stacked widget to the powerup instructions page
    (works for next button)
    */
    void on_NextPagePowerups_clicked();
    
    /*
    Slot that emits signal to let gui know to go back to main menu
    */
    void on_ReturnToMainMenu_clicked();
    
    /*
    Slot that sets current stacked widget to first instructions page
    (works for back button)
    */
    void on_PrevPageHowToPlay_clicked();

    /*
    Slot that sets the current stacked widget to the enemy instructions page
    (works on back button)
    */
    void on_PrevPageEnemies_clicked();
    
    /*
    Slot that emits signal to let gui know to go back to main menu
    */
    void on_MainMenuButton_clicked();

signals:

    //lets gui know to go back to main welcome window
    void returnButtonClicked();

private:
    QPushButton* MainMenuButton = nullptr;
    Ui::InstructionsWindow *ui;
};

#endif // INSTRUCTIONSWINDOW_H
