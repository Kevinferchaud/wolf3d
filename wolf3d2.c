/*
** wireframe2.c for emacs in /home/kevin.ferchaud/wireframe
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Dec 11 12:39:58 2016 ferchaud kevin
** Last update Tue Jan 10 16:10:55 2017 ferchaud kevin
*/

#include "my.h"

sfRenderWindow          *create_window(char *name)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = 1280;
  mode.height = 720;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

t_my_framebuffer         *my_framebuffer_create(int awidth, int aheight)
{
  int                    i;
  sfUint8                *apixels;
  t_my_framebuffer       *res;

  res = malloc(sizeof(*res));
  apixels = malloc(awidth * aheight * 4 * sizeof(*apixels));
  if (apixels == NULL)
    return (NULL);
  i = -1;
  while (++i < awidth * aheight * 4)
    apixels[i] = 0;
  res->pixels = apixels;
  res->width = awidth;
  res->height = aheight;
  return (res);
}

sfColor         *set_color(int r, int g, int b, int a)
{
  sfColor       *color;

  color = malloc(sizeof(*color));
  if (color == NULL)
    return (NULL);
  color->r = r;
  color->g = g;
  color->b = b;
  color->a = a;
  return (color);
}
