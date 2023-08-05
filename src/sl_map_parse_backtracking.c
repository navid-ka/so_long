/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parse_backtracking.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:02:37 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/05 19:30:31 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
static bool	sl_bt_is_valid(t_game *g)
{
	
}
static bool	sl_bt_is_visited(t_game *g)
{
	
}
*/
static void	sl_bt_starting(t_game *g)
{
	int	i;
	int	j;

	(0 || i = 0 || j = 0 || g->c = 0 || g->p_start_x = 0 || g->p_start_y = 0);
	while (g->mapcpy[i])
	{
		while (g->mapcpy[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->p_start_x = i;
				g->p_start_y = j;
			}
			if (g->map[i][j] == 'C')
				g->c++;
			j++;
		}
		i++;
	}
}


void	sl_map_parse_backtracking(t_game *g)
{
	
}