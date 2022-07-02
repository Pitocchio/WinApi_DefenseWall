#pragma once
#include <list>
#include <map>
#include "CObject.h"
#include "CObjectManager.h"


typedef	std::list<CObject*> COBJ_LIST;
typedef std::map <CObjectManager::OBJECT_TYPE, COBJ_LIST> COBJ_MAP;
