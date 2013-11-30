#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
using namespace std;

#include "definitions.h"


#endif // SCREEN_H_INCLUDED

void RenderG(int gMap[][MAP_SIZE], int PlayerX, int PlayerY, struct Enemy ent[])
{
    system("cls");
    for (int i = 0; i < MAP_SIZE; i++)
    {

        for (int j = 0; j < MAP_SIZE; j++)
        {
            if ( i == PlayerY && j == PlayerX )
            {
                cout << "@";
                continue;
            }
            else
            for (int k = 0; k <ENEMY_NR; k++)
            {
                if ( i == ent[i].eYpos && j == ent[i].eXpos);
                    //cout << '$';
            }
            if ( i == MAP_SIZE-2 && j == MAP_SIZE-2 )
                cout << (char) 178;
            else
            switch (gMap[i][j])
            {
            case FLOOR:
                cout << ' ';
                break;
            case WALL:
                cout << (char)219;
                break;
            case DOOR:
                cout << (char)176;
                break;
            case KEY:
                cout << (char)168;
                break;
            case POINTS_ENT:
                cout << "p";
                break;

            case ENEMY:
                cout << '$';

            }
        }
            if ( i == MAP_SIZE-2 ) cout << "<- EXIT";
            cout << endl;
    }
}

