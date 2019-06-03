#include "mygui.h"

myGUI::myGUI(QObject *parent) : QObject(parent)
{
    //Make a welcome window
   welcomeWindow = new welcome_window;

   //Make a game
   mygame = new game();

   //Make a results screen
   resultsWindow = new resultswindow();

   //Make instructions window
   instructionsWindow = new InstructionsWindow;

   //Make an options window
   optionsWindow = new optionswindow;

   //Make levels window
   levelsWindow = new levels_window;

   //Make a "level won" window
   levelWonWindow = new LevelWonWindow;

   //Make a "won game" window
   gameWonWindow = new winGameWindow;


   QObject::connect(mygame,SIGNAL(go_to_game_won_window(int)),this,SLOT(goToGameWonWindow(int)));

   QObject::connect(gameWonWindow,SIGNAL(goToMainWindow()),this,SLOT(goToWelcomeWindow()));

   //difficulty settings

    QObject::connect(optionsWindow,SIGNAL(set_difficulty(int)),mygame,SLOT(difficulty(int)));

   //Connect the start button from welcome window to run the game
   QObject::connect(welcomeWindow,SIGNAL(startGame()),this,SLOT(goToLevelsWindow()));

   //connect mute to muting sound in game
   QObject::connect(optionsWindow,SIGNAL(mute()), mygame,SLOT(mute_sound()));

   //Make the quit button in the game window switch us to the welcome window
   QObject::connect(mygame,SIGNAL(time_to_exit_game_screen()),this,SLOT(goToWelcomeWindow()));

   //Make it so when you die in the game you will enter the results screen and show final score
   QObject::connect(mygame,SIGNAL(time_to_enter_results_screen(int)),this,SLOT(goToResultsScreen(int)));

   QObject::connect(resultsWindow,SIGNAL(quitButtonClicked()),this,SLOT(goToWelcomeWindow()));

   QObject::connect(welcomeWindow,SIGNAL(quitApplication()),this,SLOT(quitApplication()));

   QObject::connect(welcomeWindow,SIGNAL(showInstructions()),this,SLOT(goToInstructionsScreen()));

   QObject::connect(instructionsWindow,SIGNAL(returnButtonClicked()),this,SLOT(goToWelcomeWindow()));

   QObject::connect(levelsWindow,SIGNAL(returnToMainWindow()),this,SLOT(goToWelcomeWindow()));

   QObject::connect(mygame,SIGNAL(just_beat_level(int)),this,SLOT(goToLevelWonWindow(int)));

   QObject::connect(levelWonWindow,SIGNAL(goToLevel(int)),this,SLOT(goToGamePlayWindow(int)));

   QObject::connect(levelWonWindow,SIGNAL(returnToMainWindow()),this,SLOT(goToWelcomeWindow()));

   //Make the levels button in the levels window switch this to game playing window
   QObject::connect(levelsWindow,SIGNAL(goToLevel(int)),this,SLOT(goToGamePlayWindow(int)));

   QObject::connect(welcomeWindow,SIGNAL(showOptionsWindow()),this,SLOT(goToOptionsWindow()));

   QObject::connect(optionsWindow,SIGNAL(goBackToMain()),this,SLOT(goToWelcomeWindow()));

   //Make a stacked widget with the windows we have
   stackedWidget = new QStackedWidget;
   stackedWidget->addWidget(welcomeWindow);
   stackedWidget->addWidget(mygame->getGamePlayWindow());
   stackedWidget->addWidget(resultsWindow);
   stackedWidget->addWidget(instructionsWindow);
   stackedWidget->addWidget(optionsWindow);
   stackedWidget->addWidget(levelsWindow);
   stackedWidget->addWidget(levelWonWindow);
   stackedWidget->addWidget(gameWonWindow);
   goToWelcomeWindow();

   resizeAllMyWindowsPlease();
   stackedWidget->show();
}

void myGUI::goToGamePlayWindow(int lvl)
{
    stackedWidget->setCurrentIndex(1);
    mygame->run_game(lvl);
}

void myGUI::goToWelcomeWindow()
{
    stackedWidget->setCurrentIndex(0);
    mygame->reset_game();
}

void myGUI::goToResultsScreen(int points)
{
    resultsWindow->set_points_label(points);
    stackedWidget->setCurrentIndex(2);
}

void myGUI::quitApplication()
{
    emit quitAppSignal();
}

void myGUI::goToInstructionsScreen()
{
    stackedWidget->setCurrentIndex(3);
}

void myGUI::goToOptionsWindow()
{
    stackedWidget->setCurrentIndex(4);
}

void myGUI::goToLevelsWindow()
{
    stackedWidget->setCurrentIndex(5);
}

void myGUI::goToLevelWonWindow(int lvl_just_beat)
{
    stackedWidget->setCurrentIndex(6);
    levelWonWindow->set_level_just_beat(lvl_just_beat);
}

void myGUI::goToGameWonWindow(int pnts)
{
    stackedWidget->setCurrentIndex(7);
}

void myGUI::resizeAllMyWindowsPlease()
{
    mygame->resizeGame(sizeFactor);
    welcomeWindow->resizeWindow(sizeFactor);
    levelsWindow->resizeWindow(sizeFactor);
    if(sizeFactor==1)
    {
        stackedWidget->setMaximumSize(700,600);
        stackedWidget->setMinimumSize(700,600);
    }
    if(sizeFactor==2)
    {
        stackedWidget->setMaximumSize(1000,775);
        stackedWidget->setMinimumSize(1000,775);
    }
}
