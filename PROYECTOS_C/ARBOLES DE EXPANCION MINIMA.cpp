//al inicio hay que carbiarlo a 32-bit release para que funcione, tambien tener winbgim
#include <winbgim.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

/* Estructuras y tipos */
typedef struct _nodo 
{
    struct _nodo *izquierdo;
    int dato;
    struct _nodo *derecho;
} tipoNodo;

struct grafico
{
    int x;
    int y;
    int radio;
};

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;


void margen(int c, int f);
void gotoxy(int x, int y);
int decision();
void dibujarNodo(Arbol a, int x, int y, int nivel, int ventanaAncho);
void mostrarArbol(Arbol a);
/* Funciones con árboles: */
/* Insertar en árbol ordenado: */
void Insertar(Arbol *a);
/* Borrar un elemento: */
void Borrar(Arbol *a);
/* Función de búsqueda: */
int Buscar(Arbol *a);
/* Comprobar si el árbol está vacío: */
int Vacio(Arbol r);
/* Comprobar si es un nodo hoja: */
int EsHoja(pNodo r);
/* Contar número de nodos: */
int NumeroNodos(Arbol a, int* c);
/* Calcular la altura de un árbol: */
int AlturaArbol(Arbol a, int* altura);
/* Calcular altura de un dato: */
int Altura(Arbol a, int dat);
/* Aplicar una función a cada elemento del árbol: */
void InOrden(Arbol);

/* Funciones auxiliares: */
void Podar(Arbol *a);
void auxContador(Arbol nodo, int *c);
void auxAltura(pNodo nodo, int a, int *altura);


/* Poda: borrar todos los nodos a partir de uno, incluido */
void Podar(Arbol *a)
{
	int c = 13, f = 2;
	
   /* Algoritmo recursivo, recorrido en postorden */
   if(!Vacio(*a)) {
      Podar(&(*a)->izquierdo); /* Podar izquierdo */
      Podar(&(*a)->derecho);   /* Podar derecho */
      free(*a);                /* Eliminar nodo */
      *a = NULL;
   }
    
}

/* Insertar un dato en el árbol ABB */
/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a)
{
    int dat;
    int c = 13, f = 2;
    int altura = 1; // Declarar la variable altura

    pNodo padre = NULL;
    pNodo actual = *a;

    system("cls");
    margen(c, f);
    gotoxy(53, 5);printf("Arbol Binario");
    gotoxy(14, 8);printf("Ingrese Dato: ");scanf("%d", &dat);

    /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
    while (!Vacio(actual) && dat != actual->dato)
    {
        padre = actual;
        if (dat < actual->dato)
            actual = actual->izquierdo;
        else if (dat > actual->dato)
            actual = actual->derecho;
    }

    /* Si se ha encontrado el elemento, regresar sin insertar */
    if(!Vacio(actual)) return;

    /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
    if (Vacio(padre))
    {
        *a = (Arbol)malloc(sizeof(tipoNodo));
        (*a)->dato = dat;
        (*a)->izquierdo = (*a)->derecho = NULL;
    }
    /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
    else if (dat < padre->dato)
    {
        actual = (Arbol)malloc(sizeof(tipoNodo));
        padre->izquierdo = actual;
        actual->dato = dat;
        actual->izquierdo = actual->derecho = NULL;
    }
    /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
    else if (dat > padre->dato)
    {
        actual = (Arbol)malloc(sizeof(tipoNodo));
        padre->derecho = actual;
        actual->dato = dat;
        actual->izquierdo = actual->derecho = NULL;
    }

    /* Mostrar la altura del árbol después de la inserción */
    gotoxy(14, 10);printf("Altura del arbol: %d\n", AlturaArbol(*a, &altura));

    /* Mostrar el árbol InOrden */
    gotoxy(14, 9);printf("Arbol: ");
    InOrden(*a);
    printf("\n");
    gotoxy(77, 22);system("pause");
	system("cls");
}








/* Funciones */
void dibujarNodo(Arbol a, int x, int y, int nivel, int ventanaAncho) 
{
    // Calcular la posición del nodo en función del nivel
    int nodoX = x;
    int nodoY;
    
    // Ajustar la posición hacia abajo solo a partir del segundo nivel
    if (nivel > 1) {
        nodoY = y + (nivel - 1) * 70; 
    } else {
        nodoY = y; // Mantener la misma posicion para el primer nivel
    }

    // Dibujar el nodo en la posición calculada
    circle(nodoX, nodoY, 20); // Dibujar el círculo (parámetros: coordenadas x, y del centro y radio)
    
    // Convertir el valor del nodo a una cadena y mostrarlo en el centro del círculo
    char valorStr[10];
    itoa(a->dato, valorStr, 10);
    outtextxy(nodoX - textwidth(valorStr) / 2, nodoY - textheight(valorStr) / 2, valorStr);

    // Dibujar las líneas a los nodos izquierdo y derecho (si existen)
    if (a->izquierdo != NULL) {
        line(nodoX, nodoY + 20, nodoX - ventanaAncho / 4, nodoY + 50); // Dibujar línea al nodo izquierdo (parámetros: x1, y1, x2, y2)
        dibujarNodo(a->izquierdo, x - ventanaAncho / 4, y, nivel + 1, ventanaAncho / 2); 
    }
    if (a->derecho != NULL) {
        line(nodoX, nodoY + 20, nodoX + ventanaAncho / 4, nodoY + 50); // Dibujar línea al nodo derecho
        dibujarNodo(a->derecho, x + ventanaAncho / 4, y, nivel + 1, ventanaAncho / 2); 
    }
}



void mostrarArbol(Arbol a) 
{
    initwindow(1366, 768);
    dibujarNodo(a,  getmaxx() / 2, 50, 2,  getmaxx());  
    getch();
    closegraph();
}


/* Eliminar un elemento de un árbol ABB */
void Borrar(Arbol *a)
{
    int dat;
    int c = 13, f = 2;
    pNodo padre = NULL;
    pNodo actual;
    pNodo nodo;
    int aux;
    
    system("cls");
    margen(c, f);
    gotoxy(53, 5);printf("Arbol Binario");
    gotoxy(14, 8);printf("Ingrese Dato: ");scanf("%d", &dat);
    actual = *a;
   /* Mientras sea posible que el valor esté en el árbol */
   while(!Vacio(actual)) 
   {
      if(dat == actual->dato) { /* Si el valor está en el nodo actual */
         if(EsHoja(actual)) { /* Y si además es un nodo hoja: lo borramos */
            if(padre) /* Si tiene padre (no es el nodo raiz) */
               /* Anulamos el puntero que le hace referencia */
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            gotoxy(14, 9);printf("Se ha eliminado el Elemento: %d",dat);
            /* Mostrar el árbol InOrden */
            gotoxy(14, 10);printf("Arbol: ");
            InOrden(*a);
            printf("\n");
            
            free(actual); /* Borrar el nodo */
            actual = NULL;
            gotoxy(77, 22);system("pause");
            system("cls");
            return;
         }
         else { /* Si el valor está en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo más izquierdo de rama derecha */
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            /* O buscar nodo más derecho de rama izquierda */
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            /* Intercambiar valores de no a borrar u nodo encontrado
               y continuar, cerrando el bucle. El nodo encontrado no tiene
               por qué ser un nodo hoja, cerrando el bucle nos aseguramos
               de que sólo se eliminan nodos hoja. */
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { /* Todavía no hemos encontrado el valor, seguir buscándolo */
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
    gotoxy(14, 9);printf("El Elemento %d no se encuentra en el Arbol",dat);
    gotoxy(77, 22);system("pause");
    system("cls");
}

/* Recorrido de árbol en inorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void InOrden(Arbol a)
{
   if(a->izquierdo) InOrden(a->izquierdo);
   printf("%d, ", a->dato);
   if(a->derecho) InOrden(a->derecho);
}

/* Buscar un valor en el árbol */
int Buscar(Arbol *a)
{
    int dat;
    int c = 13, f = 2;

    pNodo actual = *a;
    system("cls");
    margen(c, f);
    gotoxy(53, 5);
    printf("Arbol Binario");
    gotoxy(14, 8);
    printf("Ingrese Dato: ");
    scanf("%d", &dat);

    /* Todavía puede aparecer, ya que quedan nodos por mirar */
    while (!Vacio(actual))
    {
        if (dat == actual->dato)
        {
            gotoxy(14, 9);printf("El dato %d se encuentra en el arbol.\n", dat);

            /* Mostrar el árbol InOrden */
            gotoxy(14, 10);
            printf("Arbol: ");
            InOrden(*a);
            printf("\n");

            gotoxy(77, 22);system("pause");
            system("cls");
            return TRUE; /* dato encontrado */
        }
        else if (dat < actual->dato)
            actual = actual->izquierdo; /* Seguir buscando a la izquierda */
        else if (dat > actual->dato)
            actual = actual->derecho; /* Seguir buscando a la derecha */
    }

    gotoxy(14, 9);printf("El dato %d no se encuentra en el arbol.\n", dat);
    gotoxy(77, 22);system("pause");
    system("cls");
    return FALSE; /* No está en árbol */
}


/* Calcular la altura del nodo que contiene el dato dat */
int Altura(Arbol a, int dat)
{
	
   int altura = 0;
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; /* No está en árbol, devolver -1 */
}


/* Contar el número de nodos */
int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Función auxiliar */
   return *contador;
}

/* Función auxiliar para contar nodos. Función recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxContador(Arbol nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

/* Calcular la altura del árbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(Arbol a, int *altura)
{
   *altura = 1;

   auxAltura(a, 1, altura); /* Función auxiliar */
   return *altura;
}

/* Función auxiliar para calcular altura. Función recursiva de recorrido en
   postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
   altura de la máxima actual */
void auxAltura(pNodo nodo, int a, int *altura)
{
   /* Recorrido postorden */
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{	
   return !r->derecho && !r->izquierdo;
}

int main()
{
    Arbol ArbolInt = NULL;
    int altura;
    int nnodos;
    int c = 13, f = 2;
    int dec;

    do
    {
        margen(c, f);
        gotoxy(53, 5);
        printf("Arbol Binario");
        dec = decision();

        switch (dec)
        {
            case 1:
                Insertar(&ArbolInt);
                break;
            case 2:
    			if (ArbolInt == NULL) 
				{
					system("cls");
					margen(c, f);
        			gotoxy(53, 5);printf("Arbol Binario");
        			gotoxy(14, 9);printf("El arbol esta vacio.");
        			gotoxy(77, 22);system("pause");
                	system("cls");
    			} 
				else 
				{
        			mostrarArbol(ArbolInt);
    			}
   				break;
            case 3:
                Buscar(&ArbolInt);
                break;
            case 4:
                Borrar(&ArbolInt);
                break;
            case 5:
                system("cls");
                margen(c, f);
                gotoxy(53, 5);printf("Arbol Binario");
                Podar(&ArbolInt);
                gotoxy(14, 9);printf("EL Arbol ha sido Vaciado");
                gotoxy(77, 22);system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                gotoxy(14, 8);printf("Saliendo del programa");
                break;
            default:
                printf("Opcion no valida");
        }
    } while (dec != 6);

    return 0;
}


int decision()
{
    int opc;
    gotoxy(50, 7);printf("1._Insertar");
    gotoxy(50,8);printf("2._Mostrar");
    gotoxy(50, 9);printf("3._Buscar");
    gotoxy(50, 10);printf("4._Eliminar");
    gotoxy(50,11);printf("5._Vaciar");
    gotoxy(50,12);printf("6._Salir");
    gotoxy(50, 13);printf("Seleccione opcion...........[ ]");
    gotoxy(79, 13);scanf("%d", &opc);
    gotoxy(77, 22);system("pause");
    return opc;
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
    int i, p, q, j, m = 40, l = 4;

    gotoxy(c, f);
    printf("%c", 201);

    for (i = 0; i < 105; i++) {
        gotoxy(c + i + 1, f);
        printf("%c", 205);
        for (j = 0; j < 20; j++) {
            gotoxy(c, f + 1 + j);
            printf("%c", 186);

            gotoxy(c + 105, f + 1 + j);
            printf("%c", 186);
        }
        gotoxy(c + i + 1, f + 21);
        printf("%c", 205);
    }

    gotoxy(c, f + 21);
    printf("%c", 200);

    gotoxy(c + 105, f);
    printf("%c", 187);

    gotoxy(c + 105, f + 21);
    printf("%c", 188);

    gotoxy(m, l);
    printf("%c", 201);

    for (p = 0; p < 50; p++) {
        gotoxy(m + p + 1, l);
        printf("%c", 205);
        for (q = 0; q < 2; q++) {
            gotoxy(m, l + 1 + q);
            printf("%c", 186);

            gotoxy(m + 50, l + 1 + q);
            printf("%c", 186);
        }
        gotoxy(m + p + 1, l + 2);
        printf("%c", 205);
    }

    gotoxy(m, l + 2);
    printf("%c", 200);

    gotoxy(m + 50, f + 2);
    printf("%c", 187);

    gotoxy(m + 50, f + 4);
    printf("%c", 188);
}

