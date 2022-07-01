#pragma once
#include "Macro.h"
#include "MyVector.h"

/*

Componont Pattern : Has a Relationship( <-> Is a Relationship = inheritance)

	Component = Interface = Abstract Method�θ� �����Ǹ�, �ٸ� Variables�̳� Methods�� ���� �� ����. (Interface Class��� ��������)

*/

class Component // Component Pattern
{

public: // Enum
	enum class COMPONENT_TYPE { TRANSFORM, COLLIDER2D, CPNTYPEEND };

public: 
	Component() {};
	~Component() {};

public: // Life Cycle
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;

};




