// BasadoDLGDlg.h : header file
//

#if !defined(AFX_BASADODLGDLG_H__B87D0434_3060_48DA_A21C_D4DC758CDD6D__INCLUDED_)
#define AFX_BASADODLGDLG_H__B87D0434_3060_48DA_A21C_D4DC758CDD6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBasadoDLGDlg dialog

class CBasadoDLGDlg : public CDialog
{
// Construction
public:
	CWnd *pCombo;
	CBasadoDLGDlg(CWnd* pParent = NULL);	// standard constructor
	CComboBox *c1;
	CEdit *edit;
	

// Dialog Data
	//{{AFX_DATA(CBasadoDLGDlg)
	enum { IDD = IDD_BASADODLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasadoDLGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBasadoDLGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAccion();
	afx_msg void OnUpdateEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASADODLGDLG_H__B87D0434_3060_48DA_A21C_D4DC758CDD6D__INCLUDED_)
