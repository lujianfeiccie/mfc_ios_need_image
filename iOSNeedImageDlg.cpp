
// iOSNeedImageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "iOSNeedImage.h"
#include "iOSNeedImageDlg.h"
#include "afxdialogex.h"
#include "CheckResulgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CiOSNeedImageDlg �Ի���




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


// CiOSNeedImageDlg ��Ϣ�������

BOOL CiOSNeedImageDlg::OnInitDialog()
{
	CBaseDlg::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CiOSNeedImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CBaseDlg::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CiOSNeedImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CiOSNeedImageDlg::setEnable(BOOL enable)
{

}

void CiOSNeedImageDlg::OnBnClickedBtnBrowser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString directory_path = ShowDirectoryDlg();
	m_edit_directory.SetWindowTextW(directory_path);
}


void CiOSNeedImageDlg::OnBnClickedBtnStartValidate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString directory_str;
	m_edit_directory.GetWindowTextW(directory_str);
	if(directory_str.Trim() == L"")
	{
		MessageBox(L"��ʾ",L"�ļ��в���Ϊ��!");
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
        sInfo.lpszTitle   = _T("��ѡ��һ���ļ��У�");   
        sInfo.ulFlags   = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;   
        sInfo.lpfn     = NULL;   
   
         // ��ʾ�ļ���ѡ��Ի���   
         LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);    
         if (lpidlBrowse != NULL)   
         {   
             // ȡ���ļ�����   
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
