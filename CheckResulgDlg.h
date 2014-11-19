#pragma once
#include "BaseDlg.h"
#include "afxcmn.h"
#include "ModelResult.h"
#include <vector>
using namespace std;
// CCheckResulgDlg 对话框

class CCheckResulgDlg : public CBaseDlg
{
public:
	CCheckResulgDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckResulgDlg();

// 对话框数据
	enum { IDD = IDD_CHECKRESULGDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
