#if !defined(AFX_TIP2_H__EE5C2B03_66A6_4E17_9668_EEB884D2D046__INCLUDED_)
#define AFX_TIP2_H__EE5C2B03_66A6_4E17_9668_EEB884D2D046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tip2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Tip2 dialog

class Tip2 : public CDialog
{
// Construction
public:
	Tip2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Tip2)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Tip2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Tip2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIP2_H__EE5C2B03_66A6_4E17_9668_EEB884D2D046__INCLUDED_)
