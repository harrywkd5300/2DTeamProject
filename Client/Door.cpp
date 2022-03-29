#include "StdAfx.h"
#include "Door.h"

CDoor::CDoor(void)
{
}

CDoor::~CDoor(void)
{
	Release();
}
void CDoor::initirize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 100.f;

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );
	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}
int CDoor::Update()
{
	CObj::Update();
	return 0;
}
void CDoor::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Door"))->GetMemDC();
	TransparentBlt(hDC,int(m_tInfo.vPos.x - 25) + g_iScrollX, int(m_tInfo.vPos.y - 50) + g_iScrollY, (int)m_tInfo.fCX, (int)m_tInfo.fCY
		, hMemDC, 0, 0
		, 17, 26, RGB(255,0,255));

}
void CDoor::Release()
{

}
