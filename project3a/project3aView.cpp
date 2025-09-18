
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
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Cproject3aView 생성/소멸

Cproject3aView::Cproject3aView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

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

void Cproject3aView::OnDraw(CDC* /*pDC*/)
{
	Cproject3aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

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

int Cproject3aView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	AfxMessageBox(_T("윈도우가 생성되었습니다."), MB_OKCANCEL | MB_ICONINFORMATION);
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}

void Cproject3aView::OnDestroy()
{
	CView::OnDestroy();
	AfxMessageBox(_T("윈도우가 종료되었습니다."), MB_OK | MB_ICONINFORMATION);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void Cproject3aView::OnLButtonDblClk(UINT nFlags, CPoint point)
{	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxMessageBox(_T("왼쪽 마우스 버튼을 더블클릭하였습니까?"), MB_YESNO| MB_ICONQUESTION);

	CView::OnLButtonDblClk(nFlags, point);
}
