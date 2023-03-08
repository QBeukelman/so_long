/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_messages.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:39:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/01/20 17:16:22 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_message(t_map *map_struct)
{
	if (map_struct->player_pos_x == map_struct->exit_pos_x
		&& map_struct->player_pos_y == map_struct->exit_pos_y)
	{
		if (map_struct->player_coins == map_struct->map_coins)
			ft_printf("\n\nCongradulations! You have completed this level."
				" Press esc to close the window and select another level.\n");
	}
	else
	{
		ft_printf("\n[Moves: %d] [Coins: %d/%d]", map_struct->move_count,
			map_struct->player_coins, map_struct->map_coins);
	}
}

void	escape_message(void *map_ptr)
{
	t_map	*map;

	map = (t_map *) map_ptr;
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
	exit (0);
}
