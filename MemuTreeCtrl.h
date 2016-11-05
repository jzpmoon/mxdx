#if !defined(AFX_MEMUTREECTRL_H__B6334590_F41C_4D90_B8BB_8E92108BA836__INCLUDED_)
#define AFX_MEMUTREECTRL_H__B6334590_F41C_4D90_B8BB_8E92108BA836__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MemuTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMemuTreeCtrl window
#include "ContentTabCtrl.h"

class CMemuTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CMemuTreeCtrl();

// Attributes
public:

// Operations
public:
	void setContent(CContentTabCtrl* content);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemuTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMemuTreeCtrl();
	virtual BOOL CMemuTreeCtrl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext);

	// Generated message map functions
protected:
	//{{AFX_MSG(CMemuTreeCtrl)
	afx_msg void OnPaint();
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	HTREEITEM item[3];
	HTREEITEM citem[3][3];
	CContentTabCtrl* content;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMUTREECTRL_H__B6334590_F41C_4D90_B8BB_8E92108BA836__INCLUDED_)
