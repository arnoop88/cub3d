/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:05:54 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/28 13:24:20 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <libft.h>
# include <error_messages.h>
# include <keys.h>
# include <mlx.h>
# include <config.h>
# include <float.h>

# ifndef RGB_ARRAY
#  define RGB_ARRAY 3
# endif

#define RGB_GREY 0x808080
#define RGB_DARK_RED 0x880000
#define RGB_LIGHT_RED 0xA80000
#define RGB_BLUE 0x6495ED


typedef struct s_point
{
	int x;
	int y;
}	t_point;


typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	double	hit_box_angle;
	t_point	*hit_box_center;
	t_point *hit_box_left;
	t_point *hit_box_right;
	t_point *dir;
	t_point	*left_corner;
	t_point	*right_corner;
	t_point	*center;

}	t_pc;

#define PLAYER(prg) (prg->player)
#define PLAYER_X(prg) (prg->player->x)
#define PLAYER_Y(prg) (prg->player->y)
#define PLAYER_DIR_X(prg) (prg->player->dir->x)
#define PLAYER_DIR_Y(prg) (prg->player->dir->y)
#define PLAYER_LEFT_X(prg) (prg->player->left_corner->x)
#define PLAYER_LEFT_Y(prg) (prg->player->left_corner->y)
#define PLAYER_RIGHT_X(prg) (prg->player->right_corner->x)
#define PLAYER_RIGHT_Y(prg) (prg->player->right_corner->y)
#define PLAYER_CENTER(prg) (prg->player->center)
#define PLAYER_CENTER_X(prg) (prg->player->center->x)
#define PLAYER_CENTER_Y(prg) (prg->player->center->y)
#define PLAYER_ANGLE(prg) (prg->player->angle)
#define HIT_BOX_CENTER(prg) (prg->player->hit_box_center)
#define HIT_BOX_LEFT(prg)	(prg->player->hit_box_left)
#define HIT_BOX_RIGHT(prg)	(prg->player->hit_box_right)
#define HIT_BOX_ANGLE(prg) (prg->player->hit_box_angle)

typedef struct s_ray
{
	t_point *start;
	t_point *end;

	int		mapX;		
	int		mapY;		
	double	camera;		
	double	rayDirX;	
	double	rayDirY;	
	double	sideDistX;	
	double	sideDistY;	
	double	deltaDistX;	
	double	deltaDistY;	
	double	wallDist;	
	int		stepX;		
	int		stepY;		
	int		hit;		
	int		side;		

	double 	dir_x;
	double	dir_y;
	double	distance;
	double	delta_dist_x;
	double	delta_dist_y;
	double	map_step_x;
	double	map_step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
} t_ray;

#define RAY_START_X(prg) (prg->ray->start->x)
#define RAY_START_Y(prg) (prg->ray->start->y)
#define RAY_END_X(prg) (prg->ray->end->x)
#define RAY_END_Y(prg) (prg->ray->end->y)
#define RAY_DIRECTION_X(prg) (prg->ray->dir_x)
#define RAY_DIRECTION_Y(prg) (prg->ray->dir_y)
#define RAY_DELTA_X(prg) (prg->ray->delta_dist_x)
#define RAY_DELTA_Y(prg) (prg->ray->delta_dist_y)
#define RAY_STEP_X(prg) (prg->ray->map_step_x)
#define RAY_STEP_Y(prg) (prg->ray->map_step_y)
#define RAY_DIST_X(prg) (prg->ray->side_dist_x)
#define RAY_DIST_Y(prg) (prg->ray->side_dist_y)
#define RAY_MAP_X(prg)	(prg->ray->map_x)
#define RAY_MAP_Y(prg)	(prg->ray->map_y)
typedef struct  t_s_mlx
{
    void    *ptr;
    void    *window;
}   t_mlx;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_prg
{
	int		north_img; //0
	int		south_img; // 1
	int		west_img; //2
	int		east_img; //3
	int		floor_vals[4];
	int		ceiling_vals[4];
	double	camara_x;
	double	camara_y;
	double	plane_x;
	double	plane_y;
	int		map_h;
	int		map_w;
	char	**map;
	char	*error_msg;
    t_mlx   *mlx;
	t_img	*img;	//
	t_pc	*player;
	t_ray	*ray;
}	t_prg;

#define MLX_PTR(prg) (prg->mlx->ptr)
#define MLX_WIN(prg) (prg->mlx->window)
#define MAP(prg) (prg->map)

#define CAMARA_X(prg) (prg->camara_x)
#define CAMARA_Y(prg) (prg->camara_y)

// AUX FUNCTIONS 
bool	print_error(char *error);
void	init_int_array(int *array, int size);
void	exit_success(t_prg *p);
void	exit_error(char *error, t_prg *prg);
void	close_imgs_fd(t_prg *prg);
int		check_if_invalid_ext(char *file_name, \
		char *extension, int extension_len);
bool	is_new_line(char *element);
void	free_mallocs(t_prg *p);
int		ft_max(int a, int b);

int is_inside_map(int x, int y, t_prg *prg);


// CHECK FILE FUNCTIONS
void	validate_map(char *file_name, t_prg *prg);
bool	parse_file(int fd, t_prg *prg);


// GAME FUNCTIONS

void	get_hooks(t_prg *prg);
void	update_window(t_prg *prg);
int		make_move(t_prg *prg, int dir, int side);
void	cast_ray(t_prg *prg);
void	draw_map(t_prg *prg);
void	raycaster(t_prg *prg);			//
void	ray_to_img(t_prg *prg, int i);	//



// MINI MAP FUNCTIONS

void	draw_ray(t_prg *p);

//BONUS

int		rotate_player(t_prg *prg, int dir);
void	draw_map(t_prg *prg);
void	rotate_point(t_point *point, t_point *center, int dir );
void	move_triangle(t_prg *prg, int dir, double x, double y);
int		open_door(t_prg *prg);



// INIT PRG

void	init_prg(t_prg *prg);
#endif
