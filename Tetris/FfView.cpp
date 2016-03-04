// FfView.cpp : implementation of the CFfView class
//

#include "stdafx.h"
#include "Ff.h"
#include "mmsystem.h"
#pragma  comment(lib,"winmm.lib")
#include "FfDoc.h"
#include "FfView.h"
#include "TipDlg.h"
#include"Tip2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//自己定义的
/*--------------------------------------------------------------------------*/
//int shapes[4][4]={{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}};
//int shapes[4][4]={{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}};
//int shapes[4][4]={{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}};
int music=1;
int  level=5;//等级
bool frist=true;   //第一次运行程序的标志位
bool gameing=true; //游戏正在运行标志位
bool frist_type=true; //第一次产生图形标志位 
bool m_gamePause=false;
bool m_gameOver=false;
int shapes[4][4];  //图形数组
int shapes_pre[4][4];//预览数组
int const c=20;
int const k=12;
int const p=4;
int const s=20;
int  const ss=10;
int ground[k+p-1][c+p-1];//障碍物数组
int shape[7][4][4][4]={     //存储图形的数组库
	{   //直线型
		{{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
		{{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}}
	},
	{   //方形类
		{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
		{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
		{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
		{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}
	},
	{   //第三类
		{{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}},
		{{0,0,0,0},{0,1,1,1},{0,1,0,0},{0,0,0,0}},
		{{0,0,1,0},{0,0,1,0},{0,0,1,1},{0,0,0,0}},
		{{0,0,0,1},{0,1,1,1},{0,0,0,0},{0,0,0,0}}
	},
	{   //第四类
		{{0,0,1,1},{0,0,1,0},{0,0,1,0},{0,0,0,0}},
		{{0,1,0,0},{0,1,1,1},{0,0,0,0},{0,0,0,0}},
		{{0,0,1,0},{0,0,1,0},{0,1,1,0},{0,0,0,0}},
		{{0,0,0,0},{0,1,1,1},{0,0,0,1},{0,0,0,0}}
	},
	{   //第五类
		{{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
		{{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
		{{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
	},
	{   //第六类
		{{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,0,0}},
		{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
		{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}
		},
		{   //第七类
			{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
			{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
			{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
		}
};
/*--------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////////////////
// CFfView
IMPLEMENT_DYNCREATE(CFfView, CView)
BEGIN_MESSAGE_MAP(CFfView, CView)
	//{{AFX_MSG_MAP(CFfView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_GAME_START, OnGameStart)
	ON_COMMAND(ID_GAME_OVER, OnGameOver)
	ON_COMMAND(ID_GAME_PAUSE, OnGamePause)
	ON_UPDATE_COMMAND_UI(ID_GAME_START, OnUpdateGameStart)
	ON_UPDATE_COMMAND_UI(ID_GAME_OVER, OnUpdateGameOver)
	ON_UPDATE_COMMAND_UI(ID_GAME_PAUSE, OnUpdateGamePause)
	ON_COMMAND(ID_LEVEL_NO1, OnLevelNo1)
	ON_UPDATE_COMMAND_UI(ID_LEVEL_NO1, OnUpdateLevelNo1)
	ON_COMMAND(ID_LEVEL_NO2, OnLevelNo2)
	ON_UPDATE_COMMAND_UI(ID_LEVEL_NO2, OnUpdateLevelNo2)
	ON_COMMAND(ID_LEVEL_HIGH, OnLevelHigh)
	ON_UPDATE_COMMAND_UI(ID_LEVEL_HIGH, OnUpdateLevelHigh)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_FILE_MUSIC, OnFileMusic)
	ON_UPDATE_COMMAND_UI(ID_FILE_MUSIC, OnUpdateFileMusic)
	ON_COMMAND(ID_GAME_RESTART, OnGameRestart)
	ON_UPDATE_COMMAND_UI(ID_GAME_RESTART, OnUpdateGameRestart)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_UPDATE_COMMAND_UI(ID_APP_ABOUT, OnUpdateAppAbout)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CFfView construction/destruction
CFfView::CFfView()
{   // TODO: add construction code here
	m_bitmap =new CBitmap;
    m_bitmap->LoadBitmap(IDB_BITMAP1);
	left=k/2+p;
	mark=0;
	top=0;
	puase=true;
	for(int y=0;y<=c+p-2;y++){
		for(int x=0;x<=k+p-2;x++){
			ground[x][y]=0;
			}
	}
}
CFfView::~CFfView()
{
}
BOOL CFfView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}
/////////////////////////////////////////////////////////////////////////////
// CFfView drawing
void CFfView::OnDraw(CDC* pDC)
{
	CDC MemDC;   
	//定义一个位图对象   
	CBitmap MemBitmap;  
	//建立与屏幕设备描述表（前端缓冲区）兼容的内存设备描述表句柄（后备缓冲区）   
	MemDC.CreateCompatibleDC(NULL);  
	//这时还不能绘图，因为没有位图的设备描述表是不能绘图的   
	//下面建立一个与屏幕设备描述表（或者内存设备描述表）兼容的位图   
	MemBitmap.CreateCompatibleBitmap(pDC,600,600);  
	//将位图选入到内存设备描述表   
	//只有选入了位图的设备描述表才有地方绘图，画到指定的位图上   
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);  
	//先用背景色将位图清除干净，这里我用的是白色作为背景   
	//你也可以用自己应该用的颜色   
	MemDC.FillSolidRect(0,0,600,600,RGB(255,255,255));  
	//绘图   



	if(frist)
		SetTimer(1,level*100,NULL);
	CFfDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc); 
	if(frist){
		getShape();
		toShapes(type,status);
		frist=false;
	}

	toShapes_pre(type1);
	showPanel(&MemDC);
	showGround(&MemDC);
	showShape(&MemDC);
	showShape_pre(&MemDC);
	showMark(&MemDC);





	pDC->BitBlt(0,0,600,600,&MemDC,0,0,SRCCOPY);  
	//绘图完成后的清理   
	MemBitmap.DeleteObject();  
    MemDC.DeleteDC();  
	/*
	CBitmap bm;
	bm.LoadBitmap(IDB_BITMAP1);
	CDC mem;
	mem.CreateCompatibleDC(NULL);
	mem.SelectObject(&bm);
	pDC->BitBlt(10,320,100,450,&mem,0,0,SRCCOPY);
	*/
	
	// TODO: add draw code for native data here
}
/////////////////////////////////////////////////////////////////////////////
// CFfView diagnostics
#ifdef _DEBUG
void CFfView::AssertValid() const
{
	CView::AssertValid();
}
void CFfView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
CFfDoc* CFfView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFfDoc)));
	return (CFfDoc*)m_pDocument;
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
// CFfView message handlers
//自己定义的 
/*==================================================================*/
//显示图形
void CFfView::showShape(CDC *pDC){
	CBrush newBrush(RGB(227,166,245));
	CBrush *oldBrush=pDC->SelectObject(&newBrush);
	for(int x=0;x<=3;x++){
		for(int y=0;y<=3;y++){
			if(shapes[x][y]==1){
				pDC->Rectangle((left+y)*s,(top+x)*s,(left+y+1)*s,(top+x+1)*s);
			}
		}
	}
	//pDC->SelectObject(oldBrush);
}
//显示图形预览
void CFfView::showShape_pre(CDC *pDC){
	for(int x=0;x<=3;x++){
		for(int y=0;y<=3;y++){
			if(shapes_pre[x][y]==1){
				pDC->Rectangle((y)*s+(p+k)*20+100-20,(x)*s+30,(y+1)*s+(p+k)*20+100-20,(x+1)*s+30);
			}
		}
	}
}
//显示游戏背景
void CFfView::showPanel(CDC *pDC){
	CBrush newBrush(RGB(208,208,208));
	CBrush *oldBrush=pDC->SelectObject(&newBrush);
	//pDC->Rectangle(0,0,(20+p)*s,(19+p)*s);       //整体背景
	pDC->SelectObject(oldBrush); 
	CBrush newBrush1(RGB(230,228,228));
	CBrush *oldBrush1=pDC->SelectObject(&newBrush1);
	//pDC->Rectangle(p*s,0,(k+p)*s,(c)*s);    //游戏背景
	pDC->Rectangle((16+p)*s,1.25*s,(19+p)*s,4*s);              //显示预览图形
	pDC->SelectObject(oldBrush1);
	//pDC->Rectangle((14+p)*s+10,6.5*s,(17+p)*s+10,8*s);            //显示得分
}
//显示障碍物
void CFfView::showGround(CDC *pDC){	
	CRect rect; 
	GetClientRect(rect);///取得客户区域    
	//pDC->FillRect(rect,&m_brushBackground); ///用背景画刷填充区域 
	CBitmap bitmap; 
	bitmap.LoadBitmap(IDB_BITMAP1);  
	BITMAP bmp1; 
	bitmap.GetBitmap(&bmp1); 
	CDC dcCompatible; 
	dcCompatible.CreateCompatibleDC(pDC); 
	dcCompatible.SelectObject(&bitmap); 
	pDC->BitBlt(0,0,600,600,&dcCompatible,0,0,SRCCOPY);
	CBrush newBrush(RGB(200,63,204));
	CBrush *oldBrush=pDC->SelectObject(&newBrush);
	for(int x=0;x<=k+p-2;x++){
		for(int y=5;y<=c-1;y++){
			if(ground[x][y]==1){  
				//pDC->Rectangle((x+p)*s,(y+p-1)*s,(x+p+1)*s,(y+p)*s);
				pDC->Rectangle((x+1)*s,(y)*s,(x+2)*s,(y+1)*s);
			}
		}
	}

	for( x=0;x<=k+p-2;x++){
		for(int y=0;y<=5;y++){
			if(ground[x][y]==1){  
				pDC->Rectangle((x+1)*s,(y)*s,(x+2)*s,(y+1)*s);
				mciSendString("play danger.wav","",NULL,NULL);
			}
		}
	}


 


   pDC->SelectObject(oldBrush);
	CView::OnEraseBkgnd(pDC);
}
//判断是否允许下落
bool CFfView::isMovedown(){
	top++;
	for(int x=3;x>=0;x--){
		for(int y=3;y>=0;y--){
		if(shapes[x][y]==1){
			if(top+x>c-1||ground[left+y-1][top+x]==shapes[x][y]){		
			      top--;
			      accessShape();
		          isdeleteLine();
			      if(isGameover()){
			       KillTimer(1);
			       return false;
				  }
                  else{
				   getShape();
			        toShapes(type,status);
			       left=k/2+p;
		        	top=0;
			      return false;
				  }
			}
			}     
		}
	}
top--;
return true;
}
//判断是够允许左移动
bool CFfView::isMoveleft(){
	left--;
	for(int x=0;x<=3;x++){
		for(int y=0;y<=3;y++){
			if(shapes[x][y]==1){
				if(left+y<p||ground[left+y-1][top+x]==shapes[x][y]){
					left++;
					return false;
				}
			}
		}
	}
	left++;
	return true;
}
//判断是够允许右移动
bool CFfView::isMoveright(){
	left++;
	for(int x=3;0<=x;x--){
		for(int y=3;0<=y;y--){
			if(shapes[x][y]==1){
				if(k+p-1<left+y||ground[left+y-1][top+x]==shapes[x][y]){
					left--;
					return false;
				}
			}
		}
	}
	left--;
	return true;
}
//接收图形的函数
void CFfView::accessShape(){
	for(int x=0;x<=3;x++){
		for(int y=0;y<=3;y++){
			if(shapes[x][y]==1){
			ground[left+y-1][top+x]=1;
			mciSendString("play 变成障碍.wav","",NULL,NULL);
			}
		}
	}
}
//行满，删行的函数
void CFfView::isdeleteLine(){
	for(int y=0;y<=c-2+p;y++){
		bool full=true;
		for(int x=p-1;x<=k-2+p;x++){
			if(ground[x][y]==0){
				full=false;
			}
		}
		if(full){
			deleteLine(y);
			mciSendString("play 消行.wav","",NULL,NULL);
		}
	}
}
//真正删行的函数
void CFfView::deleteLine(int y){
	for(y;0<=y;y--){
		for(int x=0;x<=k+p-2;x++){
		ground[x][y]=ground[x][y-1];
		}
	}
	for(int x=0;x<=k+p-2;x++){
		ground[x][0]=0;
	}
	if(level==1)
	mark=mark+3;
	else if(level==3)
		mark=mark+2;
	else if(level==5)
		mark=mark+1;
}
//给图形动态赋值
void CFfView::toShapes(int type,int status){
	for(int x=0;x<=3;x++){
		for(int y=0;y<=3;y++){
			shapes[x][y]=shape[type][status][x][y];
		}
	}
}
//预览数赋值
void CFfView::toShapes_pre(int type1){
	for(int x=0;x<=3;x++){
		for(int y=0;y<=3;y++){
			shapes_pre[x][y]=shape[type1][0][x][y];
		}
	}
}
//产生一个新的图形
void CFfView::getShape(){
	srand((unsigned)time(NULL));
	if(!puase)
	SetTimer(1,level*100,NULL);
	if(frist_type){
		type1=rand()%7;
		frist_type=false;
	}
	type=type1;
	type1=rand()%7;
	status=0;
	Invalidate();
}
//改变图形状态的函数
void CFfView::changeStatus(){
	if(type == 0 && (status == 1 || status == 3) )
	{
		if(left == p - 1 || left == k+p-2 || left == k+p-3)
		{
			return;
		}
		
	}
	if(type == 2)
	{
		if(status == 0 && left > k+p-4)
			return;
		if(status == 2 && left < p-1)
			return;
	}
	if(type == 3)
	{
		if(status == 0 && left < p-1)
			return;
		if(status == 2 && left > k+p-4)
			return;
	}
	if(type == 4)
	{
		if(status == 3 && left < p)
			return;
		if(status == 1 && left > k+p-3)
			return;
	}
	if(type == 5)
	{
		if(status == 0 && left < p)
			return;
		if(status == 2 && left > k+p-3)
			return;
	}
	if(type == 6)
	{
		if((status == 0 || status == 2) && left > k+p-3)
			return;
	}
	
	if(type == 0 && (status == 0 || status == 2))
	{
		if(ground[left+1-1][top] == 1 || ground[left+1-1][top+2] ==1 || ground [left+1-1][top+3]== 1)
	
			return;
		
	}
	if(type == 0 && (status == 1 || status == 3))
	{
		if(ground[left-1-1][top+1] == 1 || ground[left+2-1][top+1] ==1 || ground[left+3-1][top+1]== 1)

			return;
	}
	if(type == 2)
	{
		if(status == 0 && (ground[left+1-1][top+1] == 1 || ground[left+1-1][top+2] == 1 || ground[left+3-1][top+1] == 1))
			return;
		if(status == 1 && (ground[left+2-1][top] == 1 || ground[left+2-1][top+2] == 1 || ground[left+3-1][top+2] == 1))
			return;
		if(status == 2 && (ground[left+1-1][top+1] == 1 || ground[left+3-1][top] == 1 || ground[left+3-1][top+1] == 1))
			return;
		if(status == 3 && (ground[left+1-1][top] == 1 || ground[left+2-1][top] == 1 || ground[left+2-1][top+2] == 1))
			return;
		
	}
	if(type == 3)
	{
		if(status == 0 && (ground[left+1-1][top] == 1 || ground[left+3-1][top+1] == 1 || ground[left+1-1][top+1] == 1))
			return;
		if(status == 1 && (ground[left+2-1][top] == 1 || ground[left+1-1][top+2] == 1 || ground[left+2-1][top+2] == 1))
			return;
		if(status == 2 && (ground[left+1-1][top+1] == 1 || ground[left+3-1][top+2] == 1 || ground[left+3-1][top+1] == 1))
			return;
		if(status == 3 && (ground[left+2-1][top+2] == 1 || ground[left+3-1][top+0] == 1 || ground[left+2-1][top+2] == 1))
			return;
		
	}
	if(type == 4)
	{
		if(status == 0 && ground[left+1-1][top+2]==1)
			return;
		if(status == 1 && ground[left+2-1][top+1]==1)
			return;
		if(status == 2 && ground[left+1-1][top] == 1)
			return;
		if(status == 3 && ground[left-1][top+1])
			return;
		

	}
	if(type ==5)
	{
		if(status == 0 && (ground[left-1][top+1] == 1 || ground[left+2-1][top] == 1))
			return;
		if(status == 1 && (ground[left-1][top] == 1 || ground[left+1-1][top+2] == 1))
			return;
		if(status == 2 && (ground[left+1-1][top] == 1 || ground[left+2-1][top] == 1))
			return;
		if(status == 3 && (ground[left+2-1][top+2] == 1 || ground[left+2-1][top+1] == 1))
			return;
		

	}

	if(type == 6)
	{
		if(status ==0 && (ground[left-1][top]==1 || ground[left+2-1][top+1] == 1))
			return;
		if(status ==2 && (ground[left-1][top]==1 || ground[left+2-1][top+1] == 1))
			return;
		if(status ==1 && (ground[left-1][top+1]==1 || ground[left-1][top+2] == 1))
			return;
		if(status ==3 && (ground[left-1][top+1]==1 || ground[left-1][top+2] == 1))
			return;

	}

	
	if(type == 0 && (status == 0 || status == 2) && top>c-4)
		return;
	if(type == 2 && status == 3 && top > c-3)
		return;
	if(type == 3 && status == 1 && top > c-3)
		return;
	if(type == 4 && status == 0 && top > c-3)
		return;
	if(type == 5 && (status == 1 || status == 3) && top > c-3)
		return;
	if(type == 6 && (status == 1 || status == 3) && top > c-3)
		return;

	
	


	
	
	

	status=(status+1)%4;

}
//显示得分
void CFfView::showMark(CDC *pDC){
	
char str[100];
	mark_1=mark*100;
	sprintf(str,"%d",mark_1);
	//pDC->TextOut((p+k)*20+150,240,str);
	char *a = "宋体";
	LPCTSTR lpb = (LPCTSTR)(LPCTSTR)a;
	CFont font;
	font.CreatePointFont(180,lpb);
	CFont* def_font = pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(0,0,0));	
	pDC->SetBkMode(TRANSPARENT);		
	pDC->ExtTextOut((p+k)*20+150,235,ETO_CLIPPED,NULL,str,NULL);

	if(level==1){
			pDC->TextOut((p+k)*20+130,180,"中级");
	}
	else if(level==3){
		pDC->TextOut((p+k)*20+130,180,"中级");
	}
	else if(level==5){
		pDC->TextOut((p+k)*20+130,180,"初级");
	}

}
//判断游戏是否介绍
bool CFfView::isGameover(){
	for(int x=0;x<=k+p-1;x++){
		if(ground[x][0]==1){
			mciSendString("play gameover.wav","",NULL,NULL);
			KillTimer(1);
			//MessageBox("游戏结束");
			INT_PTR nRes;         //用于保存DoModal函数的返回值
			CTipDlg tipDlg;    //构造对话框类CTipDlg的实例
			nRes = tipDlg.DoModal();   //弹出对话框
			if(IDOK == nRes) //判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续
			{
				left=k/2+p;
				mark=0;
				top=0;
				for(int y=0;y<=c+p-2;y++){
					for(int x=0;x<=k+p-2;x++){
						ground[x][y]=0;
					}
				}
				//frist=true;
				Invalidate();
	         KillTimer(1);
				return true;
			}
			left=k/2+p;
			mark=0;
			top=0;
			for(int y=0;y<=c+p-2;y++){
				for(int x=0;x<=k+p-2;x++){
					ground[x][y]=0;
				}
			}
			frist=true;
			Invalidate();
	         KillTimer(1);
			return true;
		}
	}	
	return false;
}
/*==================================================================*/
int CFfView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	
	return 0;
}
void CFfView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(isMovedown()){
	top++;
	}
	InvalidateRect(NULL,false);
	CView::OnTimer(nIDEvent);
}
void CFfView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar){
	case VK_LEFT:
		if(isMoveleft()&&gameing){
		left--;
		if(frist)
		SetTimer(1,100*level,NULL);
		InvalidateRect(NULL,false);
		}
		break;
	case VK_UP:
		if(gameing){
		changeStatus();
		toShapes(type,status);
		if(frist)
		SetTimer(1,100*level,NULL);
		InvalidateRect(NULL,false);
		mciSendString("play 改变.wav","",NULL,NULL);
		}
		break;
	case VK_RIGHT:
		if(isMoveright()&&gameing){
		left++;
		if(frist)
		SetTimer(1,100*level,NULL);
		InvalidateRect(NULL,false);
		}
		break;
	case VK_DOWN:
		if(isMovedown()&&gameing){
		top++;
	    SetTimer(1,100*level,NULL);
		}	
		InvalidateRect(NULL,false);
		break;
	case VK_RETURN:
		if(gameing){
			KillTimer(1);
			gameing=false;
		}
		else
		{   SetTimer(1,100*level,NULL);
			gameing=true;
			Invalidate();
		}
	//case VK_1:
	//	level=1;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CFfView::OnGameStart() 
{
     puase=false;
     mciSendString("play pause.wav","",NULL,NULL);
	  setTime();
	 InvalidateRect(NULL,false);
}

void CFfView::OnGameOver() 
{
	exit(0); 
}

void CFfView::OnGamePause() 
{
	KillTimer(1);
    mciSendString("play pause.wav","",NULL,NULL);
	puase=true;
	setTime();
	InvalidateRect(NULL,false);
}

void CFfView::OnUpdateGameStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnUpdateGameOver(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnUpdateGamePause(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnLevelNo1() 
{
	// TODO: Add your command handler code here
	level=5;
	SetTimer(1,level*100,NULL);
    CDC *pDC=GetDC();
	pDC->TextOut((p+k)*20+130,190,"初级");
	mciSendString("play levelup.wav","",NULL,NULL);

}

void CFfView::OnUpdateLevelNo1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnLevelNo2() 
{
	// TODO: Add your command handler code here
		level=3;
		SetTimer(1,level*100,NULL);
		CDC *pDC=GetDC();
	pDC->TextOut((p+k)*20+130,190,"中级");
		mciSendString("play levelup.wav","",NULL,NULL);
}

void CFfView::OnUpdateLevelNo2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnLevelHigh() 
{
	// TODO: Add your command handler code here
		level=1;
		SetTimer(1,level*100,NULL);
		CDC *pDC=GetDC();
	    pDC->TextOut((p+k)*20+130,190,"高级");
		mciSendString("play levelup.wav","",NULL,NULL);
}

void CFfView::OnUpdateLevelHigh(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
void CFfView::setTime(){
	if(!puase)
		SetTimer(1,level*100,NULL);
}

BOOL CFfView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default

    return 0;
	//return CView::OnEraseBkgnd(pDC);
}

void CFfView::OnFileMusic() 
{
	// TODO: Add your command handler code here	
	music++;
	if(music%2==0)
	PlaySound(NULL,NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
	if(music%2==1)	PlaySound("天天爱消除.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
	
}

void CFfView::OnUpdateFileMusic(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnGameRestart() 
{
	// TODO: Add your command handler code here
	left=k/2+p;
	mark=0;
	top=0;
	for(int y=0;y<=c+p-2;y++){
		for(int x=0;x<=k+p-2;x++){
			ground[x][y]=0;
				}
	}
	frist=true;
	 Invalidate();
	 KillTimer(1);


}

void CFfView::OnUpdateGameRestart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnAppAbout() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	INT_PTR nRes;         //用于保存DoModal函数的返回值
	Tip2 tipDIg;    //构造对话框类CTipDlg的实例
	nRes = tipDIg.DoModal();   //弹出对话框
	if( IDOK== nRes) //判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续
	{
	SetTimer(1,level*100,NULL);
	}

}

void CFfView::OnUpdateAppAbout(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CFfView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar==49){
		level=5;
		SetTimer(1,level*100,NULL);
		Invalidate();
	}
	if(nChar==50){
		level=3;
		SetTimer(1,level*100,NULL);
		Invalidate();
	}
	if(nChar==51){
		level=1;
		SetTimer(1,level*100,NULL);
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CFfView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	music++;
	if(music%2==0)
		PlaySound(NULL,NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
	if(music%2==1)	PlaySound("天天爱消除.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
	
	CView::OnLButtonDown(nFlags, point);
}

void CFfView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		exit(0);
	CView::OnRButtonDown(nFlags, point);
}
