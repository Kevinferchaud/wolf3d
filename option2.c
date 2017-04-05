/*
** option2.c for emacs in /home/kevin.ferchaud/wolf3d
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Jan 15 16:06:05 2017 ferchaud kevin
** Last update Sun Jan 15 19:37:19 2017 ferchaud kevin
*/

#include "my.h"

int             largmap(char *map)
{
  int           cpt;

  cpt = 0;
  while (map[cpt] != '\n')
    cpt++;
  return (cpt);
}

int             longmap(char *map)
{
  int           cpt;
  int           val;

  cpt = -1;
  val = 0;
  while (map[++cpt] != '\0')
    if (map[cpt] == '\n')
      val++;
  return (val);
}

sfVector2f              newpos(sfVector2f pos, sfVector2f save, int **map,
			       sfRenderWindow *window)
{
  sfVector2i    from;
  sfVector2i    to;
  int           largx;

  largx = -1;
  if (map[(int)save.y][(int)save.x] == 0)
    pos = save;
  if (save.y >= 18 && save.y <= 19 &&
      save.x >= 2 && save.x < 4)
    sfRenderWindow_close(window);
  return (pos);
}
