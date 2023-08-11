/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:16:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/11 20:57:39 by nkeyani-         ###   ########.fr       */
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


void	sl_player_mov_up(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row -1, g->p_col))
	{
		sl_take_coin(g, g->p_row -1,  g->p_col);
		sl_game_finish(g, g->p_row -1,  g->p_col);
		ft_printf("INFO: Player position in mov	(%d,%d, %d)\n", g->p_row, g->p_col, g->coin);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_row = g->p_row -1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
	}
}

void	sl_player_mov_down(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row + 1, g->p_col))
	{
		sl_take_coin(g, g->p_row + 1,  g->p_col);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_row = g->p_row + 1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
		sl_game_finish(g, g->p_row + 1,  g->p_col);
	}
}

void	sl_player_mov_right(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row, g->p_col + 1))
	{
		sl_take_coin(g, g->p_row, g->p_col + 1);
		sl_game_finish(g, g->p_row, g->p_col + 1);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_col= g->p_col  +1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
	}
}

void	sl_player_mov_left(t_game *g)
{
	if (sl_move_is_valid(g, g->p_row, g->p_col - 1))
	{
		sl_take_coin(g, g->p_row, g->p_col - 1);
		sl_game_finish(g, g->p_row, g->p_col - 1);
		if (g->map[g->p_row][g->p_col] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		g->p_col = g->p_col -1;
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row * 32);
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
	}
}

