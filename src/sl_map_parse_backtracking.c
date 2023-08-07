/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parse_backtracking.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:02:37 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/06 19:06:09 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void sl_map_count_rows_cols(t_game *g)
{
	int i;

	i = 0;
	while (g->map[i])
		i++;
	g->row = i;
	g->col = ft_strlen(g->map[0]);
}

static void sl_bt_starting(t_game *g)
{
	int i;
	int j;

	(0 || (i = 0) || (j = 0) || (g->c = 0) || \
		(g->p_row = 0) || (g->p_col = 0));
	while (g->mapcpy[i])
	{
		while (g->mapcpy[i][j])
		{
			if (g->mapcpy[i][j] == 'P')
			{
				g->p_row = i;
				g->p_col = j;
			}
			if (g->mapcpy[i][j] == 'C')
				g->c++;
			if (g->mapcpy[i][j] == 'E')
				g->e++;
			j++;
		}
		i++;
		j = 0;
	}
}

static void sl_bt(t_game *g, int i, int j)
{
	while (g->mapcpy[i][j] != '1' && g->mapcpy[i][j] != 'X')
	{
		if (g->mapcpy[i][j] == 'C')
			g->c--;
		else if (g->mapcpy[i][j] == 'E')
			g->e--;
		g->mapcpy[i][j] = 'X';
		sl_bt(g, i + 1, j);
		sl_bt(g, i - 1, j);
		sl_bt(g, i, j + 1);
		sl_bt(g, i, j - 1);
	}
}

void sl_map_backtracking(t_game *g)
{
	sl_map_count_rows_cols(g);
	sl_bt_starting(g);
	ft_printf("INFO: Player position	(%d,%d)\n", g->p_row, g->p_col);
	sl_bt(g, g->p_row, g->p_col);

	for (size_t i = 0; g->mapcpy[i]; i++){
		ft_printf("%s\n", g->mapcpy[i]);
	}
	if (g->c != 0)
		ft_printf("Map does not have a valid path.\n");
	if (g->e != 0)
		ft_printf("Map does not have a valid path.\n");
}