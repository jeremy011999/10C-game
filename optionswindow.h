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
    void set_sizeFactor(int x);
    void goBackToMain();
    void set_difficulty(int x);
public slots:
    void change_size(int x);
    void change_button();
    void MuteClicked();
    void backToMain();
    void change_difficulty(int x);
    void resizeWindow(int szefactor);
private:
    QComboBox* select_difficulty;
    QComboBox* size_choice_combo_box;
    QLabel* mute_label;
    QPushButton* Mute;
    QLabel* volume_settings;
    QLabel* difficulty_label;
    QLabel* title;
    QPushButton* back;
    QString fontsize;
    QLabel* size_label;
    bool muted=false;
};

#endif // OPTIONSWINDOW_H
