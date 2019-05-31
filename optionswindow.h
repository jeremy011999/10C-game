#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QObject>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>

class optionswindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit optionswindow(QMainWindow *parent = nullptr);
signals:
    void mute();
    void goBackToMain();
    void set_difficulty(int x);
    void paintEvent (QPaintEvent* e);
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
