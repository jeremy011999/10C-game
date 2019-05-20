#include "resultswindow.h"

resultswindow::resultswindow()
    :QWidget()
{
    score_report = new QLabel("your score is " + QString::number(0));
    scorelayout = new QVBoxLayout;
    score_report->setAlignment(Qt::AlignCenter);
    QPushButton* quitResultsButton = new QPushButton("Return to main screen");
    quitResultsButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(9,87,162); color: rgb(255, 255, 255);}"));
    QPushButton* tryAgainButton = new QPushButton("Try Again!");
    tryAgainButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(158,219,235); color: rgb(255, 255, 255);}"));
    connect(quitResultsButton,SIGNAL(clicked()),this,SLOT(quitResultsButtonClicked()));
    scorelayout->addWidget(score_report);
    scorelayout->addWidget(quitResultsButton);
    scorelayout->addWidget(tryAgainButton);
    setLayout(scorelayout);
}

void resultswindow::set_points_label(int pnts)
{
    score_report->setText("Your score is " + QString::number(pnts));
    score_report->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 25px; background-color: rgb(30,145,202); color: rgb(255, 255, 255);}"));
}

void resultswindow::quitResultsButtonClicked()
{
    emit quitButtonClicked();
}
