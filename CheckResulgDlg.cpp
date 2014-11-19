// CheckResulgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "iOSNeedImage.h"
#include "CheckResulgDlg.h"
#include "afxdialogex.h"
#include "Util.h"

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

	lvColumn.mask = LVCF_FMT| LVCF_TEXT | LVCF_IMAGE | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 200;
	lvColumn.iImage = -1;
	lvColumn.pszText = _T("文件名");
	this->m_listctrl_check.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("期望分辨率");
	this->m_listctrl_check.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT |LVCF_IMAGE| LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 200;
	lvColumn.pszText = _T("结果");
	this->m_listctrl_check.InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_IMAGE| LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 48;
	lvColumn.pszText = _T("状态");
	this->m_listctrl_check.InsertColumn(3, &lvColumn);

	this->m_listctrl_check.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES|LVS_EX_SUBITEMIMAGES);

	CBitmap m_correct;
	m_correct.LoadBitmapW(IDB_CORRECT);

	CBitmap m_wrong;
	m_wrong.LoadBitmapW(IDB_WRONG);
;

	m_imagelist.Create(48, 48, ILC_COLOR32,1,0); 
	//m_imagelist.SetBkColor(RGB(255,255,255)); 
	m_imagelist.Add(&m_correct,RGB(0, 0, 0));
	m_imagelist.Add(&m_wrong,RGB(0, 0, 0));
	m_listctrl_check.SetImageList(&m_imagelist, LVSIL_SMALL); 
	//m_listctrl_check.SetItem(0,1,LVIF_TEXT | LVIF_IMAGE, L"Text", 3, 0, 0, 0);
	initData();

	check();

	updateList();

	return TRUE;
}
void CCheckResulgDlg::initData()
{
	CModelResult* model = NULL;

	//图标(文件名|分辨率)
	model = new CModelResult;
	model->m_image_name=L"Icon.png";
	model->m_image_resolution=L"57 x 57";
	model->m_width = 57;
	model->m_height = 57;
	model->m_result = L"待检验";
	m_list.push_back(model);

	model = new CModelResult;
	model->m_image_name=L"Icon@2x.png";
	model->m_image_resolution=L"114 x 114";
	model->m_width = 114;
	model->m_height = 114;
	model->m_result = L"待检验";
	m_list.push_back(model);

	model = new CModelResult;
	model->m_image_name=L"Icon-76.png";
	model->m_image_resolution=L"76 x 76";
	model->m_width = 76;
	model->m_height = 76;
	model->m_result = L"待检验";
	m_list.push_back(model);

	model = new CModelResult;
	model->m_image_name=L"Icon-120.png";
	model->m_image_resolution=L"120 x 120";
	model->m_width = 120;
	model->m_height = 120;
	model->m_result = L"待检验";
	m_list.push_back(model);

	model = new CModelResult;
	model->m_image_name=L"Icon-152.png";
	model->m_image_resolution=L"152 x 152";
	model->m_width = 152;
	model->m_height = 152;
	model->m_result = L"待检验";
	m_list.push_back(model);

	model = new CModelResult;
	model->m_image_name=L"Icon1024x1024.jpg";
	model->m_image_resolution=L"1024 x 1024";
	model->m_width = 1024;
	model->m_height = 1024;
	model->m_result = L"待检验";
	m_list.push_back(model);

	//启动界面 (文件名|分辨率)

	model = new CModelResult;
	model->m_image_name=L"Default.png";
	model->m_image_resolution=L"320 x 480";
	model->m_width = 320;
	model->m_height = 480;
	model->m_result = L"待检验";
	m_list.push_back(model);


	model = new CModelResult;
	model->m_image_name=L"Default@2x.png";
	model->m_image_resolution=L"640 x 960";
	model->m_width = 640;
	model->m_height = 960;
	model->m_result = L"待检验";
	m_list.push_back(model);


	model = new CModelResult;
	model->m_image_name=L"Default-568h@2x.png";
	model->m_image_resolution=L"640 x 1136";
	model->m_width = 640;
	model->m_height = 1136;
	model->m_result = L"待检验";
	m_list.push_back(model);
}
void CCheckResulgDlg::check()
{
	vector<CModelResult*>::iterator it;
	int i=0;
	
	for(it = m_list.begin(),i=0;it!=m_list.end();it++,i++)
	{
		CString filename = m_directory;
		filename.Append(L"\\"+(*it)->m_image_name);
		if(Util::IsExistFile(filename))
		{
			CImage image; 
			image.Load(filename);
			if(image.GetWidth()==(*it)->m_width &&
				image.GetHeight()==(*it)->m_height)
			{
				(*it)->m_result = L"图片符合条件";
				(*it)->m_state = 0;
			}
			else
			{
				CString tmp;
				tmp.Format(L"分辨率(%d x %d)不符合条件",image.GetWidth(),image.GetHeight());
				(*it)->m_result = tmp;
				(*it)->m_state = 1;
			}
		}
		else
		{
			(*it)->m_result = L"该文件不存在";
			(*it)->m_state = 1;
		}
		Util::LOG(L"%s",filename);
	}
}
void CCheckResulgDlg::updateList()
{
	m_listctrl_check.DeleteAllItems();

	vector<CModelResult*>::iterator it;
	int i=0;
	BOOL isOK = TRUE;
	for(it = m_list.begin(),i=0;it!=m_list.end();it++,i++)
	{
		LVITEM lvItem;
		int nItem;
		int imgNbr=1;


		lvItem.mask =  LVIF_TEXT | LVIF_IMAGE;
		lvItem.iItem = i;
		lvItem.iSubItem = 0;
		lvItem.pszText =LPSTR_TEXTCALLBACK;
		lvItem.iImage =  I_IMAGECALLBACK;
		nItem = this->m_listctrl_check.InsertItem(&lvItem);

		//Util::LOG(L"item=%d",nItem);

		CModelResult* obj = *it;
		this->m_listctrl_check.SetItemText(nItem, 0, obj->m_image_name);
		this->m_listctrl_check.SetItemText(nItem, 1, obj->m_image_resolution);
		this->m_listctrl_check.SetItemText(nItem, 2, obj->m_result);
		this->m_listctrl_check.SetItem(nItem,3,LVIF_IMAGE,L"adfd",obj->m_state,0,0,0);

		if(obj->m_state==1)
		{
			isOK = FALSE;
		}
	}
/*	if(isOK)
	{
		MessageBox(L"恭喜，全部符合!");
	}
	else
	{
		MessageBox(L"抱歉,不达标!");
	}*/
}

void CCheckResulgDlg::setEnable(BOOL enable)
{
}