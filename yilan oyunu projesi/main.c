#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#include <stdlib.h>
struct bilgi
{
    int puan;
    char ismi[25];
    int hedef;

}oyuncu[50];



int harita[80][23]={0};
int girisEkrani[80][23]={0};
int kuyrukX[500];
int kuyrukY[500];



int yemx,yemy;
rastgeleyem()
{
    srand(time(NULL));
    yemx=24+rand()%75;
    yemy=6+rand()%18;

}

void main()
{
        FILE *fp;
        char text[25];
        fp=fopen("yilanoyunu.txt","a+");

        fprintf(fp,"oyuncu\t\tpuani\t\thedefi\n");
        fprintf(fp,"----------    -----------     ----------\n");



int a,b,oyuncuSayisi;


    system("color 2f");




    printf("oyuncu sayisini giriniz:");
    scanf("%d",&oyuncuSayisi);


for(a=0;a<oyuncuSayisi;a++){

    giris(0,0,79,15,3);
    girisYazdir();

    gotoxy(36,5);printf("###################//YILAN OYUNU\\###################");
    gotoxy(57,8);printf("Oyun yon tuslari ile calisir...");
    gotoxy(57,9);printf("Yilan her yemi yediginde puana 10 eklenir.");

    gotoxy(25,8);printf("oyuncu adi giriniz:");
    scanf("%s",&oyuncu[a].ismi);

    gotoxy(25,9);printf("hedefinizi giriniz:");
    scanf("%d",&oyuncu[a].hedef);
    gotoxy(25,10);printf("BASARILAR:)");
    sleep(2);
    system("cls");



    rastgeleyem();
    alan(0,0,79,22,1);
    ekranYazdir();
    int yilanx=55,yilany=15;
    int ekley=0,eklex=0;
    int kontrol=0;
    unsigned char yon;



     gotoxy(100,4);printf("HEDEF=>> %d",oyuncu[a].hedef);

	 do
    {
        if(kbhit())
        {
            yon=getch();
            if(yon==224)
            {
                yon=getch();
                switch(yon)
                {
                    case 72:ekley=-1; eklex=0;
                        break;
                    case 80:ekley=1; eklex=0;
                        break;
                    case 77: eklex=1; ekley=0;
                        break;
                    case 75: eklex=-1; ekley=0;
                }
            }
        }

        yilanx=yilanx+eklex;
        yilany=yilany+ekley;

        if(yilanx==99)
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",oyuncu[a].puan*10);
                getch();
                kontrol=1;
            }

        if(yilany==26)
           {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",oyuncu[a].puan*10);
                getch();
                kontrol=1;
            }
         if(yilanx==20)
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",oyuncu[a].puan*10);
                getch();
                kontrol=1;
            }
         if(yilany==4)
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",oyuncu[a].puan*10);
                getch();
                kontrol=1;
            }

        kuyrukX[0]=yilanx;
        kuyrukY[0]=yilany;
        int i;


        for(i=1;i<=oyuncu[a].puan;i++)
        {
            if((yilanx==kuyrukX[i] && yilany==kuyrukY[i]))
            {
                gotoxy(48,15);printf("<<OYUN BITTI>> puan:%d",oyuncu[a].puan*10);
                getch();
                kontrol=1;
            }


        }

        gotoxy(yilanx,yilany);printf("%c",254);

        for(i=0;i<=oyuncu[a].puan;i++)
        {
            gotoxy(kuyrukX[i],kuyrukY[i]);printf("%c",254);

        }


        if(yilanx==yemx && yilany==yemy)
        {
            rastgeleyem();
            oyuncu[a].puan++;
            gotoxy(100,5);printf("PUAN=>> %d",oyuncu[a].puan*10);
        }

        gotoxy(yemx,yemy);printf("%c",232);

         Sleep(50);

        gotoxy(yilanx,yilany);printf(" ");


        for(i=0;i<=oyuncu[a].puan;i++)
        {
            gotoxy(kuyrukX[i],kuyrukY[i]);printf(" ");

        }


        for(i=oyuncu[a].puan;i>0;i--)
        {
            kuyrukX[i]=kuyrukX[i-1];
            kuyrukY[i]=kuyrukY[i-1];
        }


    }
while (kontrol==0);



        fprintf(fp,"%s\t\t",oyuncu[a].ismi);
        fprintf(fp,"%d\t\t",oyuncu[a].puan*10);
        fprintf(fp,"%d\t\t\n",oyuncu[a].hedef);

        sleep(1);
        system("cls");
    }
fclose(fp);
}






void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

void alan(int dikey1, int yatay1, int dikey2, int yatay2,int tur)
{
    int i;
    for(i=dikey1; i<=dikey2;i++)
    {
        harita[i][yatay1] = tur;

        harita[i][yatay2] = tur;

    }
    for(i=yatay1; i<=yatay2;i++)
    {
        harita[dikey1][i] = tur;

        harita[dikey2][i] = tur;

    }
}

void ekranYazdir()
{
    int x,y;
    for(x=0;x<80;x++)
    {


        for(y=0;y<23;y++)
        {
        gotoxy(x+20,y+4);

            if(harita[x][y]==1)
            {
                printf("%c",219);
            }

            else if(harita[x][y]==2)
            {
                printf("%c",176);
            }
            else if(harita[x][y]==3)
                printf("%c",88);


        }
    }
}

void giris(int dik1, int yaty1, int dik2, int yaty2,int hat)
{
    int i;
    for(i=dik1; i<=dik2;i++)
    {
        girisEkrani[i][yaty1] = hat;

        girisEkrani[i][yaty2] = hat;

    }
    for(i=yaty1; i<=yaty2;i++)
    {
        girisEkrani[dik1][i] = hat;

        girisEkrani[dik2][i] = hat;

    }
}
void girisYazdir()
{
    int x,y;
    for(x=0;x<80;x++)
    {


        for(y=0;y<23;y++)
        {
        gotoxy(x+20,y+4);

            if(girisEkrani[x][y]==1)
            {
                printf("%c",219);
            }

            else if(girisEkrani[x][y]==2)
            {
                printf("%c",176);
            }
            else if(girisEkrani[x][y]==3)
                printf("%c",88);


        }
    }

}
