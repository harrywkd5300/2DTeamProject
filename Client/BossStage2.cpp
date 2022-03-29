#include "StdAfx.h"
#include "BossStage2.h"
#include "Player.h"
#include "Boss2.h"

CBossStage2::CBossStage2(void)
{
}

CBossStage2::~CBossStage2(void)
{
	Release();
}

void CBossStage2::Initialize()
{
	g_iMaxSizeX = WINCX;
	g_iMaxSizeY = WINCY;
	CBmpMgr::GetInstance()->LoadByScene(BOSS_STAGE2);
	CTileMgr::GetInstance()->LoadData(L"../Data/BossStage2.dat");

	CObjMgr::GetInstance()->AddObject(CAbstract<CBoss2>::CreateObj(), BOSS);

	//CObjMgr::GetInstance()->AddObject(CAbstract<CPlayer>::CreateObj(200.f , 500.f , 0.f), PLAYER);

	CObjMgr::GetInstance()->GetObj(PLAYER)->SetPos(100.f , 50.f);
	CObjMgr::GetInstance()->GetObj(PLAYER)->initirize();
}
int CBossStage2::Update()
{
	CObjMgr::GetInstance()->UpdateObj();
	CTileMgr::GetInstance()->Update();
	CCollision::CollisionPlayer(CObjMgr::GetInstance()->GetObj(PLAYER), CTileMgr::GetInstance()->GetVecTile());
	CCollision::CollisionBoss2(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(BOSS)));
	CCollision::CollisionBullet(CObjMgr::GetInstance()->GetObj(PLAYER), &(CObjMgr::GetInstance()->GetList(MONSTER_BULLET)));
	return 0;
}
void CBossStage2::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"BossStage2"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	if(dynamic_cast<CPlayer*>(CObjMgr::GetInstance()->GetObj(PLAYER))->TileView())
		CTileMgr::GetInstance()->Render(hDC);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CBossStage2::Release()
{
}