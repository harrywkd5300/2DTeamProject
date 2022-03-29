#pragma once
#include "obj.h"

class CBoss2Bullet3 :
	public CObj
{
public:
	CBoss2Bullet3(void);
	virtual ~CBoss2Bullet3(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	void SetDir(float fX, float fY) { m_tInfo.vDir.x = fX, m_tInfo.vDir.y = fY; }
	void SetPosXY(float fX, float fY) { m_tInfo.vPos.x = fX, m_tInfo.vPos.y = fY; }
	void SetAngle(float fAngle) { m_fAngle = fAngle; }
};
