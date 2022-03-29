#include "StdAfx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "MyMenu.h"
#include "Stage1.h"
#include "Stage2.h"
#include "BossStage1.h"
#include "BossStage2.h"
#include "MyEdit.h"


IMPLEMENT_SINGLETON(CSceneMgr)

CSceneMgr::CSceneMgr(void)
:m_pScene(NULL)
{
}

CSceneMgr::~CSceneMgr(void)
{
	Release();
}
void CSceneMgr::SetScene(Scene eType)
{
	if(m_pScene)
		safeDelete<CScene*>(m_pScene);

	switch(eType)
	{
	case MENU:
		m_pScene = new CMyMenu;
		break;
	case STAGE1:
		m_pScene = new CStage1;
		break;
	case STAGE2:
		m_pScene = new CStage2;
		break;
	case BOSS_STAGE1:
		m_pScene = new CBossStage1;
		break;
	case BOSS_STAGE2:
		m_pScene = new CBossStage2;
		break;
	case EDIT:
		m_pScene = new CMyEdit;
		break;
	}
	m_pScene->Initialize();
	m_eCurScene = eType;
}

void CSceneMgr::Update()
{
	m_pScene->Update();
}
void CSceneMgr::Render(HDC hdc)
{
	m_pScene->Render(hdc);
}

void CSceneMgr::Release()
{
	safeDelete<CScene*>(m_pScene);
}