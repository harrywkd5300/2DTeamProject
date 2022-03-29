#include "StdAfx.h"
#include "Stage1.h"
#include "Player.h"
#include "Sea.h"
#include "Item.h"
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

CStage1::CStage1(void)
{
}

CStage1::~CStage1(void)
{
	Release();
}

void CStage1::Initialize()
{
	g_iMaxSizeX = 3200;
	g_iMaxSizeY = 900;
	g_iScrollY = 304;

	CBmpMgr::GetInstance()->LoadByScene(STAGE1);
	CObjMgr::GetInstance()->AddObject(CAbstract<CPlayer>::CreateObj(100.f , 700.f , 0.f), PLAYER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CSea>::CreateObj(1150.f, 260.f, 0.f), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CSea>::CreateObj(3050.f, 230.f, 0.f), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CDoor>::CreateObj(3090.f,748.f, 0.f), UI_DOOR);
	
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster08>::CreateObj(500.f,80.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster09>::CreateObj(400.f,700.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster03>::CreateObj(300.f,300.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster04>::CreateObj(900.f,200.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster05>::CreateObj(1000.f,750.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster06>::CreateObj(1270.f,550.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster07>::CreateObj(1570.f,335.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster01>::CreateObj(1800.f,680.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster02>::CreateObj(2500.f,780.f, 0.f), MONSTER);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMonster10>::CreateObj(3000.f,150.f, 0.f), MONSTER);

	CTileMgr::GetInstance()->LoadData(L"../Data/Stage1.dat");
	CSoundMgr::GetInstance()->PlayBGM(L"stage-music-2.mp3", CSoundMgr::Channel_BGM);
}
int CStage1::Update()
{
	CObjMgr::GetInstance()->UpdateObj();
	CTileMgr::GetInstance()->Update();
	CCollision::CollisionPlayer(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile());
	CCollision::CollisionList(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(MONSTER)));
	CCollision::CollisionDoor(CObjMgr::GetInstance()->GetObj(PLAYER), CObjMgr::GetInstance()->GetObj(UI_DOOR), STAGE2);
	return 0;
}
void CStage1::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Stage1"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, -g_iScrollY, SRCCOPY);
	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CStage1::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(UI);
	CObjMgr::GetInstance()->ReleaseObj(UI_DOOR);
	CTileMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);	
}