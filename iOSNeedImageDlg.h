
// iOSNeedImageDlg.h : ͷ�ļ�
//
#include "BaseDlg.h"
#pragma once


// CiOSNeedImageDlg �Ի���
class CiOSNeedImageDlg : public CBaseDlg
{
// ����
public:
	CiOSNeedImageDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IOSNEEDIMAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
