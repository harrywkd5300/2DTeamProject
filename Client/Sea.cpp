#include "StdAfx.h"
#include "Sea.h"

CSea::CSea(void)
{
}

CSea::~CSea(void)
{
}
void CSea::initirize()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 7;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();

	if(m_tInfo.vPos.x ==1150.f)
	{
		m_tInfo.fCX = 200.f;
		m_tInfo.fCY = 50.f;
	}
	else if (m_tInfo.vPos.x == 3050.f)
	{
		m_tInfo.fCX = 150.f;
		m_tInfo.fCY = 50.f;
	}

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}
int CSea::Update()
{
	CObj::FrameMove();
	CObj::Update();
	return 0;
}
void CSea::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Sea"))->GetMemDC();
	TransparentBlt(hDC,int(m_tInfo.vPos.x - 50) + g_iScrollX , int(m_tInfo.vPos.y - 25) + g_iScrollY, (int)m_tInfo.fCX, (int)m_tInfo.fCY
		, hMemDC, m_tFrame.iFrameStart * 64, 0
		, 64, 12, RGB(128,128, 128));

}
void CSea::Release()
{

}