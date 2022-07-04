#pragma once

/*

Componont Pattern : Has a Relationship( <-> Is a Relationship = inheritance)

	Component = Interface = Abstract Method�θ� �����Ǹ�, �ٸ� Variables�̳� Methods�� ���� �� ����. (Interface Class��� ��������)

*/

class Component // Component Pattern
{
public: // Enum
	enum class COMPONENT_TYPE { TRANSFORM, COLLIDER2D, CPNTYPEEND };

public: 
	explicit Component() {}
	virtual ~Component() {}
	
public: // Life Cycle
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;

};
