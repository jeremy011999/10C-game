#ifndef WELCOME_WINDOW_H
#define WELCOME_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStyle>
#include "optionswindow.h"
#include <QMediaPlayer>


class welcome_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcome_window(QWidget *parent = nullptr);
    ~welcome_window();
    /* paintEvent(QPaintEvent *e) sets background image of welcome window
    @param QPaintEvent *e contains object pixmap is called on
    @return void
    */
    void paintEvent(QPaintEvent *e);
public slots:
    /* GameButtonClicked() slot for clicking start game
    @param none
    @return void
    */
    void GameButtonClicked();
    
    /* quitButtonclicked() slot for clicking quit button
    @param none 
    @return void
    */
    void quitButtonClicked();
    
    /* instructionsButtonClicked() slot for clicking instructions window button
    @param none
    @return void
    */
    void instructionsButtonClicked();
    
    /* OptionsButtonClicked() slot for clicking options window button
    @param none
    @return void
    */
    void OptionButtonClicked();
    
    /*
     resizeWindow(int sizefactor) slot for adjusting window size
     @param int sizefactor - this changes size of window by factor
    */
    void resizeWindow(int sizefactor);
signals:
    // signal to start game
    void startGame();
    
    // signal to quit game
    void quitApplication();
    
    // signal to show instructions
    void showInstructions();
    
    // signal to show options
    void showOptionsWindow();
private:
    QLabel* welcomePage = nullptr;
    QPushButton* GameButton = nullptr;
    QPushButton* OptionButton;
    QPushButton* InstructionButton = nullptr;
    QPushButton* QuitButton = nullptr;
    QHBoxLayout* mainLayout = nullptr;
    optionswindow* options;
};

#endif // WELCOME_WINDOW_H
