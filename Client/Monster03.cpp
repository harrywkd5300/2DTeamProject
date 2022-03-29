#include "StdAfx.h"
#include "Monster03.h"

CMonster03::CMonster03(void)
:m_bLeft(true), m_iCount(0)
{
}

CMonster03::~CMonster03(void)
{
	Release();
}


void CMonster03::initirize()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 2;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();

	m_tInfo.fCX = 35;
	m_tInfo.fCY = 35;

	m_fSpeed = 1.f;

	//m_tInfo.vPos = D3DXVECTOR3( 200.f, 300.f, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 1.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}

int  CMonster03::Update()
{
	if(m_bIsDead)
		return 1;

	if(true == m_bLeft)
	{
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = -1.f;
		if(25 > m_iCount)
			m_tInfo.vDir.y = -1.f;
		else if(25 <= m_iCount)
			m_tInfo.vDir.y = +1.f;

		m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

		++m_iCount;
	}
	else if(false == m_bLeft)
	{
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = 1.f;
		if(25 > m_iCount)
			m_tInfo.vDir.y = -1.f;
		else if(25 <= m_iCount)
			m_tInfo.vDir.y = +1.f;

		m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
		++m_iCount;
	}


	if(50 == m_iCount && true == m_bLeft)
	{
		m_iCount = 0;
		m_bLeft = false;
	}
	else if(50 == m_iCount && false == m_bLeft)
	{
		m_iCount = 0;
		m_bLeft = true;
	}

	CObj::FrameMove();
	CObj::Update();
	return 0;
}

void CMonster03::Render(HDC hdc)
{
	//Rectangle(hdc, int(m_tInfo.vPos.x - m_tInfo.fCX / 2), int(m_tInfo.vPos.y - m_tInfo.fCY / 2),
	//			int(m_tInfo.vPos.x + m_tInfo.fCX / 2), int(m_tInfo.vPos.y + m_tInfo.fCY / 2) );

	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Monster3"))->GetMemDC();
	HDC hMemDC2 = (CBmpMgr::GetInstance()->FindBmp(L"MonsterR3"))->GetMemDC();

	if(true == m_bLeft)
	{
		TransparentBlt(hdc,int(m_tInfo.vPos.x - 25) + g_iScrollX, int(m_tInfo.vPos.y - 25) + g_iScrollY, 50, 50
			, hMemDC2, m_tFrame.iFrameStart * 27, 0
			, 27, 25, RGB(255, 0, 255));
	}
	if(false == m_bLeft)
	{
		TransparentBlt(hdc,int(m_tInfo.vPos.x - 25) + g_iScrollX, int(m_tInfo.vPos.y - 25) + g_iScrollY, 50, 50
			, hMemDC, m_tFrame.iFrameStart * 27, 0
			, 27, 25, RGB(255, 0, 255));
	}
}

void CMonster03::Release()
{

}