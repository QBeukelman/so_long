/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_coordinates.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 13:38:57 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 13:41:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// ===== X / Y =====
size_t	get_player_xy(t_map *map, char c)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((unsigned char)map->content[i] == 'P')
			{
				if (c == 'y')
					return (y);
				return (x);
			}
			i++;
			x++;
		}
		y++;
	}
	return (0);
}

// ===== X / Y =====
size_t	get_exit_xy(t_map *map, char c)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((unsigned char)map->content[i] == 'E')
			{
				if (c == 'y')
					return (y);
				return (x);
			}
			i++;
			x++;
		}
		y++;
	}
	return (0);
}

size_t	get_bot_xy(t_map *map, char c)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((unsigned char)map->content[i] == 'B')
			{
				if (c == 'y')
					return (y);
				return (x);
			}
			i++;
			x++;
		}
		y++;
	}
	return (0);
}