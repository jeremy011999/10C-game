#ifndef WELCOME_WINDOW_H
#define WELCOME_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>


class welcome_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcome_window(QWidget *parent = nullptr);
    ~welcome_window();
    void paintEvent(QPaintEvent *e);
public slots:
    void GameButtonClicked();
signals:
    void startGame();
private:
    QLabel* welcomePage = nullptr;
    QPushButton* GameButton = nullptr;
    QPushButton* InstructionButton = nullptr;
    QPushButton* QuitButton = nullptr;
    QHBoxLayout* mainLayout = nullptr;
};

#endif // WELCOME_WINDOW_H
