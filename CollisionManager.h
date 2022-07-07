#pragma once


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
	void Check_Collision(COLLISION_TYPE coltype, OBJECT_TYPE objtype1, OBJECT_TYPE objtype2);
	void Check_Collision2(COLLISION_TYPE coltype, OBJECT_TYPE objtype1, OBJECT_TYPE objtype2);


private: // Variables
	static CollisionMnager* m_ColMgr;
};


