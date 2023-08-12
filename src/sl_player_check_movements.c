/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_check_movements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:01:39 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/13 00:02:08 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_move_is_valid(t_game *g, int row, int col)
{
	if (g->map[row][col] == '1')
	{
		return (0);
	}
	return (1);
}

void	sl_take_coin(t_game *g, int row, int col)
{
	if (g->map[row][col] == 'C')
	{
		g->coin--;
		g->map[row][col] = '0';
	}
}

int	sl_game_read_keys_finish(int key_pressed, t_game *g)
{
	if (key_pressed == ESC)
	{
		ft_printf("KEY PRESSED:		%d\n", ESC);
		sl_game_destroy(g);
	}
	return (0);
}

void	sl_game_finish(t_game *g, int row, int col)
{
	if (g->map[row][col] == 'E' && g->coin == 0)
	{
		mlx_key_hook(g->win, sl_game_read_keys_finish, g);
		mlx_string_put(g->mlx, g->win, (g->w_w * 32) / 2 - 96, \
			(g->h_w * 32) / 2, 0x00FFFFFFF, "over");
	}
}
