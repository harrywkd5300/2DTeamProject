#pragma once

class CScene;
class CSceneMgr
{
	DECLARE_SINGLETON(CSceneMgr)

private:
	CScene*		m_pScene;
	Scene		m_eCurScene;
public:
	CSceneMgr(void);
	~CSceneMgr(void);

public:
	void		SetScene(Scene eType);

public:
	Scene		GetCurScene() { return m_eCurScene; }

public:
	void		Update();
	void		Render(HDC hdc);
	void		Release();
};
