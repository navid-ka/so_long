/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/08 14:40:27 by nkeyani-         ###   ########.fr       */
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
		if (line && line[0] == '\n')
		{
			free(line);
			ft_printf("%s\n", "Error empieza por \\n");
			exit(1);
		}
		tmp_line = all_lines;
		all_lines = ft_strjoin(tmp_line, line);
		free(tmp_line);
	}
	if (ft_strcmp(all_lines, "") == 0)
	{
		ft_printf("%s\n", "NULL \\n");
		exit(1);
		}
	g->map = ft_split(all_lines, '\n');
	g->mapcpy = ft_split(all_lines, '\n');
	for (size_t i = 0; g->mapcpy[i]; i++){
        ft_printf("%s\n", g->mapcpy[i]);
    }
	free(all_lines);
}

void	sl_map_parser(t_game *g)
{
	if (sl_map_parse_rect(g) == 0)
		sl_map_exit(g->map, NOT_RECT, "Error map not rect\n");
	else if (sl_map_parse_walls(g) > 0)
		sl_map_exit(g->map, NOT_WALLS, "Error map have incorrect size/walls\n");
	else if (sl_map_parse_char(g) == 0)
		sl_map_exit(g->map, NOT_CHARS, "Error duplicate or missing chars\n");
	else if (sl_map_parse_incorrect_chars(g) == 0)
		sl_map_exit(g->map, BAD_CHARS, "Error invalid chars\n");
	sl_map_backtracking(g);
}

/*void	sl_map_draw(t_game *g)
{
	
}
*/
void	sl_map_init(char **argv, t_game *g)
{
	int		fd;
	char	*str;

	str = argv[1];
	while (*str != '.')
		str++;
	if ((str + 1) == ft_strnstr(str + 1, "ber", 3) && !(str + 4))
		sl_map_exit(NULL, NOT_BER, "Error no .ber file\n");
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		exit(1);
	ft_printf("INFO: FILE SUCCESFULLY OPEN IN FD %d\n", fd);
	sl_map_read(fd, g);
	sl_map_parser(g);
	ft_printf("INFO: Map parsed correctly\n");
	close(fd);
}
