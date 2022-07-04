#pragma once
#include "Component.h"

class Transform : public Component
{
public:
	explicit Transform() : Component(), m_VecPos({}) {};
	virtual ~Transform();
	Transform(Vector2 vecPos);

public: // Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;

public: // Get
	Vector2 Get_VecPos() const { return m_VecPos; }

public: // Set
	void Set_VecPos(Vector2 vec2) { m_VecPos = vec2; }
	
private : // Variables
	Vector2 m_VecPos = {};

};

