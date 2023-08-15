/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/16 01:24:06 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_game_dimension(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	g->h_w = i;
	g->w_w = ft_strlen(g->map[0]);
}

void	sl_game_start(t_game *g)
{
	g->mlx = mlx_init();
	sl_game_dimension(g);
	g->win = mlx_new_window(g->mlx, g->w_w * 32, g->h_w * 32, TITLE);
	sl_image_init(g);
	sl_draw_map(g);
	mlx_hook(g->win, 2, 0, sl_game_read_keys, g);
	mlx_hook(g->win, 17, 0, sl_game_destroy, g);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc == 2)
	{
		g = (t_game *)malloc(sizeof (t_game));
		sl_var_init(g);
		sl_map_init(argv, g);
		sl_game_start(g);
		mlx_loop(g->mlx);
		mlx_destroy(g->mlx);
		sl_free(g->map);
		free(g);
	}
	else
		ft_printf("Error\nNo map provided.\n");
	return (0);
}
