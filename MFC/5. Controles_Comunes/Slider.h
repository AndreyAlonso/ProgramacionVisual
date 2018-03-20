#if !defined(AFX_SLIDER_H__34A7FFEC_FE60_4CBA_98A4_676AF7C82FD1__INCLUDED_)
#define AFX_SLIDER_H__34A7FFEC_FE60_4CBA_98A4_676AF7C82FD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Slider.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlider dialog

class CSlider : public CDialog
{
// Construction
public:
	BOOL band_accion;
	CSlider(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSlider)
	enum { IDD = IDD_SLIDER };
	CSliderCtrl	m_Slider2;
	CSliderCtrl	m_Slider1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlider)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSlider)
	afx_msg void OnAccion();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDER_H__34A7FFEC_FE60_4CBA_98A4_676AF7C82FD1__INCLUDED_)
