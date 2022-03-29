#pragma once

#define WINCX 800
#define WINCY 600

#define TILEX 64
#define TILEY 18

#define TILECX 50
#define TILECY 50

#define KEYPRESS(DST, SRC) (DST & SRC)


#define DECLARE_SINGLETON(ClassName)		\
public:										\
	static ClassName* GetInstance()			\
	{										\
	if(NULL == m_pInstance)					\
	m_pInstance = new ClassName;			\
	return m_pInstance;						\
	}										\
	void DestroyInstance()					\
	{										\
	if(m_pInstance)							\
		{									\
		delete m_pInstance;					\
		m_pInstance = NULL;					\
		}									\
	}										\
private:									\
	static ClassName* m_pInstance;



#define IMPLEMENT_SINGLETON(ClassName)		\
	ClassName* ClassName::m_pInstance = NULL;