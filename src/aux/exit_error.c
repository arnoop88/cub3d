/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:19:52 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/27 16:47:35 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	exit_error(char *error, t_prg *prg)
{
	mlx_destroy_image(prg->mlx->ptr, prg->img->img);
	mlx_destroy_window(prg->mlx->ptr, prg->mlx->window);
	close_imgs_fd(prg);
	free_mallocs(prg);
	if (error)
	{
		ft_printf(STDERR_FILENO, error);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (errno)
		{
			perror("Error");
			exit(errno);
		}
		else
		{
			ft_printf(STDERR_FILENO, prg->error_msg);
			exit(EXIT_FAILURE);
		}
	}
}
