// convertShellCodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "convertShellCode.h"
#include "convertShellCodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvertShellCodeDlg dialog

CConvertShellCodeDlg::CConvertShellCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConvertShellCodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConvertShellCodeDlg)
	m_c_format = _T("");
	m_javacript_format = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvertShellCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConvertShellCodeDlg)
	DDX_Text(pDX, IDC_EDIT_C, m_c_format);
	DDX_Text(pDX, IDC_EDIT_JAVASCRIPT, m_javacript_format);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CConvertShellCodeDlg, CDialog)
	//{{AFX_MSG_MAP(CConvertShellCodeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TO_JAVASCRIPT, OnButtonToJavascript)
	ON_BN_CLICKED(IDC_BUTTON_TO_C, OnButtonToC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvertShellCodeDlg message handlers

BOOL CConvertShellCodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetWindowText("C←→javascript的shellcode格式转化工具(by giantbranch)");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CConvertShellCodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CConvertShellCodeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CConvertShellCodeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CConvertShellCodeDlg::OnButtonToJavascript() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); //将界面上的数据更新到变量
	int c_format_len = strlen(m_c_format);
	CString final;
	char *result;
	result = new char[c_format_len];
	//将result置空
	sprintf(result, "%s", "");
	char *tmp = new char[10];
	//如果shellcode不是偶数个字节
	if (c_format_len % 8){
		m_c_format = m_c_format + "\\x00";
		//将长度更新
		c_format_len = strlen(m_c_format);
	}
	for (int i = 2; i <= c_format_len-6 ;i = i + 8 ){
			CString tmp1 = m_c_format.Mid(i, 2);
			CString tmp2 = m_c_format.Mid(i+4, 2);
			sprintf(tmp, "\\u%s%s", tmp2, tmp1);
			strcat(result, tmp);
	}
	final.Format("%s", result);
	m_javacript_format = final;
	UpdateData(FALSE); //变量值更新到界面
}

void CConvertShellCodeDlg::OnButtonToC() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); //将界面上的数据更新到变量
	int javacript_format_len = strlen(m_javacript_format);
	CString final;
	char *result;
	result = new char[javacript_format_len*2];
	//将result置空
	sprintf(result, "%s", "");
	char *tmp = new char[10];
	for (int i = 2; i <= javacript_format_len-4 ;i = i + 6 ){
			CString tmp1 = m_javacript_format.Mid(i, 2);
			CString tmp2 = m_javacript_format.Mid(i+2, 2);
			sprintf(tmp, "\\x%s\\x%s", tmp2, tmp1);
			strcat(result, tmp);
	}
	final.Format("%s", result);
	m_c_format = final;
	UpdateData(FALSE); //变量值更新到界面
}
