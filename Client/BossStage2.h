#pragma once
#include "scene.h"

class CBossStage2 :
	public CScene
{
public:
	CBossStage2(void);
	virtual ~CBossStage2(void);

public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render(HDC hDC);
	virtual void Release();
};
