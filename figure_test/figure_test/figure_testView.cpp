
// figure_testView.cpp : implementation of the Cfigure_testView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "figure_test.h"
#endif

#include "figure_testDoc.h"
#include "figure_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <afx.h>



// Cfigure_testView

IMPLEMENT_DYNCREATE(Cfigure_testView, CView)

BEGIN_MESSAGE_MAP(Cfigure_testView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cfigure_testView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TEST, &Cfigure_testView::OnTest)
	ON_COMMAND(ID_TEST2, &Cfigure_testView::OnTest2)
	ON_COMMAND(ID_TEST3, &Cfigure_testView::OnTest3)
END_MESSAGE_MAP()

// Cfigure_testView construction/destruction

Cfigure_testView::Cfigure_testView()
{
	// TODO: add construction code here

}

Cfigure_testView::~Cfigure_testView()
{
}

BOOL Cfigure_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cfigure_testView drawing

void Cfigure_testView::OnDraw(CDC* /*pDC*/)
{
	Cfigure_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cfigure_testView printing


void Cfigure_testView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cfigure_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cfigure_testView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cfigure_testView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cfigure_testView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cfigure_testView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cfigure_testView diagnostics

#ifdef _DEBUG
void Cfigure_testView::AssertValid() const
{
	CView::AssertValid();
}

void Cfigure_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cfigure_testDoc* Cfigure_testView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cfigure_testDoc)));
	return (Cfigure_testDoc*)m_pDocument;
}
#endif //_DEBUG


// Cfigure_testView message handlers



void Cfigure_testView::OnTest()
{
	// TODO: Add your command handler code here
	CClientDC aDC(this);

	CStdioFile data;
	CStringArray line;
	int len;
	CString strRead,data_str;
	data.Open(_T("test_data.txt"),CFile::modeRead);
	CString site[1076],pos_x[1076],pos_y[1076],rs_1[1076],rs_2[1076],cmp_rs[1076];
	CString t_site,t_x,t_y,t_rs1,t_rs2,t_cp;
	int line_counter=0;
	while(data.ReadString(strRead))
	{
		AfxExtractSubString(site[line_counter],strRead,1,'\t');
		AfxExtractSubString(pos_x[line_counter],strRead,2,'\t');
		AfxExtractSubString(pos_y[line_counter],strRead,3,'\t');
		AfxExtractSubString(rs_1[line_counter],strRead,4,'\t');
		AfxExtractSubString(rs_2[line_counter],strRead,5,'\t');
		AfxExtractSubString(cmp_rs[line_counter],strRead,6,'\t');

		t_site+=site[line_counter];
		t_site+=",";
		t_x+=pos_x[line_counter];
		t_x+=",";
		t_y+=pos_y[line_counter];
		t_y+=",";
		t_rs1+=rs_1[line_counter];
		t_rs1+=",";
		t_rs2+=rs_2[line_counter];
		t_rs2+=",";
		t_cp+=cmp_rs[line_counter];
		t_cp+=",";

		line_counter++;

	}
	
	for (int i=0;i<1076;i++)
	{
		int px=(_ttoi(pos_x[i])+17)*40;
		int py=(_ttoi(pos_y[i])+5)*20;

		if(_ttoi(site[i])==0)
		{//²Lºñ
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(193,255,193));}
			}
		}
		else if(_ttoi(site[i])==1)
		{//²L¶À
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,246,143));}
			}
		}
		else if(_ttoi(site[i])==2)
		{//«G¶À
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,255,0));}
			}
		}
		else if(_ttoi(site[i])==3)
		{//¾í¶À1
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,215,0));}
			}
		}
		else if(_ttoi(site[i])==4)
		{//¾í¶À2
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,185,15));}
			}
		}
		else if(_ttoi(site[i])==5)
		{//¾ï¦â
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,140,0));}
			}
		}
		else if(_ttoi(site[i])==6)
		{//´Ä¦â
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(205,102,29));}
			}
		}
		else if(_ttoi(site[i])==7)
		{//©@°Ø
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(139,35,35));}
			}
		}
		aDC.SetBkMode(TRANSPARENT);
		aDC.DrawText(rs_1[i],CRect(px+5,py,px+40,py+20),0);
	}
	//¾î½u
	for (int i=0;i<38;i++)
	{
		aDC.MoveTo(80,80+20*i);
		aDC.LineTo(1640,80+20*i);
		if(i==0 || i==37){continue;}
		CString y;
		y.Format(_T("%d"),i-1);
		aDC.DrawText(y,CRect(80+5,80+20*i,120,80+20*i+20),0);
	}
	//ª½½u
	for (int i=0;i<40;i++)
	{
		aDC.MoveTo(80+40*i,80);
		aDC.LineTo(80+40*i,820);
		if(i==0 || i==39){continue;}
		CString x;
		x.Format(_T("%d"),i-15);
		aDC.DrawText(x,CRect(80+40*i+5,80,120+40*i,100),0);
	}

	for (int j=0;j<100;j++)
	{
		for(int k=0;k<20;k++)
		{
			aDC.SetPixel(1680+j,100+k,RGB(193,255,193));
			aDC.SetPixel(1680+j,140+k,RGB(255,246,143));
			aDC.SetPixel(1680+j,180+k,RGB(255,255,0));
			aDC.SetPixel(1680+j,220+k,RGB(255,215,0));
			aDC.SetPixel(1680+j,260+k,RGB(255,185,15));
			aDC.SetPixel(1680+j,300+k,RGB(255,140,0));
			aDC.SetPixel(1680+j,340+k,RGB(205,102,29));
			aDC.SetPixel(1680+j,380+k,RGB(139,35,35));
		}
	}
	aDC.SetBkMode(TRANSPARENT);
	aDC.DrawText(_T("Site0"),CRect(1680,100,1900,120),0);
	aDC.DrawText(_T("Site1"),CRect(1680,140,1900,160),0);
	aDC.DrawText(_T("Site2"),CRect(1680,180,1900,200),0);
	aDC.DrawText(_T("Site3"),CRect(1680,220,1900,240),0);
	aDC.DrawText(_T("Site4"),CRect(1680,260,1900,280),0);
	aDC.DrawText(_T("Site5"),CRect(1680,300,1900,320),0);
	aDC.DrawText(_T("Site6"),CRect(1680,340,1900,360),0);
	aDC.DrawText(_T("Site7"),CRect(1680,380,1900,400),0);

}


void Cfigure_testView::OnTest2()
{
	// TODO: Add your command handler code here
	CClientDC aDC(this);
	CStdioFile data;
	CStringArray line;
	int len;
	CString strRead,data_str;
	data.Open(_T("test_data.txt"),CFile::modeRead);
	CString site[1076],pos_x[1076],pos_y[1076],rs_1[1076],rs_2[1076],cmp_rs[1076];
	CString t_site,t_x,t_y,t_rs1,t_rs2,t_cp;
	int line_counter=0;
	while(data.ReadString(strRead))
	{
		AfxExtractSubString(site[line_counter],strRead,1,'\t');
		AfxExtractSubString(pos_x[line_counter],strRead,2,'\t');
		AfxExtractSubString(pos_y[line_counter],strRead,3,'\t');
		AfxExtractSubString(rs_1[line_counter],strRead,4,'\t');
		AfxExtractSubString(rs_2[line_counter],strRead,5,'\t');
		AfxExtractSubString(cmp_rs[line_counter],strRead,6,'\t');

		t_site+=site[line_counter];
		t_site+=",";
		t_x+=pos_x[line_counter];
		t_x+=",";
		t_y+=pos_y[line_counter];
		t_y+=",";
		t_rs1+=rs_1[line_counter];
		t_rs1+=",";
		t_rs2+=rs_2[line_counter];
		t_rs2+=",";
		t_cp+=cmp_rs[line_counter];
		t_cp+=",";

		line_counter++;

	}
	
	for (int i=0;i<1076;i++)
	{
		int px=(_ttoi(pos_x[i])+17)*40;
		int py=(_ttoi(pos_y[i])+5)*20;

		if(_ttoi(site[i])==0)
		{//²Lºñ
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(193,255,193));}
			}
		}
		else if(_ttoi(site[i])==1)
		{//²L¶À
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,246,143));}
			}
		}
		else if(_ttoi(site[i])==2)
		{//«G¶À
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,255,0));}
			}
		}
		else if(_ttoi(site[i])==3)
		{//¾í¶À1
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,215,0));}
			}
		}
		else if(_ttoi(site[i])==4)
		{//¾í¶À2
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,185,15));}
			}
		}
		else if(_ttoi(site[i])==5)
		{//¾ï¦â
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(255,140,0));}
			}
		}
		else if(_ttoi(site[i])==6)
		{//´Ä¦â
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(205,102,29));}
			}
		}
		else if(_ttoi(site[i])==7)
		{//©@°Ø
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(139,35,35));}
			}
		}
		aDC.SetBkMode(TRANSPARENT);
		aDC.DrawText(rs_2[i],CRect(px+5,py,px+40,py+20),0);
	}
	//¾î½u
	for (int i=0;i<38;i++)
	{
		aDC.MoveTo(80,80+20*i);
		aDC.LineTo(1640,80+20*i);
		if(i==0 || i==37){continue;}
		CString y;
		y.Format(_T("%d"),i-1);
		aDC.DrawText(y,CRect(80+5,80+20*i,120,80+20*i+20),0);
	}
	//ª½½u
	for (int i=0;i<40;i++)
	{
		aDC.MoveTo(80+40*i,80);
		aDC.LineTo(80+40*i,820);
		if(i==0 || i==39){continue;}
		CString x;
		x.Format(_T("%d"),i-15);
		aDC.DrawText(x,CRect(80+40*i+5,80,120+40*i,100),0);
	}

	for (int j=0;j<100;j++)
	{
		for(int k=0;k<20;k++)
		{
			aDC.SetPixel(1680+j,100+k,RGB(193,255,193));
			aDC.SetPixel(1680+j,140+k,RGB(255,246,143));
			aDC.SetPixel(1680+j,180+k,RGB(255,255,0));
			aDC.SetPixel(1680+j,220+k,RGB(255,215,0));
			aDC.SetPixel(1680+j,260+k,RGB(255,185,15));
			aDC.SetPixel(1680+j,300+k,RGB(255,140,0));
			aDC.SetPixel(1680+j,340+k,RGB(205,102,29));
			aDC.SetPixel(1680+j,380+k,RGB(139,35,35));
		}
	}
	aDC.SetBkMode(TRANSPARENT);
	aDC.DrawText(_T("Site0"),CRect(1680,100,1900,120),0);
	aDC.DrawText(_T("Site1"),CRect(1680,140,1900,160),0);
	aDC.DrawText(_T("Site2"),CRect(1680,180,1900,200),0);
	aDC.DrawText(_T("Site3"),CRect(1680,220,1900,240),0);
	aDC.DrawText(_T("Site4"),CRect(1680,260,1900,280),0);
	aDC.DrawText(_T("Site5"),CRect(1680,300,1900,320),0);
	aDC.DrawText(_T("Site6"),CRect(1680,340,1900,360),0);
	aDC.DrawText(_T("Site7"),CRect(1680,380,1900,400),0);
}


void Cfigure_testView::OnTest3()
{
	// TODO: Add your command handler code here
	CClientDC aDC(this);

	CStdioFile data;
	CStringArray line;
	int len;
	CString strRead,data_str;
	data.Open(_T("test_data.txt"),CFile::modeRead);
	CString site[1076],pos_x[1076],pos_y[1076],rs_1[1076],rs_2[1076],cmp_rs[1076];
	CString t_site,t_x,t_y,t_rs1,t_rs2,t_cp;
	CString cp_hw_result[1076];
	CString a,b;
	int rs_counter[4]={0,0,0,0};
	CString out_counter[5];
	int line_counter=0;
	while(data.ReadString(strRead))
	{
		AfxExtractSubString(site[line_counter],strRead,1,'\t');
		AfxExtractSubString(pos_x[line_counter],strRead,2,'\t');
		AfxExtractSubString(pos_y[line_counter],strRead,3,'\t');
		AfxExtractSubString(rs_1[line_counter],strRead,4,'\t');
		AfxExtractSubString(rs_2[line_counter],strRead,5,'\t');
		AfxExtractSubString(cmp_rs[line_counter],strRead,6,'\t');

		t_site+=site[line_counter];
		t_site+=",";
		t_x+=pos_x[line_counter];
		t_x+=",";
		t_y+=pos_y[line_counter];
		t_y+=",";
		t_rs1+=rs_1[line_counter];
		t_rs1+=",";
		t_rs2+=rs_2[line_counter];
		t_rs2+=",";
		t_cp+=cmp_rs[line_counter];
		t_cp+=",";

		AfxExtractSubString(a,rs_1[line_counter],0,'/');//¨úHW
		AfxExtractSubString(b,rs_2[line_counter],0,'/');
		cp_hw_result[line_counter]=a+"/"+b;

		line_counter++;

	}
	
	for (int i=0;i<1076;i++)
	{
		int px=(_ttoi(pos_x[i])+17)*40;
		int py=(_ttoi(pos_y[i])+5)*20;

		
		if (cmp_rs[i]=="Pass2Pass")
		{
			rs_counter[0]++;
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{aDC.SetPixel(px+j,py+k,RGB(179,238,58));}
			}
		}
		else if (cmp_rs[i]=="Pass2Fail")
		{
			rs_counter[1]++;
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{
					aDC.SetPixel(px+j,py+k,RGB(0,191,255));
				}
			}
		}
		else if (cmp_rs[i]=="Fail2Pass")
		{
			rs_counter[2]++;
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{
					aDC.SetPixel(px+j,py+k,RGB(255,255,0));
				}
			}
		}
		else if (cmp_rs[i]=="Fail2Fail")
		{
			rs_counter[3]++;
			for (int j=0;j<40;j++)
			{
				for(int k=0;k<20;k++)
				{
					aDC.SetPixel(px+j,py+k,RGB(255,48,48));
				}
			}
		}
		
		aDC.SetBkMode(TRANSPARENT);
		aDC.DrawText(cp_hw_result[i],CRect(px+5,py,px+40,py+20),0);
	}
	//result counterÂàCString
	int total=0;
	for(int i=0;i<4;i++)
	{
		total+=rs_counter[i];
		out_counter[i].Format(_T("%d"),rs_counter[i]);
	}
	out_counter[4].Format(_T("%d"),total);

	//¾î½u
	for (int i=0;i<38;i++)
	{
		aDC.MoveTo(80,80+20*i);
		aDC.LineTo(1640,80+20*i);
		if(i==0 || i==37){continue;}
		CString y;
		y.Format(_T("%d"),i-1);
		aDC.DrawText(y,CRect(80+5,80+20*i,120,80+20*i+20),0);
	}
	//ª½½u
	for (int i=0;i<40;i++)
	{
		aDC.MoveTo(80+40*i,80);
		aDC.LineTo(80+40*i,820);
		if(i==0 || i==39){continue;}
		CString x;
		x.Format(_T("%d"),i-15);
		aDC.DrawText(x,CRect(80+40*i+5,80,120+40*i,100),0);
	}


	for (int j=0;j<140;j++)
	{
		for(int k=0;k<20;k++)
		{
			aDC.SetPixel(1680+j,100+k,RGB(179,238,58));
			aDC.SetPixel(1680+j,140+k,RGB(0,191,255));
			aDC.SetPixel(1680+j,180+k,RGB(255,255,0));
			aDC.SetPixel(1680+j,220+k,RGB(255,48,48));
			aDC.SetPixel(1680+j,260+k,RGB(34,139,34));
		}
	}
	aDC.SetBkMode(TRANSPARENT);
	aDC.DrawText(_T("Pass2Pass   ")+out_counter[0],CRect(1680,100,1900,120),0);
	aDC.DrawText(_T("Pass2Fail     ")+out_counter[1],CRect(1680,140,1900,160),0);
	aDC.DrawText(_T("Fail2Pass     ")+out_counter[2],CRect(1680,180,1900,200),0);
	aDC.DrawText(_T("Fail2Fail      ")+out_counter[3],CRect(1680,220,1900,240),0);
	aDC.DrawText(_T("Total            ")+out_counter[4],CRect(1680,260,1900,280),0);


	
}
