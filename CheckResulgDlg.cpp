// CheckResulgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "iOSNeedImage.h"
#include "CheckResulgDlg.h"
#include "afxdialogex.h"


// CCheckResulgDlg 对话框


CCheckResulgDlg::CCheckResulgDlg(CWnd* pParent /*=NULL*/)
	: CBaseDlg(CCheckResulgDlg::IDD, pParent)
{

}

CCheckResulgDlg::~CCheckResulgDlg()
{
}

void CCheckResulgDlg::DoDataExchange(CDataExchange* pDX)
{
	CBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CHECK, m_listctrl_check);
}


BEGIN_MESSAGE_MAP(CCheckResulgDlg, CBaseDlg)
END_MESSAGE_MAP()


// CCheckResulgDlg 消息处理程序

BOOL CCheckResulgDlg::OnInitDialog()
{
	CBaseDlg::OnInitDialog();

	m_listctrl_check.SetView(LVS_REPORT);
	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 60;
	lvColumn.pszText = _T("Item #");
	this->m_listctrl_check.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Category");
	this->m_listctrl_check.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 160;
	lvColumn.pszText = _T("Item Name");
	this->m_listctrl_check.InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Size");
	this->m_listctrl_check.InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_RIGHT;
	lvColumn.cx = 60;
	lvColumn.pszText = _T("Unit Price");
	this->m_listctrl_check.InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_RIGHT;
	lvColumn.cx = 30;
	lvColumn.pszText = _T("Qty");
	this->m_listctrl_check.InsertColumn(5, &lvColumn);

	this->m_listctrl_check.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//ListView_SetExtendedListViewStyle(m_listctrl_check.m_hWnd,LVS_EX_FULLROWSELECT |

   //     LVS_EX_GRIDLINES);
	//m_listctrl_check.SetExtendedStyle( LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
		LVITEM lvItem;
		int nItem;
		int imgNbr;

		imgNbr = 0;

		lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvItem.iItem = 0;
		lvItem.iSubItem = 0;
		lvItem.pszText = L"strNumber";
		lvItem.iImage = imgNbr;
		nItem = this->m_listctrl_check.InsertItem(&lvItem);

		this->m_listctrl_check.SetItemText(nItem, 1, L"m_Category");
		this->m_listctrl_check.SetItemText(nItem, 2, L"m_ItemName");
		this->m_listctrl_check.SetItemText(nItem, 3, L"m_ItemSize");
		this->m_listctrl_check.SetItemText(nItem, 4, L"m_UnitPrice");
		this->m_listctrl_check.SetItemText(nItem, 5, L"m_Quantity");



	DWORD dwCurType;
	HWND hWnd;
	hWnd = this->m_listctrl_check;

	GetSafeHwnd();
	dwCurType = ::GetWindowLong(hWnd, GWL_STYLE);
	dwCurType &= ~LVS_TYPEMASK;
	DWORD dwViewType = LVS_REPORT;
	dwViewType |= dwCurType;
	::SetWindowLong(hWnd, GWL_STYLE, dwViewType);
	return TRUE;
}
void CCheckResulgDlg::InsertItems()

{

    HWND hWnd = m_listctrl_check.m_hWnd;

    // Set the LVCOLUMN structure with the required

    // column information

   LVCOLUMN list;

    list.mask = LVCF_TEXT |LVCF_WIDTH|

        LVCF_FMT |LVCF_SUBITEM;

    list.fmt = LVCFMT_LEFT;

    list.cx = 50;

    list.pszText   = L"S.No";

    list.iSubItem = 0;

    //Inserts the column

    ::SendMessage(hWnd,LVM_INSERTCOLUMN, 

        (WPARAM)0,(WPARAM)&list);

    list.cx = 100;

    list.pszText   = L"Name";

    list.iSubItem = 1;

    ::SendMessage(hWnd ,LVM_INSERTCOLUMN,

        (WPARAM)1,(WPARAM)&list);

    list.cx = 100;

    list.pszText   = L"Address";

    list.iSubItem = 2;

    ::SendMessage(hWnd ,LVM_INSERTCOLUMN,

        (WPARAM)1,(WPARAM)&list);

    list.cx = 100;

    list.pszText   = L"Country";

    list.iSubItem = 2;

    ::SendMessage(hWnd ,LVM_INSERTCOLUMN,

        (WPARAM)1,(WPARAM)&list);

    // Inserts first Row with four columns 插入行

    SetCell(hWnd,L"1",0,0);

    SetCell(hWnd,L"Prabhakar",0,1);

    SetCell(hWnd,L"Hyderabad",0,2);

    SetCell(hWnd,L"India",0,3);

    // Inserts second Row with four columns .

    SetCell(hWnd,L"2",1,0);

    SetCell(hWnd,L"Uday",1,1);

    SetCell(hWnd,L"Chennai",1,2);

    SetCell(hWnd,L"India",1,3);



}
void CCheckResulgDlg::SetCell(HWND hWnd1, 
        CString value, int nRow, int nCol)
{

    TCHAR     szString [256];

    wsprintf(szString,value ,0);

    //Fill the LVITEM structure with the

    //values given as parameters.

    LVITEM lvItem;

    lvItem.mask = LVIF_TEXT;

    lvItem.iItem = nRow;

    lvItem.pszText = szString;

    lvItem.iSubItem = nCol;

    if(nCol >0)

        //set the value of listItem

        ::SendMessage(hWnd1,LVM_SETITEM, 

            (WPARAM)0,(WPARAM)&lvItem);

    else

        //Insert the value into List

        ListView_InsertItem(hWnd1,&lvItem);

}




void CCheckResulgDlg::setEnable(BOOL enable)
{
}