#pragma once
#include "obj.h"

class CBoss2 :
	public CObj
{
public:
	CBoss2(void);
	virtual ~CBoss2(void);

public:
	virtual void initirize();
	virtual int  Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	void BossPatten(int iPatten);
	void CreateBullet1();
	void CreateBullet2();
	void CreateBullet3();
	void DamagedMotion();

private:
	int m_iPatten;
	int m_iBulletCount;
	int m_iBossHitCount;
	int m_iPatten2ShotCount;
	int m_iPatten2ChangeCount;
	
	float m_fOldHp;
	float m_fOldx;

	bool m_bBossChange;
	bool m_bBossHit;
	bool m_bHitEffect;
	bool m_bPattenChange;

	bool m_bIsDamaged;
	int  m_iDamagedCnt;
public:
	bool GetDamaged()
	{
		return m_bIsDamaged;
	}
	void SetBoolDamaged(bool _damaged = true)
	{
		m_bIsDamaged = _damaged;
	}
};
