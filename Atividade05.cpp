//MAYCON ALVES DE ALMEIDA

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>

struct bolinhas
{
	float x;
	float y;
	int raio;
	int cor;
	float vx;
	float vy;
	int ligado;
};

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


void teclado()
{
	rectangle(260,350,305,375);//Q
	rectangle(305,350,355,375);	//W
	rectangle(355,350,400,375);	//E
	rectangle(400,350,450,375);	//R
	rectangle(450,350,495,375);//T
	rectangle(495,350,545,375);//Y
	rectangle(545,350,593,375);//U
	rectangle(593,350,640,375);//I
	rectangle(640,350,690,375);//O
	rectangle(690,350,740,375);//P
	
	rectangle(285,375,330,405);//A
	rectangle(330,375,380,405);//S
	rectangle(380,375,425,405);//D
	rectangle(425,375,474,405);//F
	rectangle(474,375,524,405);//G
	rectangle(524,375,568,405);//H
	rectangle(568,375,620,405);//J
	rectangle(620,375,668,405);//K
	rectangle(668,375,712,405);//L
	
	rectangle(330,405,380,438);//Z
	rectangle(380,405,423,438);//X
	rectangle(423,405,472,438);//C
	rectangle(472,405,517,438);//V
	rectangle(517,405,570,438);//B
	rectangle(570,405,613,438);//N
	rectangle(613,405,667,438);//M
	
	rectangle(780,370,870,415);//OK
	
}

void apagar(char*nome)// reseta a variavel temporária
{
	for(int i =0;i<4;i++)
	{
		nome[i] = '\0';
	}
}


int main ()
{
	// variaveis
	bolinhas q[15] = {{350,350,40,1,.2,.1,0},{350,350,30,2,.1,.3,0},{350,350,35,3,.4,.2,0},{350,350,17,4,.4,.5,0},{350,350,15,5,1,.4,0},
	{350,350,22,6,.2,.6,0},{350,350,10,7,.2,.2,0},{350,350,35,8,.15,.2,0},{350,350,18,9,.1,.4,0},{350,350,14,11,.7,.4,0},
	{350,350,27,12,.1,.25,0},{350,350,16,13,.1,.5,0},{350,350,35,14,.35,.6,0},{350,350,17,15,.8,.4,0},{350,350,12,0,.15,.4,0}};
	srand(time(NULL));
	for(int i = 0;i<15;i++)
	{
		q[i].x = 50+rand()%900;
		q[i].y = 100+rand()%541;
	}
	int page = 0;
	int xm;
	int ym;
	int key;
	bool jogando = true;
	bool desenhar = false;
	bool score = true;
	float distancia ;
	char pontos [20];
	float tempo =0;
	int contador_tempo = 0;
	int n = 0;
	float aux; 
	int c = 0;
	char nome[4];// guarda o nome lido
	char nomes[10][4];// guarda todos os nomes
	float tempos[10];// guarda todos os tempos
	
	// lendo arquivos de texto
	FILE*arquivo;
	arquivo =fopen("tempos.txt","r");
	
	while(fscanf(arquivo,"%f\n",&aux)!= EOF)
	{
		c++;
		tempos[c-1] = aux;		
	}
	fclose(arquivo);
	c=0;
	
	arquivo = fopen("nomes.txt","r");
	if(arquivo==NULL)
	{
		printf("nao abriu\n");
	}
	while(fscanf(arquivo,"%s\n",nome)!= EOF)
	{
		c++;
		strcpy(nomes[c-1],nome);
	}
	fclose(arquivo);
	
	// definindo janela grafica
	initwindow(1000,700,"ATIVIDADE 04",100,50);
	setcolor(15);
	settextstyle(0,HORIZ_DIR,4);
	outtextxy(220,30,"ATIVIDADE PROG II");
	outtextxy(20,200,"GRUPO 06");
	settextstyle(0,HORIZ_DIR,3);
	outtextxy(20,260,"FERNANDO CESAR DOS SANTOS CONCEIÇÃO");
	outtextxy(20,290,"JONATAS JORDÂO");
	outtextxy(20,320,"MAYCON ALVES DE ALMEIDA");
	delay(10000);	
	
	setbkcolor(COLOR(44,137,160));
	while(jogando)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		
		setcolor(COLOR(44,137,160));
		setfillstyle(SOLID_FILL,COLOR(44,137,160));
		bar(0,0,1000,700);
		setcolor(COLOR(204,255,170));
		setfillstyle(SOLID_FILL,COLOR(204,255,170));
		bar(10,50,990,690);
		
		if (n>=15)
		{
			jogando = false;
		}
		
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			xm = mousex();
			ym = mousey();
			for(int i = 0;i<15;i++)
			{
				distancia = sqrt((pow(xm-q[i].x,2)+pow(ym-q[i].y,2)));
				if(distancia<= q[i].raio)
				{
					q[i].ligado = 1;
					q[i].x = -50;
					q[i].y = -50;
					n++;
				}
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		setcolor(15);
		settextstyle(0,HORIZ_DIR,3);
		
		sprintf(pontos,"TEMPO %.3fs",tempo);
		outtextxy(650,18,pontos);
		setcolor(YELLOW);
		sprintf(pontos,"RECORDE %.3fs %s",tempos[0],nomes[0]);
		outtextxy(0,18,pontos);
		
		if (desenhar)
		{
			contador_tempo+=2;
			tempo = (float)contador_tempo/1000;
			for(int i = 0;i<15;i++)
			{
				if(q[i].ligado == 0)
				{
					setcolor(q[i].cor);
					setfillstyle(SOLID_FILL,q[i].cor);
					fillellipse(q[i].x,q[i].y,q[i].raio,q[i].raio);
					
					q[i].x+=q[i].vx;
					q[i].y+=q[i].vy;
					
					if(q[i].x >(990-q[i].raio) || q[i].x < 10+q[i].raio)
					{
						q[i].vx*=-1;
					}
					if(q[i].y >(690-q[i].raio) || q[i].y < 50+q[i].raio)
					{
						q[i].vy*=-1;
					}
				}
				
			}
			
			
		}
		
		if (kbhit())
		{	
			key = getch();
			if(key == 115)//tecla S
			{
				desenhar = true;
				limpar(&key);
			}
		}
		
		page = 1-page;
		delay(1);
		
	}
	c = 0;
	n=0;
	apagar(nome);
	while(score && n<=3)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		setcolor(COLOR(44,137,160));
		setfillstyle(SOLID_FILL,COLOR(44,137,160));
		bar(0,0,1000,700);
		setcolor(15);
		settextstyle(0,HORIZ_DIR,4);
		sprintf(pontos,"SEU TEMPO: %.3fs",tempo);
		outtextxy(205,18,pontos);
		if(tempo<tempos[9])
		{
			setcolor(15);
			settextstyle(0,HORIZ_DIR,4);
			outtextxy(150,150,"VOCÊ ENTROU NO TOP 10");
			outtextxy(450,530,nome);
			
			settextstyle(0,HORIZ_DIR,3);
			outtextxy(270,350,"Q W E R T Y U I O P");
			outtextxy(295,380,"A S D F G H J K L");
			outtextxy(340,410,"Z X C V B N M");
			outtextxy(800,380,"OK");
			teclado();
			
			
			if(ismouseclick(WM_LBUTTONDOWN))
			{
				xm = mousex();
				ym = mousey();
				if(n<3)
				{
				
					if(xm>260 && xm<305 && ym>350 && ym<375)
					{
						nome[n] ='Q';
						n++;
					}	
					else if(xm>=305 && xm<355 && ym>350 && ym<375)
					{
						nome[n] ='W';
						n++;
					}
					else if(xm>=355 && xm<400 && ym>350 && ym<375)
					{
						nome[n] ='E';
						n++;
					}
					else if(xm>=400 && xm<450 && ym>350 && ym<375)
					{
						nome[n] ='R';
						n++;
					}
					else if(xm>=450 && xm<495 && ym>350 && ym<375)
					{
						nome[n] ='T';
						n++;
					}
					else if(xm>=495 && xm<545 && ym>350 && ym<375)
					{
						nome[n] ='Y';
						n++;
					}
					else if(xm>=545 && xm<593 && ym>350 && ym<375)
					{
						nome[n] ='U';
						n++;
					}
					else if(xm>=593 && xm<640 && ym>350 && ym<375)
					{
						nome[n] ='I';
						n++;
					}
					else if(xm>=640 && xm<690 && ym>350 && ym<375)
					{
						nome[n] ='O';
						n++;
					}
					else if(xm>=690 && xm<740 && ym>350 && ym<375)
					{
						nome[n] ='P';
						n++;
					}
					if(xm>285 && xm<330 && ym>=375 && ym<405)
					{
						nome[n] ='A';
						n++;
					}	
					else if(xm>=330 && xm<380 && ym>=375 && ym<405)
					{
						nome[n] ='S';
						n++;
					}
					else if(xm>=380 && xm<425 && ym>=375 && ym<405)
					{
						nome[n] ='D';
						n++;
					}
					else if(xm>=425 && xm<474 && ym>=375 && ym<405)
					{
						nome[n] ='F';
						n++;
					}
					else if(xm>=474 && xm<524 && ym>=375 && ym<405)
					{
						nome[n] ='G';
						n++;
					}
					else if(xm>=524 && xm<568 && ym>=375 && ym<405)
					{
						nome[n] ='H';
						n++;
					}
					else if(xm>=568 && xm<620 && ym>=375 && ym<405)
					{
						nome[n] ='J';
						n++;
					}
					else if(xm>=620 && xm<668 && ym>=375 && ym<405)
					{
						nome[n] ='K';
						n++;
					}
					else if(xm>=668 && xm<712 && ym>=375 && ym<405)
					{
						nome[n] ='L';
						n++;
					}
					else if(xm>330 && xm<380 && ym>=405 && ym<438)
					{
						nome[n] ='Z';
						n++;
					}
					else if(xm>=380 && xm<423 && ym>=405 && ym<438)
					{
						nome[n] ='X';
						n++;
					}
					else if(xm>=423 && xm<472 && ym>=405 && ym<438)
					{
						nome[n] ='C';
						n++;
					}
					else if(xm>=472 && xm<517 && ym>=405 && ym<438)
					{
						nome[n] ='V';
						n++;
					}
					else if(xm>=517 && xm<570 && ym>=405 && ym<438)
					{
						nome[n] ='B';
						n++;
					}
					else if(xm>=570 && xm<613 && ym>=405 && ym<440)
					{
						nome[n] ='N';
						n++;
					}
					else if(xm>=613 && xm<667 && ym>=405 && ym<440)
					{
						nome[n] ='M';
						n++;
					}
					else if(xm>780 && xm<870 && ym>370 && ym<415 && n==3)
					{
						score = false;
					}
				}
				else
				{
					if(xm>780 && xm<870 && ym>370 && ym<415 && n==3)
					{
						score = false;
					}
				}
				
				
				clearmouseclick(WM_LBUTTONDOWN);
			}
		
		}
		else
		{
			c++;
			if(c>90)
			{
				score = false;
			}
		}
		page = 1-page;
		delay(34);
	}
	
	if(tempo<tempos[9])
	{
		tempos[9] = tempo;
		strcpy(nomes[9],nome);
	}
	
	// coloca os nomes e os tempos em ordem crescente
	for(int i =0;i<10;i++)
	{
		for(int j = 0;j<9;j++)
		{
			if(tempos[j]>tempos[j+1])
			{
				aux = tempos[j];
				tempos[j]=tempos[j+1];
				tempos[j+1] = aux;
				strcpy(nome,nomes[j]);
				strcpy(nomes[j],nomes[j+1]);
				strcpy(nomes[j+1],nome);
			}
		}
	}
	
	// escrevendo arquivos
	arquivo = fopen("tempos.txt","w");
	for(int i = 0;i<10;i++)
	{
		fprintf(arquivo,"%.3f\n",tempos[i]);
	}
	fclose(arquivo);
	
	arquivo = fopen("nomes.txt","w");
	for(int i = 0;i<10;i++)
	{
		fprintf(arquivo,"%s\n",nomes[i]);
	}
	fclose(arquivo);
	
	c = 0;
	n=0;
	while(!kbhit())
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		setcolor(COLOR(44,137,160));
		setfillstyle(SOLID_FILL,COLOR(44,137,160));
		bar(0,0,1000,700);
		setcolor(15);
		settextstyle(0,HORIZ_DIR,4);
		outtextxy(400,30,"TOP 10");	
		
		while(n<10)// mostra o score
		{
			outtextxy(250,100+c,nomes[n]);
			sprintf(pontos,"%.3fs",tempos[n]);
			outtextxy(550,100+c,pontos);
			n++;
			c+=50;
		}
		c = 0;
		n=0;
		
		page = 1-page;
		delay(34);
	}

	closegraph();
	return 0;
}
