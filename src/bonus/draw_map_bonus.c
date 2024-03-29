#include <cub3d.h>

int side_of_line(t_point *p1, t_point *p2, t_point *p3)
{
  return ((p2->x - p1->x) * (p3->y - p1->y) - (p3->x - p1->x) * (p2->y - p1->y));
}


bool calculate_if_inside_player(t_pc *player, int x, int y)
{
  t_point p3;
  int     side_a_b;
  int     side_b_c;
  int     side_c_a;
  
  p3.x = x;
  p3.y = y;
  side_a_b = side_of_line(player->dir, player->left_corner, &p3);
  side_b_c = side_of_line(player->left_corner, player->right_corner, &p3);
  side_c_a = side_of_line(player->right_corner, player->dir, &p3);

  return ((side_a_b >= 0 && side_b_c >= 0 && side_c_a >= 0) || \
          (side_a_b <= 0 && side_b_c <= 0 && side_c_a <= 0)); 
}

void draw_map(t_prg *prg)
{
  int color = 0xFF0000; // Red for walls
  int y_pos;
  int x_pos; 

  int max_w = (prg->map_w + 1) * TILE_SIZE;
  int max_h = (prg->map_h - 1) * TILE_SIZE;
  printf("max_w %i map w%i\n",max_w,  prg->map_w);
  x_pos = -1;
  for (int x = 0; x < max_w; ++x)
  {
    if (x % (TILE_SIZE) == 0)
      x_pos++;
    y_pos = -1;
    for (int y = 0; y < max_w ; ++y)
    {
      if (y % (TILE_SIZE) == 0)
        y_pos++;     
      if (is_inside_map(x_pos, y_pos, prg))
      {
        if (prg->map[y_pos][x_pos] == '1')
          color = 0xFF0000;
        else if (prg->map[y_pos][x_pos] == '2')
          color = 0x00FF00;
        else if (prg->map[y_pos][x_pos] == '3')
          color = 0x00008B;
        else if (x == PLAYER_CENTER_X(prg) && y == PLAYER_CENTER_Y(prg))
          color = 0x0000FF;
        else if (calculate_if_inside_player(prg->player, x, y))
                  color = 0xFFFF00;
        else
          color = 0xededed ;
      }
      else
        color = 0xededed ;

      //DEBUG GRID
      if (x % (TILE_SIZE) == 0 || y % (TILE_SIZE)  == 0)
        color = 0xFFFFFF;

      mlx_pixel_put(prg->mlx->ptr, prg->mlx->window, x, y, color);

    }
  }
}
