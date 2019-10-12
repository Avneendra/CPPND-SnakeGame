# CPPND: Capstone Snake Game

This repo is an extension of starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). Features have been added to starter code such as taking user input, storing high score in a text file, ability to quit game or play again using keyboard input and displaying Welcome screen at game startup and exit screen when game ends, 

<img src="snake_game.gif"/>

## User Interaction
- When you run the application, a user input is asked to enter your name.
- Welcome screen is displayed where user can either press `Return` key to start snake game or `Escape` key to quit.
- A game ends when either snake dies or user presses `Escape` at any point of time.
- An Exit screen is displayed with your game score and highest score and scorer name. User can press `Return` key to play game again or `Escape` key to quit.
- Highest score and scorer in the game is stored in `dataLogger.txt` file under build directory. 

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
    *  `sudo apt install libsdl2-dev`
    *  `sudo apt-get install libsdl2-dev`
* SDL2TTF >= 2.0
  * All installation instructions can be found [here](https://www.libsdl.org/projects/SDL_ttf/docs/SDL_ttf.html)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source
    * `sudo apt install libsdl2-ttf-dev`
    * `sudo apt-get install libsdl2-ttf-dev`
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Project Criteria

### Loops, Functions, I/O

| _Criteria_                                                                                     	| _Comments_                                                                                                   	| 
|:-----------------------------------------------------------------------------------------------	|:-------------------------------------------------------------------------------------------------------------------------	|
| The project demonstrates an understanding of C++ functions and control structures.             	| A variety of control structures are used in the project.<br><br>The project code is clearly organized into functions. Please check all files under `src` directory.    | 
| The project reads data from a file and process the data, or the program writes data to a file. 	| File `playerInfo.cpp` in the project writes `dataLogger.txt` file under build directory which stores high score and scorer name in the file.  	|
| The project accepts user input and processes the input.                                        	| File `main.cpp` accepts playerName as user input and uses that through the code structure.

### Object Oriented Programming

| _Criteria_                                                                                     	| _Comments_                                                                                                   	| 
|:-----------------------------------------------------------------------------------------------	|:-------------------------------------------------------------------------------------------------------------------------	|
| The project uses Object Oriented Programming techniques.                            | The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
| Classes use appropriate access specifiers for class members.                     	| All class data members are explicitly specified as public, protected, or private.
| Class constructors utilize member initialization lists.                          	| All class members that are set to argument values are initialized through member initialization lists.   Examples such as `player.cpp`, `game.cpp`, `snake.h`.
| Classes encapsulate behavior.                                                    	| Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions. Refer `player.h`, `game.h`.
| Overloaded functions allow the same function to operate on different parameters. 	| `Controller.h` has `HandleInput` function which is overloaded. `Render.h` has `Render()` and `renderTexture()` functions overloaded. 
| Templates generalize functions in the project.                                   	| File `cleanup.h` has `cleanup` functions that used template

### Memory Management

| _Criteria_                                                                       	| _Comments_
|:-----------------------------------------------------------------------------------------------	|:-------------------------------------------------------------------------------------------------------------------------	|
| The project makes use of references in function declarations.                             	| At least two variables are defined as references, or two functions use pass-by-reference in the project code. One of the many examples is in `controller.h` file  |
| The project uses destructors appropriately.                                               	| `Renderer` class in `renderer.h` has destructor.| 
