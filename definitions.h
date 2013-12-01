/**************************************

  * Dungeon game
  *
  *
  * version 0.1.4 alpha
***************************************/

#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

#define MAP_SIZE      20
#define ENEMY_NR       3
#define FLOOR          0
#define WALL           1
#define PLAYER         2
#define DOOR           3
#define KEY            4
#define ENEMY          5
#define POINTS_ENT     6

#define KEY_UP_W     119
#define KEY_LEFT_A    97
#define KEY_DOWN_S   115
#define KEY_RIGHT_D  100

#define MOVE_X         1
#define MOVE_Y         2
#define MOVE_UP        0
#define MOVE_DOWN      1
#define MOVE_RIGHT     2
#define MOVE_LEFT      3

#define QUIT_GAME      0
#define CONT_GAME      1
#define RELOAD_GAME    2
#define DEAD_GAME      3

struct Enemy
{
    int eXpos; /// enemy X position
    int eMovD; /// enemy Movement direction
    int eYpos; /// enemy Y position
} entity[ENEMY_NR];

int pl_points;

#endif // DEFINITIONS_H_INCLUDED
