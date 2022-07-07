#pragma once


/*--------------------- WINDOW ---------------------*/
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

/*--------------------- COBJECT ---------------------*/


/*------- CPLAYER -------*/
#define CPLAYER_RADIUS 70
#define CPLAYER_START_POS_X (WINDOW_WIDTH * 0.5f)
#define CPLAYER_START_POS_Y (WINDOW_HEIGHT - CPLAYER_RADIUS)
#define CPLAYER_GUN_DISTANCE 10
#define CPLAYER_GUN_ANGLE 70  // ��Ÿ Ÿ�� �����ָ� �ʴ� �̵����� (ȭ�� �ȼ� ����)

/*------- CWALL -------*/
#define CWALL_NUM 8
#define CWALL_WIDTH (WINDOW_WIDTH / CWALL_NUM)
#define CWALL_HEIGHT 30

/*------- CBULLET -------*/
#define CBULLET_RADIUS 10
#define CBULLET_DISTANCE 400 // ��Ÿ Ÿ�� �����ָ� �ʴ� �̵��Ÿ� (ȭ�� �ȼ� ����)

/*------- CENEMY -------*/
#define CENEMY_START_POS_Y 0
#define CENEMY_RADIUS 25
#define CENEMY_DISTANCE 400 // ��Ÿ Ÿ�� �����ָ� �ʴ� �̵��Ÿ� (ȭ�� �ȼ� ����)


/*------- TIME -------*/
#define COBJECT_LIFETIME 3.0f
#define CBULLET_CREATE_DELAYTIME 0.3f
#define CENEMY_CREATE_DELAYTIME 1.0f




/*--------------------- ETC ---------------------*/

/*------- MATH -------*/
#define PI 3.14159265358979
#define RADIANTODEGREE(radian) radian * (PI / 180.0)
#define DEGREETORADIAN(degree) degree * (PI / 180.0)

