/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/07/26 15:21:55 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*solong_map_read(char **argv)
{
	size_t	i;
	char	*map_line;

	i = 0;
	while (argv[1][i])
		map_line = get_next_line(argv[1][i++]);
	close(argv[1]);
	return (map_line);
}

void	solong_map_create(int fd, t_game *g)
{
	
}

void	solong_map_destroy(int fd)
{
	
}

t_game	*solong_map_init(char **argv, t_game *g)
{
	
	fd = open(argv[1], O_RDONLY);
	g->map = solong_map_read(argv[1]);
	return (g->map);
}