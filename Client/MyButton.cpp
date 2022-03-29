#include "StdAfx.h"
#include "MyButton.h"
#include "Mouse.h"

CMyButton::CMyButton(void)
{
}

CMyButton::CMyButton(TCHAR* pFrameKey, float iX, float iY, float iCX, float iCY)
: m_pFrameKey(pFrameKey), m_iFrame(0)
{
	m_tInfo.vPos.x = iX;
	m_tInfo.vPos.y = iY;
	m_tInfo.fCX = iCX;
	m_tInfo.fCY = iCY;
}

CMyButton::~CMyButton(void)
{
	Release();
}

void CMyButton::initirize()
{
}

int CMyButton::Update()
{
	DWORD dwKey = CKeyMgr::GetInstance()->Getkey();

	CObj::Update();

	POINT pt = CMouse::GetMouse();

	m_tRect.left   = int(m_tInfo.vPos.x - m_tInfo.fCX / 2);
	m_tRect.top    = int(m_tInfo.vPos.y - m_tInfo.fCY / 2);
	m_tRect.right  = int(m_tInfo.vPos.x + m_tInfo.fCX / 2);
	m_tRect.bottom = INT(m_tInfo.vPos.y + m_tInfo.fCY / 2);

	// PtInRect: 마우스 커서 좌표가 임의의 사각형 안에 들어오면 true를 반환해준다.
	if(PtInRect(&m_tRect, pt))
	{
		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if(!lstrcmp(m_pFrameKey, L"Start"))
			{
				CSceneMgr::GetInstance()->SetScene(STAGE1);
				return 2;
			}
			else if(!lstrcmp(m_pFrameKey, L"Edit"))
			{
				CSceneMgr::GetInstance()->SetScene(EDIT);
				return 2;
			}
			else if(!lstrcmp(m_pFrameKey, L"Exit"))
			{
				DestroyWindow(g_hwnd);
				return 2;
			}
		}

		m_iFrame = 1;
	}
	else
		m_iFrame = 0;


	return 0;
}

void CMyButton::Render(HDC hDC)
{
	HDC hMemDC = (CBmpMgr::GetInstance()->FindBmp(m_pFrameKey))->GetMemDC();

	TransparentBlt(hDC,int(m_tInfo.vPos.x - m_tInfo.fCX / 2.f) , int(m_tInfo.vPos.y - m_tInfo.fCY / 2.f), (int)m_tInfo.fCX, (int)m_tInfo.fCY
		, hMemDC, m_iFrame * (int)m_tInfo.fCX, 0
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(255, 0, 255));	
}

void CMyButton::Release()
{
}
