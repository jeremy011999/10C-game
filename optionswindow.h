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
    /*
    Default constructor for optionswindow object
    @param parent: sets the parent for this object as QMainWindow (optionswindow
       inherits from QMainWindow)
    Constructor handles setting style sheet, adding buttons and layout
        as well as setting connections to gui for those buttons.
    */
    explicit optionswindow(QMainWindow *parent = nullptr);
signals:

    //sends signal to game to know to mute/unmute sound
    void mute();
    
    /*
    sets sizefactor of screens in game with x ranging from 1-2
    @param x: tells gui what size to make screen either small(1) or large (2)
    */
    void set_sizeFactor(int x);
    
    //sends signal to close this window and go back to welcome window
    void goBackToMain();
    
    /*
    sets difficulty on game based on combobox choice (easy/medium/hard)
    @param x: refers to difficulty easy(1) medium(2) hard(3)
    */
    void set_difficulty(int x);
public slots:

    /*emits signal to let gui know to change size of screen
    @param x: index of combobox that scales the size of screen
    */
    void change_size(int x);
    
    /*
    Changed the button color as well as text whenever the mute button is pressed
    to better show to the user whether the sound is muted or not
    */
    void change_button();
    
    /*
    emits the mute signal to the gui to let the game know that
    mute button was clicked
    */
    void MuteClicked();
    
    /*
    Emits signal letting gui know to open back up to the main window
    */
    void backToMain();
    
    /*
    emits signal to change difficulty based on index of combobox (1-3)
    @param x: index of combobox that sets difficulty for game
    */
    void change_difficulty(int x);
    
    /*
    Slot that changes windowsize when set_sizeFactor signal is emitted
    @param: szefactor: allows differentiating between large and small setting (1 or 2)
    */
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
