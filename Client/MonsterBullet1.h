#pragma once
#include "obj.h"

class CMonsterBullet1 :
	public CObj
{
public:
	CMonsterBullet1(void);
	virtual ~CMonsterBullet1(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
