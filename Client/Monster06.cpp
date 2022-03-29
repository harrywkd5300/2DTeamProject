#include "StdAfx.h"
#include "Monster06.h"

CMonster06::CMonster06(void)
:m_bLeft(true), m_iCount(0)
{
}

CMonster06::~CMonster06(void)
{
	Release();
}


void CMonster06::initirize()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();

	m_tInfo.fCX = 50;
	m_tInfo.fCY = 50;

	m_fSpeed = 3.f;

	//m_tInfo.vPos = D3DXVECTOR3( 200.f, 400.f, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 1.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}

int  CMonster06::Update()
{
	if(m_bIsDead)
		return 1;

	if(true == m_bLeft)
	{
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = -1.f;
		m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

		++m_iCount;
	}
	else if(false == m_bLeft)
	{
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = 1.f;
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

void CMonster06::Render(HDC hdc)
{
	//Rectangle(hdc, int(m_tInfo.vPos.x - m_tInfo.fCX / 2), int(m_tInfo.vPos.y - m_tInfo.fCY / 2),
	//			int(m_tInfo.vPos.x + m_tInfo.fCX / 2), int(m_tInfo.vPos.y + m_tInfo.fCY / 2) );

	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Monster6"))->GetMemDC();
	HDC hMemDC2 = (CBmpMgr::GetInstance()->FindBmp(L"MonsterR6"))->GetMemDC();

	if(true == m_bLeft)
	{
		TransparentBlt(hdc,int(m_tInfo.vPos.x -35) + g_iScrollX, int(m_tInfo.vPos.y - 35) + g_iScrollY, 70, 70
			, hMemDC2, m_tFrame.iFrameStart * 32, 0
			, 32, 32, RGB(255, 0, 255));
	}
	if(false == m_bLeft)
	{
		TransparentBlt(hdc,int(m_tInfo.vPos.x - 35) + g_iScrollX, int(m_tInfo.vPos.y - 35) + g_iScrollY, 70, 70
			, hMemDC, m_tFrame.iFrameStart * 32, 0
			, 32, 32, RGB(255, 0, 255));
	}
}

void CMonster06::Release()
{

}