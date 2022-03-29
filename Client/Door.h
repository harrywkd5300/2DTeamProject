#pragma once
#include "obj.h"

class CDoor :
	public CObj
{
public:
	CDoor(void);
	virtual ~CDoor(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
