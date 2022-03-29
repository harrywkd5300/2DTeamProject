#include "StdAfx.h"
#include "Maingame.h"

int g_iScrollX = 0;
int g_iScrollY = 0;
int g_iMaxSizeX = 0;
int g_iMaxSizeY = 0;

CMaingame::CMaingame(void)
{
}

CMaingame::~CMaingame(void)
{
	Release();
}
void CMaingame::initirize()
{
	CSoundMgr::GetInstance()->LoadSoundFile();
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"Back", (new CMyBitmap)->LoadBmp(L"../Image/BackBuffer/Back.bmp")));
	CBmpMgr::GetInstance()->GetMapbit().insert(
		make_pair(L"BackBuffer", (new CMyBitmap)->LoadBmp(L"../Image/BackBuffer/BackBuffer.bmp")));
	m_hdc = GetDC(g_hwnd);

	CSceneMgr::GetInstance()->SetScene(MENU);
}
void CMaingame::Update()
{	
	CSoundMgr::GetInstance()->UpdateSound();
	CKeyMgr::GetInstance()->KeyCheck();
	CSceneMgr::GetInstance()->Update();
}
void CMaingame::Render()
{
	HDC BackBuf = (CBmpMgr::GetInstance()->GetMapbit()[L"BackBuffer"])->GetMemDC();
	HDC MemDC = (CBmpMgr::GetInstance()->GetMapbit()[L"Back"])->GetMemDC();
	BitBlt(BackBuf, 0, 0, WINCX, WINCY, MemDC, 0, 0, SRCCOPY);
	CSceneMgr::GetInstance()->Render(BackBuf);
	BitBlt(m_hdc, 0, 0, WINCX, WINCY, BackBuf, 0, 0, SRCCOPY);	
	
}
void CMaingame::Release()
{
	CSoundMgr::GetInstance()->DestroyInstance();
	CSceneMgr::GetInstance()->DestroyInstance();
	CBmpMgr::GetInstance()->DestroyInstance();
	CObjMgr::GetInstance()->DestroyInstance();
	ReleaseDC(g_hwnd, m_hdc);
}