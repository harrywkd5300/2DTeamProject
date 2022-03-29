#pragma once
#include "obj.h"

class CItem :
	public CObj
{
public:
	CItem(void);
	virtual ~CItem(void);
public:
	virtual void initirize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
