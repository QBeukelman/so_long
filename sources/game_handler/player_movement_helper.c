/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement_helper.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:40:15 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/01/16 13:15:16 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_right(t_map *map)
{
	if (map->map_array[map->player_pos_y][map->player_pos_x +1] != '1')
	{
		if (map->map_array[map->player_pos_y][map->player_pos_x +1] == 'C')
			map->player_coins += 1;
		map->map_array[map->player_pos_y][map->player_pos_x +1] = '0';
		map->move_count = map->move_count +1;
		map->player_pos_x += 1;
		player_message(map);
	}
}

void	move_left(t_map *map)
{
	if (map->map_array[map->player_pos_y][map->player_pos_x -1] != '1')
	{
		if (map->map_array[map->player_pos_y][map->player_pos_x -1] == 'C')
			map->player_coins += 1;
		map->map_array[map->player_pos_y][map->player_pos_x -1] = '0';
		map->move_count = map->move_count +1;
		map->player_pos_x += -1;
		player_message(map);
	}
}

void	move_up(t_map *map)
{
	if (map->map_array[map->player_pos_y -1][map->player_pos_x] != '1')
	{
		if (map->map_array[map->player_pos_y -1][map->player_pos_x] == 'C')
			map->player_coins += 1;
		map->map_array[map->player_pos_y -1][map->player_pos_x] = '0';
		map->move_count = map->move_count +1;
		map->player_pos_y += -1;
		player_message(map);
	}
}

void	move_down(t_map *map)
{
	if (map->map_array[map->player_pos_y +1][map->player_pos_x] != '1')
	{
		if (map->map_array[map->player_pos_y +1][map->player_pos_x] == 'C')
			map->player_coins += 1;
		map->map_array[map->player_pos_y +1][map->player_pos_x] = '0';
		map->move_count = map->move_count +1;
		map->player_pos_y += 1;
		player_message(map);
	}
}
