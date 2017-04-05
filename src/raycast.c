/*
** raycast.c for emacs in /home/kevin.ferchaud/bswolf3d/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Dec 21 14:39:07 2016 ferchaud kevin
** Last update Fri Jan 20 14:56:21 2017 ferchaud kevin
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
#include "my.h"

float		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapSize)
{
  float		newdist;
  int		ok;
  sfVector2f	pos1;

  ok = 0;
  pos1 = pos;
  newdist = 0;
  while (ok != 1)
    {
      pos = move_forward(pos, direction, newdist);
      newdist += 0.0001;
	if (map[(int)pos.y][(int)pos.x] == 1)
	  ok = 1;
    }
  newdist = sqrtf(((pos.x - pos1.x) * (pos.x - pos1.x)) + \
		  ((pos.y - pos1.y) * (pos.y - pos1.y)));
  return (newdist);
}
