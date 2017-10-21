#include "wolf.h"
// #define MAPWIDTH 24	/*! def Nombre de colonnes de la carte de jeu */
// #define MAPHEIGHT 24 /*! def Nombres de lignes de la carte de jeu */
// #define WINX 512 /*! def Nombres de lignes de la carte de jeu */
// #define WINY 384 /*! def Nombres de lignes de la carte de jeu */

// static int worldMap[mapWidth][mapHeight]=
// {
// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
// {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };


// void    loop(t_val *v)
// {
//       ft_putendlcolor("loop()", MAGENTA);
//     refresh(v);
//     mlx_hook(v->win, 2, 0, event, v);
//     mlx_hook(v->win, 17, 0, clea, v);
//     mlx_loop(v->mlx);
// }

// void  refresh(t_val *v)
// {
//        ft_putendlcolor("refresh()", MAGENTA);
//     int i;

//     i = 0;
//     while (i < WINX * WINY - 1)
//       v->data[i++] = 0;
//     raycasting(v);
//     mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
// }

// /*
// ** Free all the tabs needed
// */

// int   clea(t_val *v)
// {
//       ft_putendlcolor("clean()", MAGENTA);
//   mlx_destroy_window(v->mlx, v->win);
//   mlx_destroy_image(v->mlx, v->img);
//   exit(0);
//   return (0);
// }

/*
** Event for moving up and down
*/

// void    updown(int k, t_val *v)
// {
//       ft_putendlcolor("updown()", MAGENTA);
//             ft_putendl("posx avant = ");
//             ft_putnbrendl(v->posX);
//             ft_putendl("posy avant = ");
//             ft_putnbrendl(v->posY);
//             ft_putendl("dirx * speed = ");
//             ft_putnbrendl(v->dirX * v->speed);
//   if (k == 126)
//   {
//       if(!worldMap[(int)(v->posX + v->dirX * v->speed)][(int)(v->posY)])
//         v->posX += v->dirX * v->speed;
//       if(!worldMap[(int)(v->posX)][(int)(v->posY + v->dirY * v->speed)])
//         v->posY += v->dirY * v->speed;
//   }
//   else if (k == 125)
//   {
//       if(!worldMap[(int)(v->posX - v->dirX * v->speed)][(int)(v->posY)])
//         v->posX -= v->dirX * v->speed;
//       if(!worldMap[(int)(v->posX)][(int)(v->posY - v->dirY * v->speed)])
//         v->posY -= v->dirY * v->speed;
//   }
//             ft_putendl("posx apres = ");
//             ft_putnbrendl(v->posX);
//             ft_putendl("posy apres = ");
//             ft_putnbrendl(v->posY);
//   refresh(v);
// }
// /*
// ** Event for moving left and right
// */

// void    leftright(int k, t_val *v)
// {
//       ft_putendlcolor("leftright()", MAGENTA);
//   if (k == 124)
//   {
//       v->oldDirX = v->dirX;
//       v->dirX = v->dirX * cos(-v->rot) - v->dirY * sin(-v->rot);
//       v->dirY = v->oldDirX * sin(-v->rot) + v->dirY * cos(-v->rot);
//       v->oldPlaneX = v->planeX;
//       v->planeX = v->planeX * cos(-v->rot) - v->planeY * sin(-v->rot);
//       v->planeY = v->oldPlaneX * sin(-v->rot) + v->planeY * cos(-v->rot);
//   }
//   else if (k == 123)
//   {
//       v->oldDirX = v->dirX;
//       v->dirX = v->dirX * cos(v->rot) - v->dirY * sin(v->rot);
//       v->dirY = v->oldDirX * sin(v->rot) + v->dirY * cos(v->rot);
//       v->oldPlaneX = v->planeX;
//       v->planeX = v->planeX * cos(v->rot) - v->planeY * sin(v->rot);
//       v->planeY = v->oldPlaneX * sin(v->rot) + v->planeY * cos(v->rot);
//   }
//   refresh(v);
// }

// /*
// ** Redirect the events and show/hide menus
// */

// int   event(int k, void *param)
// {
//       ft_putendlcolor("event()", MAGENTA);
//       ft_putstr("k = ");
//       ft_putnbrendl(k);
//   t_val *v;

//             // ft_putendl("POSY = ");
//             // ft_putnbrendl(v->posY);    
//   v = (t_val *)param;
//   if (k == 126 || k == 125)
//     updown(k, v);
//   else if (k == 124 || k == 123)
//     leftright(k, v);
//   return (0);
// }

// void    init_v(t_val *v, int x)
// {
//         // ft_putendlcolor("init_v()", MAGENTA);
//       v->cameraX = 2 * x / (double)WINX - 1; 
//       v->rayPosX = v->posX;         
//       v->rayPosY = v->posY;                 
//       v->rayDirX = v->dirX + v->planeX * v->cameraX;
//       v->rayDirY = v->dirY + v->planeY * v->cameraX;
//       v->mapX = (int)v->rayPosX;
//       v->mapY = (int)v->rayPosY;
//       v->dist2MurX = sqrt(1 + (v->rayDirY * v->rayDirY) / (v->rayDirX * v->rayDirX)); 
//       v->dist2MurY = sqrt(1 + (v->rayDirX * v->rayDirX) / (v->rayDirY * v->rayDirY)); 
//       v->touche = 0; 
// }

void   raycasting(t_val *v)
{
      ft_putendlcolor("raycasting()", MAGENTA);
  int w = WINX;
  int h = WINY;
  // double time = 0; 
  // double oldTime = 0;

    for(int x = 0; x < w; x++)
    {
      init_v(v, x);
      if (v->rayDirX < 0) 
      {
        v->etapeX = -1;
        v->distMurX = (v->rayPosX - v->mapX) * v->dist2MurX; 
      }
      else 
      {
        v->etapeX = 1;
        v->distMurX = (v->mapX + 1.0 - v->rayPosX) * v->dist2MurX; 
      }
      if (v->rayDirY < 0)
      {
        v->etapeY = -1;
        v->distMurY = (v->rayPosY - v->mapY) * v->dist2MurY;
      }
      else
      {
        v->etapeY = 1;
        v->distMurY = (v->mapY + 1.0 - v->rayPosY) * v->dist2MurY;
      }
      while (v->touche == 0)
      {
        if (v->distMurX < v->distMurY)
        {
          v->distMurX += v->dist2MurX;
          v->mapX += v->etapeX;
          v->murVertiOuHori = 0; 
        }
        else
        {
          v->distMurY += v->dist2MurY;
          v->mapY += v->etapeY;
          v->murVertiOuHori = 1; 
        }
        if (worldMap[v->mapX][v->mapY] > 0)
            v->touche = 1;
      }
      if (v->murVertiOuHori == 0)
      v->longueurMur = fabs((v->mapX - v->rayPosX + (1 - v->etapeX) / 2) / v->rayDirX);
      else
      v->longueurMur = fabs((v->mapY - v->rayPosY + (1 - v->etapeY) / 2) / v->rayDirY);
      v->hauteurMur = fabs(h / v->longueurMur);
      v->drawStart = -v->hauteurMur / 2 + h / 2;
      if(v->drawStart < 0)v->drawStart = 0;
      v->drawEnd = v->hauteurMur / 2 + h / 2;
      if(v->drawEnd >= h)v->drawEnd = h - 1;
      if(worldMap[v->mapX][v->mapY] == 0)
        v->color = 0;
      else if(worldMap[v->mapX][v->mapY] == 1)
        v->color = 0xff0000;
      else if(worldMap[v->mapX][v->mapY] == 2)
        v->color = 0x00ff00;
      else if(worldMap[v->mapX][v->mapY] == 3)
        v->color = 0x0000ff;
      else if(worldMap[v->mapX][v->mapY] == 4)
        v->color = 0x000fff;
      else if(worldMap[v->mapX][v->mapY] == 5)
        v->color = 0x0ffff0;
      // if (murVertiOuHori == 1)
      // {
      //     v->colorR /= 2;
      //     v->colorB /= 2;
      //     v->colorG /= 2;
      // }
      // v->color = 0;
      // v->color = (v->color >> 24 | v->colorR);
      // v->color = (v->color >> 16 | v->colorG);
      // v->color = (v->color >> 8 | v->colorB);
      // verLine(x, v->drawStart, v->drawEnd, v->color);
      int j;
      j = v->drawStart;
        while (j < v->drawEnd)
        {
            if (x > WINX || x < 0 || j > WINY || j < 0)
               ;
             else
               v->data[(int)(j++ * WINX + x)] = v->color;
        }
    }
}

// int    main()
// {
//   t_val v;

//   v.color = 0;
//   v.posX = 2;
//   v.posY = 2;
//   v.dirX = -1;
//   v.dirY = 0;
//   v.planeX = 0;
//   v.planeY = 0.66;
//   v.bpp = 0;
//   v.endian = 0;
//   v.sizeline = 0;
//   v.rot = 0.12; 
//   v.speed = 0.1;
//   v.longueurMur = 0;
//   v.murVertiOuHori = 0; 
//   v.etapeX = 0; 
//   v.etapeY = 0; 
//   v.distMurX = 0; 
//   v.distMurY = 0; 
//   v.mlx = mlx_init();
//   v.win = mlx_new_window(v.mlx, WINX, WINY, "Wolf3D");
//   v.img = mlx_new_image(v.mlx, WINX, WINY);
//   v.data = (int*)mlx_get_data_addr(v.img, &v.bpp, &v.sizeline, &v.endian);
//   loop(&v);
//   return (0);
// }























