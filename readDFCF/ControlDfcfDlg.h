#pragma once


// CControlDfcfDlg �Ի���

class CControlDfcfDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CControlDfcfDlg)

public:
	CControlDfcfDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CControlDfcfDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LASTMSGBOXINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
