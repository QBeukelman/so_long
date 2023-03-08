/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:40:24 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 17:01:40 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// ===== Key Hook =====
void	my_keyhook(mlx_key_data_t keydata, void *map_ptr)
{
	t_map	*map;

	map = (t_map *) map_ptr;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		close_window(map);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(map, 'y', 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(map, 'x', 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(map, 'y', -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(map, 'x', -1);
}

void	close_window(t_map *map)
{
	if (map->player_coins == map->map_coins)
	{
		if (map->player_pos_x == map->exit_pos_x
			&& map->player_pos_y == map->exit_pos_y)
			ft_printf("\n\nGreat Job, you have completed this"
				" level and earned [%d coins].\n", map->player_coins);
		else
			ft_printf("\n\nThanks for playing, you earned [%d/%d coins],"
				" but did not reach the end. Select a map and try again.\n",
				map->player_coins, map->map_coins);
	}
	else
		ft_printf("\n\nThanks for playing, you earned [%d/%d coins],"
			" but did not reach the end. Select a map and try again.\n",
			map->player_coins, map->map_coins);
	mlx_close_window(map->mlx);
}

// ===== Place Player =====
void	place_player(t_map *map_struct)
{
	int32_t			x;
	int32_t			y;

	x = (((map_struct->width * 128) / 4) - 64)
			+ ((map_struct->player_pos_x * 64) - (map_struct->player_pos_y * 64));

	y = ((map_struct->player_pos_y * 64) + ((map_struct->player_pos_x * 32) - (map_struct->player_pos_y * 32))) + 32;

	// Player
	if (mlx_image_to_window(map_struct->mlx,
			map_struct->images_struct->img_p, x, y) < 0)
		exit_message("Error with MLX image");
}

// ===== Move Player =====
void	move_player(t_map *map_struct, char axis, int direction)
{
	int32_t			x;
	int32_t			y;

	x = (((map_struct->width * 128) / 4) - 64)
			+ ((map_struct->player_pos_x * 64) - (map_struct->player_pos_y * 64));
	y = ((map_struct->player_pos_y * 64) + ((map_struct->player_pos_x * 32) - (map_struct->player_pos_y * 32))) + 32;

	// Check exit
	if (map_struct->player_pos_x == map_struct->exit_pos_x
		&& map_struct->player_pos_y == map_struct->exit_pos_y)
	{
		if (mlx_image_to_window(map_struct->mlx,
				map_struct->images_struct->img_e, x, y) < 0)
			exit_message("Error with MLX image.\n");
	}

	// Move player
	move_in_direction(map_struct, axis, direction);

	// Update position
	x = (((map_struct->width * 128) / 4) - 64)
			+ ((map_struct->player_pos_x * 64) - (map_struct->player_pos_y * 64));
	y = ((map_struct->player_pos_y * 64) + ((map_struct->player_pos_x * 32) - (map_struct->player_pos_y * 32))) + 32;
}

void	move_in_direction(t_map *map_struct, char axis, int direction)
{
	if (axis == 'x')
	{
		if (direction > 0)
			move_right(map_struct);
		else
			move_left(map_struct);
	}
	if (axis == 'y')
	{
		if (direction > 0)
			move_up(map_struct);
		else
			move_down(map_struct);
	}
}
