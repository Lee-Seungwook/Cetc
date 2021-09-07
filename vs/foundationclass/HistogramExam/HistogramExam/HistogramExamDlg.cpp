// HistogramExamDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "HistogramExam.h"
#include "HistogramExamDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHistogramExamDlg 대화 상자

CHistogramExamDlg::CHistogramExamDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HISTOGRAMEXAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHistogramExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHistogramExamDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHistogramExamDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHistogramExamDlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CHistogramExamDlg::OnClickedButton3)
END_MESSAGE_MAP()


// CHistogramExamDlg 메시지 처리기

BOOL CHistogramExamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);            // 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);        // 작은 아이콘을 설정합니다.

	m_image.Load(L"cfc.jpg");



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}


void CHistogramExamDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHistogramExamDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CHistogramExamDlg::OnClickedButton1()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CHistogramExamDlg::OnClickedButton2()
{
	CClientDC dc(this);

	for (int i = 0; i < 255; i++) {
		dc.Rectangle(200 + (i * 2), 400 - his_arr_r[i], 205 + (i * 2), 400);
	}
	
}

void CHistogramExamDlg::OnClickedButton3()
{
	CClientDC dc(this);

	COLORREF temp_color;

	int color_count = 0, x, y, i;

	for (y = 0; y < m_image.GetHeight(); y++) {
		for (x = 0; x < m_image.GetWidth(); x++) {

			temp_color = dc.GetPixel(x, y); // x,y 위치의 색상을 가져와서 temp_color에 저장

			BYTE r = GetRValue(temp_color);
			BYTE g = GetGValue(temp_color);
			BYTE b = GetBValue(temp_color);

			his_arr_r[(int)r]++;
			his_arr_g[(int)g]++;
			his_arr_b[(int)b]++;
		}
	}
}