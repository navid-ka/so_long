/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_var_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:25:20 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/14 12:25:07 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_var_init(t_game *g)
{
	g->h = 0;
	g->w = 0;
	g->e = 0;
	g->c = 0;
	g->coin = 0;
	g->mov = 1;
	g->h_w = 0;
	g->w_w = 0;
	g->p_col = 0;
	g->p_row = 0;
	g->col = 0;
	g->row = 0;
}
