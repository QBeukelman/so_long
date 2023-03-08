/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images_to_window.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:40:02 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 16:31:36 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// ===== MLX images =====
t_images	*initialize_images_struct(mlx_t *mlx)
{
	t_images	*images_struct;

	images_struct = ft_calloc(sizeof(t_images), 1);
	if (!images_struct)
		exit_message("Malloc error: initialize_images_struct().\n");
	images_struct = initialize_map_images_1(mlx, images_struct);
	images_struct = initialize_map_images_0(mlx, images_struct);
	images_struct = initialize_map_images_c(mlx, images_struct);
	images_struct = initialize_map_images_c_item(mlx, images_struct);
	images_struct = initialize_map_images_p(mlx, images_struct);
	images_struct = initialize_map_images_e(mlx, images_struct);
	images_struct = initialize_map_images_b(mlx, images_struct);
	images_struct = initialize_map_images_r(mlx, images_struct);
	return (images_struct);
}

// ===== Images to window =====
void	images_to_window(t_map *map, t_images *images, mlx_t *mlx)
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

void	select_image(char c, t_images *images, mlx_t *mlx, size_t *pix)
{
	if (c == '1')
	{
		if (mlx_image_to_window(mlx, images->img_1, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
	else if (c == '0' || c == 'B')
	{
		if (mlx_image_to_window(mlx, images->img_0, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
	else if (c == 'C')
	{
		if (mlx_image_to_window(mlx, images->img_c, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
	else if (c == 'E')
	{
		if (mlx_image_to_window(mlx, images->img_e, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
	else if (c == 'R')
	{
		if (mlx_image_to_window(mlx, images->img_r, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
	if (c == 'B')
	{
		if (mlx_image_to_window(mlx, images->img_b, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
	if (c == 'C')
	{
		if (mlx_image_to_window(mlx, images->img_c_item, pix[0], pix[1]) < 0)
			exit_message("Error with MLX image.\n");
	}
}
