//MAYCON ALVES DE ALMEIDA

#include<stdio.h>
#include<graphics.h>

void desenha_circulos(short*x,short*y,short*raio,short*incr_x,short*incr_y)
{
	for(short i=0;i<=*incr_y;i+=*incr_y)
	{
		for(short j = 0;j<=(2* *incr_x);j+=*incr_x)
		{
			fillellipse(*x+j,*y+i,*raio,*raio);		
		}
	}
}

void desenha_resto(short*raio)
{
	for(short i=0;i<=200;i+=100)
	{
		fillellipse(80+i,380,*raio,*raio);		
	}
	for(short i=0;i<=200;i+=100)
	{
		fillellipse(480+i,380,*raio,*raio);		
	}
}

void ret1()
{	
	//barras horizontais
	bar(80,71,680,89);
	bar(80,671,680,689);
	bar(180,171,580,189);
	bar(180,571,580,589);
	bar(280,271,480,289);
	bar(280,471,480,489);
	bar(80,371,280,389);
	bar(480,371,680,389);
	
	//barras verticais
	bar(71,80,89,680);
	bar(671,80,689,680);
	bar(171,180,189,580);
	bar(571,180,589,580);
	bar(271,280,289,480);
	bar(471,280,489,480);
	bar(371,80,389,280);
	bar(371,480,389,680);
}

void ret2()
{
	//barras horizontais
	bar(80,75,680,85);
	bar(80,675,680,685);
	bar(180,175,580,185);
	bar(180,575,580,585);
	bar(280,275,480,285);
	bar(280,475,480,485);
	bar(80,375,280,385);
	bar(480,375,680,385);
	
	//barras verticais
	bar(75,80,85,680);
	bar(675,80,685,680);
	bar(175,180,185,580);
	bar(575,180,585,580);
	bar(275,280,285,480);
	bar(475,280,485,480);
	bar(375,80,385,280);
	bar(375,480,385,680);
}

void incrementar(short*x,short*y,short*incr_x,short*incr_y)
{
	*x+=100;
	*y+=100;
	*incr_x-=100;
	*incr_y-=200;
}

void resetar(short*x,short*y,short*incr_x,short*incr_y)
{
	*x=80;
	*y=80;
	*incr_x = 300;
	*incr_y = 600;
}

void pecas()
{
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	fillellipse(80,80,25,25);
	fillellipse(180,180,25,25);
	fillellipse(280,280,25,25);
	fillellipse(580,180,25,25);
	fillellipse(380,80,25,25);
	fillellipse(680,80,25,25);
	fillellipse(380,180,25,25);
	
	setcolor(15);
	setfillstyle(SOLID_FILL,15);
	fillellipse(80,680,25,25);
	fillellipse(380,680,25,25);
	fillellipse(680,680,25,25);
	fillellipse(180,580,25,25);
	fillellipse(580,580,25,25);
}

int main()
{
	short x,y,raio,incr_x,incr_y;
	x=80;
	y=80;
	raio = 39;
	incr_x= 300;
	incr_y = 600;
	
	initwindow(1000,760,"Atividade PROG II",100,10);
	setbkcolor(WHITE);
	cleardevice();
	
	setcolor(COLOR(128,0,128));
	setfillstyle(SOLID_FILL,COLOR(128,0,128));
	bar(0,0,760,760);
	
	setcolor(COLOR(55,171,200));
	setfillstyle(SOLID_FILL,COLOR(55,171,200));
	bar(20,20,740,740);
	
	setcolor(0);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(780,0,"INTEGRANTES:");
	outtextxy(780,20,"FABIO");
	outtextxy(780,40,"JONATAS");
	outtextxy(780,60,"MAYCON");
	
	setcolor(RGB(128,0,128));
	setfillstyle(SOLID_FILL,COLOR(128,0,128));
	
	ret1();
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	incrementar(&x,&y,&incr_x,&incr_y);
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	incrementar(&x,&y,&incr_x,&incr_y);
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	desenha_resto(&raio);
	
	resetar(&x,&y,&incr_x,&incr_y);
	raio=35;
	
	setcolor(RGB(255,255,0));
	setfillstyle(SOLID_FILL,COLOR(255,255,0));
	
	ret2();
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	incrementar(&x,&y,&incr_x,&incr_y);
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	incrementar(&x,&y,&incr_x,&incr_y);
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	desenha_resto(&raio);
	
	resetar(&x,&y,&incr_x,&incr_y);
	raio=25;
	
	setcolor(RGB(128,0,128));
	setfillstyle(SOLID_FILL,COLOR(128,0,128));
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	incrementar(&x,&y,&incr_x,&incr_y);
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	incrementar(&x,&y,&incr_x,&incr_y);
	
	desenha_circulos(&x,&y,&raio,&incr_x,&incr_y);
	desenha_resto(&raio);
	
	pecas();
	
	getch();
	closegraph();
	return 0;
}
