#pragma once


// CControlDfcfDlg 对话框

class CControlDfcfDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CControlDfcfDlg)

public:
	CControlDfcfDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CControlDfcfDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LASTMSGBOXINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
