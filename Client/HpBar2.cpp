#include "StdAfx.h"
#include "HpBar2.h"

CHpBar2::CHpBar2(void)
{
}

CHpBar2::~CHpBar2(void)
{
	Release();
}
void CHpBar2::initirize()
{
	m_tFrame.iFrameStart = 5;

	m_tInfo.fCX = 250.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}
int CHpBar2::Update()
{
	m_tInfo.fCX = CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsHp() * 50.f;
	CObj::Update();
	return 0;
}
void CHpBar2::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"HpBar1"))->GetMemDC();
	TransparentBlt(hDC,int(m_tInfo.vPos.x - 125), int(m_tInfo.vPos.y - 25), (int)m_tInfo.fCX, (int)m_tInfo.fCY
		, hMemDC, 0, 0
		, (int)CObjMgr::GetInstance()->GetObj(PLAYER)->GetIsHp() * 50, 50, RGB(0,0,255));

}
void CHpBar2::Release()
{

}