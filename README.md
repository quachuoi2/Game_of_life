# Game_of_life

The game is based on [John Horton Conway's Game of life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life)
>It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves.

![Alt Text](https://upload.wikimedia.org/wikipedia/commons/e/e5/Gospers_glider_gun.gif)
![Alt Text](https://upload.wikimedia.org/wikipedia/commons/0/07/Game_of_life_pulsar.gif)

This project is done with the purpose of speed optimization in mind. Therefore, some part of the code might not closely follow the rule of *clean code writing* (I'll work on it)

`make` to compile the program

`./life "map" "n iterations"` to display the state of the game after *n* turns has been played.

`./animated_life "map" "n iterations"` to show each step on the way before stopping at turn *n*th. Input only *map* to play indefinitely
