
// figure_testView.h : interface of the Cfigure_testView class
//

#pragma once


class Cfigure_testView : public CView
{
protected: // create from serialization only
	Cfigure_testView();
	DECLARE_DYNCREATE(Cfigure_testView)

// Attributes
public:
	Cfigure_testDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cfigure_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
	afx_msg void OnTest2();
	afx_msg void OnTest3();
};

#ifndef _DEBUG  // debug version in figure_testView.cpp
inline Cfigure_testDoc* Cfigure_testView::GetDocument() const
   { return reinterpret_cast<Cfigure_testDoc*>(m_pDocument); }
#endif

