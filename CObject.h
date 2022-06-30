#pragma once

class CObject
{

public :
	CObject();
	~CObject();

	void virtual Update();
	void virtual LateUpdate();
	void virtual Render();

};