#include "StdAfx.h"
#include "Boss2Bullet2.h"

CBoss2Bullet2::CBoss2Bullet2(void)
{
}

CBoss2Bullet2::~CBoss2Bullet2(void)
{
	Release();
}

void CBoss2Bullet2::initirize()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();

	m_tInfo.fCX = 20;
	m_tInfo.fCY = 20;

	m_fSpeed = 8.f;
	m_fHp = 1;

	m_tInfo.vPos = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );
}

int  CBoss2Bullet2::Update()
{
	if(m_fHp <= 0)
	{
		return 1;
	}

	if(0 >= m_tInfo.vPos.y || 600 <= m_tInfo.vPos.y || 0 >= m_tInfo.vPos.x || 800 <= m_tInfo.vPos.x)
		return 1;

	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	CObj::FrameMove();
	CObj::Update();
	return 0;
}

void CBoss2Bullet2::Render(HDC hdc)
{
	Rectangle(hdc, m_tRect.left, m_tRect.top,
				m_tRect.right, m_tRect.bottom );

		HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2IceBullet"))->GetMemDC();

		TransparentBlt(hdc,int(m_tInfo.vPos.x - 15) , int(m_tInfo.vPos.y - 15), 30, 30
			, hMemDC, m_tFrame.iFrameStart * 16, 0
			, 16, 18, RGB(255, 0, 255));
}

void CBoss2Bullet2::Release()
{

}