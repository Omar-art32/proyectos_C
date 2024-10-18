#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct Nodo
{
    int info;
    struct Nodo *sig;
};

int menu();
struct Nodo *crea();
struct Nodo *llenar(struct Nodo *cola, int *frente, int *final);
struct Nodo *vaciar(struct Nodo *cola, int *frente, int *final);
void margen(int c, int f);
void gotoxy(int x,int y);
void imprime(int d, int h,int *final);

int main()
{
    struct Nodo *cola = NULL;
    int frente = -1;
    int final = -1;
	int c = 9, f = 2;
    int opc;


	margen(c,f);

    do
    {
        opc = menu();

        switch (opc)
        {
        case 1:
            cola = llenar(cola, &frente, &final);
            break;
        case 2:
            cola = vaciar(cola, &frente, &final);
            break;
        case 3:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida\n");
        }
    } while (opc != 3);

    return 0;
}

int menu()
{
    int seleccion;

    gotoxy(50,7);
	printf("1.-Ingresar dato");
	gotoxy(50,8);
	printf("2.-Borrar dato");
	gotoxy(50,9);
	printf("3.-Salir del programa");
	gotoxy(50,10);
	printf("SELECCIONE OPCION: ");
	gotoxy(68,10);
	scanf("%d",&seleccion);

    return seleccion;
}

struct Nodo *crea()
{
    struct Nodo *aux = (struct Nodo *)malloc(sizeof(struct Nodo));
    return aux;
}

struct Nodo *llenar(struct Nodo *cola, int *frente, int *final)
{
    struct Nodo *p = crea();
	int d=40, h=15;
	
	imprime(d,h,final);
	
	gotoxy(37+((*final+1)*4),13);//imprimir en la posicion -1 final
	printf("FINAL");
	gotoxy(37+((*final+1)*4),14);
	printf("%c",42);
		
		
    gotoxy(41+((*final+1)*4),16);//ingresar dato a la cola
	scanf("%d",&p->info);

	gotoxy(37+((*final+1)*4),13);//borrar la posicion -1 final
	printf("     ");
	gotoxy(37+((*final+1)*4),14);
	printf(" ");

	gotoxy(41+((*final+1)*4),13);//imprimir en la posicion 0 final
	printf("FINAL");
	gotoxy(41+((*final+1)*4),14);
	printf("%c",42);

    p->sig = NULL;

    if (*frente == -1 && *final == -1)
    {
        *frente = *final = 0;
        cola = p; // La cola se inicia aquí si está vacía
        
        gotoxy(37+((*final+1)*4),19);//imprimir en la posicion -1 final
		printf("FRENT");
		gotoxy(37+((*final+1)*4),18);
		printf("%c",42);
    }
    else
    {
        struct Nodo *temp = cola;
        while(temp->sig != NULL)
        {
            temp = temp->sig;
        }
        temp->sig = p;
        (*final)++;
    }

    return cola;
}


struct Nodo *vaciar(struct Nodo *cola, int *frente, int *final)
{
    if (*frente == -1 && *final == -1 && cola == NULL)
    {
    	gotoxy(45,22);
        printf("La cola esta vacia.");
        sleep(2);
		gotoxy(45,22);
		printf("                    ");
    }
    else
    {
        struct Nodo *temp = cola;

        if (*frente == *final)
        {
        	gotoxy(41+((*final)*4),16);//eliminar dato de la cola
			printf("  ");
		
		
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
		
		
		
		
		
            // Solo hay un elemento en la cola
            *frente = *final = -1;
            cola = NULL;
            
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
			
			
            // Hay más de un elemento en la cola
            cola = cola->sig;
            (*frente)++;
        }

		gotoxy(37+((*frente)*4),16);//ingresar dato a la cola
		printf("  ");

		gotoxy(10,10);
        printf("Elemento eliminado: %d", temp->info);
        
        
        free(temp);
    }

    return cola;
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
 
void imprime(int d, int h,int *final)
{
	int i;
	gotoxy(d,h);
	printf("%c",218);
	gotoxy(d,h+1);
	printf("%c",179);
	gotoxy(d,h+2);
	printf("%c",192);
	
	for(i=0;i<*final+1;i++)
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
 
