/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/03 19:32:41 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_map_all_lines(char *line)
{
	int		i;

	i = 0;
	/*if (line[0] == '\n' || line[0] == '\0')
		return (0);*/
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	void_print()
{
	ft_printf("Error pre map not rect\n");
}

void	sl_map_pre_check(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (exit(1));
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	if (sl_map_all_lines(line) == 0)
		return (void_print(), exit(1));
}

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
	g->map = ft_split(all_lines, '\n');
	for (size_t i = 0; g->map[i]; i++){
        ft_printf("%s\n", g->map[i]);
    }
	free(all_lines);
}

void	sl_map_parser(t_game *g)
{
	if (sl_map_parse_rect(g) == 0)
		ft_printf("Error map not rect\n");
	else if (sl_map_parse_walls(g) > 0)
		ft_printf("Error map no walls\n");
	else if (sl_map_parse_char(g) == 0)
		ft_printf("Error not correct chars: more or less valid chars\n");
	else if (sl_map_parse_incorrect_chars(g) == 0)
		ft_printf("Error invalid chars\n");
	/*else if (!sl_map_parse_path(g))*/
}

/*void	sl_map_draw(t_game *g)
{
	
}
*/
void	sl_map_init(char **argv, t_game *g)
{
	int fd;
	char *str;

	str = argv[1];
	/*fd = open(str, O_RDONLY);
	if (!fd)
		return ;
	ft_printf("fd open %d\n", fd);
	sl_map_pre_check(fd);
	close(fd);*/
	fd = open(str, O_RDONLY);
	sl_map_read(fd, g);
	sl_map_parser(g);
	//sl_map_draw(g);
	close(fd);
}