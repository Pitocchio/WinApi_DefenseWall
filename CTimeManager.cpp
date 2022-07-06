#include "stdfx.h"
#include "CTimeManager.h"

CTimeManager* CTimeManager::m_TimeMgr = nullptr;

// Have to initialize static variables! (프로그램 생성과 동시에 초기화를 해주는데 자체가 없다면 오류)

CTimeManager::CTimeManager()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	//1초동안 CPU의 진동수를 반환하는 함수 (고정값. 시스템 부팅시 고정됨)


	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
	// 생성자함수는 Update()함수보다 이전에 실행되기 때문에 lastTime에 저장.

	timeScale = 1.0 / (double)periodFrequency;
	// 미리  '1 / 초당진동수'  의 형태로 만들어 놓는다.
	// 컴퓨터는 나눗셈연산보다 곱셈연산이 더 빠르기때문에 매 프레임마다 연산을 해야할경우 
	역수로 만들어놓고 실제 계산때 곱셈하게 만들어놓는게 좋다.
}

CTimeManager::~CTimeManager()
{
}

CTimeManager* CTimeManager::Get_Instance()
{
	if (!m_TimeMgr)
		m_TimeMgr = new CTimeManager;
	return m_TimeMgr;
}

void CTimeManager::Destroy_Instance()
{
	delete m_TimeMgr;
}

void CTimeManager::Update()
{

}
