#pragma once
#include "Component.h"
#include "Macro.h"
#include <map>
#include <list>

class CObject
{

public: // Enum
	enum class OBJECT_TYPE { CPLAYER, CBULLET, CWALL, CENEMY, OBJTYPEEND };

private: // Typedef
	typedef	Component COMPONENT;
	typedef std::map <Component::COMPONENT_TYPE, COMPONENT*> COMPONENT_MAP;

public:
	CObject();
	~CObject();

public: // Life Cycle
	virtual void Init() = 0;
	virtual void Update() = 0; // 이 안에서 컴포넌트 맵을 돌려서 업데이트
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;

public: // Method
	void Add_Component(Component::COMPONENT_TYPE type, Component* temp); 
	COMPONENT_MAP Get_ComponentMap() const { return m_CpnMap; }

protected: // Variables
	COMPONENT_MAP m_CpnMap; // 객체 각각이 갖고 있는 컴포넌트이다.

public: // Variables
		    
};

