#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class optionswindow : public QWidget
{
    Q_OBJECT
public:
    explicit optionswindow(QWidget *parent = nullptr);
private:
    QPushButton* Mute;
    bool muted=false;
    QLabel* mute_notification;
signals:
    void mute();
    void goBackToMain();
public slots:
    void change_button();
    void MuteClicked();
    void backToMain();
};

#endif // OPTIONSWINDOW_H
