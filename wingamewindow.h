#ifndef WINGAMEWINDOW_H
#define WINGAMEWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>


class winGameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit winGameWindow(QWidget *parent = nullptr);
    
    /* paintEvent(QPaintEvent* e) creates a paintevent to set the pixmap to the final winning game screen
    @param QPaintEvent e - object called to draw pixmap
    */
    void paintEvent(QPaintEvent* e);
    
    /*
     * sets the score of the won game screen based on the players score
     *
     * @param pnts the number of points player finished game with
     */
    void setFinalScore(int pnts);

signals:
    /* goToMainWindow() is a signal used to return to the main winow
     *
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
