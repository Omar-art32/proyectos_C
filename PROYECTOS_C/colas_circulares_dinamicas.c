#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
struct nodo
{
    int info;
    struct nodo *sig;
};

struct nodo *crea();
struct nodo *encolar(struct nodo *cola, int *frente, int *final);
struct nodo *eliminar(struct nodo *cola, int *frente, int *final);
struct nodo *vaciar(struct nodo *cola, int *frente, int *final);
void gotoxy(int x,int y);
void mostrarCola(struct nodo *cola);
int menu();
void margen(int c, int f);

int main()
{
    struct nodo *cola = NULL;
    int frente = -1; // Inicializa frente a -1 para indicar que la cola está vacía
    int final = -1;  // Inicializa final a -1 para indicar que la cola está vacía
    int opc;
	int c = 9, f = 2;
    


	margen(c,f);
	gotoxy(48,5);
	printf("MANEJO DE COLAS CIRCULARES");
    do
    {
        opc = menu();

        switch (opc)
        {
        case 1:
            cola = encolar(cola, &frente, &final);
            mostrarCola(cola);
            break;
        case 2:
        	gotoxy(10,14);
			printf("                            ");
            cola = eliminar(cola, &frente, &final);
            mostrarCola(cola);
            break;
        case 3:
            cola = vaciar(cola,&frente, &final);
            mostrarCola(cola);
            
            break;
        case 4:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida\n");
        }

    } while (opc != 4);


    return 0;
}

struct nodo *crea()
{
    struct nodo *aux;
    aux = (struct nodo *)malloc(sizeof(struct nodo));
    return aux;
}

int menu()
{
    int opc;
    gotoxy(50,7);
    printf("Menu:");
    gotoxy(50,8);
    printf("1. Insertar valor");
    gotoxy(50,9);
    printf("2. Extraer valor");
    gotoxy(50,10);
    printf("3. Vaciar cola");
    gotoxy(50,11);
    printf("4. Salir");
    gotoxy(50,12);
    printf("Ingrese su opcion: ");
    gotoxy(69,12);
    scanf("%d", &opc);
    
    gotoxy(69,12);
    printf(" ");

    return opc;
}

struct nodo *encolar(struct nodo *cola, int *frente, int *final)
{
    struct nodo *q;
    q = crea();
	
	gotoxy(10,13);
    printf("Ingrese un valor: ");
    gotoxy(28,13);
    scanf("%d", &q->info);

	gotoxy(10,13);
    printf("                  ");
	gotoxy(28,13);
    printf("  ");

    if (*frente == -1) // Cola vacía
    {
        *frente = 0;
        *final = 0;
        q->sig = q; // Hacer que el último apunte al frente para formar el círculo
        cola = q;   // Actualizar la cola para apuntar al nuevo nodo
    }
    else
    {
        q->sig = cola->sig;
        cola->sig = q;
        *final = q->info; // Actualizar el último elemento de la cola
        cola = q;         // Actualizar la cola para apuntar al nuevo nodo
    }

    return cola;
}


struct nodo *eliminar(struct nodo *cola, int *frente, int *final)
{
	int i;
	
    if (*frente == -1)
    {
    	gotoxy(45,22);
        printf("La cola esta vacia.");     
		sleep(2);
		printf("                   ");
        return cola;
    }

    struct nodo *temp = cola->sig;

	i++;
	

    if (cola->sig == cola) // Si solo hay un elemento en la cola
    {
    	
        free(temp);
        cola = NULL;
        *frente = -1; // Después de eliminar, reinicia frente y final
        *final = -1;
        
    }
    else
    {
        cola->sig = temp->sig;
        free(temp);
        *frente = cola->sig->info; // Actualiza frente al siguiente elemento
    }

	
    
    return cola;
}

struct nodo *vaciar(struct nodo *cola, int *frente, int *final)
{
	gotoxy(10,14);
	printf("                               ");
    while (cola != NULL)
    {
        cola = eliminar(cola, frente, final);
    }

	*frente = -1; // Después de vaciar la cola, reinicia frente y final
    *final = -1;
    return cola;
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

void mostrarCola(struct nodo *cola)
{
	int i;
    if (cola == NULL)
    {
		gotoxy(45,22);        
		printf("Cola vacia.");
		sleep(2);
		printf("           ");
        return;
    }

    struct nodo *temp = cola->sig;
    gotoxy(10,14);
    printf("Cola: ");
    do
    {
    	i++;
    	gotoxy(16+(i*2),14);
        printf("%d ", temp->info);
        temp = temp->sig;
    } while (temp != cola->sig);

	
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

