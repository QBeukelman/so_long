/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_solve.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:41:13 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/01/20 17:10:17 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	solve_map(t_map *map_struct)
{
	char	*map_str_dup;
	size_t	i;

	i = 1;
	map_str_dup = ft_strdup(map_struct->content);
	if (!map_str_dup)
		exit_message("Malloc error: map_solve().\n");
	map_str_dup[map_struct->player_pos] = 'X';
	while (i)
		i = check_map_string(map_struct, map_str_dup);
	if (check_remaining_objects(map_str_dup))
		exit_message("The map does not contain a valid path.\n");
	free(map_str_dup);
}

size_t	check_map_string(t_map *map_struct, char *map_str)
{
	size_t	i;

	i = 0;
	while (*map_str)
	{
		if (*map_str == 'X')
		{
			i++;
			*map_str = 'x';
			clear_space(map_str + 1);
			clear_space(map_str - 1);
			clear_space(map_str + map_struct->width);
			clear_space(map_str - map_struct->width);
		}
		map_str++;
	}
	return (i);
}

void	clear_space(char *position)
{
	if (*position == '0' || *position == 'P'
		|| *position == 'C' || *position == 'E')
		*position = 'X';
}

size_t	check_remaining_objects(char *map_str)
{
	size_t	i;

	i = 0;
	while (*map_str)
	{
		if (*map_str == 'P' || *map_str == 'C' || *map_str == 'E')
			i++;
		map_str++;
	}
	return (i);
}
