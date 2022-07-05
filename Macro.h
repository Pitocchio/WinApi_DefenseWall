#pragma once

/*--------------------- WINDOW ---------------------*/
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960


/*--------------------- COBJECT ---------------------*/

/*------- CPLAYER -------*/
#define CPLAYER_START_POS_X (WINDOW_WIDTH * 0.5f)
#define CPLAYER_START_POS_Y WINDOW_HEIGHT
#define CPLAYER_RADIUS 70
#define CPLAYER_GUN_DISTANCE 100

/*------- CWALL -------*/
#define CWALL_NUM 8
#define CWALL_WIDTH (WINDOW_WIDTH / CWALL_NUM)
#define CWALL_HEIGHT 30













/*--------------------- ETC ---------------------*/

/*------- MATH -------*/
#define PI 3.14159265358979
#define RADIANTODEGREE(radian) radian * (PI / 180.0)
#define DEGREETORADIAN(degree) degree * (PI / 180.0)






enum class RETURNTYPE
{
	OBJ_ERR,
	OBJ_NOEVENT,
	OBJ_DEAD
};



// ≥Œ√º≈©!