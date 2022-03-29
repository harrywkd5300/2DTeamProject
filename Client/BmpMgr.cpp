#include "StdAfx.h"
#include "BmpMgr.h"

IMPLEMENT_SINGLETON(CBmpMgr)

CBmpMgr::CBmpMgr(void)
{
}

CBmpMgr::~CBmpMgr(void)
{
	Release();
}
void CBmpMgr::LoadByScene(Scene eScene)
{
	switch(eScene)
	{
	case MENU:
		m_Mapbit.insert(
			make_pair(L"Menu", (new CMyBitmap)->LoadBmp(L"../Image/UI/Menu.bmp")));
		m_Mapbit.insert(
			make_pair(L"Title", (new CMyBitmap)->LoadBmp(L"../Image/UI/Title.bmp")));
		m_Mapbit.insert(
			make_pair(L"Start", (new CMyBitmap)->LoadBmp(L"../Image/UI/GameStart.bmp")));
		m_Mapbit.insert(
			make_pair(L"Edit", (new CMyBitmap)->LoadBmp(L"../Image/UI/Edit.bmp")));
		break;
	case EDIT:
		m_Mapbit.insert(
			make_pair(L"Stage1", (new CMyBitmap)->LoadBmp(L"../Image/map/Stage2.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOff", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileDoorOff.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOn", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileDoorOn.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileFalse", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileFalse.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileTrue", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileTrue.bmp")));
		break;
	case STAGE1:
		m_Mapbit.insert(
			make_pair(L"Stage1", (new CMyBitmap)->LoadBmp(L"../Image/Map/Stage1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster1", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster1.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR1", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster2", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster2.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR2", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR2.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster3", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster3.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR3", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR3.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster4", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster4.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR4", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR4.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster5", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster5.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR5", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR5.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster6", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster6.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR6", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR6.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster7", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster7.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR7", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR7.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster8", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster8.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR8", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR8.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster9", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster9.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR9", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR9.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster10", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster10.bmp")));
		m_Mapbit.insert(
			make_pair(L"MonsterR10", (new CMyBitmap)->LoadBmp(L"../Image/Monster/MonsterR10.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster8Bullet1", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster8Bullet1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster8Bullet2", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster8Bullet2.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster11", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster11.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOff", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileDoorOff.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileDoorOn", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileDoorOn.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileFalse", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileFalse.bmp")));
		m_Mapbit.insert(
			make_pair(L"TileTrue", (new CMyBitmap)->LoadBmp(L"../Image/tile/TileTrue.bmp")));
		m_Mapbit.insert(
			make_pair(L"Sea", (new CMyBitmap)->LoadBmp(L"../Image/UI/Sea.bmp")));
		m_Mapbit.insert(
			make_pair(L"Item2", (new CMyBitmap)->LoadBmp(L"../Image/UI/Item2.bmp")));
		m_Mapbit.insert(
			make_pair(L"Door", (new CMyBitmap)->LoadBmp(L"../Image/UI/Door.bmp")));
		break;
	case STAGE2:
		m_Mapbit.insert(
			make_pair(L"Stage2", (new CMyBitmap)->LoadBmp(L"../Image/Map/Stage2.bmp")));
		break;
	case BOSS_STAGE1:
		m_Mapbit.insert(
			make_pair(L"BossStage1", (new CMyBitmap)->LoadBmp(L"../Image/Map/BossStage1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster8Bullet1", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster8Bullet1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Monster8Bullet2", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Monster8Bullet2.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss1", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss1/Boss1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss1Hit", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss1/Boss1Hit.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss1Hide2", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss1/Boss1Hide2.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss1Bullet1", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss1/Boss1Bullet1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss1Bullet2", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss1/Boss1Bullet2.bmp")));
		break;
	case BOSS_STAGE2:
		m_Mapbit.insert(
			make_pair(L"BossStage2", (new CMyBitmap)->LoadBmp(L"../Image/Map/BossStage2.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2Fire", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2Fire.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2FireR", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2FireR.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2Ice", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2Ice.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2IceR", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2IceR.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2FireBullet", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2FireBullet.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2IceBullet", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2IceBullet.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2FireHit", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2FireHit.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2IceHit", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2IceHit.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2FireHitR", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2FireHitR.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2IceHitR", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2IceHitR.bmp")));
			m_Mapbit.insert(
			make_pair(L"Boss2Change1", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2Change1.bmp")));
		m_Mapbit.insert(
			make_pair(L"Boss2Change2", (new CMyBitmap)->LoadBmp(L"../Image/Monster/Boss2/Boss2Change2.bmp")));
		break;
	}
}

void CBmpMgr::Release()
{
	map<const TCHAR*, CMyBitmap*>::iterator iter_begin = m_Mapbit.begin();
	map<const TCHAR*, CMyBitmap*>::iterator iter_end = m_Mapbit.end();

	for(; iter_begin != iter_end; ++iter_begin)
		safeDelete<CMyBitmap*>(iter_begin->second);
	m_Mapbit.clear();
}

CMyBitmap* CBmpMgr::FindBmp(const TCHAR* pFindKey)
{
	map<const TCHAR*, CMyBitmap*>::iterator iter_find = find_if(m_Mapbit.begin()
		, m_Mapbit.end(), CStringCmp(pFindKey));

	if(iter_find == m_Mapbit.end())
		return NULL;

	return iter_find->second;
}
