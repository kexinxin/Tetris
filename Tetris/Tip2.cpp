// Tip2.cpp : implementation file
//

#include "stdafx.h"
#include "Ff.h"
#include "Tip2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Tip2 dialog


Tip2::Tip2(CWnd* pParent /*=NULL*/)
	: CDialog(Tip2::IDD, pParent)
{
	//{{AFX_DATA_INIT(Tip2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Tip2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Tip2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Tip2, CDialog)
	//{{AFX_MSG_MAP(Tip2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Tip2 message handlers
