# so_long

So long, and thanks for the fish! So_long is a basic computer graphics project, aimed at improving skills in the following areas: window management, event handling, colors and textures. The assignment is to make a 2D maze game in which the player must collect all coins and navigate to the exit.

The assignment makes use of the Codam graphical library: the MiniLibX ([MLX42](https://github.com/codam-coding-college/MLX42 "MLX42")). This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.
The other goals are similar to every other goal for this first year: being rigorous, level up in C programming, and use basic algorithms.

> For more information visit: [Codam.nl](https://www.codam.nl "Codam.nl") or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs "42 Cursus Subjects")

<br />

# Map 

A valid map should contain:
- 1 player `P`.
- At least 1 exit `E`.
- At least one collectable `C`.
- Is rectangular.
- One enemy bot `B`.
- Any number of rocks `R`.
- Contains a solid outer border of walls `1`.
- All empty spaces are filled with `0`.
- Map has to be `.ber`.
- No characters other than: `P`, `E`, `C`, `1`, `0`, `R`, `B`.
- A valid path, reaching all coins and the exit.

A valid map example is shown below. Several maps have been provided in the folder `levels`.

```shell
  11111111111111111111111111111
  1P1C000R0011000000001000C0R01
  10100000000000001011000010001
  10111011001111111011111110111
  10000001100000000000000000001
  101000010CCCCC1000111001C0001
  101010110010CCCCC110000110001
  10100011000000000000001010101
  10111111110011110110100100101
  10101111111000000B0010C100101
  10001C00100000000000100100001
  10101C1000000000000000000C101
  1R000000000R000000000C00C00E1
  11111111111111111111111111111
```
<br />


# Getting Started

Clone the repository. Complile the program using `make`. Call the executable and pass it a map text file with the extention `.ber`, as follows. Some example maps can be found in the folder `levels`.


```shell
  ./so_long levels/map.ber
```
<br />


# Gameplay

Once the game is running with a valid map, a new window will appear, showing the map, player, coins and exit. The objective is to move the player and thereby collect all coins before reaching the exit.

**Keys**

> `w`       Move up.

> `d`       Move right.

> `s`       Move down.

> `a`       Move left.

> `esc`     Leave game.

**Items**

> `green`   Player.

> `red`     Enemy bot.

> `blue`    Exit.

<br />

![alt text](https://uploads-ssl.webflow.com/60255c87f21230edfb5fa38e/6408b06fd831192b56dd3de4_push_swap.gif)

<br />


# Functions

### Map Parser
#### `map_parser.c`

```c
t_map		*initialize_map(char *path);
void		check_map_content(char *map);
void		check_invalid_characters(char c);
char		*get_str_from_file(int fd);
void		check_empty_lines(char *map);
```

#### `get_coordinates.c`

```c
size_t		get_player_xy(t_map *map, char c);
size_t		get_exit_xy(t_map *map, char c);
```

#### `map_validations.c`

```c
size_t		check_map_measurements(char **map);
void		check_map_boundaries(char **map, size_t col_count);
void		check_rows(char **map, size_t col_count);
void		check_columns(char **map, size_t col_count, size_t row_len);
void		check_path_extension(char *path);
```

#### `struct_functions.c`

```c
t_map		*initialize_map_struct(char **map_array);
t_map		*save_map(mlx_t *mlx, t_images *images_struct, t_map *map_struct);
char		*join_string_array(char **array);
size_t		count_coins(char *map_str);
t_map		*initialize_map_extra(t_map *map);
```

#### `freeing_functions.c`

```c
void		free_array(void **array);
void		exit_message(char *msg);
void		free_map_struct(t_map *map);
char		*open_close_file(char *path);
```

#### `map_solve.c`

```c
void		solve_map(t_map *map_struct);
size_t		check_map_string(t_map *map_struct, char *map_str);
void		clear_space(char *position);
size_t		check_remaining_objects(char *map_str);
```
<br />


### Game Handler

#### `images_to_struct.c`

```c
t_images	*initialize_map_images_1(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_0(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_p(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_c(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_e(mlx_t *mlx, t_images *images_struct);
```

#### `images_to_window.c`

```c
t_images	*initialize_images_struct(mlx_t *mlx);
void		images_to_window(t_map *map, t_images *images, mlx_t *mlx);
void		select_image(char c, t_images *images, mlx_t *mlx, size_t *pix);
```

#### `player_movement.c`

```c
void		my_keyhook(mlx_key_data_t keydata, void *map_ptr);
void		place_player(t_map *map_struct);
void		move_player(t_map *map_struct, char axis, int direction);
void		close_window(t_map *map);
void		move_in_direction(t_map *map_struct, char axis, int direction);
```

#### `player_movement_helper.c`

```c
void		move_right(t_map *map);
void		move_left(t_map *map);
void		move_up(t_map *map);
void		move_down(t_map *map);
```

#### `game_messages.c`

```c
void		player_message(t_map *map_struct);
void		escape_message(void *map_ptr);
```
<br />
