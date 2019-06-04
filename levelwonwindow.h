#ifndef LEVELWONWINDOW_H
#define LEVELWONWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMainWindow>

class LevelWonWindow : public QWidget
{
    Q_OBJECT
public:
    LevelWonWindow();
    
    /* set_level_just_beat(int lvl_just_beat) is responsible for text that notifies you what level you just beat
    @param int lvl_just_beat - value of the level just beat
    @return void
    */
    void set_level_just_beat(int lvl_just_beat);
signals:
    /* returnToMainWindow() is a signal emitted to return to the main screen
    @param none
    @return void
    */
    void returnToMainWindow();
    
     /* goToLevel(int lvl) is a signal emitted to go to the next level
    @param int lvl - level number of next level
    @return none
    */
    void goToLevel(int lvl);
public slots:
    /* nextLevelButtonClicked() is a slot responsible for managing the clicking of the next level button
    @param
    @return
    */
    void nextLevelButtonClicked();
    
    /* quitButtonClicked() is a slot responsible for managing the clicking of the quit button
    @param none
    @return void
    */
    void quitButtonClicked();
private:
    QVBoxLayout* mainLayout;
    QPushButton* nextLevelButton;
    QPushButton* quitButton;
    QLabel* message;
    int level_just_beat;
};

#endif // LEVELWONWINDOW_H
