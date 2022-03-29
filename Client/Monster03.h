#pragma once
#include "obj.h"

class CMonster03 :
	public CObj
{
public:
	CMonster03(void);
	virtual ~CMonster03(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
