#include "StdAfx.h"
#include "KeyMgr.h"

IMPLEMENT_SINGLETON(CKeyMgr)

CKeyMgr::CKeyMgr(void)
{
}

CKeyMgr::~CKeyMgr(void)
{
}

void CKeyMgr::KeyCheck()
{
	m_dwKey = 0;

	if(GetAsyncKeyState(VK_LEFT))
		m_dwKey |= KEY_LEFT;
	if(GetAsyncKeyState(VK_RIGHT))
		m_dwKey |= KEY_RIGHT; 
	if(GetAsyncKeyState(VK_UP))
		m_dwKey |= KEY_UP;
	if(GetAsyncKeyState(VK_DOWN))
		m_dwKey |= KEY_DOWN; 
	if(GetAsyncKeyState(VK_SPACE))
		m_dwKey |= KEY_SPACE;
	if(GetAsyncKeyState(VK_RETURN))
		m_dwKey |= KEY_RETURN;
	if(GetAsyncKeyState(VK_LBUTTON))
		m_dwKey |= KEY_LBUTTON;
	if(GetAsyncKeyState('C'))
		m_dwKey |= C;
	if(GetAsyncKeyState('X'))
		m_dwKey |= X;
	if(GetAsyncKeyState('Z'))
		m_dwKey |= Z;
	if(GetAsyncKeyState('P'))
		m_dwKey |= P;
	if(GetAsyncKeyState('V'))
		m_dwKey |= V;
}