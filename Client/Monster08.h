#pragma once
#include "obj.h"

class CMonster08 :
	public CObj
{
public:
	CMonster08(void);
	virtual ~CMonster08(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
