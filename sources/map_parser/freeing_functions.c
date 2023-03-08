/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeing_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:40:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/01/20 17:17:15 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_map_struct(t_map *map)
{
	free(map->content);
	free_array((void **) map->map_array);
}

char	*open_close_file(char *path)
{
	int		fd;
	char	*map_str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_message("Faild to open .ber file.\n");
	map_str = get_str_from_file(fd);
	close (fd);
	if (!*map_str)
		exit_message("The map is empty.\n");
	return (map_str);
}
