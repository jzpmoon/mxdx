// MemuTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "mxdx.h"
#include "MemuTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMemuTreeCtrl

CMemuTreeCtrl::CMemuTreeCtrl()
{
}

CMemuTreeCtrl::~CMemuTreeCtrl()
{
}
void CMemuTreeCtrl::setContent(CContentTabCtrl* content)
{
	this->content=content;
}


BEGIN_MESSAGE_MAP(CMemuTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CMemuTreeCtrl)
	ON_WM_PAINT()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMemuTreeCtrl message handlers

BOOL CMemuTreeCtrl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CMemuTreeCtrl::OnPaint() 
{
	//CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CTreeCtrl::OnPaint() for painting messages
	static int i=1;
	if(i){
		int j=0;
		while(j<3){
			item[j]=this->InsertItem(_T("hello"),0,0);
			int t=0;
			while(t<3){
				citem[j][t]=this->InsertItem(_T("hello"),1,1,item[j],TVI_LAST);
				t++;
			}
			j++;
		}
		i--;
	}
	CTreeCtrl::OnPaint();
}


void CMemuTreeCtrl::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	content->DeleteAllItems();
	content->InsertItem(0,_T("hello"));
	*pResult = 0;
}
