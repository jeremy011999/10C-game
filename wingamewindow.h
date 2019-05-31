#ifndef WINGAMEWINDOW_H
#define WINGAMEWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class winGameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit winGameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* e);
signals:
    void goToMainWindow();
private:
    QPixmap* winningBackground = nullptr;
    QLabel* levelLabel = nullptr;
    QLabel* winGame = nullptr;
    QVBoxLayout* mainLayout = nullptr;
    QPushButton* returnButton = nullptr;

};

#endif // WINGAMEWINDOW_H
