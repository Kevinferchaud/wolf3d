/*
** wolf.c for emacs in /home/kevin.ferchaud/bswolf3d
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Dec 21 14:08:39 2016 ferchaud kevin
** Last update Tue Jan 10 15:55:29 2017 ferchaud kevin
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

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	newpos;

  newpos.x = distance * cos(direction * M_PI / 180) + pos.x;
  newpos.y = distance * sin(direction * M_PI / 180) + pos.y;
  return (newpos);
}
