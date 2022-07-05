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
	virtual void Update() = 0; // 이 안에서 컴포넌트 맵을 돌려서 업데이트
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
	COMPONENT_MAP m_CpnMap; // 오브젝트 객체 자신이 컴포넌트 맵을 갖고 있음

protected: // Variables
	float m_Angle;
	Vector2 m_LookVec;
	// 기본 포지션은 Transform Component가 들고 있음
		    
};


// cf
/*


			플레이어		총알		벽		애로우

포지션		O			O		O		O


움직임		X			O		X		O

방향벡터		X			O		X		O

스피드		X			O		X		O

각도			X			O		X		O



콜라이더		X			O		O		O








*/