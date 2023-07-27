/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/07/27 12:15:57 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	solong_map_read(char **argv, t_game *g)
{
	size_t	i;
	char	*line;

	i = 0;
	line = get_next_line(argv[1]);
	while (line)
		g->map = ft_strjoin(g->map, map_line);
	free(line);
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
	solong_map_read(argv[1]);
	return (g->map);
}