#pragma once

class CObj
{
protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	FRAME			m_tFrame;

	float			m_fAngle;
	float			m_fSpeed;
	float			m_fDistance;

	float			m_fHp;
	bool			m_bIsDead;
	bool			m_bIsFly;
	bool			m_firstMake;

	TCHAR*			m_pFrameKey;


	D3DXVECTOR3		m_vPoint[4];
	D3DXVECTOR3		m_vOriginal[4];

public:
	CObj(void);
	virtual ~CObj(void);

public:
	INFO		GetInfo()	{ return m_tInfo; }
	RECT		GetRect()	{ return m_tRect; }

public:
	void		SetPos(float iX, float iY, float iZ)  { m_tInfo.vPos.x = iX , m_tInfo.vPos.y = iY, m_tInfo.vPos.z = iZ;   }
	void		IsDead() { m_bIsDead = true; }
	void		SetIsHp(float m_iAtk) { m_fHp -= m_iAtk; }
	void		SetInfo(INFO& rInfo) { m_tInfo = rInfo; }

	void		SetPos(float _x, float _y)
	{
		m_tInfo.vPos.x = _x;
		m_tInfo.vPos.y = _y;
	}
	void		SetbIsFly(bool isFly) { m_bIsFly = isFly; }
	void		SetDamaged()
	{
		--m_fHp;
	}

public:
	bool        GetIsDead() { return m_bIsDead; }
	float       GetIsHp()   { return m_fHp;     }
	float       GetfSpeed() { return m_fSpeed;  }
public:
	void FrameMove();

public:
	virtual void initirize() = 0;
	virtual int  Update();
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;
};
