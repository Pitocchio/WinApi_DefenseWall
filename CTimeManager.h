#pragma once

class CTimeManager
{
private:
	CTimeManager();
	~CTimeManager();

public: // SingleTone
	static CTimeManager* Get_Instance();
	static void Destroy_Instance();

public: 
	void Update(); 
	double Get_Deltatime();


private: // Variables
	static CTimeManager* m_TimeMgr;
	__int64 periodFrequency;
	__int64 curtime;
	__int64 lastTime;
	
	double timeScale;
	double deltatime;
};

