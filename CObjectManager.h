#pragma once
#include "Macro.h"

class CObjectManager
{

public :
	enum class OBJECT_TYPE {CPLAYER, CBULLET, CWALL, CENEMY};

private:
	CObjectManager() {};
	~CObjectManager() {};
public:
	static CObjectManager* Get_Instance();
	static void Destroy_Instance();

public:
	void Init();
	void Update();
	void LateUpdate();
	void Render();

private:
	static CObjectManager* m_ObjMgr;
};