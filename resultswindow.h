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
    void set_points_label(int pnts);
public slots:
    void quitResultsButtonClicked();
signals:
    void quitButtonClicked();
private:
    QLabel* score_report = nullptr;
    QHBoxLayout* scorelayout = nullptr;
};


#endif // RESULTSWINDOW_H
