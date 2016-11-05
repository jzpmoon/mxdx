#if !defined(AFX_LOGINDIALOG_H__2F5901C3_1657_4499_BFB0_092C95A35AEF__INCLUDED_)
#define AFX_LOGINDIALOG_H__2F5901C3_1657_4499_BFB0_092C95A35AEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog

class CLoginDialog : public CDialog
{
// Construction
public:
	CLoginDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDialog)
	enum { IDD = IDD_DIALOG_LOGIN };
	CString	m_name;
	CString	m_password;
	//}}AFX_DATA
	CString m_radio;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDialog)
	afx_msg void OnLoginOk();
	afx_msg void OnLoginCancel();
	afx_msg void OnRadioAdmin();
	afx_msg void OnRadioUser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDIALOG_H__2F5901C3_1657_4499_BFB0_092C95A35AEF__INCLUDED_)
