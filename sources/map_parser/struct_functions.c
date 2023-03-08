/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:41:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 13:42:08 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	*initialize_map_struct(char **map_array)
{
	t_map	*map;
	size_t	x;
	size_t	y;

	x = ft_strlen(map_array[0]);
	y = 0;
	while (map_array[y])
		y++;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		exit_message("Malloc error: initialize_map_struct().\n");
	map->height = y;
	map->width = x;
	map->content = join_string_array(map_array);
	map->map_array = map_array;
	map->size = ft_strlen(map->content);
	map->player_pos = ft_strchr(map->content, 'P') - map->content;
	map->player_pos = ft_strchr(map->content, 'B') - map->content;
	map = initialize_map_extra(map);
	map->map_coins = count_coins(map->content);
	return (map);
}

t_map	*initialize_map_extra(t_map *map)
{
	map->player_pos_x = get_player_xy(map, 'x');
	map->player_pos_y = get_player_xy(map, 'y');
	map->bot_pos_x = get_bot_xy(map, 'x');
	map->bot_pos_y = get_bot_xy(map, 'y');
	map->exit_pos_x = get_exit_xy(map, 'x');
	map->exit_pos_y = get_exit_xy(map, 'y');
	map->content[map->player_pos] = '0';
	map->move_count = 0;
	map->player_coins = 0;
	return (map);
}

t_map	*save_map(mlx_t *mlx, t_images *images_struct, t_map *map_struct)
{
	map_struct->mlx = mlx;
	map_struct->images_struct = images_struct;
	return (map_struct);
}

char	*join_string_array(char **array)
{
	char	*str;
	char	*str2;
	size_t	i;

	i = 0;
	if (!array[i])
		return (NULL);
	else
		str = ft_strdup(array[i]);
	if (!str)
		exit_message("Malloc error: join_string_array().\n");
	i++;
	while (array[i])
	{
		str2 = ft_strjoin(str, array[i]);
		if (!str2)
			exit_message("Malloc error: join_string_array().\n");
		free(str);
		str = str2;
		i++;
	}
	return (str);
}

size_t	count_coins(char *map_str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (map_str[i])
	{
		if (map_str[i] == 'C')
			count++;
		i++;
	}
	return (count);
}
