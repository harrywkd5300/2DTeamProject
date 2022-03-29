#pragma once
#include "obj.h"

class CHpBar2 :
	public CObj
{
public:
	CHpBar2(void);
	virtual ~CHpBar2(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
