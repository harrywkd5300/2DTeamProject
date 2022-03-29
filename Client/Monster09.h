#pragma once
#include "obj.h"

class CMonster09 :
	public CObj
{
public:
	CMonster09(void);
	virtual ~CMonster09(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
