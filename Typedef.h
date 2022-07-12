#pragma once

class CObject;

enum class OBJECT_TYPE { CPLAYER, CBULLET, CWALL, CENEMY, OBJTYPEEND };

enum class COLLIDER2D_TYPE{CIRCLE_COLLIDER2D, BOX_COLLIDER2D};

typedef	std::list<CObject*> COBJ_LIST;
typedef std::map<OBJECT_TYPE, COBJ_LIST> COBJ_MAP;


