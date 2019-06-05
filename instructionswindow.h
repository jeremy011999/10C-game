#ifndef INSTRUCTIONSWINDOW_H
#define INSTRUCTIONSWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

/**
 * Class makes a stacked widget for the instructions window
 */
class InstructionsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InstructionsWindow(QWidget *parent = nullptr);

private slots:
    
    /**
     * Sets up the how to play page
     */
    void setUpHowToPlayPage();
    
    /**
     * Sets up the enemies page
     */
    void setUpEnemiesPage();
    
    /**
     * Sets up the powerups page
     */
    void setUpPowerUpPage();


signals:
    
    //emits signal to return to the main screen
    void returnButtonClicked();
private:
    QPushButton* nextPageEnemyButton = nullptr;
    QPushButton* prevPageEnemyButton = nullptr;
    QPushButton* nextPagePowerupsButton = nullptr;
    QPushButton* returnToMain1Button = nullptr;
    QPushButton* returnToMain2Button = nullptr;
    QPushButton* prevPageHow2PlayButton = nullptr;
    QStackedWidget* stackedWidget = nullptr;
    QWidget* howToPlayPage = nullptr;
    QWidget* enemiesPage = nullptr;
    QWidget* powerUpsPage = nullptr;
};

#endif // INSTRUCTIONSWINDOW_H
