#include "stdfx.h"
#include "CTimeManager.h"

CTimeManager* CTimeManager::m_TimeMgr = nullptr;

CTimeManager::CTimeManager()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	//1�ʵ��� CPU�� �������� ��ȯ�ϴ� �Լ� (������. �ý��� ���ý� ������)


	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
	// �������Լ��� Update()�Լ����� ������ ����Ǳ� ������ lastTime�� ����.

	timeScale = 1.0 / (double)periodFrequency;
	// �̸�  '1 / �ʴ�������'  �� ���·� ����� ���´�.
	// ��ǻ�ʹ� ���������꺸�� ���������� �� �����⶧���� �� �����Ӹ��� ������ �ؾ��Ұ�� 
	//������ �������� ���� ��궧 �����ϰ� �������°� ����.
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
	QueryPerformanceCounter((LARGE_INTEGER*)&curtime); // ���� ������ ������ ����.

	deltatime = (double)(curtime - lastTime) * timeScale; // (���� ������ ������ - ���� ������ ������) * ( 1 / �ʴ������� )

	lastTime = curtime; // ���� �������� ���� ���������� ����. ���� ��� �ݺ�.
}

double CTimeManager::Get_Deltatime() // �ʿ��Ѱ����� ������ ����.
{
	return deltatime;
}