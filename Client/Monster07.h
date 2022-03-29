#pragma once
#include "obj.h"

class CMonster07 :
	public CObj
{
public:
	CMonster07(void);
	virtual ~CMonster07(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	bool m_bLeft;

	int m_iCount;
};
