// mxdx.h : main header file for the MXDX application
//

#if !defined(AFX_MXDX_H__1183C825_3347_4AFB_A610_8570F0CDBBA5__INCLUDED_)
#define AFX_MXDX_H__1183C825_3347_4AFB_A610_8570F0CDBBA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMxdxApp:
// See mxdx.cpp for the implementation of this class
//

class CMxdxApp : public CWinApp
{
public:
	CMxdxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMxdxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMxdxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
private:
	void enter();

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MXDX_H__1183C825_3347_4AFB_A610_8570F0CDBBA5__INCLUDED_)
