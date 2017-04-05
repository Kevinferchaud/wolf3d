/*
** drawsaber.c for emacs in /home/kevin.ferchaud/wolf3d
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Jan 15 15:47:44 2017 ferchaud kevin
** Last update Sun Jan 15 18:44:22 2017 ferchaud kevin
*/

#include "my.h"

void            my_draw_boum(t_my_framebuffer *b)
{
  int           largx;
  sfVector2i    to;
  sfVector2i    from;

  largx = 629;
  while (++largx <= 650)
    {
      from.x = largx;
      from.y = 380;
      to.y = 620;
      to.x = largx;
      my_draw_line(b, to, from, sfBlue);
    }
}

void            my_draw_red(t_my_framebuffer *b)
{
  int           largx;
  sfVector2i    to;
  sfVector2i    from;

  largx = 629;
  while (++largx <= 650)
    {
      from.x = largx;
      from.y = 380;
      to.y = 620;
      to.x = largx;
      my_draw_line(b, to, from, sfRed);
    }
}

void            drawsaber(int lx, sfVector2i from, sfVector2i to,
			  t_my_framebuffer *b)
{
  if (lx >= 630 && lx <= 650)
    {
      from.x = lx;
      from.y = 620;
      to.x = from.x;
      to.y = 720;
      my_draw_line(b, from, to, sfWhite);
    }
  else
    {
      from.x = lx;
      from.y = 660;
      to.x = from.x;
      to.y = 720;
      my_draw_line(b, from, to, sfBlack);
    }
  if (lx >= 635 && lx <= 645)
    {
      from.x = lx;
      from.y = 640;
      to.x = from.x;
      to.y = 700;
      my_draw_line(b, from, to, sfWhite);
    }
}
