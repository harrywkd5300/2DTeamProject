#include "StdAfx.h"
#include "Boss1.h"
#include "Boss1Bullet.h"

CBoss1::CBoss1(void)
:m_iPatten(1), m_bLeft(true), m_iCount(0),m_iPattenChange(0), m_bBossHit(false), m_iBossHitCount(0), m_bHitEffect(true), m_iShotCount(0)
{
}

CBoss1::~CBoss1(void)
{
	Release();
}

void CBoss1::initirize()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 7;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 70;
	m_tFrame.dwFrameOld = GetTickCount();

	m_tInfo.fCX = 120;
	m_tInfo.fCY = 120;

	m_fSpeed = 5.f;

	m_fHp = 10.f;
	m_fOldHp = m_fHp;

	m_tInfo.vPos = D3DXVECTOR3( 700, 420, 0.f );

	m_tInfo.vDir = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_tInfo.vLook = D3DXVECTOR3( 0.f, 0.f, 0.f );

	m_bIsDamaged = false;
	m_iDamagedCnt = 0;

}

int  CBoss1::Update()
{
	if(m_fHp <= 0)
	{
		return 1;
	}

	if(m_fOldHp > m_fHp)
	{
		m_bBossHit = true;
		m_tFrame.iFrameEnd = 1;
		m_fOldHp = m_fHp;
	}

	if(true == m_bBossHit)
		++m_iBossHitCount;

	if(25 == m_iBossHitCount)
	{
		m_tFrame.iFrameEnd = 7;
		m_iBossHitCount = 0;
		m_bBossHit = false;
	}

	if(80 == m_iShotCount)
	{
		m_iShotCount = 0;
		CreateBullet();
	}

	//if(GetAsyncKeyState(VK_SPACE))
	//	--m_fHp;

	DamagedMotion();
	BossPatten(m_iPatten);


	++m_iShotCount;
	CObj::FrameMove();
	CObj::Update();
	return 0;
}

void CBoss1::Render(HDC hdc)
{
	/*Rectangle(hdc, int(m_tInfo.vPos.x - m_tInfo.fCX / 2), int(m_tInfo.vPos.y - m_tInfo.fCY / 2),
	int(m_tInfo.vPos.x + m_tInfo.fCX / 2), int(m_tInfo.vPos.y + m_tInfo.fCY / 2) );*/


	if(true == m_bBossHit)
	{
		if(true == m_bHitEffect)
		{
			HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss1Hit"))->GetMemDC();

			TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
				, hMemDC, m_tFrame.iFrameStart * 45, 0
				, 45, 50, RGB(255, 0, 255));

			m_bHitEffect = false;
		}
		else if(false == m_bHitEffect)
		{
			m_bHitEffect = true;
		}

	}
	else if(8 == m_iPatten || 10 == m_iPatten || 11 == m_iPatten)
	{
		HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss1Hide2"))->GetMemDC();

		TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
			, hMemDC, m_tFrame.iFrameStart * 42, 0
			, 42, 40, RGB(255, 0, 255));
	}
	else
	{
		HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Boss1"))->GetMemDC();

		TransparentBlt(hdc,int(m_tInfo.vPos.x - 75) , int(m_tInfo.vPos.y -75), 150, 150
			, hMemDC, m_tFrame.iFrameStart * 42, 0
			, 42, 45, RGB(255, 0, 255));
	}

	
}

void CBoss1::Release()
{

}

void CBoss1::BossPatten(int iPatten)
{
	switch(iPatten)
	{
	case 1:
		if(true == m_bLeft)
		{
			m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

			m_tInfo.vDir.x = -1.f;
			m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

			++m_iCount;
		}
		else if(false == m_bLeft)
		{
			m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

			m_tInfo.vDir.x = 1.f;
			m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
			++m_iCount;
		}

		if(110 == m_iCount && true == m_bLeft)
		{
			m_iCount = 0;
			++m_iPattenChange;
			m_bLeft = false;
		}
		else if(110 == m_iCount && false == m_bLeft)
		{
			m_iCount = 0;
			++m_iPattenChange;
			m_bLeft = true;
		}

		if(4 == m_iPattenChange)
		{
			m_iPattenChange = 0;
			m_iCount = 0;
			++m_iPatten;
		}
		break;
	case 2:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.y = -1.f;
		m_tInfo.vPos += m_tInfo.vDir * 10;

		if(180 >= m_tInfo.vPos.y)
			++m_iPatten;
		break;
	case 3:
		if(true == m_bLeft)
		{
			m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

			m_tInfo.vDir.x = -1.f;
			m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

			++m_iCount;
		}
		else if(false == m_bLeft)
		{
			m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

			m_tInfo.vDir.x = 1.f;
			m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
			++m_iCount;
		}

		if(110 == m_iCount && true == m_bLeft)
		{
			m_iCount = 0;
			++m_iPattenChange;
			m_bLeft = false;
		}
		else if(110 == m_iCount && false == m_bLeft)
		{
			m_iCount = 0;
			++m_iPattenChange;
			m_bLeft = true;
		}

		if(3 == m_iPattenChange)
		{
			m_iPattenChange = 0;
			m_iCount = 0;
			++m_iPatten;
		}
		break;
	case 4:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.y = 1.f;
		m_tInfo.vPos += m_tInfo.vDir * 10;

		if(420 <= m_tInfo.vPos.y)
			++m_iPatten;
		break;
	case 5:
		if(28 >= m_iCount)
			m_tInfo.vDir.y = -1.f;
		else if(28 <= m_iCount)
			m_tInfo.vDir.y = 1.f;

		if(420 <= m_tInfo.vPos.y)
		{
			m_tInfo.vDir.x = 0.f;
			m_iCount = 0;
			++m_iPattenChange;
		}

		if(9 <= m_iPattenChange)
		{
			m_iCount = 0;
			m_iPattenChange = 0;
			++m_iPatten;
		}

		m_tInfo.vDir.x = +0.3f;
		m_tInfo.vPos += m_tInfo.vDir * 8;
		++m_iCount;
		break;
	case 6:
		if(28 >= m_iCount)
			m_tInfo.vDir.y = -1.f;
		else if(28 <= m_iCount)
			m_tInfo.vDir.y = 1.f;

		if(420 <= m_tInfo.vPos.y)
		{
			m_tInfo.vDir.x = 0.f;
			m_iCount = 0;
			++m_iPattenChange;
		}

		if(9 <= m_iPattenChange)
		{
			m_iCount = 0;
			m_iPattenChange = 0;
			++m_iPatten;
		}

		m_tInfo.vDir.x = -0.3f;
		m_tInfo.vPos += m_tInfo.vDir * 8;
		++m_iCount;
		break;
	case 7:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.y = -1.f;
		m_tInfo.vPos += m_tInfo.vDir * 10;

		if(180 >= m_tInfo.vPos.y)
			++m_iPatten;
		break;
	case 8:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = +1.f;
		m_tInfo.vPos += m_tInfo.vDir * 15;
		++m_iCount;

		if(40 == m_iCount)
		{
			m_iCount = 0;
			++m_iPatten;
		}
		break;
	case 9:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.y = 1.f;
		m_tInfo.vPos += m_tInfo.vDir * 10;

		if(420 <= m_tInfo.vPos.y)
			++m_iPatten;
		break;
	case 10:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = -1.f;
		m_tInfo.vPos += m_tInfo.vDir * 15;
		++m_iCount;

		if(44 == m_iCount)
		{
			m_iCount = 0;
			++m_iPatten;
		}
		break;
	case 11:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = 1.f;
		m_tInfo.vPos += m_tInfo.vDir * 15;
		++m_iCount;

		if(44 == m_iCount)
		{
			m_iCount = 0;
			++m_iPatten;
		}
		break;
	case 12:
		m_tInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);

		m_tInfo.vDir.x = -1.f;
		m_tInfo.vPos += m_tInfo.vDir * 15;

		if(700 >= m_tInfo.vPos.x)
		{
			m_bLeft = true;
			m_iPatten = 1;
		}
		break;
	}
}

void CBoss1::CreateBullet()
{
	float iXRand = float(rand() % 800);
	CObj* pBossBullet = CAbstract<CBoss1Bullet>::CreateObj();
	CObjMgr::GetInstance()->AddObject(pBossBullet, MONSTER_BULLET);
	dynamic_cast<CBoss1Bullet*>(pBossBullet)->SetXPos(iXRand);
}

void CBoss1::DamagedMotion()
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
