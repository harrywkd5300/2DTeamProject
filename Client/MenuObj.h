#pragma once
#include "Obj.h"

class CMenuObj :
	public CObj
{
public:
	CMenuObj(void);
	virtual ~CMenuObj(void);
public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
