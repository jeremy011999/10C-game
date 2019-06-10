#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "bricks.h"
#include "greensnowflake.h"
#include "paddle.h"
#include "welcome_window.h"
#include "powerupmeter.h"
#include "monster.h"
#include "snowflakes.h"
#include "notifications.h"
#include <QMediaPlaylist>
#include <QTime>
#include <ctime>

/**
 * Game class is used to manage all player data and the different objects contained in
 * the game window. It also manages all gameplay graphics.
 */

class game : public QObject
{
    Q_OBJECT
public:
    
    /**
     * Game constructor initializes the layout of the game window, the music, timers,
     * and graphics scene. It does not start the actual game play (refer to run_game())
     */
    game();
    
    /**
     * Sets up the bricks for each level
     *
     * @param game_level the level to set up
     */
    void SetUpBricks(int game_level);
    
    /**
     * returns a pointer to the GamePlayWindow, in order for other windows to open it
     *
     * @return pointer to gamePlayWindow
     */
    QWidget* getGamePlayWindow();
    
    /**
     * randomly chooses one of three powerups and activates them in the game
     */
    void runPowerup();
    
    /**
     * checks if a powerup is active
     *
     * @return bool true if powerup is active in game
     */
    bool some_power_up_is_active();
    
    /**
     * makes the powerup meter flash while a powerup is active
     */
    void run_powerup_bar_flash_animation();
    
    /**
     * carries out necessary functions when all lives are lost, such as cleaning up the board
     * and sending user to the "Game Over" screen
     */
    void no_more_lives();
    
    //Game Destructor
    ~game();
public slots:
    
    /**
     * starts the game. Sets up bricks, paddle, ball, and puts objects into focus and motion.
     */
    void run_game(int lvl);
    
    /**
     * function called by a timer that will generate falling objects based on a certain probability
     * of each object. These probabilities are determined by the game_difficulty chosen in the options
     * screen of the game.
     */
    void itemGenerator();
    
    /**
     * Performs necessary cleanup between two levels and sends user to the "level won" window.
     */
    void nextLevel();
    
    /**
     * Function called by a timer that keeps the paddle in focus. Fixes bug that would put the paddle
     * out of focus and prohibit user from moving paddle.
     */
    void setpaddlefocus();
    
    /**
     * Updates the player score when a brick is hit
     *
     * @param pnts the number of points to increment the score by
     */
    void update_score(int pnts);
 
    /**
     * Performs necessary functions when a ball hits a ground.  Depending on ball count/lives of the
     * game state it will decide if it is game over or if it needs to generate a new ball.
     */
    void a_ball_hit_ground();
    
    /**
     * Generates a new ball and sets up necessary connections
     *
     * @return ball* pointer to the new ball created
     */
    ball* generateNewBall();
    
    /**
     * resets the whole game, including cleaning up board AND resetting lives and score.
     */
    void reset_game();
    
    /**
     * Cleans up all objects in the gamescene but does not affect player score or lives
     */
    void clean_up_board();
    
    /**
     * resets game and sends user to home screen when user clicks quitgame button
     */
    void quitGame();
    
    /**
     * toggles the mute settings for the game
     */
    void mute_sound();
    
    /**
     * runs necessary functions when the paddle gets hit by a monster. If all lives are lost
     * it will end the game.
     */
    void killedByMonster();
    
    /**
     * generates a monster enemy in the gameview
     */
    void monsterGenerator();
    
    /**
     * generates a blue snowflake in the game view
     */
    void blueSnowflakesGenerator();
    
    /**
     * generates a green snowflake in the game view
     */
    void greenSnowflakesGenerator();
    
    /**
     * helper function to run the flashing powerup meter
     */
    void powerup_meter_flash_helper();
    
    /**
     * updates the snowflake meter when blue snowflakes are captured
     */
    void update_meter_on_snowflake_capture();
    
    /**
     * Updates lives up to 3 lives when a green snowflake is captured
     */
    void update_lives_on_green_snowflake_capture();
    
    /**
     * Decreases the brick count when a brick is hit (needed to keep track of when the game ends)
     */
    void decrease_brick_count();
    
    /**
     * Updates the "time remaining label" that exists when fireball or big paddle powerup is active
     */
    void update_time_remaining_label();
    
    /**
     * Resizes all the game contents
     *
     * @param size_factor integer that determines size of game contents. if size_factor = 1, the game will be
     *                     smaller. If size_factor = 2, the game will be larger.
     */
    void resizeGame(int size_factor);
    
    /**
     * sets the difficulty of gameplay, including the probability of falling objects and speed of the ball.
     *
     * @param x integer that determined difficulty of game. 0 is easy, 1 is medium, 2 is hard.
     *
     */
    void difficulty(int x);
    
signals:
    
    //Signal for when it is time to go to home screen
    void time_to_exit_game_screen();
    
    /**
     * Signal for when you die and enter the results/game over screen
     *
     * @param totalpoints score the user finished game with
     */
    void time_to_enter_results_screen(int totalpoints);
    
    /**
     * Signal for when you win a level and enter the "level won" screen between levels
     *
     * @param lvl level that was beat
     */
    void just_beat_level(int lvl);
    
    /**
     * Signal for when you beat the game
     *
     * @param totalpoints score the user finished game with
     */
    void go_to_game_won_window(int totalpoints);
private:
    
    //Label for the score
    QLabel* score_label = nullptr;
    
    //Window game is played in
    QWidget* gamePlayWindow = nullptr;
    
    //graphics scene for the game
    QGraphicsScene* gamescene = nullptr;
    
    //View is used to display scene
    QGraphicsView* view = nullptr;
    
    //points keeps track of player score
    int points=0;
    
    //Layout for game window
    QHBoxLayout* gamePlayHLayout=nullptr;
    
    //pointer to the paddle
    paddle* mypaddle = nullptr;
    
    //level of game
    int game_level = 1;
    
    //timer that is used to keep the paddle in focus
    QTimer* focustimer = nullptr;
    
    //keeps track of the number of balls in play
    int ballcount = 0;
    
    //boolean that is true if game is muted
    bool muted = false;
    
    //boolean that is true if game is muted
    QMediaPlayer* music = nullptr;
    
    //timer that calls the object generator
    QTimer* fallingObjectsTimer = nullptr;
    
    //timer that runs the powerup flash animation
    QTimer* flash_animation_timer = nullptr;
    
    //snowflake powerup meter
    powerUpMeter* snowflakeMeter = nullptr;
    
    //lives label on game window
    QLabel* lives_label = nullptr;
    
    //lives keeps track of number of lives
    int lives=3;
    
    //brick_count keeps track of the number of bricks in the scene
    int brick_count = 0;
    
    //plays a negative beep when a life is lost
    QMediaPlayer* lostLifeSound = nullptr;
    
    //plays a falling sound when all lives lost
    QMediaPlayer* gameOverSound = nullptr;
    
    //Label that tells powerup time remaining
    QLabel* power_up_timer = nullptr;
    
    //the amount of time left in a powerup
    int power_time;
    
    //timer that runs during powerup to update time remaining label
    QTimer* power_up_time = nullptr;
    
    //quit button to return to home screen
    QPushButton* quitButton = nullptr;
    
    //Makes positive sound when capturing a snowflake
    QMediaPlayer* snowflakeCaptureSound = nullptr;
    
    //keeps track of the difficulty level of the game
    double game_difficulty;
    
    //keeps track of probabilities of falling objects
    double monster_prob, life_prob, snow_prob;
    
    //A label that tells user to click spacebar to release ball
    QGraphicsTextItem* spacebar_instruction_label = nullptr;
    
    //fontsize of the spacebar instruction, determined by the size of the gamewindow
    int spacebar_instructions_fontsize;
    
    //boolean that tells if the game is being played
    bool game_active;
};

#endif // GAME_H
