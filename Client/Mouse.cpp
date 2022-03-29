#include "StdAfx.h"
#include "Mouse.h"

CMouse::CMouse(void)
{
}

CMouse::~CMouse(void)
{
	Release();
}
void CMouse::initirize()
{
	m_tInfo.fCX = 32;
	m_tInfo.fCY = 32;
	m_dwTime = GetTickCount();
	m_dwClick = 500;
}
int CMouse::Update()
{
	GetCursorPos(&m_ptMouse);
	ScreenToClient(g_hwnd, &m_ptMouse);

	m_tInfo.vPos.x = float(m_ptMouse.x);
	m_tInfo.vPos.y = float(m_ptMouse.y);

	m_ptAgoMouse.x = m_ptMouse.x;
	m_ptAgoMouse.y = m_ptMouse.y;

	CObj::Update();
	return 0;
}
void CMouse::Render(HDC hDC)
{
	
}
void CMouse::Release()
{

}