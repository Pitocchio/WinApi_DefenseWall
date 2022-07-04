#pragma once

/*

Componont Pattern : Has a Relationship( <-> Is a Relationship = inheritance)

	Component = Interface = Abstract Method로만 구성되며, 다른 Variables이나 Methods를 가질 수 없다. (Interface Class라고 정의하자)

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
