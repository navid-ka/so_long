/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:16:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/16 16:14:22 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_player_mov_up(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row -1, g->p_col))
	{
		sl_take_coin(g, g->p_row -1, g->p_col);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_row = g->p_row -1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		sl_game_finish(g, g->p_row, g->p_col);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
	}
}

void	sl_player_mov_down(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row + 1, g->p_col))
	{
		sl_take_coin(g, g->p_row + 1, g->p_col);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_row = g->p_row + 1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		sl_game_finish(g, g->p_row, g->p_col);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
	}
}

void	sl_player_mov_right(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row, g->p_col + 1))
	{
		sl_take_coin(g, g->p_row, g->p_col + 1);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_col = g->p_col + 1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		sl_game_finish(g, g->p_row, g->p_col);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
	}
}

void	sl_player_mov_left(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row, g->p_col - 1))
	{
		sl_take_coin(g, g->p_row, g->p_col - 1);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_col = g->p_col -1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[5].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		sl_game_finish(g, g->p_row, g->p_col);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
	}
}
