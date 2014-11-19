#pragma once
#include "BaseDlg.h"
#include "afxcmn.h"
#include "ModelResult.h"
#include <vector>
using namespace std;
// CCheckResulgDlg �Ի���

class CCheckResulgDlg : public CBaseDlg
{
public:
	CCheckResulgDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckResulgDlg();

// �Ի�������
	enum { IDD = IDD_CHECKRESULGDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	void setEnable(BOOL enable);
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_listctrl_check;
	void InsertItems();
	void SetCell(HWND hWnd,CString value, int nRow, int nCol);

	vector<CModelResult*> m_list;
	void initData();
	void check();
	void updateList();

	CString m_directory;
	CImageList m_imagelist;
};
