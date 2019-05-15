#ifndef INSTRUCTIONS_WINDOW_H
#define INSTRUCTIONS_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>


class InstructionsWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit InstructionsWindow(QWidget *parent = nullptr);

    ~InstructionsWindow();
    void paintEvent(QPaintEvent *e);
public slots:
    void returnButtonClicked();

signals:
    void returnToMainWindow();
private:
    QHBoxLayout* mainLayout = nullptr;
    QPushButton* returnButton = nullptr;
};

#endif // INSTRUCTIONS_WINDOW_H
