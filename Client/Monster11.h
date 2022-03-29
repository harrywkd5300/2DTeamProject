#pragma once
#include "obj.h"

class CMonster11 :
	public CObj
{
public:
	CMonster11(void);
	virtual ~CMonster11(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
