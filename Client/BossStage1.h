#pragma once
#include "scene.h"

class CBossStage1 :
	public CScene
{
	bool b_MakeDoor;
	bool b_MakeDoor2;
public:
	CBossStage1(void);
	virtual ~CBossStage1(void);

public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
