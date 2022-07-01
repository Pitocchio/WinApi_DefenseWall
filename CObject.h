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
	virtual void Update() = 0; // �� �ȿ��� ������Ʈ ���� ������ ������Ʈ
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;

public: // Method
	void Add_Component(Component::COMPONENT_TYPE type, Component* temp); 
	COMPONENT_MAP Get_ComponentMap() const { return m_CpnMap; }

protected: // Variables
	COMPONENT_MAP m_CpnMap; // ��ü ������ ���� �ִ� ������Ʈ�̴�.

public: // Variables
		    
};

