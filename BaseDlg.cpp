// BaseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "iOSNeedImage.h"
#include "BaseDlg.h"
#include "afxdialogex.h"



UINT indicators_base_dlg[]={ 
 IDS_STRING_STATUS 
}; 

// CBaseDlg �Ի���

IMPLEMENT_DYNAMIC(CBaseDlg, CDialogEx)

CBaseDlg::CBaseDlg(UINT nIDTemplate,CWnd* pParent /*=NULL*/)
	: CDialogEx(nIDTemplate, pParent)
{

}

CBaseDlg::~CBaseDlg()
{
}

void CBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBaseDlg, CDialogEx)
	ON_MESSAGE(WM_MSG_STATUS,&CBaseDlg::OnMessageReceive)
END_MESSAGE_MAP()


// CBaseDlg ��Ϣ�������
BOOL CBaseDlg::OnInitDialog() 
{ 
 	CDialogEx::OnInitDialog(); 
 
 
 	if (!m_statusbar_status.Create(this) || 
         !m_statusbar_status.SetIndicators(indicators_base_dlg,sizeof(indicators_base_dlg)/sizeof(UINT)) 
     ) 
 	{ 
 		   TRACE0("Failed to create status bar\n"); 
 		   return -1;      // fail to create 
 	} 
 	m_statusbar_status.SetPaneInfo(0,indicators_base_dlg[0],SBPS_STRETCH,400);	 
      
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,AFX_IDW_CONTROLBAR_FIRST); 
 
 
 	ModifyStyleEx(0,WS_EX_APPWINDOW); 
 	DragAcceptFiles(); 
 
 
	setEnable(FALSE); 
 
 
	  
 	return TRUE; 
} 
void CBaseDlg::SendMessageStatus(MSG_TYPE type,CString msg) 
{ 
 	SendMessage(WM_MSG_STATUS,type,(LPARAM)msg.GetBuffer()); 
 	msg.ReleaseBuffer(); 
} 
LONG CBaseDlg::OnMessageReceive(WPARAM wParam,LPARAM lParam) 
 { 
 	CString msg = (TCHAR*)lParam; 
 	switch(wParam) 
 	{	 
 	case MSG_TYPE::MSG_Processing: 
 		{ 
 			m_statusbar_status.SetPaneText(0,L"������"); 
 			setEnable(FALSE); 
 		} 
 		break; 
 	case MSG_TYPE::MSG_Finish: 
 		{ 
 			setEnable(TRUE); 
 			m_statusbar_status.SetPaneText(0,L"���"); 
 			MessageBox(L"�ɹ�",L"��ʾ"); 
 		} 
 		break; 
 	case MSG_TYPE::MSG_Loading: 
 		{ 
 		    m_statusbar_status.SetPaneText(0,L"������"); 
 			setEnable(FALSE); 
 		} 
 		break;	 
 	case MSG_TYPE::MSG_Other: 
 		{ 
 			m_statusbar_status.SetPaneText(0,msg); 
 		} 
 		break; 
 	}	 
 	return 0; 
 } 
BOOL CBaseDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE || pMsg->wParam==VK_RETURN) return TRUE;  
 	return CDialog::PreTranslateMessage(pMsg); 
} 
