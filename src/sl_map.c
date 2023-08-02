/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/02 19:39:27 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_map_read(int fd, t_game *g)
{
	char	*line;
	char	*tmp_line;
	char	*all_lines;

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
	//ft_printf("all lines es \n%s", all_lines);
	g->map = ft_split(all_lines, '\n');
	for (size_t i = 0; g->map[i]; i++) { 
        ft_printf("%s\n", g->map[i]);
    }
	free(all_lines);
}

void	sl_map_parser(t_game *g)
{
	if (sl_map_parse_rect(g) == 0)
		ft_printf("Error map not rect\n");
	else if (sl_map_parse_walls(g) == 0)
		ft_printf("Error map no walls\n");
	else if (!sl_map_parse_char(g))
		ft_printf("Error not correct chars\n");
	/*else if (!sl_map_parse_walls(g))
	else if (!sl_map_parse_path(g))*/
}

/*void	sl_map_draw(t_game *g)
{
	
}
*/
void	sl_map_init(char **argv, t_game *g)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	ft_printf("fd open %d\n", fd);
	sl_map_read(fd, g);
	sl_map_parser(g);
	//sl_map_draw(g);
	close(fd);
}