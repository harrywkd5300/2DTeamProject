#pragma once

class CObj;
class CCollision
{
public:
	CCollision(void);
	~CCollision(void);
public:
	static void CollisionPlayer(CObj* pSrc, vector<CObj*>* tailVector);
	static void CollisionList(CObj* pSrc, list<CObj*>* ObjList);
	static void CollisionBoss1(CObj* pSrc, list<CObj*>* ObjList);
	static void CollisionBullet(CObj* pSrc, list<CObj*>* ObjList);
	static void CollisionDoor(CObj* pSrc, CObj* pDrc, Scene pScene);
	static void CollisionBoss2(CObj* pSrc, list<CObj*>* ObjList);
};
