/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:41:31 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/08 15:56:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// ===== Map Measurements =====
size_t	check_map_measurements(char	**map)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(map[i]);
	if (len < 3)
		exit_message("Map is too small.");
	i++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			exit_message("Map rows are not the same length.\n");
		i++;
	}
	if (i < 3)
		exit_message("The map is too small.\n");
	return (i);
}

// ===== Validate Map Boundaries =====
void	check_map_boundaries(char **map, size_t col_count)
{
	check_rows(map, col_count);
	check_columns(map, col_count, ft_strlen(map[0]));
}

// ===== Check Rows =====
void	check_rows(char **map, size_t col_count)
{
	size_t	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			exit_message("Boundaries/First_Row.\n");
		if (map[col_count -1][i] != '1')
			exit_message("Boundaries/Last_Row.\n");
		i++;
	}
}

// ===== Check Columns =====
void	check_columns(char **map, size_t col_count, size_t row_len)
{
	size_t	i;

	i = 0;
	while (i < col_count)
	{
		if (map[i][0] != '1')
			exit_message("Boundaries/First_Columns.\n");
		if (map[i][row_len -1] != '1')
			exit_message("Boundaries/Last_Columns.\n");
		i++;
	}
}

// ===== Check Path Extension =====
void	check_path_extension(char *path)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	temp[5];

	len = ft_strlen(path);
	i = len - 4;
	j = 0;
	while (path[i])
	{
		temp[j] = path[i];
		i++;
		j++;
	}
	if (ft_strncmp(".ber", temp, 4))
		exit_message("File extension should exactly match (.ber).\n");
}
