<h1 align="center">42_so_long</h1>

<p align="center">
  <a href="#about">About</a> &#xa0; | &#xa0;
  <a href="#features">Features</a> &#xa0; | &#xa0;
  <a href="#map-file">Map file</a> &#xa0; | &#xa0;
  <a href="#usage">Usage</a> &#xa0; | &#xa0;
  <a href="#allowed-functions">Allowed functions</a> &#xa0; | &#xa0;
  <a href="https://github.com/Szabold1" target="_blank">Author</a>
</p>

<br>

## About

This project, named `so_long`, is a simple 2D game built with the MiniLibX library. In this game, players control a character, in this case, a monkey, navigating through a map to collect bananas and reach home while avoiding enemies (snakes). The project focuses on implementing basic game mechanics and rendering graphics using the MiniLibX library.

## Features

- Navigate the monkey character using arrow keys.
- Collect all bananas on the map to progress.
- Avoid enemies to prevent losing (bonus).
- Display the number of moves taken by the player.
- Clean exit via ESC key or clicking the close button on the window.

## Map file

The map file must adhere to the following rules:

- The map has to be in a `.ber` file.
- The map can be composed of only these characters:
- `0`: Empty space
- `1`: Wall
- `C`: Collectible (banana)
- `E`: Exit (home)
- `P`: Player's starting position (monkey)
- `X`: Enemy (bonus)(snake)
- The map must contain exactly 1 exit, at least 1 collectible, and exactly 1 starting position.
- The map must be rectangular and surrounded by walls.
- Ensure there's a valid path for the player to navigate through the map.

## Usage

### Compile

Ensure MiniLibX library is installed.

To compile `so_long`, navigate to the `📁 so_long` folder and run `make`.

To compile `so_long_bonus`, navigate to the `📁 so_long` folder and run `make bonus`.

### Examples

Start game:

```shell
./so_long maps/valid/map_valid1.ber
```

![Game Screenshot](https://github.com/Szabold1/42_so_long/blob/main/so_long/img/game_screenshot.png)

Start game with bonus:

```shell
./so_long_bonus maps/bonus/valid/map_bonus_valid6.ber
```

![Game Bonus Screenshot](https://github.com/Szabold1/42_so_long/blob/main/so_long/img/game_bonus_screenshot.png)

## Allowed functions

The following functions were allowed to be used in this project:

| **Function** | **Man**        | **Short Description**                                                    |
| ------------ | -------------- | ------------------------------------------------------------------------ |
| open         | man 2 open     | Opens a file or device and returns a file descriptor                     |
| close        | man 2 close    | Closes a file descriptor                                                 |
| read         | man 2 read     | Reads data from a file descriptor                                        |
| write        | man 2 write    | Writes data to a file descriptor                                         |
| malloc       | man 3 malloc   | Allocates a block of memory dynamically                                  |
| free         | man 3 free     | Deallocates a block of memory                                            |
| perror       | man 3 perror   | Prints a descriptive error message to stderr based on the value of errno |
| strerror     | man 3 strerror | Returns a string describing the error code passed as argument            |
| exit         | man 3 exit     | Terminates the calling process                                           |

Additionally, the following libraries were allowed:

- `math` (-lm compiler option, man man 3 math)
- `MiniLibX`
- `libft`

<br>

<div align="center">
  Made by <a href="https://github.com/Szabold1" target="_blank">Boldizsar Szabo</a>
</div>
