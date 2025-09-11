
// practice1a.h: practice1a 애플리케이션의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'pch.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// Cpractice1aApp:
// 이 클래스의 구현에 대해서는 practice1a.cpp을(를) 참조하세요.
//

class Cpractice1aApp : public CWinApp
{
public:
	Cpractice1aApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cpractice1aApp theApp;
