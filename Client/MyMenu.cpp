#include "StdAfx.h"
#include "MyMenu.h"
#include "Mouse.h"
#include "MenuObj.h"
#include "MyButton.h"

CMyMenu::CMyMenu(void)
{
}

CMyMenu::~CMyMenu(void)
{
	Release();
}
void CMyMenu::Initialize()
{
	CBmpMgr::GetInstance()->LoadByScene(MENU);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMenuObj>::CreateObj(), UI);
	CObjMgr::GetInstance()->AddObject(CAbstract<CMouse>::CreateObj(), MOUSE);
	CObjMgr::GetInstance()->AddObject(new CMyButton(L"Start", 200, 500, 116, 45), UI_BUTTON);	
	CObjMgr::GetInstance()->AddObject(new CMyButton(L"Edit", 600, 500, 116, 45), UI_BUTTON);
	CSoundMgr::GetInstance()->PlayBGM(L"menu.mp3", CSoundMgr::Channel_BGM);
}
int CMyMenu::Update()
{
	CObjMgr::GetInstance()->UpdateObj();
	return 0;
}
void CMyMenu::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Menu"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::GetInstance()->RenderObj(hDC);
}
void CMyMenu::Release()
{
	CObjMgr::GetInstance()->ReleaseObj(UI);
	CObjMgr::GetInstance()->ReleaseObj(UI_BUTTON);
	CSoundMgr::GetInstance()->StopSound(CSoundMgr::Channel_BGM);
}