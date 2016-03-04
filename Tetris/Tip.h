#if !defined(AFX_TIP_H__F62B5CC9_3A61_4C5D_8B52_A737CAC05D8D__INCLUDED_)
#define AFX_TIP_H__F62B5CC9_3A61_4C5D_8B52_A737CAC05D8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tip.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Tip dialog

class Tip : public CDialog
{
// Construction
public:
	Tip(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Tip)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Tip)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Tip)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIP_H__F62B5CC9_3A61_4C5D_8B52_A737CAC05D8D__INCLUDED_)
