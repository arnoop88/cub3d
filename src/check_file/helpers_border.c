/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:31:43 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/09/07 19:11:02 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "parse_file.h"

void	prepare_parse_vals(t_prg *prg, t_parseer *parse, int i)
{
	if (i > 0)
		parse->prev_len = ft_strlen(prg->map[i - 1]);
	if (prg->map[i + 1])
	{
		parse->next_len = ft_strlen(prg->map[i + 1]);
		parse->next_line = prg->map[i + 1];
	}
	else
	{
		parse->next_len = 0;
		parse->next_line = NULL;
	}
}

bool	set_open_map_error(t_prg *prg)
{
	prg->error_msg = OPEN_MAP;
	return (false);
}

bool	check_zero(t_prg *prg, int i, int j, t_parseer *parse)
{
	if (i == 0 || j == 0)
		return (set_open_map_error(prg));
	else if (!prg->map[i][j + 1] || prg->map[i][j + 1] == ' ')
		return (set_open_map_error(prg));
	else if (parse->next_line && j < parse->next_len && \
			parse->next_line[j] == ' ')
		return (set_open_map_error(prg));
	else if (!parse->next_line || j >= parse->next_len)
		return (set_open_map_error(prg));
	else if (parse->prev_len > 0 && parse->prev_len <= j)
		return (set_open_map_error(prg));
	return (true);
}

bool	check_space(t_prg *prg, int i, int j, t_parseer *parse)
{
	if (prg->map[i][j + 1] && prg->map[i][j + 1] == '0')
		return (set_open_map_error(prg));
	else if (parse->next_line && j < parse->next_len && \
			parse->next_line[j] == '0')
		return (set_open_map_error(prg));
	return (true);
}
