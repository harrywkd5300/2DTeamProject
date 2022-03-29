#pragma once
#include "obj.h"

class CBoss1 :
	public CObj
{
public:
	CBoss1(void);
	virtual ~CBoss1(void);

public:
	void DamagedMotion();
	void SetBoolDamaged(bool _damaged = true)
	{
		m_bIsDamaged = _damaged;
	}

	bool GetDamaged()
	{
		return m_bIsDamaged;
	}

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	void BossPatten(int iPatten);
	void CreateBullet();

private:
	int m_iPatten;
	int m_iCount;
	int m_iPattenChange;
	int m_iBossHitCount;
	int m_iShotCount;

	float m_fOldHp;

	bool m_bLeft;
	bool m_bBossHit;
	bool m_bHitEffect;

	bool m_bIsDamaged;
	int  m_iDamagedCnt;
};
