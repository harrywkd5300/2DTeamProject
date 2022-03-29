#include "StdAfx.h"
#include "Player.h"
#include "HpBar.h"
#include "HpBar2.h"

#define MAX_ATT_CNT 40		//	공격하는 시간
#define MAX_DMG_CNT 50		//	데미지 받은 후 무적 시간

//	씬에서
//	CObj* m_pPlayer;
//	m_pPlayer = CAbstract<CPlayer>::CreateObj();

CPlayer::CPlayer(void)
{
}

CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::initirize()
{
	//	플레이어 위치
	//m_tInfo.vPos.x = 150.f;
	//m_tInfo.vPos.y = 100.f;
	//m_tInfo.vPos.z = 0.f;
	m_bTileView = false;

	m_bIsCollisionTail = false;
	m_tInfo.vLook = D3DXVECTOR3(1.f, 0.f, 0.f);
	m_tInfo.vDir = D3DXVECTOR3(1.f, 0.f, 0.f);

	//	플레이어 크기
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	//	플레이어 정보 초기화
	m_fAngle = 0.f;
	m_fSpeed = 8.f;
	m_fHp = 5;
	m_bIsDead = false;
	m_bIsWater = false;;
	m_bIsJump = false;
	m_bIsAttack = false;
	m_fJumpAcc = 0.0f;
	m_iAttCount = 0;
	m_bIsDamaged = false;
	m_iDamagedCnt = 0;
	m_bIsShock = false;
	m_iShockCnt = 0;
	m_iShockTime = 0;
	m_bIsFly = false;

	m_bIsRun = false;
	m_iAttEnd = 1;
	m_iPushCnt = 0;

	m_fJumpAngle = 0.f;

	m_bIsAttPush = false;
	m_iAttPushCnt = 0;


	//	플레이어 애니메이션
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iScene = 0;
	m_tFrame.dwFrameSpd = 150;
	m_tFrame.dwFrameOld = GetTickCount();
	m_pFrameKey = L"Player_Idle";

	m_eCurState = IDLE;
	m_ePreState = m_eCurState;

	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Idle", (new CMyBitmap)->LoadBmp(L"../Image/Player/idle.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Idle_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/idle_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Idle_Water", (new CMyBitmap)->LoadBmp(L"../Image/Player/water_idle.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Idle_Water_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/water_idle_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Run", (new CMyBitmap)->LoadBmp(L"../Image/Player/run.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Run_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/run_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Run_Water", (new CMyBitmap)->LoadBmp(L"../Image/Player/water_run.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Run_Water_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/water_run_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Run_Water_U", (new CMyBitmap)->LoadBmp(L"../Image/Player/water_run_U.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Run_Water_D", (new CMyBitmap)->LoadBmp(L"../Image/Player/water_run_D.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Walk", (new CMyBitmap)->LoadBmp(L"../Image/Player/walk.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Walk_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/walk_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Attack", (new CMyBitmap)->LoadBmp(L"../Image/Player/attack.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Damaged", (new CMyBitmap)->LoadBmp(L"../Image/Player/damaged.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Damaged_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/damaged_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Shock", (new CMyBitmap)->LoadBmp(L"../Image/Player/shock.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Jump", (new CMyBitmap)->LoadBmp(L"../Image/Player/jump.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Jump_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/jump_L.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Fly", (new CMyBitmap)->LoadBmp(L"../Image/Player/fly.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"Player_Fly_L", (new CMyBitmap)->LoadBmp(L"../Image/Player/fly_L.bmp")));


	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"HpBar2", (new CMyBitmap)->LoadBmp(L"../Image/UI/HpBar2.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(make_pair(L"HpBar1", (new CMyBitmap)->LoadBmp(L"../Image/UI/HpBar1.bmp")));

	//	점 초기화, 좌측 상단부터 시계 방향
	m_vPoint[0] = D3DXVECTOR3(m_tInfo.vPos.x - m_tInfo.fCX / 2.f, m_tInfo.vPos.y - m_tInfo.fCY / 2.f, 0.f);
	m_vPoint[1] = D3DXVECTOR3(m_tInfo.vPos.x + m_tInfo.fCX / 2.f, m_tInfo.vPos.y - m_tInfo.fCY / 2.f, 0.f);
	m_vPoint[2] = D3DXVECTOR3(m_tInfo.vPos.x + m_tInfo.fCX / 2.f, m_tInfo.vPos.y + m_tInfo.fCY / 2.f, 0.f);
	m_vPoint[3] = D3DXVECTOR3(m_tInfo.vPos.x - m_tInfo.fCX / 2.f, m_tInfo.vPos.y + m_tInfo.fCY / 2.f, 0.f);

	for(int i = 0; i < 4; ++i)
		m_vOriginal[i] = m_vPoint[i];

	////	플레이어 충돌 렉트
	//m_tRect.left = static_cast<long>(m_vPoint[0].x);
	//m_tRect.top = static_cast<long>(m_vPoint[0].y);
	//m_tRect.right = static_cast<long>(m_vPoint[2].x);
	//m_tRect.bottom = static_cast<long>(m_vPoint[2].y);

	m_fCollisionX = 70.f;
	m_fCollisionY = 70.f;

	if(m_firstMake)
	{
		m_firstMake = false;
		CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar>::CreateObj(150.f, 550.f, 0.f), HP);
		CObjMgr::GetInstance()->AddObject(CAbstract<CHpBar2>::CreateObj(300.f, 550.f, 0.f), HP);
	}
	CollisionUpdate();
	CObj::Update();
}

int CPlayer::Update()
{
	if(m_bIsDead)
		return 1;


	Damaged();


	if(m_bIsShock)
	{
		++m_iShockTime;
		if(m_iShockTime > 50)
		{
			m_bIsShock = false;
			m_iShockTime = 0;
		}
		else
		{
			CObj::FrameMove();
			CObj::Update();
			return 0;
		}
	}

	KeyInput();
	Jump();
	Scroll();
	Attack();
	SuccessAtt();
	Run();
	Fly();

	CObj::Update();

	D3DXMatrixTranslation(&m_tInfo.matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
	D3DXMatrixScaling(&m_tInfo.matScale, 0.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&m_tInfo.matAngle, m_fAngle);

	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matAngle * m_tInfo.matTrans;

	for(int i = 0; i < 4; ++i)
	{
		m_vPoint[i] = m_vOriginal[i];
		m_vPoint[i] -= D3DXVECTOR3(400, 300, 0);
		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	StateChange();
	//CollisionUpdate();
	CObj::FrameMove();
	return 0;
}

void CPlayer::Render( HDC hdc )
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();

	TransparentBlt(hdc,int(m_tInfo.vPos.x - 100.f / 2.f) + g_iScrollX , int(m_tInfo.vPos.y - 100.f / 2.f) - 10 + g_iScrollY, 100, 100
		, hMemDC, m_tFrame.iFrameStart * 30, 0
		, 30, 30, RGB(0, 160, 184));

	if(m_bTileView)
		Rectangle(hdc, m_tRect.left + g_iScrollX, m_tRect.top + g_iScrollY, m_tRect.right + g_iScrollX, m_tRect.bottom + g_iScrollY);
	//Rectangle(hdc, m_rcCollision.left + g_iScrollX, m_rcCollision.top + g_iScrollY, m_rcCollision.right + g_iScrollX, m_rcCollision.bottom + g_iScrollY);
}

void CPlayer::Release()
{

}

void CPlayer::KeyInput()
{
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();

	if(KEYPRESS(dwKey, P))
	{
		if(m_bTileView)
			m_bTileView = false;
		else
			m_bTileView = true;
	}
	if (KEYPRESS(dwKey, V))
	{
		m_fHp = 5;
	}
	if(!m_bIsWater)		//	물 안에 있을 때
	{
		if(KEYPRESS(dwKey, KEY_LEFT))
		{
			m_tInfo.vDir = D3DXVECTOR3(-1.f, 0.f, 0.f);

			//	수영
			if(KEYPRESS(dwKey, Z))
			{
				m_fSpeed = 16.f;
				m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Run_Water_L";
					m_eCurState = RUN_WATER;
				}
			}
			else
			{
				m_fSpeed = 8.f;
				m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Idle_Water_L";
					m_eCurState = IDLE_WATER;
				}
			}
		}
		else if(KEYPRESS(dwKey, KEY_RIGHT))
		{
			m_tInfo.vDir = D3DXVECTOR3(1.f, 0.f, 0.f);

			//	수영
			if(KEYPRESS(dwKey, Z))
			{
				m_fSpeed = 16.f;
				m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Run_Water";
					m_eCurState = RUN_WATER;
				}
			}
			else
			{
				m_fSpeed = 8.f;
				m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Idle_Water";
					m_eCurState = IDLE_WATER;
				}
			}
		}
		else if(KEYPRESS(dwKey, KEY_DOWN))
		{
			m_tInfo.vDir = D3DXVECTOR3(0.f, 1.f, 0.f);
			//	수영
			if(KEYPRESS(dwKey, Z))
			{
				m_fSpeed = 16.f;
				m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Run_Water_D";
					m_eCurState = RUN_WATER;
				}
			}
			else
			{
				m_fSpeed = 8.f;
				m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Idle_Water";
					m_eCurState = IDLE_WATER;
				}
			}
		}
		else if(KEYPRESS(dwKey, KEY_UP))
		{
			m_tInfo.vDir = D3DXVECTOR3(0.f, -1.f, 0.f);

			//	수영
			if(KEYPRESS(dwKey, Z))
			{
				m_fSpeed = 16.f;
				m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Run_Water_U";
					m_eCurState = RUN_WATER;
				}
			}
			else
			{
				m_fSpeed = 8.f;
				m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Idle_Water";
					m_eCurState = IDLE_WATER;
				}
			}
		}
		else
		{
			if(!m_bIsAttack && !m_bIsDamaged)
			{
				if(m_tInfo.vDir.x < 0)
					m_pFrameKey = L"Player_Idle_Water_L";
				else
					m_pFrameKey = L"Player_Idle_Water";
				m_eCurState = IDLE_WATER;
			}
		}

		if(KEYPRESS(dwKey, X))
		{
			if(!m_bIsAttack)
				m_bIsAttack = true;
			else
			{
				++m_iShockCnt;

				if(m_iShockCnt > 10)
				{
					m_bIsShock = true;
					m_eCurState = SHOCK;
					m_pFrameKey = L"Player_Shock";
				}
			}
		}
	}

	else				//	물 밖에 있을 때
	{

		if(KEYPRESS(dwKey, KEY_LEFT))
		{
			if(!m_bIsFly)
			{
				m_fSpeed = 8.f;
				m_tInfo.vDir = D3DXVECTOR3(-1.f, 0.f, 0.f);
				m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
				if(!m_bIsAttack && !m_bIsDamaged)

				{
					m_pFrameKey = L"Player_Walk_L";
					m_eCurState = WALK;
				}
			}
			else
			{
				m_fSpeed = 16.f;
				m_tInfo.vDir = D3DXVECTOR3(-1.f, 0.f, 0.f);
				m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
			}
		}
		else if(KEYPRESS(dwKey, KEY_RIGHT))
		{
			if(!m_bIsFly)
			{
				m_fSpeed = 8.f;
				m_tInfo.vDir = D3DXVECTOR3(1.f, 0.f, 0.f);
				m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

				if(!m_bIsAttack && !m_bIsDamaged)
				{
					m_pFrameKey = L"Player_Walk";
					m_eCurState = WALK;
				}
			}
			else
			{
				m_fSpeed = 16.f;
				m_tInfo.vDir = D3DXVECTOR3(1.f, 0.f, 0.f);
				m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
			}
		}
		else if(KEYPRESS(dwKey, KEY_DOWN))
		{
			if(m_bIsFly)
			{
				m_fSpeed = 16.f;
				m_tInfo.vDir = D3DXVECTOR3(0.f, 1.f, 0.f);
				m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
			}
		}
		else
		{
			if(!m_bIsAttack && !m_bIsDamaged)
			{
				if(m_tInfo.vDir.x < 0)
					m_pFrameKey = L"Player_Idle_L";
				else
					m_pFrameKey = L"Player_Idle";
				m_eCurState = IDLE;
			}
		}


		if(KEYPRESS(dwKey, Z))
		{
			if(!m_bIsJump)
			{
				m_bIsJump = true;
			}

			if(m_fJumpAcc > 5.0f)
			{
				m_fJumpAcc = 0.f;
				m_bIsJump = false;
				m_bIsFly = true;
			}
		}


		if(KEYPRESS(dwKey, X))
		{
			if(!m_bIsAttack)
				m_bIsAttack = true;

			if(m_iAttEnd == 2)
			{
				m_bIsRun = true;
			}
		}
		if (KEYPRESS(dwKey, C))
		{
			m_bIsRun = true;
		}
		else
		{
			m_bIsRun = false;
		}
	}
}

void CPlayer::Jump( void )
{
	if(m_bIsWater)	//	물 밖에서
	{
		if(m_bIsJump)	//	점프
		{
			m_fJumpAcc += 0.3f;

			if(m_fJumpAcc > 12.f)
				m_fJumpAcc = 12.f;

			float fJumpY = 4.f * m_fJumpAcc - 0.98f * m_fJumpAcc * m_fJumpAcc * 0.5f;

			m_tInfo.vPos.y -= fJumpY;

			m_eCurState = JUMP;
			if(m_tInfo.vDir.x > 0)
				m_pFrameKey = L"Player_Jump";
			else
				m_pFrameKey = L"Player_Jump_L";

			if(m_bIsCollisionTail)
			{
				m_fJumpAcc = 0.f;
				m_bIsCollisionTail = false;
				m_bIsJump = false;
				if(m_tInfo.vDir.x > 0)
					m_pFrameKey = L"Player_Idle";
				else
					m_pFrameKey = L"Player_Idle_L";
				m_eCurState = IDLE;
			}

			//if(m_tInfo.vPos.y >= 100)	//	땅과 충돌했을 때, 400을 땅의 높이로 바꿔야 함
			//{
			//	m_fJumpAcc = 0.f;
			//	m_bIsJump = false;
			//	//m_tInfo.vPos.y = 100; // - m_tInfo.CY / 2.f;
			//	if(m_tInfo.vDir.x > 0)
			//		m_pFrameKey = L"Player_Idle";
			//	else
			//		m_pFrameKey = L"Player_Idle_L";
			//	m_eCurState = IDLE;
			//}
		}
		else
		{
			if(!m_bIsCollisionTail)
			{
				m_tInfo.vPos.y += 5.f;
			}
		}

		//else if(!m_bIsJump && !m_bIsFly)
		//{
		//	m_tInfo.vPos.y = 100;	// - m_tInfo.CY / 2.f;
		//}
	}
	else	//	물 안에서 중력
	{
		if(m_eCurState == IDLE_WATER)
		{
			m_tInfo.vPos.y += 2.0f;
		}
	}
}

void CPlayer::Damaged( void )
{
	if(m_bIsDamaged)
	{
		if(m_iDamagedCnt == 0)		//	처음 데미지 받았을 때
		{
			if(m_tInfo.vDir.x > 0)
			{
				m_pFrameKey = L"Player_Damaged";
			}
			else
			{
				m_pFrameKey = L"Player_Damaged_L";
			}
			m_eCurState = DAMAGED;

			--m_fHp;

			if(m_fHp <= 0)
			{
				m_bIsDead = true;
				return;
			}

			++m_iDamagedCnt;
		}
		if(m_iDamagedCnt > MAX_DMG_CNT)		//	데미지 시간 끝
		{
			m_iDamagedCnt = 0;
			m_bIsDamaged = false;
			m_iPushCnt = 0;
		}
		else						//	데미지 중
		{
			++m_iDamagedCnt;
			++m_iPushCnt;

			if(m_iPushCnt < 10)
			{
				//	밀려나는 부분
				if(m_tInfo.vDir.x < 0)
				{
					m_tInfo.vPos.x -= m_tInfo.vDir.x * 10.f;
				}
				else
				{
					m_tInfo.vPos.x -= m_tInfo.vDir.x * 10.f;
				}

				if (m_tInfo.vDir.y > 0)
				{
					m_tInfo.vPos.y -= m_tInfo.vDir.y * 10.f;
				}
				else
				{
					m_tInfo.vPos.y -= m_tInfo.vDir.y * 10.f;
				}
			}
		}
	}
}

void CPlayer::Attack(void)
{
	if(m_bIsAttack)
	{
		if(m_iAttCount > MAX_ATT_CNT)	//	공격 끝
		{
			m_iAttCount = 0;
			m_bIsAttack = false;
			m_iShockCnt = 0;
			m_iAttEnd = 2;

		}
		else if (m_iAttCount == 0)	//	공격 시작
		{
			m_pFrameKey = L"Player_Attack";
			m_eCurState = ATTACK;
			++m_iAttCount;
			m_iAttEnd = 0;
		}
		else						//	공격중
		{
			++m_iAttCount;
		}
	}
}
void CPlayer::Scroll()
{
	if(400 + 100 < m_tInfo.vPos.x + g_iScrollX)
		g_iScrollX -= (int)m_fSpeed;
	else if(400 - 100 > m_tInfo.vPos.x + g_iScrollX)
		g_iScrollX += (int)m_fSpeed;

	if(300 + 100 < m_tInfo.vPos.y + g_iScrollY)
		g_iScrollY -= (int)m_fSpeed;
	else if(300 - 100 > m_tInfo.vPos.y + g_iScrollY)
		g_iScrollY += (int)m_fSpeed;

	if(0 <= g_iScrollX)
		g_iScrollX = 0;
	else if(-g_iMaxSizeX + WINCX >= g_iScrollX)
		g_iScrollX = -g_iMaxSizeX + WINCX;

	if(0 <= g_iScrollY)
		g_iScrollY = 0;
	else if(-g_iMaxSizeY + WINCY >= g_iScrollY)
		g_iScrollY = -g_iMaxSizeY + WINCY;
}

void CPlayer::StateChange()
{
	if(m_eCurState != m_ePreState)
	{
		switch(m_eCurState)
		{
		case IDLE:			
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iScene = 0;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case WALK:			
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 6;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case IDLE_WATER:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 4;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case RUN_WATER:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 4;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case ATTACK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 30;
			m_tFrame.dwFrameOld = GetTickCount();
			break;
		case SHOCK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 80;
			m_tFrame.dwFrameOld = GetTickCount();			
			break;
		case JUMP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();			
			break;
		case RUN:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 80;
			m_tFrame.dwFrameOld = GetTickCount();			
			break;
		case FLY:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 150;
			m_tFrame.dwFrameOld = GetTickCount();			
			break;
		case DAMAGED:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iScene = 1;
			m_tFrame.dwFrameSpd = 100;
			m_tFrame.dwFrameOld = GetTickCount();			
			break;
		}
	}

	m_ePreState = m_eCurState;
}

void CPlayer::Fly( void )
{
	if(m_bIsFly)
	{
		//m_tInfo.vPos.y += 0.2f;

		if(m_tInfo.vDir.x > 0)
			m_pFrameKey = L"Player_Fly";
		else
			m_pFrameKey = L"Player_Fly_L";

		m_eCurState = FLY;

		if(m_bIsCollisionTail)
		{
			m_fJumpAcc = 0.f;
			m_bIsCollisionTail = false;
			m_bIsFly = false;
			if(m_tInfo.vDir.x > 0)
				m_pFrameKey = L"Player_Idle";
			else
				m_pFrameKey = L"Player_Idle_L";
			m_eCurState = IDLE;
		}
	}
}

void CPlayer::CollisionUpdate()
{
	m_rcCollision.left   = int(m_tInfo.vPos.x - m_fCollisionX / 2.f);
	m_rcCollision.top    = int(m_tInfo.vPos.y - m_fCollisionX / 2.f);
	m_rcCollision.right  = int(m_tInfo.vPos.x + m_fCollisionY / 2.f);
	m_rcCollision.bottom = int(m_tInfo.vPos.y + m_fCollisionY / 2.f);
}

void CPlayer::Run()
{
	if(m_bIsRun)
	{
		if(m_tInfo.vDir.x < 0)
			m_pFrameKey = L"Player_Run_L";
		else
			m_pFrameKey = L"Player_Run";
		m_eCurState = RUN;

		m_fSpeed = 10.f;
		m_tInfo.vPos.x += m_tInfo.vDir.x * (m_fSpeed);
	}
}

void CPlayer::SuccessAtt( void )
{
	if(m_bIsAttPush)
	{
		if(m_iAttPushCnt == 0)
		{
			++m_iAttPushCnt;
		}
		else if(m_iAttPushCnt > 20)
		{
			m_bIsAttPush = false;
			m_iAttPushCnt = 0;
		}
		else
		{
			if(m_tInfo.vDir.x < 0)
			{
				m_tInfo.vPos.x -= m_tInfo.vDir.x * 5.f;
			}
			else
			{
				m_tInfo.vPos.x -= m_tInfo.vDir.x * 5.f;
			}

			if (m_tInfo.vDir.y > 0)
			{
				m_tInfo.vPos.y -= m_tInfo.vDir.y * 5.f;
			}
			else
			{
				m_tInfo.vPos.y -= m_tInfo.vDir.y * 5.f;
			}
			++m_iAttPushCnt;
		}
	}
}
