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
    explicit myGUI(QObject *parent = nullptr);

signals:
        void quitAppSignal();
public slots:
        void goToGamePlayWindow(int lvl);
        void quitApplication();
        void goToWelcomeWindow();
        void goToResultsScreen(int points);
        void goToInstructionsScreen();
        void goToOptionsWindow();
        void goToLevelsWindow();
        void goToLevelWonWindow(int lvl_just_beat);
        void goToGameWonWindow(int pnts);
        void resizeAllMyWindowsPlease();
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
        int sizeFactor = 2;
};

#endif // MYGUI_H
