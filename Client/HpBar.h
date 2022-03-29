#pragma once
#include "obj.h"

class CHpBar :
	public CObj
{
public:
	CHpBar(void);
	virtual ~CHpBar(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
