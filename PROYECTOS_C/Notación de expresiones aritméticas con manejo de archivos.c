#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
typedef struct Nodo 
{
    char dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct 
{
    Nodo* cima;
} Pila;


void gotoxy(int x, int y);
void margen(int c, int f);
void push(Pila* pila, char dato);
char pop(Pila* pila);
char tope(Pila* pila);
void inicializarPila(Pila* pila);
int estaVacia(Pila* pila);
int esOperador(char c);
int obtenerPrecedencia(char operador);
void convertirInfijoAPrefijo(char expresionInfija[], char expresionPrefija[]);
void convertirInfijoAPostfijo(char expresionInfija[], char expresionPostfija[]);





void push(Pila* pila, char dato) 
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
}

char pop(Pila* pila) 
{
    if (pila->cima == NULL) 
	{
        printf("Error: Desbordamiento de la pila\n");
        exit(EXIT_FAILURE);
    }

    Nodo* temp = pila->cima;
    char dato = temp->dato;
    pila->cima = temp->siguiente;
    free(temp);
    return dato;
}

char tope(Pila* pila) 
{
    if (pila->cima == NULL) 
	{
        printf("Error: La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    return pila->cima->dato;
}

void inicializarPila(Pila* pila) 
{
    pila->cima = NULL;
}


int estaVacia(Pila* pila) 
{
    return pila->cima == NULL;
}

int esOperador(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int obtenerPrecedencia(char operador) 
{
    switch (operador) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void convertirInfijoAPrefijo(char expresionInfija[], char expresionPrefija[]) 
{
    Pila operadores, resultado;
    inicializarPila(&operadores);


    int i, j;
    for (i = strlen(expresionInfija) - 1, j = 0; i >= 0; i--) 
	{
        char simbolo = expresionInfija[i];

        if (isalnum(simbolo)) {//comprueba si es un simbolo alfanumerico
            expresionPrefija[j++] = simbolo;
        } else if (simbolo == ')') {
            push(&operadores, simbolo);
        } else if (simbolo == '(') {
            while (!estaVacia(&operadores) && tope(&operadores) != ')') 
			{
                expresionPrefija[j++] = pop(&operadores);
            }
            pop(&operadores); // Elimina el paréntesis de apertura de la pila
        } else {
            while (!estaVacia(&operadores) && obtenerPrecedencia(tope(&operadores)) > obtenerPrecedencia(simbolo)) 
			{
                expresionPrefija[j++] = pop(&operadores);
            }
            push(&operadores, simbolo);
        }
    }

    while (!estaVacia(&operadores)) 
	{
        expresionPrefija[j++] = pop(&operadores);//si quedan aun elementos los pasa
    }

    expresionPrefija[j] = '\0';
}

void convertirInfijoAPostfijo(char expresionInfija[], char expresionPostfija[]) 
{
    Pila operadores;
    inicializarPila(&operadores);

    int i, j;
    for (i = 0, j = 0; i < strlen(expresionInfija); i++) 
	{
        char simbolo = expresionInfija[i];

        if (isalnum(simbolo)) { //comprueba si es un simbolo alfanumerico
            expresionPostfija[j++] = simbolo;
        } else if (simbolo == '(') {
            push(&operadores, simbolo);
        } else if (simbolo == ')') {
            while (!estaVacia(&operadores) && tope(&operadores) != '(') 
			{
                expresionPostfija[j++] = pop(&operadores);
            }
            pop(&operadores);
        } else {
            while (!estaVacia(&operadores) && obtenerPrecedencia(tope(&operadores)) >= obtenerPrecedencia(simbolo)) 
			{
                expresionPostfija[j++] = pop(&operadores);
            }
            push(&operadores, simbolo);
        }
    }

    while (!estaVacia(&operadores)) 
	{
        expresionPostfija[j++] = pop(&operadores);
    }

    expresionPostfija[j] = '\0';
}

int main() 
{
    int c = 9, f = 2;
    char expresionInfija[100], expresionPrefija[100], expresionPostfija[100];



	gotoxy(42,5);
	printf("NOTACION DE EXPRESIONES ARITMETICAS");
	margen(c,f);
    // Se abre el archivo en modo lectura
    FILE *archivo = fopen("expre_pilas.txt", "r");

    // Verifica si el archivo se pudo abrir correctamente
    if (archivo == NULL) 
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    // Leer expresiones desde el archivo
    while (fgets(expresionInfija, 100, archivo) != NULL) 
    {
        // Elimina el salto de línea al final de la expresión
        expresionInfija[strcspn(expresionInfija, "\n")] = '\0';

        // Convertir a notación prefija y postfija
        convertirInfijoAPrefijo(expresionInfija, expresionPrefija);
        convertirInfijoAPostfijo(expresionInfija, expresionPostfija);

        // Imprimir resultados
        gotoxy(11,10);
        printf("Expresion infija: %s", expresionInfija);
        gotoxy(11,12);
        printf("Notacion prefija: %s", strrev(expresionPrefija));
        gotoxy(11,14);
        printf("Notacion postfija: %s", expresionPostfija);

        
        gotoxy(65, 22);
        printf("Pulse una tecla para continuar.....");
        getchar();  // Espera a que el usuario presione una 
        
        gotoxy(29,10);
        printf("                                                         ");
        gotoxy(29,12);
        printf("                                                         ");
        gotoxy(29,14);
        printf("                                                         ");
        
    }

    // Cerrar el archivo después de leer
    fclose(archivo);

    gotoxy(65, 22);
    printf("Pulse una tecla para terminar....:()");
    getchar();
    
    return 0;
}





void gotoxy(int x, int y) 
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
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



