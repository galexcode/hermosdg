#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "definitions.h"

#endif // GENERATOR_H_INCLUDED

bool ReturnToExit(int gMap[][MAP_SIZE], int x, int y)
{
    if (x == MAP_SIZE-2)
    {
        while (y < MAP_SIZE-1)
            {
                gMap[y][x] = FLOOR;
                y++;
            }
            return true;
    }
    else
    if (y == MAP_SIZE-2)
    {

        while (x < MAP_SIZE-1)
            {
                gMap[y][x] = FLOOR;
                x++;
            }
            return true;
    }
    else return false;
}

void smoothMap(int gMap[][MAP_SIZE])
{
    for (int y = 1; y < MAP_SIZE-1; y++)
        for (int x = 1; x < MAP_SIZE-1; x++)
        {
            if (gMap[y][x] == FLOOR && gMap[y-1][x-1] == FLOOR) gMap[y-1][x] = FLOOR;
            if (gMap[y][x] == FLOOR && gMap[y-1][x+1] == FLOOR) gMap[y-1][x] = FLOOR;
            else
            if ( gMap[y][x] == FLOOR  &&
                 gMap[y-1][x] == WALL &&
                 gMap[y][x-1] == WALL &&
                 gMap[y+1][x] == WALL &&
                 gMap[y][x+1] == WALL   ) gMap[y][x] = WALL;
            else
            if ( gMap[y][x] == POINTS_ENT &&
                 gMap[y-1][x] == WALL     &&
                 gMap[y][x-1] == WALL     &&
                 gMap[y+1][x] == WALL     &&
                 gMap[y][x+1] == WALL       ) gMap[y][x] = WALL;
        }
}

void CreatePath(int gMap[][MAP_SIZE])
{
    srand(time(NULL));

    int x = 1,
        y = 1;
    while ( x < MAP_SIZE-2 && y < MAP_SIZE-2 )
    {
        if (rand() % 2 == 1) x++;
        else y++;
        if (x > 2 && y > 2 && rand() % 10 == 0)
        {
            gMap[y][x] = DOOR;
            if (gMap[y][x-1] == FLOOR) gMap[y][x-1] = KEY;
            else
            if (gMap[y-1][x] == FLOOR) gMap[y-1][x] = KEY;
            else
            if (gMap[y+1][x] == FLOOR) gMap[y+1][x] = KEY;
        }
        else
        if (rand() % 15 == 0)
        {
            gMap[y][x] = POINTS_ENT;
        }
        else gMap[y][x] = FLOOR;
        //gMap[y][x] = (rand() % 10 == 9) ? DOOR : FLOOR;
    }
    ReturnToExit(gMap, x, y);
    smoothMap(gMap);
}

void GenerateMap(int gMap[][MAP_SIZE], int gentype, int* PlayerX, int* PlayerY)
{
    srand(time(NULL));

    for (int i = 0; i < MAP_SIZE; i++)
        for (int j = 0; j < MAP_SIZE; j++)
        {
            gMap[i][j] = WALL;
        }

    for (int i = 1; i < MAP_SIZE-1; i++)
        for (int j = 1; j < MAP_SIZE-1; j++)
        {
            if (rand() % gentype == 1)
                gMap[i][j] = FLOOR;//rand() % 2;
            else
            if (rand() % 20 == 0)
            {
                gMap[i][j] = POINTS_ENT;
            }
        }
    gMap[*PlayerY][*PlayerX] = FLOOR;
}


