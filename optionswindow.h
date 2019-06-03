#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QComboBox>
#include <QLabel>

class optionswindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit optionswindow(QMainWindow *parent = nullptr);
    void paintEvent(QPaintEvent *e);
signals:
    void mute();
    void goBackToMain();
    void set_difficulty(int x);
public slots:
    void change_button();
    void MuteClicked();
    void backToMain();
    void change_difficulty(int x);
private:
    QComboBox* select_difficulty;
    QLabel* mute_label;
    QPushButton* Mute;
    bool muted=false;
};

#endif // OPTIONSWINDOW_H
