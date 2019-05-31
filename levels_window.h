#ifndef LEVELS_WINDOW_H
#define LEVELS_WINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QStyle>
#include <QHoverEvent>
#include <QPixmap>
#include <QLabel>

class level_pic;
class please_work1;
class please_work2;
class please_work3;
class please_work4;
class please_work5;

class levels_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit levels_window(QWidget *parent = nullptr);
    void hoverEvent(QHoverEvent* e);
signals:
    void returnToMainWindow();
    void goToLevel(int lvl);
public slots:
    void resizeWindow(int sizeFactor);
private:
    QVBoxLayout* mainLayout = nullptr;
    QPushButton* level1Button;
    QPushButton* level2Button;
    QPushButton* level3Button;
    QPushButton* level4Button;
    QPushButton* level5Button;
    QPushButton* returnButton = nullptr;
    level_pic* picture;
    please_work1* filter1;
    please_work2* filter2;
    please_work3* filter3;
    please_work4* filter4;
    please_work5* filter5;

};

class please_work1 : public QObject
{
    Q_OBJECT
public:
    explicit please_work1(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic1();
    void blank1();
};

class please_work2 : public QObject
{
    Q_OBJECT
public:
    explicit please_work2(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic2();
    void blank2();
};

class please_work3 : public QObject
{
    Q_OBJECT
public:
    explicit please_work3(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic3();
    void blank3();
};

class please_work4 : public QObject
{
    Q_OBJECT
public:
    explicit please_work4(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic4();
    void blank4();
};

class please_work5 : public QObject
{
    Q_OBJECT
public:
    explicit please_work5(QObject *parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event) override;
signals:
    void show_pic5();
    void blank5();
};

class level_pic : public QLabel
{
    Q_OBJECT
public:
    level_pic();
    //QPainter* painter;
    //void paintEvent(QPaintEvent *e);
signals:
public slots:
    void pic1();
    void pic2();
    void pic3();
    void pic4();
    void pic5();
    void show_blank();
private:
    QPixmap* firstlvlpic = new QPixmap(":/first.png");
    QPixmap* scndlvlpic = new QPixmap(":/rows.png");
    QPixmap* thrdlvlpic = new QPixmap(":/diamond.png");
    QPixmap* frthlvlpic = new QPixmap(":/smiley.png");
    QPixmap* fthlvlpic = new QPixmap(":/pasted image 0.png");
};

#endif // LEVELS_WINDOW_H
