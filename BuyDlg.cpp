// BuyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mxdx.h"
#include "BuyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBuyDlg dialog


CBuyDlg::CBuyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBuyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBuyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBuyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBuyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBuyDlg, CDialog)
	//{{AFX_MSG_MAP(CBuyDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBuyDlg message handlers
