#pragma once

//#include "Typedef.h"
class CObject;

class CObjectManager
{

public : // Enum
	enum class OBJECT_TYPE {CPLAYER, CBULLET, CWALL, CENEMY, OBJTYPEEND};

//private: // Typedef
//	typedef	std::list<CObject*> COBJ_LIST;
//	typedef std::map <OBJECT_TYPE, COBJ_LIST> COBJ_MAP;

private:
	CObjectManager();
	~CObjectManager();

	
public: // SingleTone
	static CObjectManager* Get_Instance();
	static void Destroy_Instance();

public: // Life Cycle
	void Init();
	void Update(); // Collision check
	void LateUpdate(); // Collision implement
	void Render(HDC hdc);

public: // Method
	void Add_CObject(OBJECT_TYPE, CObject*);
	COBJ_MAP Get_ObjectMap() const { return m_ObjMap; }

private: // Variables
	static CObjectManager* m_ObjMgr;
	COBJ_MAP m_ObjMap;
};