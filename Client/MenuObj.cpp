#include "StdAfx.h"
#include "MenuObj.h"

CMenuObj::CMenuObj(void)
{
}

CMenuObj::~CMenuObj(void)
{
	Release();
}
void CMenuObj::initirize()
{
	m_tInfo.vPos.x = 400.f;
	m_tInfo.vPos.y = 200.f;
	m_tInfo.vPos.z = 0.f;
	m_tInfo.fCX = 500.f;
	m_tInfo.fCY = 300.f;


	m_fAngle = 0.f;

	CObj::Update();

	m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_tInfo.vLook = D3DXVECTOR3(1.f, 0.f, 0.f);	

	m_fSpeed = 5.f;
}
int  CMenuObj::Update()
{	
	D3DXMatrixTranslation(&m_tInfo.matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
	D3DXMatrixScaling(&m_tInfo.matScale, 1.f, 1.f, 1.f);

	D3DXMatrixRotationZ(&m_tInfo.matAngle, m_fAngle);

	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matAngle * m_tInfo.matTrans;
	return 0;
}
void CMenuObj::Render(HDC hdc)
{
	HDC hmemDC = (CBmpMgr::GetInstance()->FindBmp(L"Title"))->GetMemDC();

	TransparentBlt(hdc, int(m_tInfo.vPos.x - m_tInfo.fCX / 2), int(m_tInfo.vPos.y - m_tInfo.fCY / 2), 500, 300, 
		hmemDC, 0, 0, 500 , 300, RGB(255,0,255));
}
void CMenuObj::Release()
{

}