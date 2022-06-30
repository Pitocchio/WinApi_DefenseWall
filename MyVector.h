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
	
	������ ������ 0���� ���, ��Ÿ��� ������ ����Ͽ� dis(����)�� ���� ���Ѵ�.

	*/

	MyVector2 Get_Normalize()
	{
		float dis = sqrt(pow(fx, 2) + pow(fy, 2));
		fx = fx / dis;
		fy = fy / dis;
		return *this;
	}
	/*
	
	������ ����ȭ�� ���͸� ũ��(����)�� ������ ũ�Ⱑ 1�� ���͸� ����� = ���⸸ ���� �ǹǷ� ���⺤��, �������Ͷ�� �Ѵ�.

	*/


}Vector2;

