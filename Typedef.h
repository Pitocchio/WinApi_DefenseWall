#pragma once

class CObject;

enum class OBJECT_TYPE { CPLAYER, CBULLET, CWALL, CENEMY, OBJTYPEEND };

typedef	std::list<CObject*> COBJ_LIST;
typedef std::map<OBJECT_TYPE, COBJ_LIST> COBJ_MAP;
