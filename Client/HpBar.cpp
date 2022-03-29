#include "StdAfx.h"
#include "HpBar.h"

CHpBar::CHpBar(void)
{
}

CHpBar::~CHpBar(void)
{
	Release();
}
void CHpBar::initirize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}
int CHpBar::Update()
{
	CObj::Update();
	return 0;
}
void CHpBar::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"HpBar2"))->GetMemDC();
	TransparentBlt(hDC,int(m_tInfo.vPos.x - 25), int(m_tInfo.vPos.y - 25), (int)m_tInfo.fCX, (int)m_tInfo.fCY
		, hMemDC, 0, 0
		, 22, 21, RGB(0,0,255));

}
void CHpBar::Release()
{

}