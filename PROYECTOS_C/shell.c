#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define RESET_COLOR	 "\x1b[0m"
#define CYAN_T		"\x1b[36m"
#define AMARILLO_T "\x1b[33m"


#define max 24

// proto
void shell(int arr[], int n);
void imprime_datos(int arr[], int size);
void imprime(int d, int h, int n);
void margen(int c, int f);
void gotoxy(int x, int y);

int main()
{
    int arr[max]={0};
    int n, j, i = 0; 
    int existe,num;       
    int c = 9, f = 2;
    int d = 12, h = 15;

    // Semilla para números aleatorios
    srand(time(NULL));

    margen(c, f);
    gotoxy(48, 5);
    printf("Metodo de ordenacion shell");

    gotoxy(10,7);
	printf("Ingrese cuantos valores se ordenaran: ");
	gotoxy(48,7);
	scanf("%d",&n);;

    if (n <= max)
    {
        imprime(d, h, n);
        while (i < n)
        {
             num = rand() % 90 + 10;
            existe = 0;

            for (j = 0; j < i; j++)
            {
                if (arr[j] == num)
                {
                    existe = 1;
                    break;
                }
            }

            if (!existe)
            {
                arr[i] = num;
                i++;
            }
			imprime_datos(arr,n);
        }

        shell(arr, n); 
    }
    else
    {
        printf("Ingrese una cantidad mas pequeña. :(");
    }
    
	getch();

    return 0;
}


void shell(int arr[], int size) 
{
    int ini, i, aux, in, band,x,h;
    
    ini = size;

    while (ini > 1) 
	{
        ini = ini / 2;
        band = 1;
		
		gotoxy(10,9);
		printf("INI= %d",ini);
        while (band == 1) 
		{
            band = 0;
            i = 0;

            while ((i + ini) < size) 
			{
				gotoxy(13+(i*4),20);
            	printf(AMARILLO_T"*"RESET_COLOR);
            	gotoxy(13+((i+ini)*4),20);
            	printf(AMARILLO_T"*"RESET_COLOR);

				sleep(1);
				
                if (arr[i] > arr[i + ini]) 
				{
                    aux = arr[i];//codigo
                    
                    //subida y bajda
                    gotoxy(13+(i*4),16); printf("  ");Sleep(150);
                    
                    gotoxy(13+(i+ini)*4,16); printf("  "); Sleep(150);//

                    
                	gotoxy(13+(i*4),15); printf(CYAN_T"%d",arr[i]); Sleep(150);
                	

                	gotoxy(13+(i+ini)*4,17); printf("%d",arr[i+ini]); Sleep(150);//


                	gotoxy(13+(i*4),15); printf("  ");Sleep(150);
                	
                	gotoxy(13+(i*4),15);printf("%c%c",196,196);

                    
                    gotoxy(13+(i+ini)*4,17); printf("  "); Sleep(150);//
                	
                	gotoxy(13+(i+ini)*4,17);printf("%c%c",196,196);

                	
                	gotoxy(13+(i*4),14); printf("%d",arr[i]); Sleep(150);
                	
                	gotoxy(13+(i+ini)*4,18); printf("%d",arr[i+ini]); Sleep(150);//
                	
                	
                	gotoxy(13+(i*4),14); printf("  ");Sleep(150);
                    
                    gotoxy(13+(i+ini)*4,18); printf("  "); Sleep(150);//
                	
                	
                	gotoxy(13+(i*4),13); printf("%d",arr[i]); Sleep(150);
                	
                	gotoxy(13+(i+ini)*4,19); printf("%d",arr[i+ini]); Sleep(150);//
                	
                	
                	gotoxy(13+(i*4),13); printf("  ");Sleep(150);
                    
                    gotoxy(13+(i+ini)*4,19); printf("  "); Sleep(150);//
                	
                	
                	//lados
                	
                	
                	for (x = i; x < ini+i; x++) 
					{
    					Sleep(150);

    					// Imprimir en la primera línea
    					gotoxy(13 + (x * 4) + 4, 13); printf("%d", arr[i]);

    					// Imprimir en la segunda línea
    					gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 - 4, 19); printf("%d", arr[i + ini]);

    					Sleep(150);

    					// Borrar valores anteriores en la primera línea
    					gotoxy(13 + (x * 4) + 4, 13); printf("  ");

    					// Borrar valores anteriores en la segunda línea
						gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 - 4, 19); printf("  ");
					}

					//subida y bajada
					gotoxy(13 + (x * 4), 14); printf("%d", arr[i]);					
                	
					gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 , 18); printf("%d", arr[i + ini]);

                	
                	Sleep(150);
                    
                    gotoxy(13 + (x * 4), 14); printf("  ");
                    
					gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 , 18); printf("  ");

                    
                    Sleep(150);
                    
                    gotoxy(13 + (x * 4) , 15); printf("%d", arr[i]);					
                	
                	gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 , 17); printf("%d", arr[i + ini]);

                	Sleep(150);
                    
                    gotoxy(13 + (x * 4), 15); printf("  ");
                    
                    gotoxy(13 + (x * 4) , 15);  printf("%c%c",196,196);

                    
  					gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 , 17); printf("  ");

                    
                    gotoxy(13 + (x * 4) , 16); printf("%d", arr[i]);			
					
		
                	
                	gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 , 16); printf("%d"RESET_COLOR, arr[i + ini]);

                	
                	gotoxy(13 + ((i + ini) * 4) - (x - i) * 4 , 17);  printf("%c%c",196,196);
                    
                    
                    
                    arr[i] = arr[i + ini];//codifo
                    arr[i + ini] = aux;//codigo
                    band = 1;//codigo
                    
                    sleep(1);//provi
                    imprime_datos(arr,size);


                }
                
                gotoxy(13+(i*4),20);
            	printf(" ");
            	gotoxy(13+((i+ini)*4),20);
            	printf(" ");
                
                i = i + 1;
            }
        }
    }
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
 



