/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parse_rect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:15:05 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/01 19:34:03 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_map_parse_rect(t_game *g)
{
	g->x = 0;
	g->y = 0;
	while (g->map[g->y])
	{
		while (g->map[g->y][g->x])
			g->x++;
		g->y++;
	}
	ft_printf("MATRIX\nlength of g->y:	%d\n", g->y);
	ft_printf("length of g->x:	%d\n", g->x);
	if (g->x == g->y)
		return (0);
	else
		return (1);
}
