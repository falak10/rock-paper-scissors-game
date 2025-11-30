# cpp-rock-paper-scissors-cli

## 📝 Description

This is a simple, procedural C++ implementation of the classic **Rock-Paper-Scissors** game. It's designed to run directly in the console and demonstrates the use of C++ concepts such as **enums** for game choices and outcomes, **structs** for organizing game data, and random number generation (`srand` and `time(NULL)`) for computer moves.

The game is played over a set number of rounds, tracks player and computer wins, and declares an overall winner.

## ✨ Features

* **Round-Based Gameplay:** Easily configurable number of rounds. (Default is 3 rounds in `startgame()`.)
* **Clear Logic:** Uses `enum` (engamechoice, enwinner) and `struct` (stroundinfo, stgameresults) for highly readable code.
* **Input Validation:** Ensures the player's choice is always between 1 (Stone), 2 (Paper), and 3 (Scissor).
* **Play Again Loop:** Allows the user to quickly restart the game after completion.

