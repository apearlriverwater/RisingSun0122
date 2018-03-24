// ControlDfcfDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "readDFCF.h"
#include "ControlDfcfDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// CControlDfcfDlg 对话框

IMPLEMENT_DYNAMIC(CControlDfcfDlg, CDialogEx)

CControlDfcfDlg::CControlDfcfDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LASTMSGBOXINFO, pParent)
{

}

CControlDfcfDlg::~CControlDfcfDlg()
{
}

void CControlDfcfDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CControlDfcfDlg, CDialogEx)
END_MESSAGE_MAP()


// CControlDfcfDlg 消息处理程序
