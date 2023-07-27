/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/07/27 13:14:18 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_map_read(char **argv, t_game *g)
{
	size_t	i;
	char	*line;

	i = 0;
	line = get_next_line(argv[1]);
	while (line)
		g->map = ft_strjoin(g->map, line);
	free(line);
}

void	sl_map_create(int fd, t_game *g)
{
	
}

void	sl_map_destroy(int fd)
{
	
}

t_game	*sl_map_init(char **argv, t_game *g)
{
	
	fd = open(argv[1], O_RDONLY);
	sl_map_read(argv[1]);
	g->map = ft_split(g->map, '\n');
	return (g->map);
}