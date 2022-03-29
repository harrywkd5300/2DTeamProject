#include "StdAfx.h"
#include "Boss1Bullet.h"

CBoss1Bullet::CBoss1Bullet(void)
:m_bBulletChange(true), m_iBulletCount(0)
{
}

CBoss1Bullet::~CBoss1Bullet(void)
{
}


void CBoss1Bullet::initirize()
{
	m_tInfo.fCX = 20;
	m_tInfo.fCY = 20;

	m_fSpeed = 4.f;
	m_fHp = 1;

	m_tInfo.vPos = D3DXVECTOR3( 0.f, 600.f, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 0.f, -1.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}

int  CBoss1Bullet::Update()
{
	if(m_fHp <= 0)
	{
		return 1;
	}

	if(140 >= m_tInfo.vPos.y)
		return 1;

	if(15 == m_iBulletCount && true == m_bBulletChange)
	{
		m_iBulletCount = 0;
		m_bBulletChange = false;
	}
	else if(15 == m_iBulletCount && false == m_bBulletChange)
	{
		m_iBulletCount = 0;
		m_bBulletChange = true;
	}

	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	++m_iBulletCount;
	CObj::Update();
	return 0;
}

void CBoss1Bullet::Render(HDC hdc)
{
	//Rectangle(hdc, m_tRect.left, m_tRect.top,
	//			m_tRect.right, m_tRect.bottom );

	if(true == m_bBulletChange)
	{
		HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss1Bullet1"))->GetMemDC();

		TransparentBlt(hdc,int(m_tInfo.vPos.x - 10) , int(m_tInfo.vPos.y - 10), 20, 20
			, hMemDC, 0, 0
			, 8, 8, RGB(255, 0, 255));
	}
	else if(false == m_bBulletChange)
	{
		HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss1Bullet2"))->GetMemDC();

		TransparentBlt(hdc,int(m_tInfo.vPos.x - 10) , int(m_tInfo.vPos.y - 10), 20, 20
			, hMemDC, 0, 0
			, 8, 8, RGB(255, 0, 255));
	}
}

void CBoss1Bullet::Release()
{

}