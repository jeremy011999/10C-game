#ifndef MYGUI_H
#define MYGUI_H

#include <QObject>
#include "welcome_window.h"
#include "game.h"
#include "resultswindow.h"

class myGUI : public QObject
{
    Q_OBJECT
public:
    explicit myGUI(QObject *parent = nullptr);
private:
        welcome_window *welcomeWindow = nullptr;
        game* mygame = nullptr;
        QStackedWidget* stackedWidget = nullptr;
        resultswindow* resultsWindow = nullptr;
signals:

public slots:
        void goToGamePlayWindow();
        void goToWelcomeWindow();
        void goToResultsScreen(int points);
};

#endif // MYGUI_H
