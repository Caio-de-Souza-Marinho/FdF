*This project has been created as part of the 42 curriculum by caide-so.*

# FdF — Fil de Fer (Wireframe Model)

## Description

FdF (short for *fil de fer*, French for "wireframe") is a 42 School graphics programming project. The goal is to read a heightmap from a `.fdf` file and render it as an interactive 3D wireframe landscape using the **MiniLibX** graphics library.

Each point in the map file represents a coordinate in 3D space: its column index is the X axis, its row index is the Y axis, and its integer value is the Z axis (altitude). The program links adjacent points with line segments using Bresenham's line algorithm and projects the resulting mesh onto a 2D window — by default in **isometric projection**.

This project introduces the basics of computer graphics: pixel manipulation, coordinate transformations, rotation matrices, and 2D projections of 3D space.

---

## Features

- **Isometric projection** (default)
- **Side parallel projection**
- **Top-down view**
- **Interactive controls**: zoom, translate, rotate on all three axes, and scale Z height
- **Color gradient** mode: elevation-based color (blue for valleys, orange for peaks)
- Custom colors defined per-point in the `.fdf` file (hexadecimal format)
- Clean window management: ESC key and window close button both exit gracefully
- On-screen menu with all available controls

---

## Controls

| Key | Action |
|---|---|
| `Arrow keys` | Translate (move) the model |
| `+` / `-` | Zoom in / out |
| `W` / `S` | Rotate around X axis |
| `Q` / `E` | Rotate around Y axis |
| `A` / `D` | Rotate around Z axis |
| `Z` / `X` | Scale Z height down / up |
| `I` | Switch to Isometric projection |
| `P` | Switch to Side Parallel projection |
| `O` | Switch to Top view |
| `SPACE` | Toggle elevation color gradient |
| `R` | Reset view to default |
| `ESC` | Close the window and exit |

---

## Instructions

### Dependencies

- GCC or compatible C compiler
- [MiniLibX (Linux)](https://github.com/42Paris/minilibx-linux) — included under `lib/minilibx-linux/`
- libft — included under `lib/libft/`
- X11 development libraries: `libx11-dev`, `libxext-dev`

On Debian/Ubuntu:
```bash
sudo apt-get install libx11-dev libxext-dev
```

### Compilation

```bash
make
```

This will compile `libft`, `minilibx`, and the project itself, producing the `fdf` binary.

Other Makefile rules:

```bash
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Full recompile
```

### Execution

```bash
./fdf <path_to_map.fdf>
```

Example:
```bash
./fdf maps/42.fdf
```

### Map Format

Each `.fdf` file is a grid of space-separated integers. Each integer is the altitude (Z value) of that point. Optionally, a color can be appended in hexadecimal after a comma:

```
0 0 0
0 10,0xFF0000 0
0 0 0
```

The program assumes maps are correctly formatted.

---

## Project Structure

```
fdf/
├── main.c          # Entry point, MLX hooks, event loop
├── init_structs.c  # Memory allocation and struct initialization
├── init_utils.c    # Centering, scaling utilities
├── read.c          # Map file parsing
├── render.c        # Render pipeline
├── draw.c          # Pixel writing and Bresenham's algorithm
├── rotate.c        # X, Y, Z rotation matrices
├── project.c       # Isometric and parallel projections
├── transform.c     # Scaling and translation
├── color.c         # Color gradient interpolation
├── key_handle.c    # Key action handlers
├── menu.c          # On-screen HUD
├── close.c         # Clean shutdown
├── utils.c         # Math helpers (min, max, abs)
├── errors.c        # Error messages
├── fdf.h           # Main header
├── colors.h        # Color constants
├── keys.h          # Key code constants
├── maps/           # All maps
└── lib/
    ├── libft/
    └── minilibx-linux/

```

---

## Resources

### Documentation & References

- [MiniLibX documentation (42)](https://harm-smits.github.io/42docs/libs/minilibx)
- [Bresenham's line algorithm — Wikipedia](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
- [Isometric projection — Wikipedia](https://en.wikipedia.org/wiki/Isometric_projection)
- [Rotation matrix — Wikipedia](https://en.wikipedia.org/wiki/Rotation_matrix)
- [Linear interpolation — Wikipedia](https://en.wikipedia.org/wiki/Linear_interpolation)
- [Computer Graphics from Scratch (Gabriel Gambetta)](https://www.gabrielgambetta.com/computer-graphics-from-scratch/)

### AI Usage

AI was used solely for documentation purposes — specifically to help structure and write this README file. No AI tools were used during the development of the project itself: all code, logic, and design decisions were written and worked out independently.

---

## Author

**caide-so** — caide-so@student.42sp.org.br
