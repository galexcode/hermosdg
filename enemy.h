#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "definitions.h"

#endif // ENEMY_H_INCLUDED

void enemyMov(int gMap[][MAP_SIZE])
{
    int x, y;
    for (int i = 0; i < ENEMY_NR; i++ )
    {
        switch (entity[i].eMovD)
        {
        case MOVE_UP: case MOVE_DOWN:
            x = entity[i].eXpos;
            y = entity[i].eYpos;
            if ((gMap[y-1][x] == FLOOR && entity[i].eMovD == MOVE_UP) || gMap[y+1][x] == WALL)
            {
                entity[i].eMovD = MOVE_UP;
                entity[i].eYpos = entity[i].eYpos -1;
            }
            else
            if ((gMap[y+1][x] == FLOOR && entity[i].eMovD == MOVE_DOWN) || gMap[y-1][x] == WALL)
            {
                entity[i].eMovD = MOVE_DOWN;
                entity[i].eYpos = entity[i].eYpos +1;
            }
            break;
        case MOVE_RIGHT: case MOVE_LEFT:
            x = entity[i].eXpos;
            y = entity[i].eYpos;
            if ((gMap[y][x-1] == FLOOR && entity[i].eMovD == MOVE_LEFT) || gMap[y][x+1] == WALL)
            {
                entity[i].eMovD = MOVE_LEFT;
                entity[i].eXpos = entity[i].eXpos -1;
            }
            else
            if ((gMap[y][x+1] == FLOOR && entity[i].eMovD == MOVE_RIGHT) || gMap[y][x-1] == WALL)
            {
                entity[i].eMovD = MOVE_RIGHT;
                entity[i].eXpos = entity[i].eXpos +1;
            }
            break;

        }
    }
}

