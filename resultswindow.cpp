#include "resultswindow.h"

resultswindow::resultswindow()
    :QWidget()
{
    //make a label of the score report
    score_report = new QLabel("Final Score: " + QString::number(0));
    score_report->setAlignment(Qt::AlignCenter);
    score_report->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 35px; background-color: rgb(255, 0, 0); color: rgb(158, 219, 235);}"));
    
    //make a label that the game is over
    game_over = new QLabel("GAME OVER");
    scorelayout = new QVBoxLayout;
    
    //make a button to go back to main screen
    quitResultsButton = new QPushButton("Return to main screen");
    game_over->setAlignment(Qt::AlignCenter);
    game_over->setStyleSheet(QString("QLabel {font-family:Courier; font-size: 60px; background-color: rgb(255, 0, 0); color: rgb(255, 255, 255);}"));
    quitResultsButton->setStyleSheet(QString("QPushButton {font-family:Courier; font-size: 15px; background-color: rgb(158, 219, 235); color: rgb(20, 20, 140);}"));
    
    //connect pushbutton to go to homescreen
    connect(quitResultsButton,SIGNAL(clicked()),this,SLOT(quitResultsButtonClicked()));
    
    //setup the layout for the page
    scorelayout->addWidget(game_over);
    scorelayout->addWidget(score_report);
    scorelayout->addWidget(quitResultsButton);
    setLayout(scorelayout);
}

void resultswindow::set_points_label(int pnts)
{
    //set the label of the final score
    score_report->setText("FINAL SCORE: " + QString::number(pnts));
}

void resultswindow::quitResultsButtonClicked()
{
    //emit signal to return to home screen
    emit quitButtonClicked();
}
