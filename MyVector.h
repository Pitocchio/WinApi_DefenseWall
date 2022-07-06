#pragma once
#include <cmath>

typedef struct MyVector2
{
	float x, y;




	MyVector2 operator+(MyVector2& vector2) { return MyVector2({ x + vector2.x, y + vector2.y }); }
	MyVector2 operator-(MyVector2& vector2) { return MyVector2({ x - vector2.x, y - vector2.y }); }
	MyVector2 operator*(MyVector2& vector2) { return MyVector2({ x * vector2.x, y * vector2.y }); }
	MyVector2 operator/(MyVector2& vector2) { return MyVector2({ x / vector2.x, y / vector2.y }); }


	MyVector2 operator*(float mul) { return MyVector2({ x * mul, y * mul }); }

	void operator *= (float mul) { x *= mul; y *= mul; };
	void operator += (float rbs) { x += rbs; y += rbs; };
	//MyVector2 operator += (float rbs) { x += rbs; y += rbs; };


	//void operator=(Vector2& vector2) { x = vector2.x; y = vector2.y; }
	void operator += (MyVector2& vector2) { x += vector2.x, y += vector2.y ; }
	void operator -= (MyVector2& vector2) { x -= vector2.x, y -= vector2.y ; }
	void operator *= (MyVector2& vector2) { x *= vector2.x, y *= vector2.y ; }
	void operator /= (MyVector2& vector2) { x /= vector2.x, y /= vector2.y ; }

	
	float Distance() 
	{ 
		return float(sqrt(pow(x, 2) + pow(y, 2))); 
	}
	/*
	
	벡터의 시점을 0으로 잡고, 피타고라스 정리를 사용하여 dis(빗변)의 값을 구한다.

	*/

	MyVector2& Normalize()
	{
		float dis = float(sqrt(pow(this->x, 2) + pow(this->y, 2)));
		this->x /= dis;
		this->y /= dis;
		return *this;
	}
	/*
	
	벡터의 정규화는 벡터를 크기(길이)로 나누어 크기가 1인 벡터를 만든다 = 방향만 갖게 되므로 방향벡터, 단위벡터라고도 한다.

	*/


}Vector2;
