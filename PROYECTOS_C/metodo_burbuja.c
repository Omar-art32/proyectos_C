#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define max 24



void burbuja(int arr[], int n);
void imprime(int d, int h,int n);
void gotoxy(int x,int y);
void margen(int c, int f);

main()
{
	int arr[max]={0};
	int n,i;
	int c=9,f=2;
	int d=12, h=15;
	// Semilla para números aleatorios
    srand(time(NULL));
	
	margen(c,f);
	gotoxy(48,5);
	printf("METODO DE LA BURBUJA");
	
	gotoxy(10,7);
	printf("Ingrese cuantos valores se ordenaran: ");
	gotoxy(48,7);
	scanf("%d",&n);
	
	
	
	if(n<=max)
	{
		imprime(d,h,n);
		
		for(i=0;i<n;i++)
		{
			arr[i]=rand()%90+10;
			imprime_datos(arr,n);
		}
		
		burbuja(arr,n);
		
	}
	else
	{
		printf("Ingrese un valor mas pequeno.");
	}
	getch();
	return 0;
}

void burbuja(int arr[], int n) {
    int i, j, temp,p=0;

    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n-i-1; j++)//Aqui para hcer la representacion visual modifique n-1, originalmente era n-i-1 para que ya no contara los datos ya ordenados
		{
            gotoxy(13+(j*4),22);
            printf("*");
            gotoxy(17+(j*4),22);
            printf("*");

            if (arr[j] > arr[j + 1]) 
			{
				p++;
				
                temp = arr[j];//codigo
                
                //para ariba
                gotoxy(13+(j*4),16); printf("  ");Sleep(100);
                
                gotoxy(13+(j*4),15); printf("%d",arr[j]); Sleep(100);
                
                gotoxy(17+(j*4),16); printf("  "); Sleep(100);//

                gotoxy(17+(j*4),17); printf("%d",arr[j+1]); Sleep(100);//
                
                gotoxy(13+(j*4),15); printf("  "); Sleep(100);
                
                gotoxy(17+(j*4),17); printf("  "); Sleep(100);//

                gotoxy(17+(j*4),17); printf("%c%c",196,196); Sleep(100);//

                
                gotoxy(13+(j*4),15); printf("%c%c",196,196); Sleep(100);
				
				gotoxy(17+(j*4),18); printf("%d",arr[j+1]); Sleep(100);//

				gotoxy(13+(j*4),14); printf("%d",arr[j]); Sleep(100);
				
				
				gotoxy(17+(j*4),18); printf("  "); Sleep(100);//

				
                gotoxy(13+(j*4),14); printf("  "); Sleep(100);
                
                gotoxy(17+(j*4),19); printf("%d",arr[j+1]);Sleep(100);//
                
                gotoxy(13+(j*4),13); printf("%d",arr[j]); Sleep(100);
                
                
				gotoxy(13+(j*4),13); printf("  "); Sleep(100);
				
				gotoxy(17+(j*4),19); printf("  "); Sleep(100);//

                
                
                //lado
                
                gotoxy(14+(j*4),13); printf("%d",arr[j]); Sleep(100);
                
                gotoxy(16+(j*4),19); printf("%d",arr[j+1]);Sleep(100);//
                
                gotoxy(14+(j*4),13); printf("  ");Sleep(100);
                
                gotoxy(16+(j*4),19); printf("  "); Sleep(100);//
                
                gotoxy(15+(j*4),13); printf("%d",arr[j]); Sleep(100);
                
                gotoxy(15+(j*4),19); printf("%d",arr[j+1]); Sleep(100);//
                
                gotoxy(15+(j*4),13); printf("  "); Sleep(100);
                
                gotoxy(15+(j*4),19); printf("  "); Sleep(100);//
                
                gotoxy(16+(j*4),13); printf("%d",arr[j]);Sleep(100);
                
                gotoxy(14+(j*4),19); printf("%d",arr[j+1]); Sleep(100);//
                
                gotoxy(16+(j*4),13); printf("  ");Sleep(100);
                
                gotoxy(14+(j*4),19); printf("  "); Sleep(100);//
                
                gotoxy(17+(j*4),13); printf("%d",arr[j]); Sleep(100);
                
                gotoxy(13+(j*4),19); printf("%d",arr[j+1]);Sleep(100);//
                
                gotoxy(17+(j*4),13); printf("  "); Sleep(100);
                
                gotoxy(13+(j*4),19); printf("  "); Sleep(100);//

                
                //bajada
                
                gotoxy(17+(j*4),14); printf("%d",arr[j]); Sleep(100);
                
                gotoxy(13+(j*4),18); printf("%d",arr[j+1]); Sleep(100);//

                
                gotoxy(17+(j*4),14); printf("  "); Sleep(100);
                
                gotoxy(13+(j*4),18); printf("  "); Sleep(100);//

                
                gotoxy(17+(j*4),15); printf("%d",arr[j]); Sleep(100);
                
                gotoxy(13+(j*4),17); printf("%d",arr[j+1]); Sleep(100);//

                
                gotoxy(17+(j*4),15); printf("  "); Sleep(100);
                
                gotoxy(13+(j*4),17); printf("  "); Sleep(100);//

                
                gotoxy(17+(j*4),15); printf("%c%c",196,196); Sleep(	100);
                
                gotoxy(13+(j*4),16); printf("%d",arr[j+1]); Sleep(100);//

                
                gotoxy(17+(j*4),16); printf("%d",arr[j]); Sleep(100);
                
                gotoxy(13+(j*4),17); printf("%c%c",196,196); Sleep(100);

                
                arr[j] = arr[j + 1];//codigo
                arr[j + 1] = temp;
            }
			
            

            gotoxy(13+(j*4),22);
            printf(" ");
            gotoxy(17+(j*4),22);
            printf(" ");
        }
    }
}

void imprime(int d, int h,int n)
{
	int i;
	gotoxy(d,h);
	printf("%c",218);
	gotoxy(d,h+1);
	printf("%c",179);
	gotoxy(d,h+2);
	printf("%c",192);
	
	for(i=0;i<n-1;i++)
	{
		gotoxy(d+(i*4)+1,h);
		printf("%c%c%c%c",196,196,196,194);
		gotoxy(d+(i*4)+4,h+1);
		printf("%c",179);
		gotoxy(d+(i*4)+1,h+2);
		printf("%c%c%c%c",196,196,196,193);
	}
	gotoxy(d+(i*4)+1,h);
	printf("%c%c%c%c",196,196,196,191);
	gotoxy(d+(i*4)+1,h+1);
	printf("   %c",179);
	gotoxy(d+(i*4)+1,h+2);
	printf("%c%c%c%c",196,196,196,217);
}
 
void margen(int c, int f)
{
	int i,p,q,j,m=40,l=4;
	
	gotoxy(c,f);
	printf("%c",201);
	
	for(i=0;i<100;i++)
	{
		gotoxy(c+i+1,f);
		printf("%c",205);
		for(j=0;j<20;j++)
		{
			gotoxy(c,f+1+j);
			printf("%c",186);
			
			gotoxy(c+100,f+1+j);
			printf("%c",186);
			
		}
		gotoxy(c+i+1,f+21);
		printf("%c",205);
		
	}
	
	gotoxy(c,f+21);
	printf("%c",200);
	
	gotoxy(c+100,f);
	printf("%c",187);
	
	gotoxy(c+100,f+21);
	printf("%c",188);
	
	
	gotoxy(m,l);
	printf("%c",201);
	
	for(p=0;p<38;p++)
	{
		gotoxy(m+p+1,l);
		printf("%c",205);
		
		for(q=0;q<2;q++)
		{
			gotoxy(m,l+1+q);
			printf("%c",186);

			gotoxy(m+38,l+1+q);
			printf("%c",186);
			
		}
		gotoxy(m+p+1,l+2);
		printf("%c",205);
	}	
	
	gotoxy(m,l+2);
	printf("%c",200);
	
	gotoxy(m+38,f+2);
	printf("%c",187);
	
	gotoxy(m+38,f+4);
	printf("%c",188);
}

 void gotoxy(int x,int y)
 {  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
void imprime_datos(int arr[],int size)
{
	int x;
	for(x=0;x<size;x++)
	{
	
		gotoxy(13+(x*4),16);
		printf("%d",arr[x]);
	}
}



