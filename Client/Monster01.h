#pragma once
#include "obj.h"

class CMonster01 :
	public CObj
{
public:
	CMonster01(void);
	virtual ~CMonster01(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
