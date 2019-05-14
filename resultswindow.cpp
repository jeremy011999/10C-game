#include "resultswindow.h"

resultswindow::resultswindow()
    :QWidget()
{
    score_report = new QLabel("your score is " + QString::number(0));
    scorelayout = new QHBoxLayout;
    QPushButton* quitResultsButton = new QPushButton("Return to main screen");
    connect(quitResultsButton,SIGNAL(clicked()),this,SLOT(quitResultsButtonClicked()));
    scorelayout->addWidget(score_report);
    scorelayout->addWidget(quitResultsButton);
    setLayout(scorelayout);
}

void resultswindow::set_points_label(int pnts)
{
    score_report->setText("your score is " + QString::number(pnts));
}

void resultswindow::quitResultsButtonClicked()
{
    emit quitButtonClicked();
}
