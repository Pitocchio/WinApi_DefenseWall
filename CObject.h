#pragma once
#include "Component.h"


class CObject
{

public: // Enum
	//enum class OBJECT_TYPE { CPLAYER, CBULLET, CWALL, CENEMY, OBJTYPEEND };

protected: // Typedef
	typedef map<Component::COMPONENT_TYPE, Component*> COMPONENT_MAP;

public:
	CObject();
	~CObject();
	CObject(Vector2 pos);
	CObject(Vector2 pos, Vector2 Lookvec);


public: // Life Cycle
	virtual void Init() = 0;
	virtual void Update() = 0; // �� �ȿ��� ������Ʈ ���� ������ ������Ʈ
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;

public: // Set
	virtual void Set_Lookvec();
	void Set_BoolIsCollision(bool b) { bIsCollision = b; }
	bool Get_BoolIsCollision() { return bIsCollision; }

public: // Method
	void Add_Component(Component::COMPONENT_TYPE type, Component* temp); 
	COMPONENT_MAP Get_ComponentMap() const { return m_CpnMap; }
	//Vector2 Get_Transform() const { return dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos(); }
	
protected: // Variables
	COMPONENT_MAP m_CpnMap; // ������Ʈ ��ü �ڽ��� ������Ʈ ���� ���� ����

protected: // Variables
	float m_Angle;
	Vector2 m_LookVec;
	bool bIsCollision;
	// �⺻ �������� Transform Component�� ��� ����
		    
};


// cf
/*


			�÷��̾�		�Ѿ�		��		�ַο�

������		O			O		O		O


������		X			O		X		O

���⺤��		X			O		X		O

���ǵ�		X			O		X		O

����			X			O		X		O



�ݶ��̴�		X			O		O		O








*/