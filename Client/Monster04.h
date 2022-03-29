#pragma once
#include "obj.h"

class CMonster04 :
	public CObj
{
public:
	CMonster04(void);
	virtual ~CMonster04(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
