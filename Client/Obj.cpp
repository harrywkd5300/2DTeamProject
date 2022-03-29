#include "StdAfx.h"
#include "Obj.h"

CObj::CObj(void)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	D3DXMatrixIdentity(&m_tInfo.matWorld);
	D3DXMatrixIdentity(&m_tInfo.matTrans);
	D3DXMatrixIdentity(&m_tInfo.matScale);
	D3DXMatrixIdentity(&m_tInfo.matAngle);
	m_bIsDead = false;
	m_firstMake = true;
}

CObj::~CObj(void)
{

}

int CObj::Update()
{
	m_tRect.left   = int(m_tInfo.vPos.x - m_tInfo.fCX / 2.f);
	m_tRect.top	   = int(m_tInfo.vPos.y - m_tInfo.fCX / 2.f);
	m_tRect.right  = int(m_tInfo.vPos.x + m_tInfo.fCY / 2.f);
	m_tRect.bottom = int(m_tInfo.vPos.y + m_tInfo.fCY / 2.f);

	m_vPoint[0] = D3DXVECTOR3(m_tInfo.vPos.x - m_tInfo.fCX / 2.f,
		m_tInfo.vPos.y - m_tInfo.fCY / 2.f, 
		0.f);
	m_vPoint[1] = D3DXVECTOR3(m_tInfo.vPos.x + m_tInfo.fCX / 2.f,
		m_tInfo.vPos.y - m_tInfo.fCY / 2.f, 
		0.f);
	m_vPoint[2] = D3DXVECTOR3(m_tInfo.vPos.x + m_tInfo.fCX / 2.f,
		m_tInfo.vPos.y + m_tInfo.fCY / 2.f, 
		0.f);
	m_vPoint[3] = D3DXVECTOR3(m_tInfo.vPos.x - m_tInfo.fCX / 2.f,
		m_tInfo.vPos.y + m_tInfo.fCY / 2.f, 
		0.f);

	return 0;
}

void CObj::FrameMove()
{
	if(m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < GetTickCount())
	{
		m_tFrame.dwFrameOld = GetTickCount();
		++m_tFrame.iFrameStart;
	}

	if(m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		m_tFrame.iFrameStart = 0;
}

