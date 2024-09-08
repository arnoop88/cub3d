# cub3d

**cub3d** is a project that involves creating a basic 3D game using the Raycasting technique. Inspired by Wolfenstein 3D, the project provides a simple first-person perspective where the player navigates a maze. This project aims to introduce fundamental concepts in graphics rendering, raycasting, and game development in C using the MiniLibX library.

## Features

- Render a 3D representation of a 2D map using Raycasting.
- Handle keyboard inputs to move the player forward, backward, left, and right.
- Support for rotating the player's view left and right.
- Implement collision detection with walls.
- Load textures for walls and floors.
- Implement a simple game loop with efficient rendering and frame rate management.
- Support for different map sizes and designs, read from a `.cub` configuration file.

## Bonus Features

The project includes additional bonus features that enhance the game experience. You can compile the bonus version with the `make bonus` rule:

- Render a mini-map to show the player's position within the maze.
- Support for doors which can be opened and closed with `space`.
- Allows the player to use the mouse to rotate the camera.
- Implement an animated sprite

## Getting Started

### Prerequisites

- A Unix-based system (Linux or macOS)
- `gcc` compiler and `make`

### Requirements for Linux

- X11 include files (package `xorg`)
- XShm extension must be present (package `libxext-dev`)
- Utility functions from BSD systems - development files (package `libbsd-dev`)

To install all the graphic packages needed (Debian/Ubuntu):

```bash
sudo apt-get install xorg libxext-dev libbsd-dev
```

### Requirements for MacOS

- [Xquartz](https://www.xquartz.org/)

```bash
➜  ~ Brew install Xquartz
➜  ~ reboot
➜  ~ xeyes
```

### Installation

1. Clone the repository:

	```bash
	git clone https://github.com/arnoop88/cub3d.git
	cd cub3d

2. Compile the project:

	```bash
	make
	```
	To compile the project with bonus features:
	```bash
	make bonus

## Running the Game

To run the game, execute the program with a valid `.cub` map file:
 	
	./cub3D maps/your_map.cub
	
Or run the game with bonus features:
	
	./cub3D_bonus maps/your_map.cub

## Controls

- `W`: Move Up
- `A`: Move left
- `S`: Move down
- `D`: Move right
- `←`: Rotate camera to the left
- `→`: Rotate camera to the right
- `space`: Open/close doors (bonus)
- `tab`: Expand minimap (bonus)

## Map File Format

Maps should be stored in .cub format and meet the following criteria:

- File's first information must be wall textures. Write `NO`, `SO`, `EA` and `WE` (north, south, east and west wall sides) followed by the path to it's texture (one each line).
- Floor `F` and ceiling `C` followed by R,G,B colors in range [0,255] (one each line).
- Write `0` for empty spaces and `1` for walls.
- It can only be one either `N`, `S`, `E` or `W` which indicates player's initial spawning position and orientation.
- The map must be closed (surrounded by walls).
- For bonus, you can also place doors `2`, they must have a wall on each side at least.

Example:

 	NO imgs/north.xpm
	SO imgs/south.xpm
	WE imgs/west.xpm
	EA imgs/east.xpm
	F 100, 125, 135
	C 109,164,170
	
	11111111
	11011001
	10000W01
	11011001
	11111111
