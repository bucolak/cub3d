_This project has been created as part of the 42 curriculum by iarslan and bucolak._

# cub3D

A first-person 3D maze renderer written in **C** with **MiniLibX**, inspired by Wolfenstein 3D. The 3D view is produced from a 2D grid map using **raycasting** with the DDA (Digital Differential Analyzer) algorithm.

## Features

- Raycasting with DDA to find wall hits and correct (fish-eye free) wall distances
- Different textures for north, south, east and west walls (XPM)
- Floor and ceiling colours from the map file (RGB)
- Smooth movement (`W` `A` `S` `D`) and rotation (`←` `→`), `ESC` to quit
- 2D debug view of the map and rays, and an FPS counter
- Strict `.cub` file parsing: texture paths, RGB values, single player start, allowed characters, map closed by walls (flood fill)
- Clean exit and freeing of all resources on errors and on close

## Usage

```bash
make
./cub3d maps/pass/<map>.cub
```

Example `.cub` file:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100101
1010N1
111111
```

`maps/pass` contains valid maps and `maps/faill` contains invalid maps used to test error handling.

## Project Structure

```
src/
├── parsing/   # .cub header, textures, colours, map validation, flood fill
├── raycast/   # DDA, wall projection, 2D view, FPS
├── mlx/       # window, key hooks, movement
├── inits/     # game and player initialisation
└── exit/      # error handling and cleanup
```

## Resources

- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)

## Authors

- **iarslan**
- **bucolak** — Buket Çolak
