// mxdxDlg.h : header file
//

#if !defined(AFX_MXDXDLG_H__68350A03_D61D_46B1_AF5D_F4A533F52958__INCLUDED_)
#define AFX_MXDXDLG_H__68350A03_D61D_46B1_AF5D_F4A533F52958__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMxdxDlg dialog

#include "MemuTreeCtrl.h"
#include "ContentTabCtrl.h"

class CMxdxDlg : public CDialog
{
// Construction
public:
	CMxdxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMxdxDlg)
	enum { IDD = IDD_MXDX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMxdxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMxdxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangedTreeMenu(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CTreeCtrl m_Menu;
	CTabCtrl m_Content;
	#define MENUICOUNT 5
	#define MI_0_COUNT 2
	#define MI_1_COUNT 2
	#define MI_2_COUNT 1
	#define MI_3_COUNT 2
	#define MI_4_COUNT 2
	#define MENUICCOUNT MI_0_COUNT+MI_1_COUNT+MI_2_COUNT+MI_3_COUNT+MI_4_COUNT
	#define TITLELEN 64
	HTREEITEM m_MenuItem[MENUICOUNT];
	HTREEITEM m_MenuItemChild[MENUICCOUNT];
	char m_MenuTitle[(MENUICCOUNT)*TITLELEN];
	CDialog** m_ContentItem;
	void initMenu();
	void changeTab();
	void createCntDlg(int idx);
	void showCntDlg(int idx);
};
static int MICC[]={MI_0_COUNT,MI_1_COUNT,MI_2_COUNT,MI_3_COUNT,MI_4_COUNT};
static int MI_ID[]={IDS_MENUITEM_0,IDS_MENUITEM_1,IDS_MENUITEM_2,IDS_MENUITEM_3,IDS_MENUITEM_4};
static int MIC_ID[]={IDS_MI_0_BUY,IDS_MI_0_CREDIT,IDS_MI_1_INOUT,IDS_MI_1_DATA,IDS_MI_2_RECORD,IDS_MI_3_USER1,IDS_MI_3_USER2,IDS_MI_4_SYSDATA,IDS_MI_4_PERSON};
static int CI_ID[]={IDD_DIALOG_BUY,IDD_DIALOG_CREDIT,IDD_DIALOG_DATA,IDD_DIALOG_INOUT,IDD_DIALOG_RECORD,IDD_DIALOG_USER1,IDD_DIALOG_USER2,IDD_DIALOG_SYSDATA,IDD_DIALOG_PERSON};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MXDXDLG_H__68350A03_D61D_46B1_AF5D_F4A533F52958__INCLUDED_)
