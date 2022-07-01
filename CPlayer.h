#pragma once
#include "CObject.h"

class CPlayer : public CObject
{

public :
	CPlayer();
	~CPlayer();

public :
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};