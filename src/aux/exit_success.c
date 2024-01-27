/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_success.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:19:57 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/27 16:46:57 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	exit_success(t_prg *p)
{
	mlx_destroy_image(p->mlx->ptr, p->img->img);
	mlx_destroy_window(p->mlx->ptr, p->mlx->window);
	close_imgs_fd(p);
	free_mallocs(p);
	exit(EXIT_SUCCESS);
}
