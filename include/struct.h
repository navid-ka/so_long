/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:32:23 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/07/24 16:44:11 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*img;
	void		*player;
	void		*map;
	void		*bg;
	char		*asset;
	int			h;
	int			w;
	int			h_win;
	int			w_win;
	uint16_t	x;
	uint16_t	y;
}	t_game;

#endif