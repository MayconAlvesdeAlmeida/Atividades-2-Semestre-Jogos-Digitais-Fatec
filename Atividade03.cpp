// MAYCON ALVES DE ALMEIDA
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

struct circulo
{
	int x;
	int y;
	int raio;
	float vx;
	float vy;
	int r;
	int g;
	int b;
};

struct copias
{
	int x ;
	int xa ;
	
	int y;
	
	int xc;
	int xca;
	
	int yc;
	
	int nx1;
	int ny1;
	
	int nx2;
	int ny2;
	
	int nx3;
	int ny3;
	
	int nx4;
	int ny4;
	
	int nx5;
	int ny5;
};

void d_galpao(int*a,int*b,int*c,int*d,int*x,int*y,int*xa)
{
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(10,a);
	fillpoly(10,c);
	setcolor(COLOR(102,102,102));
	setfillstyle(SOLID_FILL,COLOR(102,102,102));
	fillpoly(11,b);
	fillpoly(11,d);
	
	setfillstyle(SOLID_FILL,0);
	setcolor(0);
	bar(*x+25,(*y-40),(*x+75),(*y+1));
	bar((*x+35),(*y-80),(*x+65),(*y-50));
	bar((*xa+25),(*y-40),(*xa+75),(*y+1));
	bar((*xa+35),(*y-80),(*xa+65),(*y-50));
	
}
	

void limites(int*xt,int*yt)
{
	setcolor(5);
	line(10,10,*xt-10,10);
	line(*xt-10,10,*xt-10,*yt-10);
	line(*xt-10,*yt-10,10,*yt-10);
	line(10,*yt-10,10,10);
}

void cerca(int*xc,int*yc)
{
	setcolor(COLOR(211,188,95));
	for(int i = 0;i<=60;i+=12)
	{
		line((*xc+i),*yc,(*xc+i),(*yc-17));
		line((*xc+i),(*yc-17),(*xc+3+i),(*yc-20));
		line((*xc+3+i),(*yc-20),(*xc+6+i),(*yc-17));
		line((*xc+6+i),(*yc-17),(*xc+6+i),*yc);
		line((*xc+6+i),*yc,(*xc+i),*yc);
		
		setfillstyle(SOLID_FILL,COLOR(211,188,95));
		floodfill((*xc+3+i),(*yc-3),COLOR(211,188,95));
	}
	bar((*xc-6),(*yc-12),(*xc+72),(*yc-9));

}

void cerca_a(int*xca,int*yc)
{
	setcolor(COLOR(211,188,95));
	for(int i = 0;i<=60;i+=12)
	{
		
		line((*xca+i),*yc,(*xca+i),(*yc-17));
		line((*xca+i),(*yc-17),(*xca+3+i),(*yc-20));
		line((*xca+3+i),(*yc-20),(*xca+6+i),(*yc-17));
		line((*xca+6+i),(*yc-17),(*xca+6+i),*yc);
		line((*xca+6+i),*yc,(*xca+i),*yc);
		
		setfillstyle(SOLID_FILL,COLOR(211,188,95));
		floodfill((*xca+3+i),(*yc-3),COLOR(211,188,95));
	}
	bar((*xca-6),(*yc-12),(*xca+72),(*yc-9));
}

void nuvem (int*xn,int*yn)
{
	setcolor(15);
	setfillstyle(SOLID_FILL,15);
	fillellipse(*xn,*yn,15,15);
	fillellipse((*xn+85),(*yn-3),18,18);
	fillellipse((*xn+55),(*yn-15),25,25);
	fillellipse((*xn+24),(*yn-15),13,13);
	bar(*xn,(*yn-15),(*xn+85),(*yn+15));
}

void retornar(int*xa,float*r,int*a,int*b,int*c,int*d,int*ca,int*cb,int*cc,int*cd)
{
	if(*xa>*r)
	{
		for(int i = 0;i<20;i++)
		{
			a[i]=ca[i];
			c[i]=cc[i];
		}
		for(int i = 0;i<22;i++)
		{
			b[i]=cb[i];
			d[i]=cd[i];
		}
	}
}

void copia(int*a,int*b,int*c,int*d,int*ca,int*cb,int*cc,int*cd)
{
	for(int i = 0;i<20;i++)
	{
		ca[i]=a[i];
		cc[i]=c[i];
	}
	for(int i = 0;i<22;i++)
	{
		cb[i]=b[i];
		cd[i]=d[i];
	}
}
	
void resetar(int*a,int*b,int*c,int*d,int*ca,int*cb,int*cc,int*cd,int*xa,float*ix,float*r)
{
	if((*xa* *ix)>*r)
	{
		for(int i = 0;i<20;i++)
		{
			a[i]=ca[i];
			c[i]=cc[i];
		}
		for(int i = 0;i<22;i++)
		{
			b[i]=cb[i];
			d[i]=cd[i];
		}
	}
}


void grama(int*xt,int*yt,int*y)
{
	setfillstyle(SOLID_FILL,COLOR(55,200,55));
	setcolor(COLOR(55,200,55));
	bar(0,*y,*xt,*yt);
}

void redefinir(int*a,int*b,int*c,int*d,float*ix,float*iy,int*xa,int*x,int*xc,int*xca,int*nx1,int*nx2,int*nx3,int*nx4,int*nx5,
int*y,int*yc,int*ny1,int*ny2,int*ny3,int*ny4,int*ny5)
{
	*xa *= *ix;
	*x *= *ix;
	*xc *= *ix;
	*xca *= *ix;
	*nx1 *= *ix;
	*nx2 *= *ix;
	*nx3 *= *ix;
	*nx4 *= *ix;
	*nx5 *= *ix;
	*y *= *iy;
	*yc *= *iy;
	*ny1 *= *iy;
	*ny2 *= *iy;
	*ny3 *= *iy;
	*ny4 *= *iy;
	*ny5 *= *iy;
	
	for(int i = 0;i<20;i++)
	{
		if(i%2==0)
		{
			a[i]*= *ix;
			c[i]*= *ix;
		}
		else
		{
			a[i]*= *iy;
			c[i]*= *iy;
		}
	}
	
	for(int i = 0;i<22;i++)
	{
		if(i%2==0)
		{
			b[i]*= *ix;
			d[i]*= *ix;
		}
		else
		{
			b[i]*= *iy;
			d[i]*= *iy;
		}
	}
}

void mover_galpao(int*a,int*b,int*c,int*d)
{
	for(int i =0;i<20;i++)
	{
		if(i%2==0)
		{
			a[i] +=1;
			c[i] +=1;
		}
	}
	for(int i =0;i<22;i++)
	{
		if(i%2==0)
		{
			b[i] +=1;
			d[i] +=1;
		}
	}	

}

int main()
{
	long long unsigned g1,g2;
	int xt,yt,page;
	page = 0;
	float ix,iy ;
	int x = 200;
	int xa = -(300+200);
	int y = 440;
	
	int xc =128;
	int xca = -(372+200);
	int yc = 440;
	
	int nx1=100;
	int ny1=100;
	
	int nx2=300;
	int ny2=150;
	
	int nx3=-(400+200);
	int ny3=100;
	
	int nx4=-(200+200);
	int ny4=150;
	
	int nx5=-110;
	int ny5=200;
	
	int va = 1;
	
	int c_galpao[20];
	int c_telhado[22];
	int c_galpao_a[20];
	int c_telhado_a[22];
	
	int galpao[20]={x,y,x+100,y,x+100,y-40,x+110,y-40,x+85,y-85,x+50,y-100,x+15,y-85,x-10,y-40,x,y-40,x,y};
	int telhado[22]={x-20,y-40,x+11,y-100,x+50,y-118,x+89,y-100,x+120,y-40,x+110,y-40,x+85,y-85,x+50,y-100,x+15,y-85,x-10,y-40,x-20,y-40};
	int galpao_a[20]={xa,y,xa+100,y,xa+100,y-40,xa+110,y-40,xa+85,y-85,xa+50,y-100,xa+15,y-85,xa-10,y-40,xa,y-40,xa,y};
	int telhado_a[22]={xa-20,y-40,xa+11,y-100,xa+50,y-118,xa+89,y-100,xa+120,y-40,xa+110,y-40,xa+85,y-85,xa+50,y-100,xa+15,y-85,xa-10,y-40,xa-20,y-40};
	
	circulo d[5]={{50,50,20,2,10,200,128,0},{50,50,25,5,3,255,255,40},{50,50,10,3,1,0,128,0},
	{150,150,40,5,3,100,0,40},{50,50,35,4,2,5,108,240}};
	printf("Informe o valor da dimensao horizontal da tela: ");
	scanf("%i",&xt);
	printf("Informe o valor da dimensao vertical da tela: ");
	scanf("%i",&yt);
	
	ix = (float)xt/500;
	iy = (float)yt/500;
	
	redefinir(galpao,telhado,galpao_a,telhado_a,&ix,&iy,&xa,&x,&xc,&xca,&nx1,&nx2,&nx3,&nx4,&nx5,
&y,&yc,&ny1,&ny2,&ny3,&ny4,&ny5);
	copias v;
	v.x=x;
	v.xa= xa ;
	
	v.y = y;
	
	v.xc= xc;
	v.xca= xca;
	
	v.yc= yc;
	
	v.nx1= nx1;
	v.ny1= ny1;
	
	v.nx2= nx2;
	v.ny2= ny2;
	
	v.nx3= nx3;
	v.ny3= ny3;
	
	v.nx4= nx4;
	v.ny4= ny4;
	
	v.nx5= nx5;
	v.ny5= ny5;
	
	copia(galpao,telhado,galpao_a,telhado_a,c_galpao,c_telhado,c_galpao_a,c_telhado_a);
	printf("%i %i\n",galpao[0],c_galpao[0]);
	float r = x*ix;

	initwindow(xt,yt,"Atividade II",100,100);
	setbkcolor(COLOR(170,238,255));
	cleardevice();
	g1 = GetTickCount();
	while(!kbhit())
	{
		g2 = GetTickCount();
		if(g2-g1>33)
		{
			g1 = GetTickCount();
			g2 = g1;
			setactivepage(page);
			setvisualpage(1-page);
			cleardevice();
			grama(&xt,&yt,&y);
			limites(&xt,&yt);
			
			nuvem(&nx1,&ny1);
			nuvem(&nx2,&ny2);
			nuvem(&nx3,&ny3);
			nuvem(&nx4,&ny4);
			nuvem(&nx5,&ny5);
			
			cerca(&xc,&yc);
			cerca_a(&xca,&yc);
			
			xc+=(175* ix);
			xca+=(175* ix);
			cerca(&xc,&yc);
			cerca_a(&xca,&yc);
			
			d_galpao(galpao,telhado,galpao_a,telhado_a,&x,&y,&xa);
			mover_galpao(galpao,telhado,galpao_a,telhado_a);
		
			xc-=(175* ix);
			xca-=(175*ix);
			x++;
			xc++;
			
			xa++;
			xca++;
			
			nx1++;
			nx2++;
			nx3++;
			nx4++;
			nx5++;
	
			for(int i = 0;i<5;i++)
			{
				setfillstyle(SOLID_FILL,COLOR(d[i].r,d[i].g,d[i].b));
				setcolor(COLOR(d[i].r,d[i].g,d[i].b));
				fillellipse(d[i].x,d[i].y,d[i].raio,d[i].raio);
				
				d[i].x+=d[i].vx;
				d[i].y+=d[i].vy;
				if((d[i].x+d[i].raio)>=xt-10 || (d[i].x-d[i].raio)<=10)
				{
					d[i].vx*= -1;
				}
				if((d[i].y+d[i].raio)>=yt-10 || (d[i].y-d[i].raio)<=10)
				{
					d[i].vy*= -1;
				}			
			}
			if(xa>r)
			{
				x = v.x;
				xa = v.xa ;
				
				y = v.y;
				
				xc =v.xc;
				xca=v.xc;
				
				yc =v.yc;
				
				nx1 =v.nx1;
				ny1 =v.ny1;
				
				nx2 =v.nx2;
				ny2 =v.ny2;
				
				nx3 =v.nx3;
				ny3 =v.ny3;
				
				nx4 =v.nx4;
				ny4= v.ny4;
				
				nx5= v.nx5;
				ny5 =v.ny5;
			
			}
			retornar(&xa,&r,galpao,telhado,galpao_a,telhado_a,c_galpao,c_telhado,c_galpao_a,c_telhado_a);
			
			page = 1 - page;
		}

	}
	
	getch();
	closegraph();
	return 0;
}
