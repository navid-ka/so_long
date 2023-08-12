/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:32:23 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/12 23:29:59 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*bg;
	t_img		*img;
	char		**map;
	char		**mapcpy;
	int			h;
	int			w;
	int			e;
	int			c;
	int			coin;
	int			mov;
	int			h_w;
	int			w_w;
	int			p_col;
	int			p_row;
	int			col;
	int			row;
}	t_game;


#endif