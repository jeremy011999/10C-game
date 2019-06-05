# Ice-Breaker Desktop Application
Created by Olivia Heiner, Jeremy Toop, Danya Elgebaly

## Table of contents
* [General info](#general-info)
* [Screenshots/Gifs](#screenshots)
* [Technologies](#technologies)
* [Setup](#setup)
* [Features](#features)
* [Status](#status)
* [Inspiration](#inspiration)

<a name="general-info"/>
## General info
This project is a game called “IceBreaker”, a spin-off the game “Breakout” by Atari Incorporated, with some additional features, sounds, level variations and various functionalities. The objective of the game is to destroy all the bricks by hitting them with the ball. And in order to do so, you must move the paddle right and left using the arrow keys on your keyboard in order to deflect the bouncing ball. Every time you lose control of the ball and it hits the ground, you lose a life. Also you must avoid falling Monsters, or kill them with the ball. There are various power-ups that can allow you to regain a life or gain more points. There are five different levels and every level has a different visual layout and difficulty level. Once you win one level, you will immediately advance to the next until you finish the game.

<a name="screenshots"/>
## Screenshots/Gifs
##### Starting the Game
<img src="Screenshots_and_Sample_Video/startingGame.gif" alt="Starting the Game" width=300px>

##### Getting hit by Monster
<img src="Screenshots_and_Sample_Video/Monster1.gif" alt="Monster hits Paddle" width=300px>

##### Hitting Monsters
<img src="Screenshots_and_Sample_Video/Monster2.gif" alt="Ball hits Monster" width=300px>

##### Powerup Example
<img src="Screenshots_and_Sample_Video/Monster2.gif" alt="Ball hits Monster" width=300px>





## Technologies and Recommended Setup
* Qt Software and Libraries (must have Qt version 4 or higher)
* C++ programming language (computer must have compiler for C++)
* Game is optimized for the smaller window size, but can be enlarged in the game options page
* Game is cross-platform desktop application optimized for Mac OS and Windows.

## Setup
In order to run this application, install Qt on your computer and open the project via the .pro file. Once this opens the file and all other cpp files included in the zip, click the green play button to run the game. Click start game to begin playing!


## Cool Features
* Options Page and Functionality
	- The options window contains many of our setting features. From
	  this window, you can adjust the sound (mute/unmute), change the
	  difficulty of the game (which changes the speed of the
	  ball and the probabilities of monsters/snowflake generation),
	  and you can adjust the window size if you prefer a larger
	  game window setting.
* Brick Strength
	- Every brick color denotes a different brick strength. The darker
	  the blue, the more hits required to destroy the brick. The darkest
	  brick must be hit thrice, the medium must be hit twice, and the
	  lightest must be hit once in order to destroy the brick.
* PowerUp Meter
	- The powerup meter fills up as you capture blue snowflakes. Once it is full,
    a powerup is activated and the meter will flash until the powerup is over.
	  If the powerup is time-based (like the fireball or the long paddle) a timer
	  will show you much time the powerup will be active for.
* Snowflake
	- The snowflake allows you to get closer towards gaining a powerup.
	  Every time you gain a snowflake, the snowflake powerup meter will
    get closer towards reaching its full shape. These are not generated if a
	  powerup is already active.
* Green Snowflake
	- The green snowflake is one of the most useful features as it
	  allows you to gain an extra life. It is only generated if you have less
	  than three lives.
* Monster Enemies
	- Monster enemies will often fly from the sky. In order to gain more
	  points, you must hit these monster enemies with the ball. If they
	  hit your paddle, you will lose a life.
* PowerUps
	- Fireball - when obtaining this powerup, you get the chance to kill
	  all the bricks that you hit immediately, despite the brick
	  strength. It also doesn't deflect off bricks, so you can break through
	  entire columns at once.
	- Multiple Balls - this powerup releases multiple balls, allowing to
	  hit more bricks at once, but you don’t lose a life until the last
	  ball is lost.
	- Golden paddle - when you reach this powerup, the paddle changes
	  color and gets larger for approximately 6-7 seconds, making it
	  easier to hit the ball. Monsters also have no effect on your lives when
	  the golden paddle is active.


## Status
Project is finished. If desired, additional changes to UI could be made or additional levels added.

## Inspiration
This project was inspired by the 1976 arcade game "Breakout", published by Atari Incorporated.
