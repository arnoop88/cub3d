/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:25:16 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/09/08 14:11:04 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	validate_map(char *file_name, t_prg *prg)
{
	int	fd;

	if (check_if_invalid_ext(file_name, ".cub", ft_strlen(".cub")))
		exit_error(INCORRECT_FILE, prg);
	if ((errno && (errno != 60)))
		exit_error(NULL, prg);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, prg);
	if (!parse_file(fd, prg) || (errno && (errno != 60)))
	{
		close(fd);
		exit_error(NULL, prg);
	}
	close(fd);
}
