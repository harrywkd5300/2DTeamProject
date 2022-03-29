#include "StdAfx.h"
#include "Collision.h"
#include "Obj.h"
#include "Player.h"
#include "Boss1.h"
#include "Boss2.h"
#include "Door.h"

CCollision::CCollision(void)
{
}

CCollision::~CCollision(void)
{
}
void CCollision::CollisionPlayer(CObj* pSrc, vector<CObj*>* tailVector)
{
	vector<CObj*>::iterator iter_begin = tailVector->begin();
	vector<CObj*>::iterator iter_end = tailVector->end();
	RECT rc = {};

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 0)
		{
			if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
			{
				float iLength = float(rc.right  - rc.left);
				float iWidth  = float(rc.bottom - rc.top );

				if(iLength > iWidth)
				{
					if(rc.top == (*iter_begin)->GetRect().top)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x, pSrc->GetInfo().vPos.y - iWidth );
					}
					else if(rc.bottom == (*iter_begin)->GetRect().bottom)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x, pSrc->GetInfo().vPos.y + iWidth ) ;
					}
				}
				if(iLength < iWidth)
				{
					if(rc.left == (*iter_begin)->GetRect().left)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x - iLength , pSrc->GetInfo().vPos.y) ;
					}
					else if(rc.right == (*iter_begin)->GetRect().right)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x + iLength , pSrc->GetInfo().vPos.y)  ;
					}
				}
			}
		}
		else if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 1)
		{
			if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
			{
				dynamic_cast<CPlayer*>(pSrc)->SetInWater(true);
			}
		}
		else if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 2)
		{
			if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
			{
				dynamic_cast<CPlayer*>(pSrc)->SetInWater(false);
			}
		}
		else if(dynamic_cast<CTile*>(*iter_begin)->GetDrawID() == 3)
		{
			if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
			{
				float iLength = float(rc.right  - rc.left);
				float iWidth  = float(rc.bottom - rc.top );

				if(pSrc->GetRect().bottom >= (*iter_begin)->GetRect().top)
					dynamic_cast<CPlayer*>(pSrc)->SetIsJump();
				if(iLength > iWidth)
				{
					if(rc.top == (*iter_begin)->GetRect().top)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x, pSrc->GetInfo().vPos.y - iWidth );
					}
					else if(rc.bottom == (*iter_begin)->GetRect().bottom)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x, pSrc->GetInfo().vPos.y + iWidth ) ;
					}
				}
				else
				{
					if(rc.left == (*iter_begin)->GetRect().left)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x - iLength , pSrc->GetInfo().vPos.y) ;
					}
					else if(rc.right == (*iter_begin)->GetRect().right)
					{
						pSrc->SetPos(pSrc->GetInfo().vPos.x + iLength , pSrc->GetInfo().vPos.y)  ;
					}
				}
			}
		}
	}
}

void CCollision::CollisionList(CObj* pSrc, list<CObj*>* ObjList)
{
	list<CObj*>::iterator iter_begin = ObjList->begin();
	list<CObj*>::iterator iter_end = ObjList->end();
	RECT rc = {};

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
		{
			if(dynamic_cast<CPlayer*>(pSrc)->GetIsAttack())	//	플레이어가 공격 상태일때
			{
				(*iter_begin)->IsDead();
				dynamic_cast<CPlayer*>(pSrc)->SetIsAttPush();
				return;
			}
			else
			{
				dynamic_cast<CPlayer*>(pSrc)->SetIsDamaged();
				return;
			}
		}
	}
}

void CCollision::CollisionBoss1(CObj* pSrc, list<CObj*>* ObjList)
{
	list<CObj*>::iterator iter_begin = ObjList->begin();
	list<CObj*>::iterator iter_end = ObjList->end();
	RECT rc = {};

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
		{
			if(!(dynamic_cast<CBoss1*>(*iter_begin)->GetDamaged()))
			{
				if(dynamic_cast<CPlayer*>(pSrc)->GetIsAttack())	//	플레이어가 공격 상태일때
				{
					float iLength = float(rc.right  - rc.left);
					float iWidth  = float(rc.bottom - rc.top );

					dynamic_cast<CPlayer*>(pSrc)->SetIsAttPush();
					if(iWidth < iLength && (*iter_begin)->GetRect().top < pSrc->GetRect().bottom)
					{
						dynamic_cast<CBoss1*>(*iter_begin)->SetBoolDamaged();
						return;
					}
					return;
				}
				else
				{
					dynamic_cast<CPlayer*>(pSrc)->SetIsDamaged();
					return;
				}
			}
		}
	}
}
void CCollision::CollisionBoss2(CObj* pSrc, list<CObj*>* ObjList)
{
	list<CObj*>::iterator iter_begin = ObjList->begin();
	list<CObj*>::iterator iter_end = ObjList->end();
	RECT rc = {};

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
		{
			if(!(dynamic_cast<CBoss2*>(*iter_begin)->GetDamaged()))
			{
				if(dynamic_cast<CPlayer*>(pSrc)->GetIsAttack())	//	플레이어가 공격 상태일때
				{
					float iLength = float(rc.right  - rc.left);
					float iWidth  = float(rc.bottom - rc.top );

					dynamic_cast<CPlayer*>(pSrc)->SetIsAttPush();
					dynamic_cast<CBoss2*>(*iter_begin)->SetBoolDamaged();
					return;
				}
				else
				{
					dynamic_cast<CPlayer*>(pSrc)->SetIsDamaged();
					return;
				}
			}
		}
	}
}

void CCollision::CollisionBullet(CObj* pSrc, list<CObj*>* ObjList)
{
	list<CObj*>::iterator iter_begin = ObjList->begin();
	list<CObj*>::iterator iter_end = ObjList->end();
	RECT rc = {};

	for( ; iter_begin != iter_end ; ++iter_begin)
	{
		if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&((*iter_begin)->GetRect())))
		{
			(*iter_begin)->SetDamaged();
			dynamic_cast<CPlayer*>(pSrc)->SetIsDamaged();
		}
	}

}

void CCollision::CollisionDoor(CObj* pSrc, CObj* pDrc, Scene pScene)
{
	RECT rc = {};
	if(IntersectRect(&rc, &(dynamic_cast<CPlayer*>(pSrc)->GetRect()),&(dynamic_cast<CDoor*>(pDrc)->GetRect())))
	{
		DWORD dwKey = CKeyMgr::GetInstance()->Getkey();
		if (KEYPRESS(dwKey, VK_UP))
		{
			CSceneMgr::GetInstance()->SetScene(pScene);
			return;
		}
	}
}