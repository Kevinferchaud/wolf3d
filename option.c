/*
** option.c for emacs in /home/kevin.ferchaud/wolf3d
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Jan 15 16:00:41 2017 ferchaud kevin
** Last update Sun Jan 15 16:28:29 2017 ferchaud kevin
*/

#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int		**grepsuite(int val, char *map, int **bouf, int cpt)
{
  int		val3;
  static int	val2;

  val3 = -1;
  bouf[val] = malloc(sizeof(int) * cpt);
  while (map[++val2] != '\n')
    {
      bouf[val][++val3] = map[val2] - '0';
      my_putchar(bouf[val][val3] + '0');
    }
  my_putchar('\n');
}
int     **grepintmap(char *map)
{
  int   cpt;
  int   cpt2;
  int   val;
  int   val2;
  int   **bouf;

  cpt = -1;
  val = 0;
  cpt2 = 1;
  while (map[++cpt] != '\0')
    if (map[cpt] == '\n')
      cpt2++;
  bouf = malloc(sizeof(int*) * cpt2);
  cpt = -1;
  while (map[++cpt] != '\n');
  val2 = -1;
  val = -1;
  while (++val < cpt2 - 1)
    grepsuite(val, map, bouf, cpt);
  return (bouf);
}

int     **grepmap(char *name)
{
  int   fd;
  int   cpt;
  char  buf[2];
  char  *buff;
  int   horiz;
  int   vert;
  int   **bouf;

  cpt = 0;
  fd = open(name, O_RDONLY);
  while (read(fd, buf, 1) != 0)
    cpt++;
  buff = malloc(sizeof(char) * (cpt + 1));
  close(fd);
  fd = open(name, O_RDONLY);
  read(fd, buff, cpt);
  write(fd, buff, cpt);
  buff[cpt] = '\0';
  close(fd);
  bouf = grepintmap(buff);
  return (bouf);
}
