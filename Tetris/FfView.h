// FfView.h : interface of the CFfView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FFVIEW_H__12CC4185_8886_4D45_9747_C09A00DDEA67__INCLUDED_)
#define AFX_FFVIEW_H__12CC4185_8886_4D45_9747_C09A00DDEA67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFfView : public CView
{protected: // create from serialization only
CFfView();
DECLARE_DYNCREATE(CFfView)
// Attributes
public:
	CFfDoc* GetDocument();
	// Operations
	//自己定义的 
	/*==================================================================*/
public:
	CBitmap *m_bitmap;
	void showShape(CDC *);      //显示图形
	void showPanel(CDC *);      //显示游戏面板
	void showGround(CDC *);     //显示障碍物
	bool isMovedown();          //判断图形是否允许下落，并且在其中做一些逻辑控制
	bool isMoveright();         //判断图形是否允许向右移动 
	bool isMoveleft();          //判断图形是否允许向左移动
    void accessShape();         //接受图形，赋予障碍物数组 
	void deleteLine(int y);     //真正删行的函数
	void isdeleteLine();        //删行的函数
	void changeStatus();        //改变图形的状态，即旋转
	void showMark(CDC *);            //显示得分
	void toShapes_pre(int type1);    //给预览图形数组赋值
	bool isGameover();            //判断游戏是否结束
	void showShape_pre(CDC *);
	void getShape();//产生图形
	int type; //图形的类型位
	int type1;//预揽图形类型位
	int status;//图形的状态位
	void toShapes(int type,int status);//给图形动态赋值
	int left;//图形横坐标
	int top;//图形纵坐标
	double mark;//记录分数
	int mark_1;//分数


	bool puase;
	void setTime();
	/*==================================================================*/
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFfView)
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	//}}AFX_VIRTUAL
	// Implementation
public:
	virtual ~CFfView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	// Generated message map functions
protected:
	//{{AFX_MSG(CFfView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnGameStart();
	afx_msg void OnGameOver();
	afx_msg void OnGamePause();
	afx_msg void OnUpdateGameStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGameOver(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGamePause(CCmdUI* pCmdUI);
	afx_msg void OnLevelNo1();
	afx_msg void OnUpdateLevelNo1(CCmdUI* pCmdUI);
	afx_msg void OnLevelNo2();
	afx_msg void OnUpdateLevelNo2(CCmdUI* pCmdUI);
	afx_msg void OnLevelHigh();
	afx_msg void OnUpdateLevelHigh(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnFileMusic();
	afx_msg void OnUpdateFileMusic(CCmdUI* pCmdUI);
	afx_msg void OnGameRestart();
	afx_msg void OnUpdateGameRestart(CCmdUI* pCmdUI);
	afx_msg void OnAppAbout();
	afx_msg void OnUpdateAppAbout(CCmdUI* pCmdUI);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in ffView.cpp
inline CFfDoc* CFfView::Getment()
{ return (CFfDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_FFVIEW_H__82332986_1A9D_487C_9E2F_82C2041DA3CB__INCLUDED_)
