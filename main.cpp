#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "definitions.h"
#include "generator.h"
#include "screen.h"
#include "playeraction.h"
#include "load.h"
#include "enemy.h"

using namespace std;

int gMap[MAP_SIZE][MAP_SIZE];
int PlayerX = 1,
    PlayerY = 1;


bool ReturnToExit(int, int);


bool mainMenu(struct Enemy ent[])
{
    int input;
    cout << "Generate random or load (just for MAP_SIZE 20)?\n~1 | Generate\n~2 | Load\n>";
    cin >> input;

    if (input == 1) return true;
    else
    if (input == 2)
    {
        loadFunc(gMap);
        loadEnemy(gMap, ent);
    }
    return false;
}



int main()
{
    int loopw;
    if ( mainMenu(entity) )
    {
        /// Generate map
        regenerateMap:
        pl_points = 0;
        PlayerX = 1;
        PlayerY = 1;
        GenerateMap(gMap, 2, &PlayerX, &PlayerY); /// 1 - no gen, 2 - 1/2 chances, 3 - 1/3 chances...
        CreatePath(gMap);
    }

    do
    {
        RenderG(gMap, PlayerX, PlayerY, entity);
        cout << "--------\n";
        cout << "Points: " << pl_points <<endl;
        enemyMov(gMap);
        loopw = movePlayer(gMap, &PlayerX, &PlayerY, &pl_points);
    }
    while (loopw == CONT_GAME);

    if (loopw == RELOAD_GAME) goto regenerateMap;
    else
    if (loopw == DEAD_GAME)
    {
        system("cls");
        cout << "u dead.";
    }
    return 0;
}


