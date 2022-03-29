#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3		vPos;	//¿ßƒ°∫§≈Õ
	D3DXVECTOR3		vDir;	//πÊ«‚∫§≈Õ
	D3DXVECTOR3		vLook;

	D3DXMATRIX matWorld;
	D3DXMATRIX matScale;
	D3DXMATRIX matTrans;
	D3DXMATRIX matAngle;

	float		fCX;
	float		fCY;

	tagInfo(void){}
	tagInfo(D3DXVECTOR3 _vPos, float _fCX, float _fCY)
		: vPos(_vPos), fCX(_fCX), fCY(_fCY)
	{}

}INFO;


typedef struct tagFrame
{
	int iFrameStart;
	int iFrameEnd;
	int iScene;

	DWORD dwFrameOld;
	DWORD dwFrameSpd;
}FRAME;