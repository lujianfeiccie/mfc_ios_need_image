
// iOSNeedImage.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CiOSNeedImageApp:
// �йش����ʵ�֣������ iOSNeedImage.cpp
//

class CiOSNeedImageApp : public CWinApp
{
public:
	CiOSNeedImageApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CiOSNeedImageApp theApp;