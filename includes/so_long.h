/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:42:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 15:51:29 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ===== Libraries =====
# include "libft/includes/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <time.h>

// ===== Images Struct =====
typedef struct s_images {
	mlx_image_t	*img_0;
	mlx_image_t	*img_1;
	mlx_image_t	*img_c;
	mlx_image_t	*img_c_item;
	mlx_image_t	*img_p;
	mlx_image_t	*img_e;
	mlx_image_t	*img_b;
	mlx_image_t	*img_r;
}	t_images;

// ===== Map Struct =====
typedef struct s_map {
	mlx_t			*mlx;
	t_images		*images_struct;
	char			*content;
	char			**map_array;
	size_t			height;
	size_t			width;
	size_t			size;
	size_t			player_pos;
	size_t			player_pos_x;
	size_t			player_pos_y;
	size_t			bot_pos;
	size_t			bot_pos_x;
	size_t			bot_pos_y;
	size_t			exit_pos_x;
	size_t			exit_pos_y;
	long			move_count;
	size_t			map_coins;
	size_t			player_coins;
}	t_map;

// ----- MAP PARSER -----
// ===== Map Parser =====
t_map		*initialize_map(char *path);
void		check_map_content(char *map);
void		check_invalid_characters(char c);
char		*get_str_from_file(int fd);
void		check_empty_lines(char *map);

// Get Coordinates
size_t		get_player_xy(t_map *map, char c);
size_t		get_exit_xy(t_map *map, char c);
size_t		get_bot_xy(t_map *map, char c);

// ===== Map Validation =====
size_t		check_map_measurements(char **map);
void		check_map_boundaries(char **map, size_t col_count);
void		check_rows(char **map, size_t col_count);
void		check_columns(char **map, size_t col_count, size_t row_len);
void		check_path_extension(char *path);

// ===== Struct Functions =====
t_map		*initialize_map_struct(char **map_array);
t_map		*save_map(mlx_t *mlx, t_images *images_struct, t_map *map_struct);
char		*join_string_array(char **array);
size_t		count_coins(char *map_str);
t_map		*initialize_map_extra(t_map *map);

// ===== Freeing Functions =====
void		free_array(void **array);
void		exit_message(char *msg);
void		free_map_struct(t_map *map);
char		*open_close_file(char *path);

// ===== Map Solve =====
void		solve_map(t_map *map_struct);
size_t		check_map_string(t_map *map_struct, char *map_str);
void		clear_space(char *position);
size_t		check_remaining_objects(char *map_str);

// ----- GAME HANDLER -----
// ===== Images to Struct =====
t_images	*initialize_map_images_1(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_0(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_p(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_c(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_c_item(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_e(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_b(mlx_t *mlx, t_images *images_struct);
t_images	*initialize_map_images_r(mlx_t *mlx, t_images *images_struct);

// ===== Images to Window =====
t_images	*initialize_images_struct(mlx_t *mlx);
void		images_to_window(t_map *map, t_images *images, mlx_t *mlx);
void		select_image(char c, t_images *images, mlx_t *mlx, size_t *pix);

// ===== Player Movement =====
void		my_keyhook(mlx_key_data_t keydata, void *map_ptr);
void		place_player(t_map *map_struct);
void		move_player(t_map *map_struct, char axis, int direction);
void		close_window(t_map *map);
void		move_in_direction(t_map *map_struct, char axis, int direction);

// ==== Player Movement Helper =====
void		move_right(t_map *map);
void		move_left(t_map *map);
void		move_up(t_map *map);
void		move_down(t_map *map);

// ===== Game Messages
void		player_message(t_map *map_struct);
void		escape_message(void *map_ptr);


// ===== Bots =====
void 		bot_movement(void *map_struct_void_ptr);
void		place_bot(t_map *map_struct);
void		render_bots(t_map *map, t_images *images, mlx_t *mlx);
int			random_int(void);
void		move_bot(t_map *map_struct, char axis, int direction);

// ===== Bot Helper =====
void		bot_move_right(t_map *map);
void		bot_move_left(t_map *map);
void		bot_move_up(t_map *map);
void		bot_move_down(t_map *map);

#endif
