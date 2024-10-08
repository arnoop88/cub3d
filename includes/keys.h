/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:54:03 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/09/07 19:10:54 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# if LINUX_KEYS == 1
#  define KEY_ESC 65307
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LFT 65361
#  define KEY_RGT 65363
#  define KEY_UP 65362
#  define KEY_DOWN 65364
# else
#  define KEY_ESC 53
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LFT 123
#  define KEY_RGT 124
#  define KEY_UP 126
#  define KEY_DOWN 125

# endif

#endif
