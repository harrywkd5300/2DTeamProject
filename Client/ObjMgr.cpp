#include "StdAfx.h"
#include "ObjMgr.h"
#include "Obj.h"

IMPLEMENT_SINGLETON(CObjMgr);

CObjMgr::CObjMgr(void)
{
}

CObjMgr::~CObjMgr(void)
{
	ReleaseAll();
}

void CObjMgr::AddObject(CObj* pObj, OBJID eID)
{
	m_ObjList[eID].push_back(pObj);
}

void CObjMgr::UpdateObj()
{
	for(int i = 0; i < OBJ_END; ++i)
	{
		list<CObj*>::iterator iter_begin = m_ObjList[i].begin();;
		list<CObj*>::iterator iter_end = m_ObjList[i].end();

		for(; iter_begin != iter_end; )
		{
			int iEvent = (*iter_begin)->Update();

			if( 1 == iEvent )
			{
				safeDelete<CObj*>(*iter_begin);
				iter_begin = m_ObjList[i].erase(iter_begin);
			}
			else if( 2 == iEvent)
				return;
			else
				++iter_begin;
		}
	}
}

void CObjMgr::RenderObj(HDC hDC)
{
	for(int i = 0; i < OBJ_END; ++i)
	{
		list<CObj*>::iterator iter_begin = m_ObjList[i].begin();
		list<CObj*>::iterator iter_end = m_ObjList[i].end();

		for(; iter_begin != iter_end; ++iter_begin)
			(*iter_begin)->Render(hDC);
	}
}

void CObjMgr::ReleaseAll()
{
	for(int i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), safeDelete<CObj*>);
		m_ObjList[i].clear();
	}	
}

void CObjMgr::ReleaseObj(OBJID eID)
{
	for_each(m_ObjList[eID].begin(), m_ObjList[eID].end(), safeDelete<CObj*>);
	m_ObjList[eID].clear();
}
