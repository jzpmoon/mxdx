// LoginDialog.cpp : implementation file
//

#include "stdafx.h"
#include "mxdx.h"
#include "LoginDialog.h"
#include "dataaccess/UserAccess.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog


CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDialog::IDD, pParent),m_radio("0")
{
	//{{AFX_DATA_INIT(CLoginDialog)
	m_name = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDialog)
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
	//{{AFX_MSG_MAP(CLoginDialog)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_OK, OnLoginOk)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_CANCEL, OnLoginCancel)
	ON_BN_CLICKED(IDC_RADIO_ADMIN, OnRadioAdmin)
	ON_BN_CLICKED(IDC_RADIO_USER, OnRadioUser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog message handlers

void CLoginDialog::OnLoginOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	UserData user;
	user.setName(m_name);
	user.setPassword(m_password);
	user.setPermission(m_radio);
	UserAccess access;
	if(access.isExists(&user))
		this->OnOK();
	else
		AfxMessageBox(_T("µÇÂ½Ê§°Ü£¡"));
}

void CLoginDialog::OnLoginCancel() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}

void CLoginDialog::OnRadioAdmin() 
{
	// TODO: Add your control notification handler code here
	m_radio="1";
}

void CLoginDialog::OnRadioUser() 
{
	// TODO: Add your control notification handler code here
	m_radio="2";
}
