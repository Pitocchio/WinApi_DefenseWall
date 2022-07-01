#pragma once
#include "Macro.h"

class Component
{

public: 
	Component();
	~Component();

public:
	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();

};