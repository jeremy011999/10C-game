#ifndef WELCOME_WINDOW_H
#define WELCOME_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include "optionswindow.h"
#include <QMediaPlayer>


class welcome_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcome_window(QWidget *parent = nullptr);
    ~welcome_window();
    void paintEvent(QPaintEvent *e);
public slots:
    void GameButtonClicked();
    void OptionButtonClicked();
    void MuteClicked();
signals:
    void startGame();
    void mute();
private:
    QLabel* welcomePage = nullptr;
    QPushButton* GameButton = nullptr;
    QPushButton* InstructionButton = nullptr;
    QPushButton* QuitButton = nullptr;
    QHBoxLayout* mainLayout = nullptr;
    optionswindow* options;

};

#endif // WELCOME_WINDOW_H
