/*
** wolf3d.c for emacs in /home/kevin.ferchaud/wolf3d
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Tue Jan 10 15:27:02 2017 ferchaud kevin
** Last update Sun Jan 15 20:05:36 2017 ferchaud kevin
*/

#include "my.h"
#include <SFML/Window/Mouse.h>

sfUint8         *clear_screen(sfUint8 *pixels, int width, int height)
{
  int           i;

  i = 0;
  while (i < width * height * 4)
    pixels[i++] = 0;
  return (pixels);
}

void		main4(t_my_framebuffer *b, int **map, int dir,
			      sfVector2f pos)
{
  static int		stop;

  stop++;
  b->pixels = clear_screen(b->pixels, 1280, 720);
  drawmap(map, b, dir, pos, stop);
  if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue && stop < 300)
    my_draw_boum(b);
  if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue && stop > 300 && stop < 500)
    my_draw_red(b);
}

void			main3(sfRenderWindow *window, t_my_framebuffer *b,
			      int **map, sfTexture *t, sfSprite *sprite,
			      sfVector2f pos, sfVector2f save)
{
  float			dir;
  sfEvent               key;

  dir = 60;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      main4(b, map, dir, pos);
      pos = newpos(pos, save, map, window);
      while (sfRenderWindow_pollEvent(window, &key))
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	  sfRenderWindow_close(window);
      if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
	dir -= 5;
      if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
	dir += 5;
      if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
	save = move_forward(pos, dir + 30, 0.3);
      if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
	save = move_forward(pos, dir + 210, 0.3);
      sfTexture_updateFromPixels(t, b->pixels, b->width, b->height, 0, 0);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
}
void                    main2(char **av, sfVector2f pos)
{
  sfTexture             *t;
  sfRenderWindow        *window;
  sfSprite              *sprite;
  t_my_framebuffer      *b;
  int			**map;

  window = create_window("Window");
  sprite = sfSprite_create();
  t = sfTexture_create(1280, 720);
  sfSprite_setTexture(sprite, t, sfTrue);
  b = my_framebuffer_create(1280, 720);
  map = grepmap(av[1]);
  main3(window, b, map, t, sprite, pos, pos);
  sfRenderWindow_destroy(window);
}

int                     main(int ac, char **av)
{
  sfVector2f		pos;

  pos.x = 3;
  pos.y = 3;
  if (ac == 2)
    {
      main2(av, pos);
      return (0);
    }
  else
    return (84);
}
