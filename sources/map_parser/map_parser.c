/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:40:56 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 15:54:00 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// ===== initialize_map =====
t_map	*initialize_map(char *path)
{
	char	*map_str;
	char	**map_rows;
	t_map	*map_struct;
	size_t	col_count;

	check_path_extension(path);
	map_str = open_close_file(path);
	check_empty_lines(map_str);
	map_rows = ft_split(map_str, '\n');
	if (!map_rows)
	{
		free(map_str);
		exit_message("Malloc error: initialize_map()/ft_split().\n");
	}
	col_count = check_map_measurements(map_rows);
	check_map_boundaries(map_rows, col_count);
	check_map_content(map_str);
	map_struct = initialize_map_struct(map_rows);
	free (map_str);
	return (map_struct);
}

// ===== Validate Map Content
void	check_map_content(char *map)
{
	size_t	players;
	size_t	exits;
	size_t	coins;

	players = 0;
	exits = 0;
	coins = 0;
	while (*map)
	{
		if (*map == 'P')
			players++;
		if (*map == 'E')
			exits++;
		if (*map == 'C')
			coins++;
		else
			check_invalid_characters(*map);
		map++;
	}
	if (players != 1)
		exit_message("Map does not have exactly one player.\n");
	if (exits != 1)
		exit_message("Map does not have exactly one exit.\n");
	if (coins < 1)
		exit_message("Map does not have at least one collectible.\n");
}

void	check_invalid_characters(char c)
{
	if (!ft_strchr("\n01PECBR", c))
		exit_message("Map contains invalid characters.\n");
}

// ===== get_str_from_file =====
char	*get_str_from_file(int fd)
{
	char	*map_str;
	char	*map_joined;
	char	*line;

	map_str = ft_calloc(1, 1);
	if (!map_str)
		exit_message("Calloc fail: get_str_from_file().\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_joined = ft_strjoin(map_str, line);
			free (map_str);
			free (line);
			if (!map_joined)
				exit_message("Malloc error:"
					" get_str_from_file()/ft_strjoin().\n");
			map_str = map_joined;
		}
		else
			break ;
	}
	return (map_str);
}

// ===== check_empty_lines =====
void	check_empty_lines(char *map)
{
	while (*map)
	{
		if (*map == '\n' && *(map + 1) == '\n')
			exit_message("Map contains empty lines.\n");
		map++;
	}
}
