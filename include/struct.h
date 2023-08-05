/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:32:23 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/05 17:10:55 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*img;
	void		*p;
	char		**map;
	char		**mapcpy;
	void		*bg;
	char		*asset;
	int			h;
	int			w;
	int			e;
	int			c;
	int			pl;
	int			h_w;
	int			w_w;
	int			p_start_y;
	int			p_start_x;
	int			col;
	int			row;
}	t_game;

#endif