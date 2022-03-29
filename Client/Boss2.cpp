#include "StdAfx.h"
#include "Boss2.h"
#include "Player.h"
#include "Boss2Bullet1.h"
#include "Boss2Bullet2.h"
#include "Boss2Bullet3.h"
#include "Boss2Bullet4.h"

CBoss2::CBoss2(void)
:m_bBossChange(true), m_iPatten(1),m_fOldx(0.f), m_iBulletCount(0), m_bBossHit(false), m_iBossHitCount(0), m_bHitEffect(true), m_iPatten2ShotCount(0), m_bPattenChange(true), m_iPatten2ChangeCount(0)
{
}

CBoss2::~CBoss2(void)
{
	Release();
}

void CBoss2::initirize()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();

	m_tInfo.fCX = 100;
	m_tInfo.fCY = 100;

	m_fAngle = 90.f;
	m_fSpeed = 3.f;
	m_fHp = 10.f;
	m_fOldHp = m_fHp;
	

	m_tInfo.vPos = D3DXVECTOR3( 400, 300, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_fOldx = m_tInfo.vPos.x;

	m_bIsDamaged = false;
	m_iDamagedCnt = 0;
}

int  CBoss2::Update()
{
	if(m_fHp <= 0)
	{
		return 1;
	}

	/*if(GetAsyncKeyState('A'))
		--m_fHp;*/

	if(m_fOldHp > m_fHp)
	{
		m_bBossHit = true;
		m_fOldHp = m_fHp;
	}

	if(true == m_bBossHit)
		++m_iBossHitCount;

	if(25 == m_iBossHitCount && true == m_bBossChange)
	{
		m_iBulletCount = 0;
		m_iPatten = 2;
		m_bBossChange = false;
		m_iBossHitCount = 0;
		m_bBossHit = false;
	}
	else if(25 == m_iBossHitCount && false == m_bBossChange)
	{
		m_iBulletCount = 0;
		m_iPatten = 2;
		m_bBossChange = true;
		m_iBossHitCount = 0;
		m_bBossHit = false;
	}

	if(30 == m_iPatten2ChangeCount)
	{
		m_iPatten2ChangeCount = 0;
		m_bPattenChange = false;
	}

	DamagedMotion();
	BossPatten(m_iPatten);


	CObj::FrameMove();
	CObj::Update();
	return 0;
}

void CBoss2::Render(HDC hdc)
{
	if(true == m_bBossChange)
	{
		if(m_fOldx >= m_tInfo.vPos.x)
		{
			if(true == m_bBossHit)
			{
				if(true == m_bHitEffect)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2FireHit"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 45, 0
						, 45, 60, RGB(255, 0, 255));

					m_bHitEffect = false;
				}
				else if(false == m_bHitEffect)
				{
					m_bHitEffect = true;
				}

			}
			else if(2 == m_iPatten)
			{
				if(true == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change1"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 60, 0
						, 60, 60, RGB(255, 0, 255));
					++m_iPatten2ChangeCount;
				}
				else if(false == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change2"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 65, 0
						, 65, 60, RGB(255, 0, 255));
				}
			}
			else
			{
				HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Fire"))->GetMemDC();

				TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
					, hMemDC, m_tFrame.iFrameStart * 55, 0
					, 55, 55, RGB(255, 0, 255));
			}
		}
		else if (m_fOldx < m_tInfo.vPos.x)
		{
			if(true == m_bBossHit)
			{
				if(true == m_bHitEffect)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2FireHitR"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 45, 0
						, 45, 60, RGB(255, 0, 255));

					m_bHitEffect = false;
				}
				else if(false == m_bHitEffect)
				{
					m_bHitEffect = true;
				}

			}
			else if(2 == m_iPatten)
			{
				if(true == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change1"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 60, 0
						, 60, 60, RGB(255, 0, 255));
					++m_iPatten2ChangeCount;
				}
				else if(false == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change2"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 65, 0
						, 65, 60, RGB(255, 0, 255));
				}
			}
			else
			{
				HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2FireR"))->GetMemDC();

				TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
					, hMemDC, m_tFrame.iFrameStart * 55, 0
					, 55, 55, RGB(255, 0, 255));
			}
		}
		m_fOldx = m_tInfo.vPos.x;
	}
	else if(false == m_bBossChange)
	{
		if(m_fOldx >= m_tInfo.vPos.x)
		{
			if(true == m_bBossHit)
			{
				if(true == m_bHitEffect)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2IceHit"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 45, 0
						, 45, 60, RGB(255, 0, 255));

					m_bHitEffect = false;
				}
				else if(false == m_bHitEffect)
				{
					m_bHitEffect = true;
				}

			}
			else if(2 == m_iPatten)
			{
				if(true == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change1"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 60, 0
						, 60, 60, RGB(255, 0, 255));
					++m_iPatten2ChangeCount;
				}
				else if(false == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change2"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 65, 0
						, 65, 60, RGB(255, 0, 255));
				}
			}
			else
			{
				HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Ice"))->GetMemDC();

				TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
					, hMemDC, m_tFrame.iFrameStart * 55, 0
					, 55, 55, RGB(255, 0, 255));
			}
		}
		else if (m_fOldx < m_tInfo.vPos.x)
		{
			if(true == m_bBossHit)
			{
				if(true == m_bHitEffect)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2IceHitR"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 45, 0
						, 45, 60, RGB(255, 0, 255));

					m_bHitEffect = false;
				}
				else if(false == m_bHitEffect)
				{
					m_bHitEffect = true;
				}

			}
			else if(2 == m_iPatten)
			{
				if(true == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change1"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 60, 0
						, 60, 60, RGB(255, 0, 255));
					++m_iPatten2ChangeCount;
				}
				else if(false == m_bPattenChange)
				{
					HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2Change2"))->GetMemDC();

					TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
						, hMemDC, m_tFrame.iFrameStart * 65, 0
						, 65, 60, RGB(255, 0, 255));
				}
			}
			else
			{
			HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss2IceR"))->GetMemDC();

			TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
				, hMemDC, m_tFrame.iFrameStart * 55, 0
				, 55, 55, RGB(255, 0, 255));
			}
		}
		m_fOldx = m_tInfo.vPos.x;
	}
	
}

void CBoss2::Release()
{

}

void CBoss2::BossPatten(int iPatten)
{
	switch(iPatten)
	{
	case 1:
		{
			if(CObjMgr::GetInstance()->GetList(PLAYER).empty())
			{
			}
			else
				m_tInfo.vDir = CObjMgr::GetInstance()->GetObj(PLAYER)->GetInfo().vPos - this->m_tInfo.vPos;

			float fDist = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

			m_tInfo.vDir.x /= fDist;
			m_tInfo.vDir.y /= fDist;
			m_tInfo.vDir.z = 0.f;

			m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

			if(30 == m_iBulletCount)
			{
				if(true == m_bBossChange)
					CreateBullet1();
				else if(false == m_bBossChange)
					CreateBullet2();

				m_iBulletCount = 0;
			}

			++m_iBulletCount;
		}
		break;
	case 2:
		if(15 == m_iBulletCount)
		{
			m_fAngle -= 20.f;
			CreateBullet3();
			m_iBulletCount = 0;
			++m_iPatten2ShotCount;
		}

		if(5 == m_iPatten2ShotCount)
		{
			m_bPattenChange = true;
			m_iPatten2ShotCount = 0;
			m_iBulletCount = 0;
			m_iPatten = 1;
		}

		++m_iBulletCount;
		break;
	}
}

void CBoss2::CreateBullet1()
{
	CObj* pBullet = CAbstract<CBoss2Bullet1>::CreateObj();
	dynamic_cast<CBoss2Bullet1*>(pBullet)->SetDir(m_tInfo.vDir.x, m_tInfo.vDir.y);
	dynamic_cast<CBoss2Bullet1*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);
}

void CBoss2::CreateBullet2()
{
	CObj* pBullet = CAbstract<CBoss2Bullet2>::CreateObj();
	dynamic_cast<CBoss2Bullet2*>(pBullet)->SetDir(m_tInfo.vDir.x, m_tInfo.vDir.y);
	dynamic_cast<CBoss2Bullet2*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);
}

void CBoss2::CreateBullet3()
{
	CObj* pBullet = CAbstract<CBoss2Bullet3>::CreateObj();
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetAngle(m_fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	float fAngle = m_fAngle - 30.f;

	pBullet = CAbstract<CBoss2Bullet4>::CreateObj();
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle + 30.f;

	pBullet = CAbstract<CBoss2Bullet4>::CreateObj();
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle - 60.f;

	pBullet = CAbstract<CBoss2Bullet3>::CreateObj();
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle + 60.f;

	pBullet = CAbstract<CBoss2Bullet3>::CreateObj();
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle - 90.f;

	pBullet = CAbstract<CBoss2Bullet4>::CreateObj();
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle + 90.f;

	pBullet = CAbstract<CBoss2Bullet4>::CreateObj();
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle - 120.f;

	pBullet = CAbstract<CBoss2Bullet3>::CreateObj();
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle + 120.f;

	pBullet = CAbstract<CBoss2Bullet3>::CreateObj();
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle - 150.f;

	pBullet = CAbstract<CBoss2Bullet4>::CreateObj();
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle + 150.f;

	pBullet = CAbstract<CBoss2Bullet4>::CreateObj();
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet4*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);

	fAngle = m_fAngle - 180.f;

	pBullet = CAbstract<CBoss2Bullet3>::CreateObj();
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetPosXY(m_tInfo.vPos.x, m_tInfo.vPos.y);
	dynamic_cast<CBoss2Bullet3*>(pBullet)->SetAngle(fAngle);
	CObjMgr::GetInstance()->AddObject(pBullet, MONSTER_BULLET);
}

void CBoss2::DamagedMotion()
{
	if(m_bIsDamaged)
	{
		if(m_iDamagedCnt == 0)		//	처음 데미지 받았을 때
		{

			--m_fHp;

			if(m_fHp < 0)
			{
				m_bIsDead = true;
				return;
			}

			++m_iDamagedCnt;
		}
		if(m_iDamagedCnt > 30)		//	데미지 시간 끝
		{
			m_iDamagedCnt = 0;
			m_bIsDamaged = false;
		}
		else						//	데미지 중
		{
			++m_iDamagedCnt;
		}
	}
}
