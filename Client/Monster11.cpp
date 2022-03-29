#include "StdAfx.h"
#include "Monster11.h"

CMonster11::CMonster11(void)
:m_bLeft(true), m_iCount(0)
{
}

CMonster11::~CMonster11(void)
{
	Release();
}

void CMonster11::initirize()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();

	m_tInfo.fCX = 70;
	m_tInfo.fCY = 70;

	m_fSpeed = 3.f;

	//m_tInfo.vPos = D3DXVECTOR3( 600, 100, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 1.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}

int  CMonster11::Update()
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

void CMonster11::Render(HDC hdc)
{
	//Rectangle(hdc, int(m_tInfo.vPos.x - m_tInfo.fCX / 2), int(m_tInfo.vPos.y - m_tInfo.fCY / 2),
	//			int(m_tInfo.vPos.x + m_tInfo.fCX / 2), int(m_tInfo.vPos.y + m_tInfo.fCY / 2) );

	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Monster11"))->GetMemDC();

	TransparentBlt(hdc,int(m_tInfo.vPos.x - 50) + g_iScrollX, int(m_tInfo.vPos.y - 50)+ g_iScrollY, 100, 100
		, hMemDC, m_tFrame.iFrameStart * 27, 0
		, 27, 25, RGB(255, 0, 255));
}

void CMonster11::Release()
{

}