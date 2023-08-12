/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:49:18 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/13 00:12:02 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_game_destroy(t_game *g)
{
	//mlx_destroy_window(g->mlx, g->win);
	sl_map_exit(g->map, FINISH, \
		"Game over.\n");
	exit(0);
}

void	sl_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}

void	sl_free_msg(char **map, char *error_msg)
{
	sl_free(map);
	ft_printf("%s", error_msg);
	exit(EXIT_FAILURE);
}
void	sl_exit_nw(void)
{
		ft_printf("%s\n", "Error map contains at the start or in the middle \\n");
		exit(EXIT_FAILURE);
}

void	sl_map_exit(char **map, int enum_msg, char *error_msg)
{
	if (enum_msg == NOT_BER)
	{
		ft_printf("Error .ber extension not found");
		exit(EXIT_FAILURE);
	}
	if (enum_msg == NOT_RECT)
		sl_free_msg(map, error_msg);
	if (enum_msg == NOT_WALLS)
		sl_free_msg(map, error_msg);
	if (enum_msg == NOT_CHARS)
		sl_free_msg(map, error_msg);
	if (enum_msg == BAD_CHARS)
		sl_free_msg(map, error_msg);
	if (enum_msg == NO_PATH)
		sl_free_msg(map, error_msg);
	if (enum_msg == FINISH)
		sl_free_msg(map, error_msg);
}
