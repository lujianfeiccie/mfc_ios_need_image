
// iOSNeedImageDlg.h : 头文件
//
#include "BaseDlg.h"
#pragma once


// CiOSNeedImageDlg 对话框
class CiOSNeedImageDlg : public CBaseDlg
{
// 构造
public:
	CiOSNeedImageDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IOSNEEDIMAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void setEnable(BOOL enable);
	afx_msg void OnBnClickedBtnBrowser();
	afx_msg void OnBnClickedBtnStartValidate();
	CString ShowDirectoryDlg();
	CEdit m_edit_directory;

	
};
