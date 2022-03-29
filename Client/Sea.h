#pragma once
#include "obj.h"

class CSea :
	public CObj
{
public:
	CSea(void);
	virtual ~CSea(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
