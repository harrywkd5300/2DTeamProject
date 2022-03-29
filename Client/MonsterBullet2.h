#pragma once
#include "obj.h"

class CMonsterBullet2 :
	public CObj
{
public:
	CMonsterBullet2(void);
	virtual ~CMonsterBullet2(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
