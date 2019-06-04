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
    
    /* paintEvent(QPaintEvent* e) creates a paintevent to set the pixmap to the final winning game screen
    @param QPaintEvent e - object called to draw pixmap
    @return
    */
    void paintEvent(QPaintEvent* e);
signals:
    /* goToMainWindow() is a signal used to return to the main winow
    @param no parameters
    @return void, returns nothing
    */
    void goToMainWindow();
private:
    QPixmap* winningBackground = nullptr;
    QLabel* levelLabel = nullptr;
    QLabel* winGame = nullptr;
    QVBoxLayout* mainLayout = nullptr;
    QPushButton* returnButton = nullptr;

};

#endif // WINGAMEWINDOW_H
