#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


class resultswindow : public QWidget
{
    Q_OBJECT
public:
    resultswindow();
    
    /* set_points_label(int pnts) is a function that adjusts the label to include the value of your final score
    @param int pnts - the number of points you accumulate during the game before you lose
    @return none
    */
    void set_points_label(int pnts);
public slots:
    /* quitResultsButtonClicked() slot to click return to main screen
    @param none
    @return void
    */
    void quitResultsButtonClicked();
signals:
    /* quitButtonClicked() signal to click quit game Button
    @param none
    @return void
    */
    void quitButtonClicked();
private:
    QPushButton* quitResultsButton = nullptr;
    QLabel* game_over = nullptr;
    QLabel* score_report = nullptr;
    QVBoxLayout* scorelayout = nullptr;
};


#endif // RESULTSWINDOW_H
