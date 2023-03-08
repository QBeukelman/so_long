/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bot_movement.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 12:49:43 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 16:39:53 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void 	bot_movement(void *map_struct_void_ptr)
{
	int			random;
    t_map 		*map_struct = (t_map *)map_struct_void_ptr;

    place_bot(map_struct);

	random = random_int();
	if (random == 0)
		bot_move_right(map_struct);
	if (random == 1)
		bot_move_left(map_struct);
	if (random == 2)
		bot_move_up(map_struct);
	if (random == 3)
		bot_move_down(map_struct);
    images_to_window(map_struct, map_struct->images_struct, map_struct->mlx);

	place_player(map_struct);

}


// ===== Place Bot =====
void	place_bot(t_map *map_struct)
{
	int32_t			x;
	int32_t			y;

	x = (((map_struct->width * 128) / 4) - 64)
			+ ((map_struct->bot_pos_x * 64) - (map_struct->bot_pos_y * 64));

	y = ((map_struct->bot_pos_y * 64) + ((map_struct->bot_pos_x * 32) - (map_struct->bot_pos_y * 32))) + 32;
	if (mlx_image_to_window(map_struct->mlx,
			map_struct->images_struct->img_b, x, y) < 0)
		exit_message("Error with MLX image");
}

void	render_bots(t_map *map, t_images *images, mlx_t *mlx)
{
	size_t		x;
	size_t		y;
	size_t		i;
	size_t		pix[2];
	size_t		diamond;

	x = 0;
	y = 0;
	i = 0;
	pix[1] = 0;
	diamond = 0;

	while (y < map->height)
	{
		x = 0;
		pix[0] = (((map->width * 128) / 4) - 64) - diamond;
		pix[1] = y * 32;
		while (x < map->width)
		{
			pix[1] += 32;
			select_image(map->content[i], images, mlx, pix);
			pix[0] += 64;
			i++;
			x++;
		}
		diamond += 64;
		pix[1] += 64;
		y++;
	}
}

void	select_bot_image(char c, t_images *images, mlx_t *mlx, size_t *pix)
{
	if (c == 'B')
	{
		if (mlx_image_to_window(mlx, images->img_b, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
}

int		random_int(void)
{
    srand(time(NULL)); // Seed the random number generator with current time
    return rand() % 4; // Generate a random number between 0 and 3 (inclusive)
}



void	move_bot(t_map *map_struct, char axis, int direction)
{
	int32_t			x;
	int32_t			y;

	x = (((map_struct->width * 128) / 4) - 64)
			+ ((map_struct->bot_pos_x * 64) - (map_struct->bot_pos_y * 64));
	y = ((map_struct->bot_pos_y * 64) + ((map_struct->bot_pos_x * 32) - (map_struct->bot_pos_y * 32))) + 32;

	if (mlx_image_to_window(map_struct->mlx,
			map_struct->images_struct->img_0, x, y) < 0)
		exit_message("Error with MLX image.\n");

	if (map_struct->bot_pos_x == map_struct->exit_pos_x
		&& map_struct->bot_pos_y == map_struct->exit_pos_y)
	{
		if (mlx_image_to_window(map_struct->mlx,
				map_struct->images_struct->img_e, x, y) < 0)
			exit_message("Error with MLX image.\n");
	}

	move_in_direction(map_struct, axis, direction);

	x = (((map_struct->width * 128) / 4) - 64)
			+ ((map_struct->bot_pos_x * 64) - (map_struct->bot_pos_y * 64));
	y = ((map_struct->bot_pos_y * 64) + ((map_struct->bot_pos_x * 32) - (map_struct->bot_pos_y * 32))) + 32;

}


void	update_bot_surroundings(t_map *map, t_images *images, mlx_t *mlx)
{
	size_t		x;
	size_t		y;
	size_t		i;
	size_t		pix[2];
	size_t		diamond;

	x = 0;
	y = 0;
	i = 0;
	pix[1] = 0;
	diamond = 0;

	while (y < map->height)
	{
		x = 0;
		pix[0] = (((map->width * 128) / 4) - 64) - diamond;
		pix[1] = y * 32;
		while (x < map->width)
		{
			pix[1] += 32;
			select_image(map->content[i], images, mlx, pix);
			pix[0] += 64;
			i++;
			x++;
		}
		diamond += 64;
		pix[1] += 64;
		y++;
	}
}
