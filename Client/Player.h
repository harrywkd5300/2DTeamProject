#pragma once
#include "obj.h"

class CPlayer :
	public CObj
{
public:
	enum State { IDLE, IDLE_WATER, WALK, CROUCH, JUMP, RUN, RUN_WATER, ATTACK, SHOCK, FLY, DAMAGED, STATE_END};

private:
	bool	m_bIsWater;	//	캐릭터가 물 속인지(true) 아닌지(false)

	//	점프
	bool	m_bIsJump;
	bool    m_bTileView;
	float	m_fJumpAcc;

	//	애니메이션
	State	m_ePreState;
	State	m_eCurState;

	//	공격
	bool	m_bIsAttack;
	int		m_iAttCount;	//	공격(회전)하는 시간
	int		m_iAttEnd;		//	0:공격 하는중 1:공격하지않는 상태 2:공격 방금 끝남

	bool	m_bIsDamaged;
	int		m_iDamagedCnt;	//	데미지 모션 시간
	int		m_iPushCnt;		//	데미지 받은 뒤 밀쳐지는 시간

	bool	m_bIsShock;
	int		m_iShockCnt;	//	연속해서 공격버튼을 얼마나 눌렀는지 체크
	int		m_iShockTime;	//	기절 시간

	bool	m_bIsFly;
	bool	m_bIsRun;

	RECT	m_rcCollision;
	float	m_fCollisionX;
	float	m_fCollisionY;

	float   m_fJumpAngle;
	bool    m_bIsCollisionTail;

	bool	m_bIsAttPush;
	int		m_iAttPushCnt;

	DWORD   m_dSoundTime;

private:
	void KeyInput(void);
	void StateChange();
	void CollisionUpdate();

	void Jump(void);
	void Scroll();
	void Damaged(void);
	void Attack(void);
	void Fly(void);
	void Run(void);

public:
	void SuccessAtt(void);	//	공격 성공했을 때 플레이어 밀치는 함수

public:
	bool TileView()	 { return m_bTileView; }
	bool GetIsWater(){ return m_bIsWater;  }
	RECT GetCollision()
	{
		return m_rcCollision;
	}
	bool GetIsAttack() { return m_bIsAttack; }

public:
	void SetInWater(bool IsWater) { m_bIsWater = IsWater; }
	void SetIsJump(bool _collision = true) { m_bIsCollisionTail = _collision; }
	void SetIsDamaged(bool _damaged = true) { m_bIsDamaged =_damaged; }
	void SetIsAttPush(bool _attpush = true) { m_bIsAttPush = _attpush; }

public:
	CPlayer(void);
	~CPlayer(void);

	virtual void initirize();
	virtual void Render( HDC hdc );
	virtual void Release();
	virtual int Update();

};
