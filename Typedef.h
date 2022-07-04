#pragma once

#include <list>
#include <map>
#include "CObjectManager.h"
#include "CObject.h"

typedef	std::list<CObject*> COBJ_LIST;
typedef std::map <CObjectManager::OBJECT_TYPE, COBJ_LIST> COBJ_MAP;
