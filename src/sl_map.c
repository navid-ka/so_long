/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/07/31 15:24:45 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_map_read(int fd, t_game *g)
{
	char	*line;
	char	*tmp_line;
	char	*all_lines;
	(void)g;

	line = ft_strdup("");
	all_lines = ft_strdup("");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		tmp_line = all_lines;
		all_lines = ft_strjoin(tmp_line, line);
		free(tmp_line);
	}
	//ft_printf("%s,", all_lines);
	g->map = ft_split(all_lines, '\n');
	for (size_t i = 0; g->map[i]; i++) {
        ft_printf("%s\n", g->map[i]);
    }
	free(all_lines);
}

/*void	sl_map_create(int fd, t_game *g)
{
	
}

void	sl_map_destroy(int fd)
{
	
}
*/
void	sl_map_init(char **argv, t_game *g)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	ft_printf("fd open %d\n", fd);
	sl_map_read(fd, g);
	close(fd);
	//g->map = ft_split(g->map, '\n');
}