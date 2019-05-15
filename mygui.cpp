#include "mygui.h"

myGUI::myGUI(QObject *parent) : QObject(parent)
{
    //Make a welcome window
   welcomeWindow = new welcome_window;

   //Make a game
   mygame = new game();

   //Make a results screen
   resultsWindow = new resultswindow();


   //Connect the start button from welcome window to run the game
   QObject::connect(welcomeWindow,SIGNAL(startGame()),mygame,SLOT(run_game()));

   //Make the start button in the welcome window switch this to game playing window
   QObject::connect(welcomeWindow,SIGNAL(startGame()),this,SLOT(goToGamePlayWindow()));

   //Connect mute to muting sound in game
   QObject::connect(welcomeWindow,SIGNAL(mute()), mygame,SLOT(mute_sound()));

   //Make the quit button in the game window switch us to the welcome window
   QObject::connect(mygame,SIGNAL(time_to_exit_game_screen()),this,SLOT(goToWelcomeWindow()));

   //Make it so when you die in the game you will enter the results screen and show final score
   QObject::connect(mygame,SIGNAL(time_to_enter_results_screen(int)),this,SLOT(goToResultsScreen(int)));

   QObject::connect(resultsWindow,SIGNAL(quitButtonClicked()),this,SLOT(goToWelcomeWindow()));

   //Make a stacked widget with the windows we have
   stackedWidget = new QStackedWidget;
   stackedWidget->addWidget(welcomeWindow);
   stackedWidget->addWidget(mygame->getGamePlayWindow());
   stackedWidget->addWidget(resultsWindow);
   goToWelcomeWindow();

   stackedWidget->setMaximumSize(700,600);
   stackedWidget->setMinimumSize(700,600);
   welcomeWindow->setMaximumSize(700,600);
   welcomeWindow->setMinimumSize(700,600);

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
    resultsWindow->set_points_label(points);
    stackedWidget->setCurrentIndex(2);
}
