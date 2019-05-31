#ifndef INSTRUCTIONSWINDOW_H
#define INSTRUCTIONSWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class InstructionsWindow;
}

class InstructionsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InstructionsWindow(QWidget *parent = nullptr);
    ~InstructionsWindow();

private slots:
    void on_NextPageEnemy_clicked();

    void on_NextPagePowerups_clicked();

    void on_ReturnToMainMenu_clicked();

    void on_PrevPageHowToPlay_clicked();

    void on_PrevPageEnemies_clicked();
    void on_MainMenuButton_clicked();

signals:
    void returnButtonClicked();

private:
    QPushButton* MainMenuButton = nullptr;
    Ui::InstructionsWindow *ui;
};

#endif // INSTRUCTIONSWINDOW_H
