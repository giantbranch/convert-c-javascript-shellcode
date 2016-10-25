// convertShellCodeDlg.h : header file
//

#if !defined(AFX_CONVERTSHELLCODEDLG_H__81807E32_49FB_4B45_80A2_6822E77D1DFD__INCLUDED_)
#define AFX_CONVERTSHELLCODEDLG_H__81807E32_49FB_4B45_80A2_6822E77D1DFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CConvertShellCodeDlg dialog

class CConvertShellCodeDlg : public CDialog
{
// Construction
public:
	CConvertShellCodeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CConvertShellCodeDlg)
	enum { IDD = IDD_CONVERTSHELLCODE_DIALOG };
	CString	m_c_format;
	CString	m_javacript_format;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertShellCodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CConvertShellCodeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonToJavascript();
	afx_msg void OnButtonToC();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTSHELLCODEDLG_H__81807E32_49FB_4B45_80A2_6822E77D1DFD__INCLUDED_)
