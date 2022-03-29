#pragma once
#include "obj.h"

class CPlayer :
	public CObj
{
public:
	enum State { IDLE, IDLE_WATER, WALK, CROUCH, JUMP, RUN, RUN_WATER, ATTACK, SHOCK, FLY, DAMAGED, STATE_END};

private:
	bool	m_bIsWater;	//	ĳ���Ͱ� �� ������(true) �ƴ���(false)

	//	����
	bool	m_bIsJump;
	bool    m_bTileView;
	float	m_fJumpAcc;

	//	�ִϸ��̼�
	State	m_ePreState;
	State	m_eCurState;

	//	����
	bool	m_bIsAttack;
	int		m_iAttCount;	//	����(ȸ��)�ϴ� �ð�
	int		m_iAttEnd;		//	0:���� �ϴ��� 1:���������ʴ� ���� 2:���� ��� ����

	bool	m_bIsDamaged;
	int		m_iDamagedCnt;	//	������ ��� �ð�
	int		m_iPushCnt;		//	������ ���� �� �������� �ð�

	bool	m_bIsShock;
	int		m_iShockCnt;	//	�����ؼ� ���ݹ�ư�� �󸶳� �������� üũ
	int		m_iShockTime;	//	���� �ð�

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
	void SuccessAtt(void);	//	���� �������� �� �÷��̾� ��ġ�� �Լ�

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
