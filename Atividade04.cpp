//MAYCON ALVES DE ALMEIDA

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define P 0.666667
#define PI 3.141559

void desenho(int*a)
{
	setlinestyle(0,0,3);
	setcolor(5);
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,a);
	setlinestyle(0,0,1);
}

void limpar(int*key)
{
	if(kbhit())
	{
		*key = getch();
	}
	if(kbhit())
	{
		*key = getch();
	}
	if(kbhit())
	{
		*key = getch();
	}
}

void up (int*a,int*passo)
{
	for(int i = 1;i<8;i+=2)
	{
		a[i]-=*passo;
	}

}
void down (int*a,int*passo)
{
	for(int i = 1;i<8;i+=2)
	{
		a[i]+=*passo;
	}

}
void left (int*a,int*passo)
{
	for(int i = 0;i<7;i+=2)
	{
		a[i]-=*passo;
	}

}

void right (int*a,int*passo)
{
	for(int i = 0;i<7;i+=2)
	{
		a[i]+=*passo;
	}
}

void reaparecer(int*a,int*xt,int*yt)
{
	a[0] = 100+rand()%((*xt-99)-100);
	a[1] = rand()%(*yt-29);
	a[2] = a[0]+100;
	a[3] = a[1]+30;
	a[4] = a[0]-100;
	a[5] = a[1]+30;
	a[6] = a[0];
	a[7] = a[1];
}

void tecla_v(int*nx,int*ny,int*nc,int*xt,int*yt,int*n)
{
	for(int i = 0;i<*n;i++)
	{	
		nx[i] = rand()% (*xt+1);
		ny[i] = rand()% (*yt+1);
		nc[i] = rand()%16;
	}
}

void tecla_s(int*cx,int*cy,int*cc,int*nx,int*ny,int*nc,int*n)
{
	for(int i = 0;i<*n;i++)
	{
		cx[i] = nx[i];
		cy[i] = ny[i];
		cc[i] = nc[i];
	}	
}
void voltar(int*cx,int*cy,int*cc,int*nx,int*ny,int*nc,int*n)
{
	for(int i = 0;i<*n;i++)
	{
		nx[i] = cx[i];
		ny[i] = cy[i];
		nc[i] = cc[i];
	}
}

void s_temporal(int*nx,int*ny,int*nc,int*xt,int*yt,int*n)
{
	for(int i = 0;i<*n;i++)
	{	
		nx[i] = rand()% (*xt+1);
		ny[i] = rand()% (*yt+1);
		nc[i] = 11;
	}
}

void limites(int*a,int*xt,int*yt)
{
	if(a[2]>*xt)
	{
		a[0] = *xt-100;
		a[2] = a[0]+100;
		a[4] = a[0]-100;
		a[6] = a[0];
	}
	if(a[4]<0)
	{
		a[0] = 100;
		a[2] = a[0]+100;
		a[4] = a[0]-100;
		a[6] = a[0];
	}
	if(a[3]>*yt)
	{
		a[1] = *yt-30;
		a[3] = a[1]+30;
		a[5] = a[1]+30;
		a[7] = a[1];
		
	}
	if(a[1]<0)
	{
		a[1] = 0;
		a[3] = a[1]+30;
		a[5] = a[1]+30;
		a[7] = a[1];
	}
}

void angulos(int*starX,int*starY,int*n,float*ang,float*iraio,int*xt,int*yt)
{
	float ca,co;
	for(int i = 0;i<*n;i++)
	{
		if(starX[i]>=(*xt/2))
		{
			ca=starX[i]-(*xt/2);
		}
		else
		{
			ca= (*xt/2)- starX[i];
		}
		
		if(starY[i]>=(*yt/2))
		{
			co=starY[i]-(*yt/2);
		}
		else
		{
			co= (*yt/2)- starY[i];
		}

		ang[i]= atan(co/ca)*180/PI;
		iraio[i]=ca * cos(ang[i]*PI/180);
	}
	
}

void mover(float*raio,float*iraio,float*fraio,int*n,int*xt,bool*hyperspace,bool*brilho_estrelas)
{
	for(int i = 0;i<*n;i++)
	{
		if(iraio[i]+raio[i]<500)
		{
			raio[i]*=1.5;
		}
		else
		{
			fraio[i]*=1.5;
		}
		
		if(iraio[i]+raio[i]>*xt && iraio[i]+fraio[i]>*xt)
		{
			*hyperspace = false;
			*brilho_estrelas = true;
			for(int i = 0;i<*n;i++)
			{
				raio[i]=.5;
				fraio[i]=.5;
			}
		}
	}

}

void desenho_hyper(int*starX,int*starY,int*starC,float*ang,float*raio,int*n,float*fraio,float*iraio,int*xt,int*yt)
{
	float ix,iy,fix,fiy;
	for(int i =0;i<*n;i++)
	{
		ix = raio[i]*cos(ang[i]*PI/180);
		iy = raio[i]*sin(ang[i]*PI/180);
		fix = fraio[i]*cos(ang[i]*PI/180);
		fiy = fraio[i]*sin(ang[i]*PI/180);
		if(starX[i]<(*xt/2))
		{
			ix= -ix;
			fix = -fix;
		}
		if(starY[i]<(*yt/2))
		{
			iy=- iy;
			fiy = -fiy;
		}
		starC[i]++;
		if(starC[i] >=15)
		{
			starC[i] = 15;
		}
		if(iraio[i]+raio[i]<*xt)
		{
			setcolor(starC[i]);
			setlinestyle(0,0,3);
			line(starX[i],starY[i],starX[i]+ix,starY[i]+iy);
		}
		else
		{
			setcolor(starC[i]);
			setlinestyle(0,0,3);
			line(starX[i]+fix,starY[i]+fiy,starX[i]+ix,starY[i]+iy);
		}
	}

}

int main()
{
	long long unsigned g1,g2;
	srand(time(NULL));
	int contador = 0;//controla o brilho das estrelas
	bool salto = false; //aciona o salto temporal
	bool hyperspace = false; //aciona o hyper
	bool brilho_estrelas = true;
	int c_salto = 0; //controla o tempo durante o salto temporal
	int page =0;
	int key;
	int passo = 15;
	int x,y; // vertices centrais do triangulo
	x = 200,y = 100;
	
	int xt,yt; // medidas x e y da tela
	int n,n1,n2; // quantidade de estrelas
	printf("Digite o valor da dimensao horizontal: ");
	scanf("%i",&xt);
	yt = P* xt; // calcula 2/3 da tela em x
	n=.008*(xt*yt); // quantidade de estrelas
	n1 = n/5;	//quantidade de estrelas nivel 2
	n2 = n1/5; //quantidade de estrelas nivel 1
	x = xt/2,y = yt-50;
	int triangulo[8] = {x,y,x+100,y+30,x-100,y+30,x,y}; // triangulo
	
	float*raio,*iraio,*fraio,*ang;
	raio = NULL,ang=NULL,iraio=NULL,fraio=NULL;
	
	int*starX,*starY,*starC,*copiax,*copiay,*copiac;
	starX=NULL,starY=NULL,starC=NULL,copiax = NULL,copiay = NULL,copiac = NULL;
	
	starX = (int*)realloc(starX,sizeof(int)*n);
	starY = (int*)realloc(starY,sizeof(int)*n);
	starC = (int*)realloc(starC,sizeof(int)*n);
	copiax = (int*)realloc(copiax,sizeof(int)*n);
	copiay = (int*)realloc(copiay,sizeof(int)*n);
	copiac = (int*)realloc(copiac,sizeof(int)*n);
	
	raio = (float*)realloc(raio,sizeof(float)*n);
	ang = (float*)realloc(ang,sizeof(float)*n);
	iraio = (float*)realloc(iraio,sizeof(float)*n);
	fraio = (float*)realloc(fraio,sizeof(float)*n);
	
	initwindow(xt,yt,"Atividade 04",100,100);
	for(int i = 0;i<n;i++)
	{	
		starX[i] = rand()% (xt+1);
		starY[i] = rand()% (yt+1);
		starC[i] = rand()%16;
	}
	
	for (int i = 0;i<n;i++)
	{
		raio[i]=.5;
		fraio[i]=.5;
	}
	
	angulos(starX,starY,&n,ang,iraio,&xt,&yt);
	g1 = GetTickCount();
	while(1)
	{
		g2 = GetTickCount();
		if (g2-g1>33)
		{
			g1 = GetTickCount();
			g2 = g1;
			setactivepage(page);
			setvisualpage(1-page);
			
			cleardevice();
			
			if(salto) 
			{
				limpar(&key);
				c_salto++;
				if(c_salto>=62)
				{
					voltar(copiax,copiay,copiac,starX,starY,starC,&n);
					c_salto=0;
					salto = false;
				}
			}
			
			
			if(hyperspace)
			{
				for(int i = 0;i<n;i++) //desenha todas as estrelas com 1 pixel
				{	
					putpixel(starX[i],starY[i],starC[i]); 
				}
				limpar(&key);
				desenho_hyper(starX,starY,starC,ang,raio,&n,fraio,iraio,&xt,&yt);
				mover(raio,iraio,fraio,&n,&xt,&hyperspace,&brilho_estrelas);
				if(hyperspace == false)
				{
					voltar(copiax,copiay,copiac,starX,starY,starC,&n);
				}
			}
			else
			{
				for(int i = 0;i<n;i++) //desenha todas as estrelas com 1 pixel
				{	
					putpixel(starX[i],starY[i],starC[i]); 
				}
			
				for(int i = 0;i<n1;i++) // desenha as estrelas de nivel 2
				{
					setcolor(starC[i]);
					setfillstyle(SOLID_FILL,starC[i]);
					fillellipse(starX[i],starY[i],2,2);
				}
			}
			
			if(brilho_estrelas)
			{
				if (contador<10) // desenha as estrelas de nivel 1
				{
					for(int i = n1;i<n1+n2;i++)
					{
						setcolor(starC[i]);
						setfillstyle(SOLID_FILL,starC[i]);
						fillellipse(starX[i],starY[i],3,3);	
					}
				}
				else
				{
					for(int i = n1;i<n1+n2;i++)
					{
						setcolor(starC[i]);
						setfillstyle(SOLID_FILL,starC[i]);
						fillellipse(starX[i],starY[i],4,4);	
					}
				
				}
				contador++;
				if (contador>25)
				{
					contador = 0;
				}
			}
			
			desenho(triangulo); // desenha o triangulo
			
			if(GetKeyState(VK_UP)&0X80)// seta para cima 
			{
				up(triangulo,&passo);
			}
			if(GetKeyState(VK_DOWN)&0X80)// seta para baixo
			{
				down(triangulo,&passo);
			}
			if(GetKeyState(VK_RIGHT)&0X80)// seta para direita
			{
				right(triangulo,&passo);
			}
			
			if(GetKeyState(VK_LEFT)&0X80)// seta para esquerda
			{
				left(triangulo,&passo);
			}
			
			if (kbhit())
			{
				key = getch();
				
				if(key== 32)// tecla espaço
				{
					reaparecer(triangulo,&xt,&yt); // altera a posiçao do triangulo aleatoriamente 
					limpar(&key);
				}
				else if(key== 118 && salto == false && hyperspace == false )// tecla V 
				{
					tecla_v(starX,starY,starC,&xt,&yt,&n); // altera o espaço no fundo
					angulos(starX,starY,&n,ang,iraio,&xt,&yt);
					limpar(&key);
				}
				else if(key== 115 &&salto == false && hyperspace == false )// tecla S 
				{
					tecla_s(copiax,copiay,copiac,starX,starY,starC,&n); //copia a posiçao atual do espaço
					s_temporal(starX,starY,starC,&xt,&yt,&n); //altera o fundo por um determinado tempo
					salto = true;
					limpar(&key);
				}
				else if(key== 104 &&salto == false)// tecla H
				{
					hyperspace = true;
					brilho_estrelas = false;
					contador = 0;
					limpar(&key);
					tecla_s(copiax,copiay,copiac,starX,starY,starC,&n); 
				}
				
				else
				{
					limpar(&key);
				}
				
			}
			
			limites(triangulo,&xt,&yt);//controla os limites para o triangulo
			
			page = 1 - page;
		}

	}
	getch();
	closegraph();
	return 0;
}
