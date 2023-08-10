/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/10 20:06:33 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	sl_game_destroy(t_game *g)
{
	//mlx_destroy_window(g->mlx, g->mlx_win);
	free(g);
	exit(0);
}

void	sl_game_dimension(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	g->h_w = i;
	g->w_w = ft_strlen(g->map[0]);
}

int	sl_game_read_keys(int key_pressed, t_game *g)
{
	if (key_pressed == ESC)
	{
		ft_printf("KEY PRESSED:		%d\n", ESC);
		sl_game_destroy(g);
	}
	return (0);
}

void	sl_game_start(t_game *g)
{
	mlx_key_hook(g->win, sl_game_read_keys, g);
	mlx_hook(g->win, 17, 0, sl_game_destroy, g);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	(void)argc;
	printf("LOADING\n");
	g = (t_game *)malloc(sizeof (t_game));

	sl_map_init(argv, g);
	g->mlx = mlx_init();
	sl_game_dimension(g);
	g->win = mlx_new_window(g->mlx, g->w_w * 32, g->h_w * 32, TITLE);
	sl_game_start(g);
	sl_image_init(g);
	sl_draw_map(g);
	sl_draw_entities(g);
	mlx_loop(g->mlx);
	mlx_destroy(g->mlx);
	sl_free(g->map);
	free(g);
	return (0);
}