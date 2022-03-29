#pragma once

class CObj;

template <typename T>
class CAbstract
{
public:
	static CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->initirize();

		return pObj;
	}
	static CObj* CreateObj(float iX, float iY, float iZ)
	{
		CObj* pObj = new T;
		pObj->SetPos(iX, iY, iZ);
		pObj->initirize();
		return pObj;
	}
	static CObj* CreateObj(int iX, int iY, float iZ)
	{
		CObj* pObj = new T;
		pObj->SetPos((float)iX, (float)iY, iZ);
		pObj->initirize();
		return pObj;
	}
};
