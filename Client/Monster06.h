#pragma once
#include "obj.h"

class CMonster06 :
	public CObj
{
public:
	CMonster06(void);
	virtual ~CMonster06(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
