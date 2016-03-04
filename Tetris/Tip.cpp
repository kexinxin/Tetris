// Tip.cpp : implementation file
//

#include "stdafx.h"
#include "Ff.h"
#include "Tip.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Tip dialog


Tip::Tip(CWnd* pParent /*=NULL*/)
	: CDialog(Tip::IDD, pParent)
{
	//{{AFX_DATA_INIT(Tip)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Tip::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Tip)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Tip, CDialog)
	//{{AFX_MSG_MAP(Tip)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Tip message handlers
