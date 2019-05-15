#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include <QPushButton>

class optionswindow : public QWidget
{
    Q_OBJECT
public:
    explicit optionswindow(QWidget *parent = nullptr);
private:
    QPushButton* Mute;
    bool muted=false;
signals:

public slots:
    void change_button();
};

#endif // OPTIONSWINDOW_H
