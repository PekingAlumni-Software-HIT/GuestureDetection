
// HandjetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Handjet.h"
#include "HandjetDlg.h"
#include "afxdialogex.h"
#include "MousePointerHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()

	
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CHandjetDlg �Ի���




CHandjetDlg::CHandjetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHandjetDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHandjetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHandjetDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHandjetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHandjetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CHandjetDlg::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_BUTTON3, &CHandjetDlg::OnBnClickedButton3)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_CHECK2, &CHandjetDlg::OnBnClickedCheck2)
END_MESSAGE_MAP()


// CHandjetDlg ��Ϣ�������

BOOL CHandjetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	blueMethod = false;
	checked = false;
	showVideo = false;
	m_ImageProcessor = NULL;

	m_cursor_hw = CopyCursor(AfxGetApp()->LoadCursor(IDC_HAND_W));
	m_cursor_backup_hw = CopyCursor(LoadCursor(NULL, IDC_ARROW));

	m_cursor_fw = CopyCursor(AfxGetApp()->LoadCursor(IDC_FIST_W));
	m_cursor_backup_fw = CopyCursor(LoadCursor(NULL, IDC_HAND));

	m_cursor_mw = CopyCursor(AfxGetApp()->LoadCursor(IDC_MIDDLE_W));
	m_cursor_backup_mw = CopyCursor(LoadCursor(NULL, IDC_WAIT));

	//SetCursor(m_cursor);
	


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHandjetDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHandjetDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHandjetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHandjetDlg::OnBnClickedButton1()
{
	SetSystemCursor(m_cursor_hw, 32512 );
	SetSystemCursor(m_cursor_mw, 32514 );
	SetSystemCursor(m_cursor_fw, 32649 );
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ImageProcessor = ImageProcessor::Instance();
	m_ImageProcessor->showVideo();
	m_ImageProcessor->process();
	delete m_ImageProcessor;
	//OnOK();
}


void CHandjetDlg::OnBnClickedButton2()
{

	SetSystemCursor(m_cursor_backup_hw, 32512 );
	SetSystemCursor(m_cursor_backup_mw, 32514 );
	SetSystemCursor(m_cursor_backup_fw, 32649 );

	DestroyCursor(m_cursor_backup_hw);
	DestroyCursor(m_cursor_backup_mw);
	DestroyCursor(m_cursor_backup_fw);

	m_cursor_backup_fw = NULL;
	m_cursor_backup_mw = NULL;
	m_cursor_backup_hw = NULL;

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ImageProcessor->stopVideo();
	m_ImageProcessor->stop();
}


void CHandjetDlg::OnBnClickedCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(!checked) {
		ImageProcessor::Instance()->setRunMode(1);
		checked = true;
	}
	else {
		ImageProcessor::Instance()->setRunMode(0);
		checked = false;
	}

	
}



void CHandjetDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_ImageProcessor) {
		if(showVideo) {
			m_ImageProcessor->stopVideo();
		}
		else {
			m_ImageProcessor->showVideo();
		}
	}
}


BOOL CHandjetDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	//if ( m_cursor )
	//{
	//	::SetCursor(m_cursor);
	//	return TRUE;
	//}
	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);;
}


void CHandjetDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	//::SetCursor(m_cursor);
	
	CDialogEx::OnMouseMove(nFlags, point);
	
}


void CHandjetDlg::OnBnClickedCheck2()
{
	m_ImageProcessor->blueMethodSwitch();
}
