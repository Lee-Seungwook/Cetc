
// HistogramExamDlg.h: 헤더 파일
//

#pragma once


// CHistogramExamDlg 대화 상자
class CHistogramExamDlg : public CDialogEx
{
private:
	CImage m_image;
	int his_arr_r[256];
	int his_arr_g[256];
	int his_arr_b[256];
// 생성입니다.
public:
	CHistogramExamDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HISTOGRAMEXAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton3();
};
