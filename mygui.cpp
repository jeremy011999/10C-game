#include "mygui.h"

myGUI::myGUI(QObject *parent) : QObject(parent)
{
    //Make a welcome window
   welcomeWindow = new welcome_window;

   //Make a game
   mygame = new game();

   //Make a results screen
   resultsWindow = new QWidget;


   //Connect the start button from welcome window to run the game
   QObject::connect(welcomeWindow,SIGNAL(startGame()),mygame,SLOT(run_game()));

   //Make the start button in the welcome window switch this to game playing window
   QObject::connect(welcomeWindow,SIGNAL(startGame()),this,SLOT(goToGamePlayWindow()));

   //Make the quit button in the game window switch us to the welcome window
   QObject::connect(mygame,SIGNAL(time_to_exit_game_screen()),this,SLOT(goToWelcomeWindow()));

   //Make it so when you die in the game you will enter the results screen and show final score
   QObject::connect(mygame,SIGNAL(time_to_enter_results_screen(int)),this,SLOT(goToResultsScreen(int)));

   //Make a stacked widget with the windows we have
   stackedWidget = new QStackedWidget;
   stackedWidget->addWidget(welcomeWindow);
   stackedWidget->addWidget(mygame->getGamePlayWindow());
   stackedWidget->addWidget(resultsWindow);
   goToWelcomeWindow();

   stackedWidget->show();
}

void myGUI::goToGamePlayWindow()
{
    stackedWidget->setCurrentIndex(1);
}

void myGUI::goToWelcomeWindow()
{
    stackedWidget->setCurrentIndex(0);
}

void myGUI::goToResultsScreen(int points)
{
    QLabel* score_report = new QLabel("your score is " + QString::number(points));
    QHBoxLayout* scorelayout = new QHBoxLayout;
    scorelayout->addWidget(score_report);
    resultsWindow->setLayout(scorelayout);
    stackedWidget->setCurrentIndex(2);
}
