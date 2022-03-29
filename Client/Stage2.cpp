#include "StdAfx.h"
#include "Stage2.h"
#include "Player.h"
#include "Door.h"
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

CStage2::CStage2(void)
{
}

CStage2::~CStage2(void)
{
	Release();
}


void CStage2::Initialize()
{
	g_iMaxSizeX = 3200;
	g_iMaxSizeY = 900;

	g_iScrollX = 0;
	g_iScrollY = 0;

	CBmpMgr::GetInstance()->LoadByScene(STAGE2);
	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(250.f , 50.f);
	CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();

	CTileMgr::GetInstance()->LoadData(L"../Data/Stage2.dat");

//	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(200.f, 100.f);

	CObjMgr::GetInstance()->AddObject(CAbstract<CDoor>::CreateObj(3090.f,748.f, 0.f), UI_DOOR);


	CObj* obj = CAbstract<CMonster01>::CreateObj();
	obj->SetPos(500.f, 130.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster01>::CreateObj();
	obj->SetPos(700.f, 690.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster02>::CreateObj();
	obj->SetPos(700.f, 330.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);
	
	obj = CAbstract<CMonster03>::CreateObj();
	obj->SetPos(1200.f, 500.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster04>::CreateObj();
	obj->SetPos(1000.f, 300.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster05>::CreateObj();
	obj->SetPos(1300.f, 700.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster06>::CreateObj();
	obj->SetPos(2100.f, 500.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster07>::CreateObj();
	obj->SetPos(2500.f, 325.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster08>::CreateObj();
	obj->SetPos(1700.f, 150.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster09>::CreateObj();
	obj->SetPos(3000.f, 200.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster10>::CreateObj();
	obj->SetPos(1900.f, 400.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);

	obj = CAbstract<CMonster11>::CreateObj();
	obj->SetPos(3100.f, 500.f);
	CObjMgr::GetInstance()->AddObject(obj, MONSTER);
	CSoundMgr::GetInstance()->PlayBGM(L"title-screen.mp3", CSoundMgr::Channel_BGM);
}
int CStage2::Update()
{
	CObjMgr::GetInstance()->UpdateObj();
	CTileMgr::GetInstance()->Update();
	CCollision::CollisionPlayer(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile());
	CCollision::CollisionList(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(MONSTER)));
	CCollision::CollisionPlayer(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile());
	CCollision::CollisionList(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(MONSTER)));
	CCollision::CollisionDoor(CObjMgr::GetInstance()->GetObj(PLAYER), CObjMgr::GetInstance()->GetObj(UI_DOOR), BOSS_STAGE1);
	return 0;
}
void CStage2::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Stage2"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, -g_iScrollY, SRCCOPY);
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CStage2::Release()
{
	//CObjMgr::GetInstance()->ReleaseObj(UI);
	CObjMgr::GetInstance()->ReleaseObj(MONSTER);
	CObjMgr::GetInstance()->ReleaseObj(UI_DOOR);
	CTileMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);
}