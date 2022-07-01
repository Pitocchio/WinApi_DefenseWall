#pragma once
#include "Component.h"
class Collider2D : public Component
{

public:
	Collider2D();
	~Collider2D();

public: // Method
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;

private: // Variables
	bool bIscollision;

};