#pragma once
#include "obj.h"

class CBoss1Bullet :
	public CObj
{
public:
	CBoss1Bullet(void);
	virtual ~CBoss1Bullet(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	void SetXPos(float fXPos) { m_tInfo.vPos.x = fXPos; }

private:
	bool m_bBulletChange;

	int m_iBulletCount;
};
