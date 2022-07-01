#pragma once
#include "Macro.h"
#include "CObjectManager.h"
#include <string>
using namespace std;

class CollisionMnager
{
public : // Enum
	enum class COLLISION_TYPE {CIRCLE2D, BOX2D, AABB, OBB, COLTYPEEND};

private:
	CollisionMnager();
	~CollisionMnager();

public: // SingleTone
	static CollisionMnager* Get_Instance();
	static void Destroy_Instance();

public: // Method
	void CheckCollision(wstring objtype1, wstring objtype2, wstring coltype1, wstring coltype2);

private: // Variables
	static CollisionMnager* m_ColMgr;
};


