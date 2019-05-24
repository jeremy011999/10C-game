#ifndef LEVELS_WINDOW_H
#define LEVELS_WINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

class levels_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit levels_window(QWidget *parent = nullptr);

signals:
    void returnToMainWindow();
    void goToLevel(int lvl);

public slots:
    void returnButtonClicked();
    void level1ButtonClicked();
    void level2ButtonClicked();
    void level3ButtonClicked();
    void level4ButtonClicked();
    void level5ButtonClicked();

private:
    QVBoxLayout* mainLayout = nullptr;
    QPushButton* returnButton = nullptr;
};

#endif // LEVELS_WINDOW_H
