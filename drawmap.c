/*
** drawmap.c for emacs in /home/kevin.ferchaud/wolf3d
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Jan 15 15:44:48 2017 ferchaud kevin
** Last update Sun Jan 15 20:07:13 2017 ferchaud kevin
*/

#include "my.h"

void            drawmap3(sfVector2i from, sfVector2i to, float dist, int lx,
			 t_my_framebuffer *b, int stop)
{
  sfColor       *color3;

  color3 = set_color(15, 60, 20, 255);
  from.y = to.y + (720 / dist);
  to.y = 720;
  from.x = lx;
  to.x = from.x;
  if (sfKeyboard_isKeyPressed(sfKeyM) && stop < 500)
    my_draw_line(b, from, to, *color3);
  else
    my_draw_line(b, from, to, sfBlack);
  if (lx >= 620 && lx <= 660)
    drawsaber(lx, from, to, b);
}

void            drawmap2(sfVector2i from, sfVector2i to, float dist, int lx,
			 t_my_framebuffer *b, int stop)
{
  sfColor       *color;

  color = set_color(107, 71, 41, 255);
  from.y = 720 / 2 - ((720 / dist) / 2);
  to.y = from.y + (720 / dist);
  from.x = lx;
  to.x = from.x;
  if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue && stop < 300)
    my_draw_line(b, from, to, *color);
  else
    my_draw_line(b, from, to, sfBlack);
  if (lx % 80 == 1)
    my_draw_line(b, from, to, sfBlack);
}

void            drawmap(int **map, t_my_framebuffer *buff,
			float dir1, sfVector2f pos, int stop)
{
  int           largx;
  float         dist;
  float         dir;
  sfVector2i    from;
  sfVector2i    to;
  sfVector2i    mapSize;
  sfColor       *color1;

  largx = -1;
  dir = dir1;
  while (++largx != 1280)
    {
      dist = raycast(pos, dir, map, mapSize) *
	cos((dir1 + 30 - dir) * M_PI/180);
      drawmap2(from, to, dist, largx, buff, stop);
      to.y = 720 / 2 - ((720 / dist) / 2);
      from.y = 0;
      from.x = largx;
      to.x = from.x;
      my_draw_line(buff, from, to, sfBlack);
      drawmap3(from, to, dist, largx, buff, stop);
      dir += 0.046875;
    }
}
