#include "StdAfx.h"
#include "Player.h"
#include "BossStage1.h"
#include "Monster01.h"
#include "Monster02.h"
#include "Monster03.h"
#include "Monster04.h"
#include "Monster05.h"
#include "Monster06.h"
#include "Monster07.h"
#include "Monster08.h"
#include "Monster09.h"
#include "Monster10.h"
#include "Monster11.h"
#include "Boss1.h"
#include "Boss2.h"
#include "Door.h"

CBossStage1::CBossStage1(void)
{
}

CBossStage1::~CBossStage1(void)
{
	Release();
}

void CBossStage1::Initialize()
{
	srand(unsigned(time(NULL)));

	g_iMaxSizeX = WINCX;
	g_iMaxSizeY = WINCY;
	CBmpMgr::GetInstance()->LoadByScene(BOSS_STAGE1);

	/*CObjMgr::GetInstance()->AddObject(CAbstract<CMonster01>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster02>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster03>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster04>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster05>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster06>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster07>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster08>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster09>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster10>::CreateObj(), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster11>::CreateObj(), MONSTER);*/
	CObjMgr::GetInstance()->AddObject(CAbstract<CBoss1>::CreateObj(), BOSS);

	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(100.f , 50.f);
	CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();

	CTileMgr::GetInstance()->LoadData(L"../Data/BossStage1.dat");
	CSoundMgr::GetInstance()->PlayBGM(L"boss.mp3", CSoundMgr::Channel_BGM);
	b_MakeDoor = false;
	b_MakeDoor2 = false;
}
int CBossStage1::Update()
{
	if(CObjMgr::GetInstance()->GetList(BOSS).empty())
		b_MakeDoor = true;

	if(b_MakeDoor)
	{
		if (CObjMgr::GetInstance()->GetList(UI_DOOR).empty())
		{
			CObjMgr::GetInstance()->AddObject(CAbstract<CDoor>::CreateObj(500.f,450.f, 0.f), UI_DOOR);			
		}
		CCollision::CollisionDoor(CObjMgr::GetInstance()->GetObj(PLAYER), CObjMgr::GetInstance()->GetObj(UI_DOOR), BOSS_STAGE2);
	}
	CObjMgr::GetInstance()->UpdateObj();
	CTileMgr::GetInstance()->Update();
	CCollision::CollisionPlayer(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile());
	//CCollision::CollisionList(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(MONSTER)));
	CCollision::CollisionBoss1(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(BOSS)));
	CCollision::CollisionBullet(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(MONSTER_BULLET)));
	return 0;
}
void CBossStage1::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"BossStage1"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CBossStage1::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(UI_DOOR);
	CObjMgr::GetInstance()->ReleaseObj(BOSS);
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);
}