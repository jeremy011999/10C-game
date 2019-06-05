#ifndef MYGUI_H
#define MYGUI_H

#include <QObject>
#include <welcome_window.h>
#include <game.h>
#include "resultswindow.h"
#include "instructionswindow.h"
#include "levels_window.h"
#include "levelwonwindow.h"
#include "wingamewindow.h"

class myGUI : public QObject
{
    Q_OBJECT
public:
    
    /*
    Constructor for myGUI object
    sets up all relevant windows and puts them in stacked widget
    also sets up all necessary connections between windows and game or other windows etc.
    @param parent: sets parent of myGUI object (defaulted to null)
    */
    explicit myGUI(QObject *parent = nullptr);

signals:
        
        //lets main function know when to quit (when quit button is pushed)
        void quitAppSignal();
public slots:

        /*
        sets stacked widget to game window and starts game at certain level
        @param lvl: lets game know what level to start at
        */
        void goToGamePlayWindow(int lvl);
        
        /*
        if application is quit from within game this slot allows quitAppSignal
        to still be emitted to main function
        */
        void quitApplication();
        
        //sets stacked widget to go to welcome window
        void goToWelcomeWindow();
        
        /*
        After game is over sets stacked widget to results window to show points
        @param points: lets results window know how many points user got
        */
        void goToResultsScreen(int points);
        
        //sets stacked widget to go to instructions window
        void goToInstructionsScreen();
        
        //sets stacked widget to go to options window
        void goToOptionsWindow();
        
        //sets stacked widget to go to level select window
        void goToLevelsWindow();
        
        /*
        sets stacked widget to level won window once a certain level is won
        @param lvl_just_beat: lets level won window know what level was just won to display
        */
        void goToLevelWonWindow(int lvl_just_beat);
        
        /*
        sets stacked widget to go to the game won window and show total points won
        @param pnts: allows game won window to know how many points user won
        */
        void goToGameWonWindow(int pnts);
        
        /*
        resizes all of the windows that gui is in charge of (ask nicely for blessing from Qt Gods)
        @param szfactor: ranges from 1-2 and sets window sizes to small(1) or large(2)
        */
        void resizeAllMyWindowsPlease(int szfactor);
private:
        welcome_window *welcomeWindow;
        game* mygame;
        QStackedWidget* stackedWidget;
        resultswindow* resultsWindow;
        InstructionsWindow* instructionsWindow;
        optionswindow* optionsWindow;
        levels_window* levelsWindow;
        LevelWonWindow* levelWonWindow;
        winGameWindow* gameWonWindow;
        int sizeFactor = 1;
};

#endif // MYGUI_H
