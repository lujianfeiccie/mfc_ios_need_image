#pragma once

#define WM_MSG_STATUS WM_USER + 100
enum MSG_TYPE 
{ 
MSG_Processing, 
MSG_Finish, 
MSG_FinishParagraphProcessing, 
MSG_Loading, 
MSG_XML_PATH_Empty, 
MSG_Other 
}; 
// CBaseDlg �Ի���

class CBaseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBaseDlg)

public:
	CBaseDlg(UINT nIDTemplate,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBaseDlg();
	BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP() 
 	CStatusBar m_statusbar_status; 

	BOOL PreTranslateMessage(MSG* pMsg);
	void SendMessageStatus(MSG_TYPE type,CString msg=L""); 
	LONG OnMessageReceive(WPARAM wParam,LPARAM lParam); 
	virtual void setEnable(BOOL enable)=0;
};
