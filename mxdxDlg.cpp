// mxdxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mxdx.h"
#include "mxdxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMxdxDlg dialog

CMxdxDlg::CMxdxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMxdxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMxdxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMxdxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMxdxDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX,IDC_TREE_MENU,m_Menu);
	DDX_Control(pDX,IDC_TAB_CONTENT,m_Content);
}

BEGIN_MESSAGE_MAP(CMxdxDlg, CDialog)
	//{{AFX_MSG_MAP(CMxdxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_MENU, OnSelchangedTreeMenu)
	ON_COMMAND(ID_MENUITEM_ABOUT, OnMenuitemAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMxdxDlg message handlers

BOOL CMxdxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	initMenu();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMxdxDlg::initMenu()
{
	char title[TITLELEN];
	int i=0;int t=0;
	while(i<MENUICOUNT){
		LoadString(GetModuleHandle(NULL),MI_ID[i],title,TITLELEN);
		m_MenuItem[i]=m_Menu.InsertItem(_T(title),0,0);
		int j=0;
		while(j<MICC[i]){
			LoadString(GetModuleHandle(NULL),MIC_ID[t],&m_MenuTitle[t*TITLELEN],TITLELEN);
			m_MenuItemChild[t]=m_Menu.InsertItem(_T(&m_MenuTitle[t*TITLELEN]),0,0,m_MenuItem[i],TVI_LAST);
			j++;t++;
		}
		i++;
	}

	m_ContentItem=(CDialog**)calloc(sizeof(CDialog**),MENUICCOUNT);
}

void CMxdxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMxdxDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMxdxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMxdxDlg::OnSelchangedTreeMenu(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code hereS
	changeTab();
	*pResult = 0;
}

void CMxdxDlg::changeTab()
{
	m_Content.DeleteAllItems();
	HTREEITEM item=m_Menu.GetSelectedItem();
	int i=0;
	while(i<MENUICCOUNT){
		if(item==m_MenuItemChild[i]){
			m_Content.InsertItem(0,&m_MenuTitle[i*TITLELEN]);
			if(!m_ContentItem[i]){
				createCntDlg(i);
			}
			showCntDlg(i);
		}
		i++;
	}
}

void CMxdxDlg::createCntDlg(int idx)
{
	m_ContentItem[idx] = new CDialog();
	m_ContentItem[idx]->Create(CI_ID[idx],&m_Content);
}

void CMxdxDlg::showCntDlg(int idx)
{
	static CDialog* dlg=NULL;
	CRect rect;
	m_Content.GetClientRect(&rect);
	rect.left += 1;                  
    rect.right -= 1;   
    rect.top += 25;   
    rect.bottom -= 1; 
	if(dlg)
		dlg->SetWindowPos(NULL,rect.left,rect.top,rect.Width(),rect.Height(),SWP_HIDEWINDOW);
	dlg=m_ContentItem[idx];
	m_ContentItem[idx]->SetWindowPos(NULL,rect.left,rect.top,rect.Width(),rect.Height(),SWP_SHOWWINDOW);
}

void CMxdxDlg::OnMenuitemAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}
