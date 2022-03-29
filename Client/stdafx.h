// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C의 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>

#include <d3dx9.h>			//포함파일.
#include <d3d9.h>
#include <d3dx9math.h>

#pragma comment(lib, "d3dx9.lib")		//라이브러리.

#include "fmod.h"
#include "fmod.hpp"
#pragma comment(lib, "fmodex_vc.lib")

using namespace std;

#include "Inclue.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "TileMgr.h"
#include "Collision.h"
#include "SoundMgr.h"

#pragma comment(lib, "msimg32.lib")

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
