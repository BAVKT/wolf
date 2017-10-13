/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:17:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 20:28:43 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include "quickcg.h"

using namespace QuickCG;

void    get_color(struct)
{
      if (worldMap[mapX][mapY] == 1)
          ray->color = R;
      else if (worldMap[mapX][mapY] == 2)
          ray->color = G;
      else if (worldMap[mapX][mapY] == 3)
          ray->color = B;
      else if (worldMap[mapX][mapY] == 4)
          ray->color = W;
      else if (worldMap[mapX][mapY] == 5)
          ray->color = Y;
}

int main(int /*argc*/, char */*argv*/[])
{
	int x;

	posX = 22;
	posY = 12;    	//x and y start position
	dirX = -1;
	dirY = 0;     	//initial direction vector
	planeX = 0;
	planeY = 0.66;	//the 2d raycaster version of camera plane
	time = 0;     	//time of current frame
	oldTime = 0;  	//time of previous frame

	screen(512, 384, 0, "WOlf3D");
	while(!done())
	{
		x = -1;
		while(++x < w)
		{
				//calculate ray position and direction
			cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
			rayPosX = posX;
			rayPosY = posY;
			rayDirX = dirX + planeX * cameraX;
			rayDirY = dirY + planeY * cameraX;
				//which box of the map we're in
			mapX = int(rayPosX);
			mapY = int(rayPosY);
				//length of ray from one x or y-side to next x or y-side
			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
			hit = 0;  //was there a wall hit?
				//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (rayPosX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (rayPosY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
					//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
  					sideDistX += deltaDistX;
  					mapX += stepX;
  					side = 0;
				}
				else
				{
  				sideDistY += deltaDistY;
  				mapY += stepY;
  				side = 1;
				}
					//Check if ray has hit a wall
				if (worldMap[mapX][mapY] > 0)
					hit = 1;
			}
  				//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
			if (side == 0)
  				perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
			else
  				perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
  				//Calculate height of line to draw on screen
			ineHeight = (int)(h / perpWallDist);
 				//calculate lowest and highest pixel to fill in current stripe
			drawStart = -lineHeight / 2 + h / 2;
			if(drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)
				drawEnd = h - 1;
			get_color(map[x][y]);
			//give x and y sides different brightness
			if (side == 1) {color = color / 2;}
			//draw the pixels of the stripe as a vertical line
			verLine(x, drawStart, drawEnd, color);
    }
    //timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    readKeys();
    //move forward if no wall in front of you
    if (keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if (keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if (keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
  }
}


