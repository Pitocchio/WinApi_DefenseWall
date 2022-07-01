#pragma once

#define PI 3.14159265358979

#define RADIANTODEGREE(r) r * (PI / 180.0)
#define DEGREETORADIAN(d) d * (PI / 180.0)

enum class RETURNTYPE
{
	OBJ_ERR,
	OBJ_NOEVENT,
	OBJ_DEAD
};