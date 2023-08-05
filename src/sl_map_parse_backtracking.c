/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parse_backtracking.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:02:37 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/05 17:11:20 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	sl_backtracking_is_valid(t_game *g)
{
	
}

static void	sl_backtracking_starting(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->mapcpy[i])
	{
		while (g->mapcpy[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->p_start_x = i;
				g->p_start_y = j;
			}
			j++;
		}
		i++;
	}
}

void	sl_map_parse_backtracking(t_game *g)
{
	
}
