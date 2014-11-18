
// iOSNeedImageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "iOSNeedImage.h"
#include "iOSNeedImageDlg.h"
#include "afxdialogex.h"
#include "CheckResulgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CiOSNeedImageDlg 对话框




CiOSNeedImageDlg::CiOSNeedImageDlg(CWnd* pParent /*=NULL*/)
	: CBaseDlg(CiOSNeedImageDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CiOSNeedImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DIRECTORY, m_edit_directory);
}

BEGIN_MESSAGE_MAP(CiOSNeedImageDlg, CBaseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_BROWSER, &CiOSNeedImageDlg::OnBnClickedBtnBrowser)
	ON_BN_CLICKED(IDC_BTN_START_VALIDATE, &CiOSNeedImageDlg::OnBnClickedBtnStartValidate)
END_MESSAGE_MAP()


// CiOSNeedImageDlg 消息处理程序

BOOL CiOSNeedImageDlg::OnInitDialog()
{
	CBaseDlg::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CiOSNeedImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CBaseDlg::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CiOSNeedImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CBaseDlg::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CiOSNeedImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CiOSNeedImageDlg::setEnable(BOOL enable)
{

}

void CiOSNeedImageDlg::OnBnClickedBtnBrowser()
{
	// TODO: 在此添加控件通知处理程序代码
	CString directory_path = ShowDirectoryDlg();
	m_edit_directory.SetWindowTextW(directory_path);
}


void CiOSNeedImageDlg::OnBnClickedBtnStartValidate()
{
	// TODO: 在此添加控件通知处理程序代码
	CString directory_str;
	m_edit_directory.GetWindowTextW(directory_str);
	if(directory_str.Trim() == L"")
	{
		MessageBox(L"提示",L"文件夹不能为空!");
		return;
	}
	CCheckResulgDlg dlg;
	dlg.DoModal();
}
CString CiOSNeedImageDlg::ShowDirectoryDlg() 
{ 
 	 TCHAR           szFolderPath[MAX_PATH] = {0};   
     CString         strFolderPath = TEXT("");   
          
        BROWSEINFO      sInfo;   
        ::ZeroMemory(&sInfo, sizeof(BROWSEINFO));   
        sInfo.pidlRoot   = 0;   
        sInfo.lpszTitle   = _T("请选择一个文件夹：");   
        sInfo.ulFlags   = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;   
        sInfo.lpfn     = NULL;   
   
         // 显示文件夹选择对话框   
         LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);    
         if (lpidlBrowse != NULL)   
         {   
             // 取得文件夹名   
             if (::SHGetPathFromIDList(lpidlBrowse,szFolderPath))     
             {   
                strFolderPath = szFolderPath;   
             }   
         }   
         if(lpidlBrowse != NULL)   
         {   
             ::CoTaskMemFree(lpidlBrowse);   
         }   
    
 		 
         return strFolderPath;   
} 
