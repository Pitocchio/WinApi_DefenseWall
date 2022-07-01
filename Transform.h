#pragma once
#include "Component.h"

class Transform : public Component
{

public:
	Transform();
	~Transform();
	Transform(Vector2 vecPos, Vector3 vecRot);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;

public: // Get
	Vector2 Get_VecPos() const { return m_VecPos; }
	Vector3 Get_VecRot() const { return m_VecRot; }

public: // Set
	void Set_VecPos(Vector2 vec2) { m_VecPos = vec2; }
	void Set_VecRot(Vector3 vec3) { m_VecRot = vec3; }
	
private : // Variables
	Vector2 m_VecPos;
	Vector3 m_VecRot;
};

