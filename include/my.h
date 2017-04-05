/*
** my.h for emacs in /home/kevin.ferchaud/wolf3d/include
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Tue Jan 10 15:15:10 2017 ferchaud kevin
** Last update Sun Jan 15 20:07:29 2017 ferchaud kevin
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct          s_my_framebuffer
{
  sfUint8               *pixels;
  int                   width;
  int                   height;
}                       t_my_framebuffer;

void            my_put_pixel(t_my_framebuffer *a, int b, int c, sfColor d);
void            my_draw_line(t_my_framebuffer *a, sfVector2i b, \
			     sfVector2i c, sfColor color);
sfVector2f      move_forward(sfVector2f pos, float direction, float distance);
float           raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapSize);
sfRenderWindow  *create_window(char *a);
t_my_framebuffer        *my_framebuffer_create(int a, int b);
sfColor         *set_color(int a, int b, int c, int d);
void            drawmap3(sfVector2i from, sfVector2i to, float dist, int lx,
			 t_my_framebuffer *b, int stop);
void            drawmap2(sfVector2i from, sfVector2i to, float dist, int lx,
			 t_my_framebuffer *b, int stop);
void            drawmap(int **map, t_my_framebuffer *buff, \
			float dir1, sfVector2f pos, int a);
void            my_draw_boum(t_my_framebuffer *b);
void            my_draw_red(t_my_framebuffer *b);
void            drawsaber(int lx, sfVector2i from, sfVector2i to, \
			  t_my_framebuffer *b);
int             largmap(char *map);
int             longmap(char *map);
void		my_putchar(char c);
int		**grepintmap(char *map);
int		**grepmap(char *name);
sfVector2f              newpos(sfVector2f pos, sfVector2f save, int **map,
			       sfRenderWindow *window);
