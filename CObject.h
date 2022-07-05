#pragma once
#include "Component.h"


class CObject
{

public: // Enum
	enum class OBJECT_TYPE { CPLAYER, CBULLET, CWALL, CENEMY, OBJTYPEEND };

protected: // Typedef
	typedef map<Component::COMPONENT_TYPE, Component*> COMPONENT_MAP;

public:
	CObject();
	~CObject();
	CObject(Vector2 pos);

public: // Life Cycle
	virtual void Init() = 0;
	virtual void Update() = 0; // �� �ȿ��� ������Ʈ ���� ������ ������Ʈ
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;

public: // Set
	void Plus_Angle(); 
	void Minus_Angle();
	virtual void Set_Lookvec();

public: // Method
	void Add_Component(Component::COMPONENT_TYPE type, Component* temp); 
	COMPONENT_MAP Get_ComponentMap() const { return m_CpnMap; }
	//Vector2 Get_Transform() const { return dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos(); }
	
protected: // Variables
	COMPONENT_MAP m_CpnMap; // ������Ʈ ��ü �ڽ��� ������Ʈ ���� ���� ����

protected: // Variables
	float m_Angle;
	Vector2 m_LookVec;
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