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


void print_(t_game *g) {
    ft_printf("Game Structure:\n");
    ft_printf("Rows: %d, Cols: %d\n", g->row, g->col);
    ft_printf("Player Start Position: (%d, %d)\n", g->p_row, g->p_col);
    ft_printf("Total 'C': %d\n", g->c);

    ft_printf("Map:\n");
    for (int i = 0; i < g->row; i++) {
        for (int j = 0; j < g->col; j++) {
            ft_printf("%c", g->mapcpy[i][j]);
        }
        ft_printf("\n");
    }
}

static bool	sl_bt_is_valid(t_game *g, int i, int j)
{
	return (g->mapcpy[i][j] != '1' && (i >= 0) && (j >= 0));
}

void	sl_bt_starting(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g->c = 0;
	g->p_row = 0;
	g->p_col = 0;
	ft_printf("p_row==%d\n", 420);
	while (g->mapcpy[i])
	{
		while (g->mapcpy[i][j])
		{
			if (g->mapcpy[i][j] == 'P')
			{
				g->p_row = i;
				ft_printf("p_row==%d\n", g->p_row);
				g->p_col = j;
			}
			if (g->mapcpy[i][j] == 'C')
				g->c++;
			j++;
		}
		i++;
	}
}

int	sl_map_backtrack(t_game *g, int i, int j)
{
	int			k;
	static char	c = 'V';

	print_(g);
	k = -1;
	if (g->mapcpy[i][j] == 'E' && g->c == 0)
		return (1);
	if (g->mapcpy[i][j] == 'C')
		g->c--;
	if (g->mapcpy[i][j] != 'E')
		g->mapcpy[i][j] = c;
	while (++k < 4)
	{
		g->row = i;
		g->col = j;
		if (sl_bt_is_valid(g, g->row, g->col)
			&& g->mapcpy[g->row][g->col] != c)
			if (sl_map_backtrack(g, g->row, g->col))
				return (1);
	}
	if (g->c == 0 && c != 'X')
	{
		c = 'X';
		return (sl_map_backtrack(g, g->row, g->col));
	}
	return (0);
}

void	sl_map_backtracking(t_game *g)
{
	sl_bt_starting(g);
	ft_printf("x==%d y==%d\n coins===%d\n", g->p_row, g->p_col, g->c);
	if (sl_map_backtrack(g, g->p_row, g->p_col) == 0)
		ft_printf("Map does not have a valid path");
}
