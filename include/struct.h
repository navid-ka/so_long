/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:32:23 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/07/27 14:15:42 by nkeyani-         ###   ########.fr       */
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
	void		*bg;
	char		*asset;
	int			h;
	int			w;
	int			h_w;
	int			w_w;
	uint16_t	x;
	uint16_t	y;
}	t_game;

#endif