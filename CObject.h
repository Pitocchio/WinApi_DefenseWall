#pragma once

class CObject
{

public:
	CObject();
	~CObject();

public:
	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
		    
};