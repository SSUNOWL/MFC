
// project3aView.cpp: Cproject3aView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "project3a.h"
#endif

#include "project3aDoc.h"
#include "project3aView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cproject3aView

IMPLEMENT_DYNCREATE(Cproject3aView, CView)

BEGIN_MESSAGE_MAP(Cproject3aView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Cproject3aView 생성/소멸

Cproject3aView::Cproject3aView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bTimerState = 1;
	m_bTimerInit = TRUE;
	m_strTimer = "00: 00. 00";
	count = 0;
}

Cproject3aView::~Cproject3aView()
{
}

BOOL Cproject3aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cproject3aView 그리기

void Cproject3aView::OnDraw(CDC* pDC)
{
	Cproject3aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);

	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	for (int i = 0; i < m_arrRecord.GetSize(); i++) {
		CString str = m_arrRecord.GetAt(i);
		pDC->TextOut(0, i*20, str);
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cproject3aView 인쇄

BOOL Cproject3aView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cproject3aView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cproject3aView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cproject3aView 진단

#ifdef _DEBUG
void Cproject3aView::AssertValid() const
{
	CView::AssertValid();
}

void Cproject3aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cproject3aDoc* Cproject3aView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cproject3aDoc)));
	return (Cproject3aDoc*)m_pDocument;
}
#endif //_DEBUG


// Cproject3aView 메시지 처리기

void Cproject3aView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//시작 1, 중지2, 계속3
	if (m_bTimerState == 1) {
		delayed = 0;
		GetLocalTime(&m_ctTimerStart);
		SetTimer(0, 10, NULL);
		m_bTimerState = 2;
	}
	else if (m_bTimerState == 2) {
		KillTimer(0);
		GetLocalTime(&m_ctTimerStop);
		m_bTimerState = 3;
	}
	else {
		SYSTEMTIME time;
		GetLocalTime(&time);
		long long stop_ms = m_ctTimerStop.wMinute * 60000 + m_ctTimerStop.wSecond * 1000 + m_ctTimerStop.wMilliseconds;
		long long times = time.wMinute * 60000 + time.wSecond * 1000 + time.wMilliseconds;
		delayed += times - stop_ms;
		m_bTimerState = 2; 
		SetTimer(0, 10, NULL);
	}

	CView::OnLButtonDown(nFlags, point);
}

void Cproject3aView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CView::OnRButtonDown(nFlags, point);
	int ret = AfxMessageBox(_T("초기화하시겠습니까?"), MB_YESNO | MB_ICONINFORMATION);
	if (ret == IDYES) {
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		m_bTimerState = 1;
		m_bTimerInit = TRUE;
		m_strTimer = "00: 00. 00";
		Invalidate();
		m_arrRecord.RemoveAll();
		KillTimer(0);
	}
}

void Cproject3aView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnTimer(nIDEvent);
	CString str;
	SYSTEMTIME timer;
				// 타이머 변수 선언
	GetLocalTime(&timer);
	int min, sec, mil;
	// 1. 시작 시간과 현재 시간을 모두 밀리초로 변환합니다.
	long long start_ms = m_ctTimerStart.wMinute * 60000 + m_ctTimerStart.wSecond * 1000 + m_ctTimerStart.wMilliseconds;
	long long current_ms = timer.wMinute * 60000 + timer.wSecond * 1000 + timer.wMilliseconds;
	// 2. 두 시간의 차이를 밀리초 단위로 계산합니다.
	long long diff_ms = current_ms - start_ms - delayed;

	// 3. 밀리초 차이를 분, 초, 밀리초로 다시 변환합니다.
	min = diff_ms / 60000;          // 1분 = 60,000ms
	sec = (diff_ms % 60000) / 1000; // 남은 밀리초를 초로 변환
	mil = (diff_ms % 1000)/10;           // 남은 밀리초
	m_strTimer.Format(_T("%02d: %02d. %02d"), min, sec, mil);
	
	Invalidate();

}

void Cproject3aView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.



	CView::OnKeyDown(nChar, nRepCnt, nFlags);


	switch (nChar)					// 가상키 코드 값에 대해 
	{
	case VK_SPACE:
		if (m_arrRecord.GetSize() > 29) {
			m_arrRecord.RemoveAll();
		}
		m_arrRecord.Add(m_strTimer);
		count++;
		Invalidate();
		break;


	}
}
