#include "StdAfx.h"
#include "Tile.h"
#include "Player.h"

CTile::CTile(void)
:m_iDrawID(0), m_iOption(0)
{
}

CTile::~CTile(void)
{
	Release();
}
void CTile::initirize()
{
	m_tInfo.fCX = (float)TILECX;
	m_tInfo.fCY = (float)TILECY;
}

int CTile::Update()
{
	CObj::Update();
	return 0;
}

void CTile::Render(HDC hdc)
{
	HDC hMemDC;
	if(m_iDrawID == 1)
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileDoorOff"))->GetMemDC();
	else if(m_iDrawID == 2)
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileDoorOn"))->GetMemDC();
	else if(m_iDrawID == 3)
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileTrue"))->GetMemDC();
	else
		hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"TileFalse"))->GetMemDC();

	if(m_iDrawID > 4)
		m_iDrawID = 0;

	TransparentBlt(hdc, int(m_tInfo.vPos.x - m_tInfo.fCX / 2.f) + g_iScrollX , int(m_tInfo.vPos.y - m_tInfo.fCY / 2.f) + g_iScrollY, (int)m_tInfo.fCX, (int)m_tInfo.fCY
		, hMemDC, 0, 0
		, 40, 40, RGB(255, 255, 255));
	/*if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top + g_iScrollY, m_tRect.right + g_iScrollX, m_tRect.bottom + g_iScrollY);*/

}

void CTile::Release()
{
}
