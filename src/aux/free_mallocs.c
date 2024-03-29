/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mallocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:20:02 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/11 10:23:11 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void free_player(t_pc * player)
{
	if (player)
	{
		if (player->dir)
			free(player->dir);
		if (player->left_corner)
			free(player->left_corner);
		if (player->right_corner)
			free(player->right_corner);
		if (player->center)
			free(player->center);
		if (player->hit_box_center)
			free(player->hit_box_center);
		if (player->hit_box_left)
			free(player->hit_box_left);
		if (player->hit_box_right)
			free(player->hit_box_right);		
		free(player);
	}
}

void free_ray(t_ray *r)
{
	if (r)
	{
		if (r->end)
			free(r->end);
		if (r->start)
			free(r->start);
		free(r);
	}
}

void free_img(t_img *img)
{
	if (img)
		free(img);
}

void	free_mallocs(t_prg *p)
{
	free_2d_array((void **)p->map);
	if (p->mlx)
		free(p->mlx);
	free_player(p->player);
	free_ray(p->ray);
	free_img(p->img);
}
