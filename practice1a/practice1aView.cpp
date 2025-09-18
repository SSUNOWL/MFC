
// practice1aView.cpp: Cpractice1aView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "practice1a.h"
#endif

#include "practice1aDoc.h"
#include "practice1aView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cpractice1aView

IMPLEMENT_DYNCREATE(Cpractice1aView, CView)

BEGIN_MESSAGE_MAP(Cpractice1aView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// Cpractice1aView 생성/소멸

Cpractice1aView::Cpractice1aView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cpractice1aView::~Cpractice1aView()
{
}

BOOL Cpractice1aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cpractice1aView 그리기

void Cpractice1aView::OnDraw(CDC* pDC)
{
	Cpractice1aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOut(10, 10, m_strWindowSize);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cpractice1aView 인쇄

BOOL Cpractice1aView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cpractice1aView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cpractice1aView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cpractice1aView 진단

#ifdef _DEBUG
void Cpractice1aView::AssertValid() const
{
	CView::AssertValid();
}

void Cpractice1aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cpractice1aDoc* Cpractice1aView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cpractice1aDoc)));
	return (Cpractice1aDoc*)m_pDocument;
}
#endif //_DEBUG


// Cpractice1aView 메시지 처리기

void Cpractice1aView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	m_strWindowSize.Format(_T("size %d %d"), cx, cy);

	Invalidate();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
