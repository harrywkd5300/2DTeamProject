#pragma once

class CObj;
class CObjMgr
{
	DECLARE_SINGLETON(CObjMgr)
private:
	CObjMgr(void);
	~CObjMgr(void);

public:
	CObj* GetObj(OBJID eID) { return m_ObjList[eID].front(); }
	OBJLIST& GetList(OBJID eID) { return m_ObjList[eID]; }

public:
	void AddObject(CObj* pObj, OBJID eID);
	void UpdateObj();
	void RenderObj(HDC hDC);
	void ReleaseAll();
	void ReleaseObj(OBJID eID);

private:
	OBJLIST		    m_ObjList[OBJ_END];
};
