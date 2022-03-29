#pragma once
#include "obj.h"

class CMonster02 :
	public CObj
{
public:
	CMonster02(void);
	virtual ~CMonster02(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
