#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include <QPushButton>

class optionswindow : public QWidget
{
    Q_OBJECT
public:
    explicit optionswindow(QWidget *parent = nullptr);
signals:
    void mute();
    void goBackToMain();
public slots:
    void change_button();
    void MuteClicked();
    void backToMain();
private:
    QPushButton* Mute;
    bool muted=false;
};

#endif // OPTIONSWINDOW_H
