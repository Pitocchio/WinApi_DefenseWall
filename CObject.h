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

public: // Method
	void Add_Component(Component::COMPONENT_TYPE type, Component* temp); 
	COMPONENT_MAP Get_ComponentMap() const { return m_CpnMap; }
	Vector2 Get_Transform() const { return dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos(); }
	/*
	
	m_CpnMap.begin() = 트랜스폼 키

	m_CpnMap.begin()->second = 벡터2 밸류
	
	*/
protected: // Variables
	COMPONENT_MAP m_CpnMap; // 객체 각각이 갖고 있는 컴포넌트이다.

protected: // Variables
	float m_Angle;
	Vector2 m_UnitVec;
	// 기본 포지션은 Transform Component가 들고 있음
		    
};



/*


			플레이어		총알		벽		애로우

포지션		O			O		O		O


움직임		X			O		X		O

방향벡터		X			O		X		O

스피드		X			O		X		O

각도			X			O		X		O



콜라이더		X			O		O		O








*/