#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#define max 10

int menu();
void llenar_cola(int cola[max],int *frente, int *final);
void eliminar_cola(int cola[max],int *frente,int *final);
void imprime(int d, int h);
void gotoxy(int x, int y);
void margen(int c, int f);



main()
{
	int cola[max],frente=-1,final=-1;
	int selec;
	int dato;
	int c = 9, f = 2;
	int d=40, h=15;
	
	margen(c,f);
	imprime(d,h);
	gotoxy(48,5);
	printf("MANEJO DE COLAS SIMPLES");
	
	do
	{
		
		selec=menu();
		
		switch (selec)
		{
			case 1:
				llenar_cola(cola,&frente,&final);
				break;
			case 2:
				eliminar_cola(cola,&frente,&final);
				break;
			case 3:
				printf("saliendo del programa....");
				break;
			default:
				printf("Opcion no valida.");
		}
		
	}while(selec!=3);
	
	
	
	
	return 0;
}



int menu()
{
	int opc;

	gotoxy(50,7);
	printf("1.-Ingresar dato");
	gotoxy(50,8);
	printf("2.-Borrar dato");
	gotoxy(50,9);
	printf("3.-Salir del programa");
	gotoxy(50,10);
	printf("SELECCIONE OPCION: ");
	gotoxy(68,10);
	scanf("%d",&opc);
	
	return opc;
}



void llenar_cola(int cola[max],int *frente, int *final)
{
	int dato,i;
	i++;
	if(*final<max-1)
	{
		
		
		gotoxy(37+((*final+1)*4),13);//imprimir en la posicion -1 final
		printf("FINAL");
		gotoxy(37+((*final+1)*4),14);
		printf("%c",42);
		
		
		gotoxy(41+((*final+1)*4),16);//ingresar dato a la cola
		scanf("%d",&dato);

	
		gotoxy(37+((*final+1)*4),13);//borrar la posicion -1 final
		printf("     ");
		gotoxy(37+((*final+1)*4),14);
		printf(" ");
		
		gotoxy(41+((*final+1)*4),13);//imprimir en la posicion 0 final
		printf("FINAL");
		gotoxy(41+((*final+1)*4),14);
		printf("%c",42);
	
		(*final)++;
		cola[*final]=dato;
		
		if(*final==0)
		{	
			*frente=0;
			gotoxy(37+((*final+1)*4),19);//imprimir en la posicion -1 final
			printf("FRENT");
			gotoxy(37+((*final+1)*4),18);
			printf("%c",42);
		}
	}
	else
	{
		gotoxy(45,22);
		printf("DESBORDAMIENTO DE COLA. COLA-LLENA");
		sleep(2);
		gotoxy(45,22);
		printf("                                  ");
	}
}


void eliminar_cola(int cola[max],int *frente,int *final)
{
	int guardar;
	
	
	
	if(*frente!=-1)
	{
		guardar=cola[*frente];
		
		if(*frente==*final)
		{
			gotoxy(37+((*frente+1)*4),16);//borrar los elementos de la cola
			printf("   ");
			
			gotoxy(37+((*final+1)*4),13);//imprimir en la posicion 0 final
			printf("     ");
			gotoxy(37+((*final+1)*4),14);
			printf(" ");
			
			
			gotoxy(37+((*frente+1)*4),19);//imprimir en la posicion -1 final
			printf("      ");
			gotoxy(37+((*frente+1)*4),18);
			printf(" ");
			
			
			
			*frente=-1;
			*final=-1;
			gotoxy(37+((*final+1)*4),13);//imprimir en la posicion -1 final
			printf("FINAL");
			gotoxy(37+((*final+1)*4),14);
			printf("%c",42);
			
			
			
		}
		else
		{
			gotoxy(37+((*frente+1)*4),16);//borrar los elementos de la cola
			printf("   ");
			
			
			gotoxy(37+((*frente+1)*4),19);//imprimir en la posicion -1 final
			printf("      ");
			gotoxy(37+((*frente+1)*4),18);
			printf(" ");
			
			gotoxy(41+((*frente+1)*4),19);//imprimir en la posicion -1 final
			printf("FRENT");
			gotoxy(41+((*frente+1)*4),18);
			printf("%c",42);
			
			
			
			
			
			(*frente)++;
		}
	}
	else
	{
		gotoxy(45,22);
		printf("SUBDESBORDAMINETO-COLA VACIA");
		sleep(2);
		gotoxy(45,22);
		printf("                            ");
	}
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
 
 
void imprime(int d, int h)
{
	int i;
	gotoxy(d,h);
	printf("%c",218);
	gotoxy(d,h+1);
	printf("%c",179);
	gotoxy(d,h+2);
	printf("%c",192);
	
	for(i=0;i<max-1;i++)
	{
		gotoxy(d+(i*4)+1,h);
		printf("%c%c%c%c",196,196,196,194);
		gotoxy(d+(i*4)+1,h+1);
		printf("   %c",179);
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

