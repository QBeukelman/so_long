/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images_struct.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:39:50 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 15:57:50 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_images	*initialize_map_images_1(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_1;

	texture_1 = mlx_load_png("./assets/tile_1.png");
	if (!texture_1)
		exit_message("Error with MLX image.\n");
	images_struct->img_1 = mlx_texture_to_image(mlx, texture_1);
	if (!images_struct->img_1)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_1);
	return (images_struct);
}

t_images	*initialize_map_images_0(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_0;

	texture_0 = mlx_load_png("./assets/tile_0.png");
	if (!texture_0)
		exit_message("Error with MLX image.\n");
	images_struct->img_0 = mlx_texture_to_image(mlx, texture_0);
	if (!images_struct->img_0)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_0);
	return (images_struct);
}

t_images	*initialize_map_images_c(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_c;

	texture_c = mlx_load_png("./assets/tile_c.png");
	if (!texture_c)
		exit_message("Error with MLX image.\n");
	images_struct->img_c = mlx_texture_to_image(mlx, texture_c);
	if (!images_struct->img_c)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_c);
	return (images_struct);
}

t_images	*initialize_map_images_c_item(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_c_item;

	texture_c_item = mlx_load_png("./assets/tile_c_item.png");
	if (!texture_c_item)
		exit_message("Error with MLX image.\n");
	images_struct->img_c_item = mlx_texture_to_image(mlx, texture_c_item);
	if (!images_struct->img_c_item)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_c_item);
	return (images_struct);
}

t_images	*initialize_map_images_p(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_p;

	texture_p = mlx_load_png("./assets/tile_p.png");
	if (!texture_p)
		exit_message("Error with MLX image.\n");
	images_struct->img_p = mlx_texture_to_image(mlx, texture_p);
	if (!images_struct->img_p)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_p);
	return (images_struct);
}

t_images	*initialize_map_images_e(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_e;

	texture_e = mlx_load_png("./assets/tile_e.png");
	if (!texture_e)
		exit_message("Error with MLX image.\n");
	images_struct->img_e = mlx_texture_to_image(mlx, texture_e);
	if (!images_struct->img_e)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_e);
	return (images_struct);
}

t_images	*initialize_map_images_b(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_b;

	texture_b = mlx_load_png("./assets/tile_b.png");
	if (!texture_b)
		exit_message("Error with MLX image.\n");
	images_struct->img_b = mlx_texture_to_image(mlx, texture_b);
	if (!images_struct->img_b)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_b);
	return (images_struct);
}

t_images	*initialize_map_images_r(mlx_t *mlx, t_images *images_struct)
{
	mlx_texture_t	*texture_r;

	texture_r = mlx_load_png("./assets/tile_block.png");
	if (!texture_r)
		exit_message("Error with MLX image.\n");
	images_struct->img_r = mlx_texture_to_image(mlx, texture_r);
	if (!images_struct->img_r)
		exit_message("Error with MLX image.\n");
	mlx_delete_texture(texture_r);
	return (images_struct);
}