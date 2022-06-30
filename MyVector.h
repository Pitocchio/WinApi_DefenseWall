#pragma once
#include <cmath>

typedef struct MyVector2
{
	float fx, fy;

	MyVector2 operator+(MyVector2& vector2) { return MyVector2({ fx + vector2.fx, fy + vector2.fy }); }
	MyVector2 operator-(MyVector2& vector2) { return MyVector2({ fx - vector2.fx, fy - vector2.fy }); }
	MyVector2 operator*(MyVector2& vector2) { return MyVector2({ fx * vector2.fx, fy * vector2.fy }); }
	MyVector2 operator/(MyVector2& vector2) { return MyVector2({ fx / vector2.fx, fy / vector2.fy }); }

	void operator=(MyVector2& vector2) { fx = vector2.fx; fy = vector2.fy; }
	void operator+=(MyVector2& vector2) { fx += vector2.fx, fy += vector2.fy ; }
	void operator-=(MyVector2& vector2) { fx -= vector2.fx, fy -= vector2.fy ; }
	void operator*=(MyVector2& vector2) { fx *= vector2.fx, fy *= vector2.fy ; }
	void operator/=(MyVector2& vector2) { fx /= vector2.fx, fy /= vector2.fy ; }


	float Get_Distance() 
	{ 
		return sqrt(pow(fx, 2) + pow(fy, 2)); 
	}
	/*
	
	벡터의 시점을 0으로 잡고, 피타고라스 정리를 사용하여 dis(빗변)의 값을 구한다.

	*/

	MyVector2 Get_Normalize()
	{
		float dis = sqrt(pow(fx, 2) + pow(fy, 2));
		fx = fx / dis;
		fy = fy / dis;
		return *this;
	}
	/*
	
	벡터의 정규화는 벡터를 크기(길이)로 나누어 크기가 1인 벡터를 만든다 = 방향만 갖게 되므로 방향벡터, 단위벡터라고도 한다.

	*/


}Vector2;

