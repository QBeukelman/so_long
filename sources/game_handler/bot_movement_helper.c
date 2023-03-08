/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bot_movement_helper.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 13:49:14 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 13:54:31 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	bot_move_right(t_map *map)
{
	if (map->map_array[map->bot_pos_y][map->bot_pos_x +1] != '1')
	{
		// if (map->map_array[map->bot_pos_y][map->bot_pos_x +1] == 'C')
		// 	map->player_coins += 1;
		map->map_array[map->bot_pos_y][map->bot_pos_x +1] = '0';
		map->bot_pos_x += 1;
	}
}

void	bot_move_left(t_map *map)
{
	if (map->map_array[map->bot_pos_y][map->bot_pos_x -1] != '1')
	{
		// if (map->map_array[map->bot_pos_y][map->bot_pos_x -1] == 'C')
		// 	map->player_coins += 1;
		map->map_array[map->bot_pos_y][map->bot_pos_x -1] = '0';
		map->bot_pos_x += -1;
	}
}

void	bot_move_up(t_map *map)
{
	if (map->map_array[map->bot_pos_y -1][map->bot_pos_x] != '1')
	{
		// if (map->map_array[map->bot_pos_y -1][map->bot_pos_x] == 'C')
		// 	map->player_coins += 1;
		map->map_array[map->bot_pos_y -1][map->bot_pos_x] = '0';
		map->bot_pos_y += -1;
	}
}

void	bot_move_down(t_map *map)
{
	if (map->map_array[map->bot_pos_y +1][map->bot_pos_x] != '1')
	{
		// if (map->map_array[map->bot_pos_y +1][map->bot_pos_x] == 'C')
		// 	map->player_coins += 1;
		map->map_array[map->bot_pos_y +1][map->bot_pos_x] = '0';
		map->bot_pos_y += 1;
	}
}