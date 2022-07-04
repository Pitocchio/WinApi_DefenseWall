#pragma once


using namespace std;

class CollisionMnager
{
public : // Enum
	enum class COLLISION_TYPE {CIRCLE2D, BOX2D, AABB, COLTYPEEND};

private:
	CollisionMnager();
	~CollisionMnager();

public: // SingleTone
	static CollisionMnager* Get_Instance();
	static void Destroy_Instance();

public: // Method
	void Check_Collision(COLLISION_TYPE coltype, CObjectManager::OBJECT_TYPE objtype1, CObjectManager::OBJECT_TYPE objtype2);

private: // Variables
	static CollisionMnager* m_ColMgr;
};


