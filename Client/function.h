#pragma once

template <typename T>
void safeDelete(T& obj)
{
	if(obj)
	{
		delete obj;
		obj = NULL;
	}
}

class CStringCmp
{
public:
	CStringCmp(const TCHAR* pKey)
		: m_pKey(pKey) {}

public:
	template <typename T>
	bool operator()(T& dst)
	{
		return !lstrcmp(dst.first, m_pKey);
	}

private:
	const TCHAR*	m_pKey;
};