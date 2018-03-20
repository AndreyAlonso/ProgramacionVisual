// Boton_ImagenDlg.h : header file
//

#if !defined(AFX_BOTON_IMAGENDLG_H__86F2B8FE_4D9F_4394_BC6F_838AC858DC48__INCLUDED_)
#define AFX_BOTON_IMAGENDLG_H__86F2B8FE_4D9F_4394_BC6F_838AC858DC48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBoton_ImagenDlg dialog

class CBoton_ImagenDlg : public CDialog
{
// Construction
public:
	CBitmapButton img;
	CBoton_ImagenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBoton_ImagenDlg)
	enum { IDD = IDD_BOTON_IMAGEN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoton_ImagenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBoton_ImagenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOTON_IMAGENDLG_H__86F2B8FE_4D9F_4394_BC6F_838AC858DC48__INCLUDED_)
