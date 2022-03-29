#pragma once
#include "obj.h"

class CMonster10 :
	public CObj
{
public:
	CMonster10(void);
	virtual ~CMonster10(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
