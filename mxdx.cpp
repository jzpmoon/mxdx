// mxdx.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "mxdx.h"
#include "mxdxDlg.h"
#include "LoginDialog.h"
#include "dataaccess/MxdxData.h"
#include "dataaccess/UserData.h"
#include "dataaccess/Resolver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMxdxApp

BEGIN_MESSAGE_MAP(CMxdxApp, CWinApp)
	//{{AFX_MSG_MAP(CMxdxApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMxdxApp construction

CMxdxApp::CMxdxApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMxdxApp object

CMxdxApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMxdxApp initialization

BOOL CMxdxApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	CLoginDialog loginDlg;
	int lResponse=loginDlg.DoModal();
	if(lResponse==IDOK)
	{
		//login
		enter();
	}
	else if(lResponse==IDCANCEL)
	{
		//logout
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
void CMxdxApp::enter()
{
	CMxdxDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
}
