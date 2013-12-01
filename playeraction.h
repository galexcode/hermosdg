#ifndef PLAYERACTION_H_INCLUDED
#define PLAYERACTION_H_INCLUDED

#include "definitions.h"
#include <windows.h>

#endif // PLAYERACTION_H_INCLUDED


void openDoor(int gMap[][MAP_SIZE], int x, int y)
{
    if ( gMap[y][x+1] == DOOR)
    {
        gMap[y][x]   = FLOOR;
        gMap[y][x+1] = FLOOR;
    }
    else
    if ( gMap[y+1][x] == DOOR)
    {
        gMap[y][x]   = FLOOR;
        gMap[y+1][x] = FLOOR;
    }
}

int movePlayer(int gMap[][MAP_SIZE], int* PlayerX, int* PlayerY, int* pl_points)
{
    char input;
    cout << "Move player (w/a/s/d), q_uit, or r_eload\n>";
    //cout << (int)'w' << " " << (int)'a' << " " << (int)'s' << " " << (int)'d';
    cin >> input;

    if ( input == 'q') return QUIT_GAME;

    switch ((int)input)
    {
    case KEY_UP_W:
        if (gMap[*PlayerY-1][*PlayerX] == FLOOR || gMap[*PlayerY-1][*PlayerX] == POINTS_ENT) *PlayerY= *PlayerY-1;
        else
        if (gMap[*PlayerY-1][*PlayerX] == KEY  )
        {
            *PlayerY= *PlayerY-1;
            openDoor(gMap, *PlayerX, *PlayerY);
            *pl_points = *pl_points +1;
        }
        break;
    case KEY_LEFT_A:
        if (gMap[*PlayerY][*PlayerX-1] == FLOOR || gMap[*PlayerY][*PlayerX-1] == POINTS_ENT) *PlayerX = *PlayerX-1;
        else
        if (gMap[*PlayerY][*PlayerX-1] == KEY  )
        {
            *PlayerX = *PlayerX -1;
            openDoor(gMap, *PlayerX, *PlayerY);
            *pl_points = *pl_points +1;
        }
        break;
    case KEY_DOWN_S:
        if (gMap[*PlayerY+1][*PlayerX] == FLOOR || gMap[*PlayerY+1][*PlayerX] == POINTS_ENT) *PlayerY = *PlayerY +1;
        else
        if (gMap[*PlayerY+1][*PlayerX] == KEY  )
        {
            *PlayerY = *PlayerY +1;
            openDoor(gMap, *PlayerX, *PlayerY);
            *pl_points = *pl_points +1;
        }
        break;
    case KEY_RIGHT_D:
        if (gMap[*PlayerY][*PlayerX+1] == FLOOR || gMap[*PlayerY][*PlayerX+1] == POINTS_ENT) *PlayerX = *PlayerX +1;
        else
        if (gMap[*PlayerY][*PlayerX+1] == KEY  )
        {
            *PlayerX = *PlayerX +1;
            openDoor(gMap, *PlayerX, *PlayerY);
            *pl_points = *pl_points +1;
        }
        break;
    }

    if ( gMap[*PlayerY][*PlayerX] == POINTS_ENT )
    {
        gMap[*PlayerY][*PlayerX] = FLOOR;
        *pl_points = *pl_points +1;
    }

    for (int ennr = 0; ennr < ENEMY_NR; ennr++)
    {
        if (*PlayerX == entity[ennr].eXpos && *PlayerY == entity[ennr].eYpos)
            return DEAD_GAME;
    }

    if ( input == 'r' || (*PlayerX == MAP_SIZE-2 && *PlayerY == MAP_SIZE-2))
    {
        Sleep(100);
        return RELOAD_GAME;
    }
    return CONT_GAME;
}

