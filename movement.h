#ifndef _MOVEMENT_
#define _MOVEMENT_
#define _USE_MATH_DEFINES

//theta = 0 is defined to be left
//left is negative x, right is positive x
//up is negative y, down is positive y
//basically opposite from what you might expect, be careful


//comment this out if not debugging
//#define ENTITYDEBUG

#ifdef ENTITYDEBUG
#include <iostream>
#endif
#include <cmath>

struct Position
{
    int x;
    int y;
};

struct Movement
{
    bool left = false;
    bool down = false;
    bool up = false;
    bool right = false;
};

//0 radians is up, positive y is up, positive x is right
//these functions are for convenience
double convertCoordsToRads(int startx, int starty, int endx, int endy);
Movement convertCoordsToMovement(int startx, int starty, int endx, int endy);
Movement convertRadsToMovement(double rads);
double convertMovementToRads(Movement &dir);

//nice clean code
typedef Position (*moveEntityFunc)(int posx, int posy, Movement dir, int speed);
typedef Position (*moveProjectileFunc)(int startx, int starty, int posx, int posy, int thetaAim);

//entity movement functions
Position moveLeft(int posx, int posy, Movement dir, int speed);
Position movePlayer(int posx, int posy, Movement dir, int speed);

//projectile movement functions
Position moveLeft(int startx, int starty, int posx, int posy, int thetaAim);
Position moveDirection(int startx, int starty, int posx, int posy, int thetaAim);
Position moveTracking(int startx, int starty, int posx, int posy, int thetaAim);


#endif