#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

#include "definitions.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

#endif // LOAD_H_INCLUDED

fstream fileload("map1.txt", ios::in);


void loadFunc(int gMap[][MAP_SIZE])
{
    int x, y;
    for ( y = 0; y < MAP_SIZE; y++)
        for ( x = 0; x < MAP_SIZE; x++)
        {
            fileload >> gMap[y][x];
        }
}

void loadEnemy(int gMap[][MAP_SIZE], struct Enemy entitate[])
{
    int x, y, d;
    srand(time(NULL));
    for (int i = 0; i < ENEMY_NR; i++)
    {
        fileload >> x;
        entitate[i].eXpos = x;
        fileload >> y;
        entitate[i].eYpos = y;
        fileload >> d;
        entitate[i].eMovD = d;

        gMap[y][x] = 5;
    }
    fileload.close();
}


