#pragma once

/*

Componont Pattern : Has a Relationship( <-> Is a Relationship = inheritance)

	Component = Interface = Abstract Method�θ� �����Ǹ�, �ٸ� Variables�̳� Methods�� ���� �� ����. (Interface Class��� ��������)

*/
#include "Transform.h"

class Component // Component Pattern
{

public: // Enum
	enum class COMPONENT_TYPE { TRANSFORM, COLLIDER2D, CPNTYPEEND };

public: 
	Component() {};
	~Component() {};
	//Vector2 Get_TransformComponent() { return dynamic_cast<Transform*>(this)->Get_VecPos(); }
	

public: // Life Cycle
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;

};




