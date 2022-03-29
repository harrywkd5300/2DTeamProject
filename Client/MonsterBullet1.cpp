#include "StdAfx.h"
#include "MonsterBullet1.h"

CMonsterBullet1::CMonsterBullet1(void)
{
}

CMonsterBullet1::~CMonsterBullet1(void)
{
	Release();
}

void CMonsterBullet1::initirize()
{
	m_tInfo.fCX = 10;
	m_tInfo.fCY = 10;

	m_fSpeed = 1.f;

	m_tInfo.vPos = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );

}

int  CMonsterBullet1::Update()
{
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	CObj::Update();
	return 0;
}

void CMonsterBullet1::Render(HDC hdc)
{
	/*Rectangle(hdc, int(m_tInfo.vPos.x - m_tInfo.fCX / 2), int(m_tInfo.vPos.y - m_tInfo.fCY / 2),
				int(m_tInfo.vPos.x + m_tInfo.fCX / 2), int(m_tInfo.vPos.y + m_tInfo.fCY / 2) );*/

	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Monster8Bullet1"))->GetMemDC();

		TransparentBlt(hdc,int(m_tInfo.vPos.x - m_tInfo.fCX / 2.f) , int(m_tInfo.vPos.y - m_tInfo.fCY / 2.f), (int)m_tInfo.fCX, (int)m_tInfo.fCY
			, hMemDC, 18, 0
			, 18, 8, RGB(255, 0, 255));
}

void CMonsterBullet1::Release()
{

}