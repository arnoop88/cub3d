/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:20:13 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/27 16:38:15 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_str_array(char **array, int size)
{
	int	i;

	i = -1;
	while (++i <= size)
		array[i] = NULL;
}

void	init_prg(t_prg *prg)
{
	prg->mlx = (t_mlx *)malloc(sizeof (t_mlx));
	prg->player = (t_pc *)malloc(sizeof (t_pc));
	prg->ray = (t_ray *)malloc(sizeof (t_ray));
	prg->img = (t_img *)malloc(sizeof (t_img));
	if (!prg->mlx || !prg->player || !prg->ray || !prg->img)
		exit_error(NULL, prg);
	prg->player->dir = (t_point *)malloc(sizeof (t_point));
	prg->player->left_corner = (t_point *)malloc(sizeof (t_point));
	prg->player->right_corner = (t_point *)malloc(sizeof (t_point));
	prg->player->hit_box_center = (t_point *)malloc(sizeof (t_point));
	prg->player->hit_box_left = (t_point *)malloc(sizeof (t_point));
	prg->player->hit_box_right = (t_point *)malloc(sizeof (t_point));
	prg->player->center = (t_point *)malloc(sizeof (t_point));
	prg->ray->start = (t_point *)malloc(sizeof (t_point));
	prg->ray->end = (t_point *)malloc(sizeof (t_point));
	if (!prg->player->dir || !prg->player->left_corner  || !prg->player->right_corner || !prg->player->center \
		|| !prg->ray->start || !prg->ray->end || !prg->player->hit_box_center || !prg->player->hit_box_left || !prg->player->hit_box_right)
		exit_error(NULL, prg);
	prg->north_img = 0;
	prg->south_img = 0;
	prg->west_img = 0;
	prg->east_img = 0;
	init_int_array(prg->floor_vals, RGB_ARRAY);
	init_int_array(prg->ceiling_vals, RGB_ARRAY);
	prg->camara_x = 0;
	prg->camara_y = 0;
	prg->error_msg = NULL;
	prg->map = NULL;
	prg->map_h = 0;
	prg->map_w = 0;
	errno = 0;
}