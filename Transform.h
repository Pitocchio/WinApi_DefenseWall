#pragma once
#include "stdfx.h"


class Transform : public Component
{

public:
	Transform();
	~Transform();
	Transform(Vector2 vecPos);

public:
	virtual void Init() ;
	virtual void Update() ;
	virtual void LateUpdate() ;

public: // Get
	Vector2 Get_VecPos() const { return m_VecPos; }

public: // Set
	void Set_VecPos(Vector2 vec2) { m_VecPos = vec2; }
	
private : // Variables
	Vector2 m_VecPos;
};

