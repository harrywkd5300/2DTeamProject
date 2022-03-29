#include "StdAfx.h"
#include "MyEdit.h"
#include "Mouse.h"
//#include "Tile.h"

CMyEdit::CMyEdit(void)
{
}

CMyEdit::~CMyEdit(void)
{
	CTileMgr::GetInstance()->SaveData();
	Release();
}

void CMyEdit::Initialize()
{
	g_iMaxSizeX = 3200;
	g_iMaxSizeY = 900;
	CBmpMgr::GetInstance()->LoadByScene(EDIT);

	//CTileMgr::GetInstance()->LoadData(L"../Data/Stage2.dat");

	int iX = 0, iY = 0;

	for(int i = 0; i < TILEY; ++i)
	{
		for(int j = 0; j < TILEX  ; ++j)
		{
			iX = TILECX * j + TILECX / 2;
			iY = TILECY * i + TILECY / 2;
			
			CTileMgr::GetInstance()->AddTile(CAbstract<CTile>::CreateObj(iX, iY, 0.f));
		}
	}
}

int CMyEdit::Update()
{
	CTileMgr::GetInstance()->Update();	

	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();

	static bool Flag = FALSE;


	if(KEYPRESS(dwKey, KEY_LBUTTON))
	{
		if(Flag == FALSE)
		{
			Picking();
			Flag = TRUE;
		}
	}
	else
	{
		Flag = FALSE;
	}

	if(KEYPRESS(dwKey, KEY_LEFT))
		g_iScrollX += 10;
	if(KEYPRESS(dwKey, KEY_RIGHT))
		g_iScrollX -= 10;
	if(KEYPRESS(dwKey, KEY_UP))
		g_iScrollY += 10;
	if(KEYPRESS(dwKey, KEY_DOWN))
		g_iScrollY -= 10;


	return 0;
}

void CMyEdit::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(L"Stage1"))->GetMemDC();
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, -g_iScrollX, -g_iScrollY, SRCCOPY);
	CTileMgr::GetInstance()->Render(hDC);
}

void CMyEdit::Release()
{
	CBmpMgr::GetInstance()->DestroyInstance();
	CTileMgr::GetInstance()->DestroyInstance();
}

void CMyEdit::Picking()
{
	vector<CObj*>* pVecTile = CTileMgr::GetInstance()->GetVecTile();

	int iX = (CMouse::GetMouse().x - g_iScrollX) / TILECX;
	int iY = (CMouse::GetMouse().y - g_iScrollY) / TILECY;

	// 타일 공식
	int iIndex = iX + (TILEX * iY);

	CTile* pTile = dynamic_cast<CTile*>((*pVecTile)[iIndex]);
	int DrawId = pTile->GetDrawID();
	++DrawId;
	pTile->SetOption(DrawId, 1);
}