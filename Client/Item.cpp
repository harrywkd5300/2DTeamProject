#include "StdAfx.h"
#include "Item.h"

CItem::CItem(void)
{
}

CItem::~CItem(void)
{
	Release();
}
void CItem::initirize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}
int CItem::Update()
{
	CObj::Update();
	return 0;
}
void CItem::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Item2"))->GetMemDC();
	TransparentBlt(hDC,int(m_tInfo.vPos.x - 15) + g_iScrollX, int(m_tInfo.vPos.y - 15) + g_iScrollY, (int)m_tInfo.fCX, (int)m_tInfo.fCY
		, hMemDC, 0, 0
		, 25, 25, RGB(255,0,255));

}
void CItem::Release()
{

}