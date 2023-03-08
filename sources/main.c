/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:38:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 16:31:05 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define WIDTH 80
#define HEIGHT 80

int	main(int argc, char **argv)
{
	t_map		*map_struct;
	t_images	*images_struct;
	mlx_t		*mlx;

	if (argc != 2)
		exit_message("Please provide a map text file"
			" (.ber) as a single argument.\n");
	map_struct = initialize_map(argv[1]);
	solve_map(map_struct);
	mlx = mlx_init((map_struct->width * 128),
			(map_struct->height * 128), "MLX42", true);
	if (!mlx)
		exit_message("Error with MLX window.\n");
	images_struct = initialize_images_struct(mlx);
	map_struct = save_map(mlx, images_struct, map_struct);
	images_to_window(map_struct, images_struct, mlx);
	
	// Key
	mlx_key_hook(mlx, &my_keyhook, map_struct);

	// Loop
	mlx_loop_hook(mlx, &bot_movement, map_struct);
	
	mlx_close_hook(mlx, &escape_message, map_struct);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map_struct(map_struct);
	exit (0);
}
