#pragma once
#include "Component.h"

class Collider2D : public Component
{
public:
	Collider2D();
	~Collider2D();



public:
	void Init();
	void Update();
	void LateUpdate();

};