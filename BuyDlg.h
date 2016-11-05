#if !defined(AFX_BUYDLG_H__4F39517C_A3F5_4128_BD98_C639B43DCD04__INCLUDED_)
#define AFX_BUYDLG_H__4F39517C_A3F5_4128_BD98_C639B43DCD04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BuyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBuyDlg dialog

class CBuyDlg : public CDialog
{
// Construction
public:
	CBuyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBuyDlg)
	enum { IDD = IDD_DIALOG_BUY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBuyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBuyDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUYDLG_H__4F39517C_A3F5_4128_BD98_C639B43DCD04__INCLUDED_)
