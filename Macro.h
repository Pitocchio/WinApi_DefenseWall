#pragma once

#define PI 3.14159265358979

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

#define CPLAYER_START_POS_X (WINDOW_WIDTH * 0.5f)
#define CPLAYER_START_POS_Y WINDOW_HEIGHT


#define RADIANTODEGREE(radian) radian * (PI / 180.0)
#define DEGREETORADIAN(degree) degree * (PI / 180.0)

enum class RETURNTYPE
{
	OBJ_ERR,
	OBJ_NOEVENT,
	OBJ_DEAD
};



// ≥Œ√º≈©!