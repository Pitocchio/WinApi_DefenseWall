#pragma once
#include "Component.h"

class Transform : public Component
{

public:
	Transform();
	~Transform();

public:
	void Init();
	void Update();
	void LateUpdate();
	
};
