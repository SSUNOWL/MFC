
// project3aView.h: Cproject3aView 클래스의 인터페이스
//

#pragma once


class Cproject3aView : public CView
{
protected: // serialization에서만 만들어집니다.
	Cproject3aView() noexcept;
	DECLARE_DYNCREATE(Cproject3aView)

// 특성입니다.
public:
	Cproject3aDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cproject3aView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_bTimerState;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	CString m_strTimer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	SYSTEMTIME m_ctTimerStart;
	bool m_bTimerInit;
	SYSTEMTIME m_ctTimerStop;
	long long delayed;
	CStringArray m_arrRecord;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int count;
};

#ifndef _DEBUG  // project3aView.cpp의 디버그 버전
inline Cproject3aDoc* Cproject3aView::GetDocument() const
   { return reinterpret_cast<Cproject3aDoc*>(m_pDocument); }
#endif

