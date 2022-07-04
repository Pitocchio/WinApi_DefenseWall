#pragma once
#include <cmath>

typedef struct MyVector2
{
	float x, y;

	MyVector2 operator+(MyVector2& vector2) { return MyVector2({ x + vector2.x, y + vector2.y }); }
	MyVector2 operator-(MyVector2& vector2) { return MyVector2({ x - vector2.x, y - vector2.y }); }
	MyVector2 operator*(MyVector2& vector2) { return MyVector2({ x * vector2.x, y * vector2.y }); }
	MyVector2 operator/(MyVector2& vector2) { return MyVector2({ x / vector2.x, y / vector2.y }); }

	//void operator=(Vector2& vector2) { x = vector2.x; y = vector2.y; }
	void operator+=(MyVector2& vector2) { x += vector2.x, y += vector2.y ; }
	void operator-=(MyVector2& vector2) { x -= vector2.x, y -= vector2.y ; }
	void operator*=(MyVector2& vector2) { x *= vector2.x, y *= vector2.y ; }
	void operator/=(MyVector2& vector2) { x /= vector2.x, y /= vector2.y ; }

	
	float Distance() 
	{ 
		return float(sqrt(pow(x, 2) + pow(y, 2))); 
	}
	/*
	
	������ ������ 0���� ���, ��Ÿ��� ������ ����Ͽ� dis(����)�� ���� ���Ѵ�.

	*/

	MyVector2 Normalize()
	{
		float dis = float(sqrt(pow(this->x, 2) + pow(this->y, 2)));
		this->x /= dis;
		this->y /= dis;
		return *this;
	}
	/*
	
	������ ����ȭ�� ���͸� ũ��(����)�� ������ ũ�Ⱑ 1�� ���͸� ����� = ���⸸ ���� �ǹǷ� ���⺤��, �������Ͷ�� �Ѵ�.

	*/


}Vector2;
