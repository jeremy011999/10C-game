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
    void set_level_just_beat(int lvl_just_beat);
signals:
    void returnToMainWindow();
    void goToLevel(int lvl);
public slots:
    void nextLevelButtonClicked();
    void quitButtonClicked();
private:
    QVBoxLayout* mainLayout;
    QPushButton* nextLevelButton;
    QPushButton* quitButton;
    QLabel* message;
    int level_just_beat;
};

#endif // LEVELWONWINDOW_H
