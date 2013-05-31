
// HandjetDlg.h : ͷ�ļ�
//

#pragma once

#include "ImageProcessor.h"

// CHandjetDlg �Ի���
class CHandjetDlg : public CDialogEx
{
// ����
public:
	CHandjetDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HANDJET_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
	ImageProcessor* m_ImageProcessor;
	bool checked;
	bool showVideo;
	bool blueMethod;


	HCURSOR m_cursor_fw;
	HCURSOR m_cursor_backup_fw;
	HCURSOR m_cursor_mw;
	HCURSOR m_cursor_backup_mw;
	HCURSOR m_cursor_hw;
	HCURSOR m_cursor_backup_hw;
	HCURSOR m_cursor_hb;
	HCURSOR m_cursor_backup_hb;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedCheck2();
};
