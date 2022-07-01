#pragma once
#include "CObject.h"
class CPlayer
{

public :
	CPlayer();
	~CPlayer();

public :
	void Init();
	void Update();
	void LateUpdate();
	void Render();
};