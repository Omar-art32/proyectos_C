#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define MAX 10

void gotoxy(int x, int y);
int menu();
int pila_llena(int tope);
int pila_vacia(int tope);
void push(char pila[MAX], int *tope, char dat);
char pop(char pila[MAX], int *tope);
void imprime(int c, int f);
int balanceo_parentesis(char *dat, char pila[MAX], int *tope);
void limpiar_pila(int *tope);

int main()
{
    char pila[MAX];
    int tope = 0, opc;
    int c = 69, f = 2;
    char dat[MAX];

    do
    {
        imprime(c, f);
        opc = menu();

        switch (opc)
        {
        case 1:
            gotoxy(7, 10);
            printf("INGRESE PARENTESIS: ");
            gotoxy(32, 10);
            scanf("%s", dat);
            balanceo_parentesis(dat, pila, &tope);
            limpiar_pila(&tope); // Limpiar la pila al finalizar la operación
            Sleep(5000);
            system("cls");
           
            break;
        case 2:
            printf("SALIENDO DEL PROGRAMA......");
            break;
        default:
            printf("Opcion no valida. Intentelo de nuevo.");
            break;
        }
    } while (opc != 2);

    return 0;
}

int menu()
{
    int dec;
    gotoxy(7, 3);
    printf("BIENVENIDO AL MENUU");
    gotoxy(7, 5);
    printf("1._INGRESAR DATO.");
    gotoxy(7, 6);
    printf("2._SALIR.");

    gotoxy(7, 8);
    printf("ELIGA UNA OPCION: ");
    gotoxy(25, 8);
    scanf("%d", &dec);

    gotoxy(25, 8);
    printf("   ");

    return dec;
}

void push(char pila[MAX], int *tope, char dat)
{
    if (pila_llena(*tope) == 1)
    {
        gotoxy(7, 10);
        printf("OVERFLOW-DESBORDAMIENTO.");
        Sleep(3000);
        gotoxy(7, 10);
        printf("                        ");
    }
    else
    {
        (*tope)++;
        pila[*tope] = dat;
        gotoxy(63, 25 - (*tope) * 2);
        printf("Tope->");

        gotoxy(24, 10);
        printf("  ");

        gotoxy(63, 25 - (*tope) * 2);
        printf("      ");

        gotoxy(63, 23 - (*tope) * 2);
        printf("Tope->");

        gotoxy(70, 23 - (*tope) * 2);
        printf("%c", dat);
        Sleep(2000);
    }
}

char pop(char pila[MAX], int *tope)
{
    char dat;
    if (pila_vacia(*tope) == 1)
    {
        gotoxy(7, 10);
        printf("UNDERFLOW-SUBDESBORDAMIENTO");
        Sleep(3000);
        gotoxy(7, 10);
        printf("                           ");
        dat = ' '; // En caso de underflow, retornar un valor por defecto
    }
    else
    {
        dat = pila[*tope];
        (*tope)--;
        Sleep(2000);
        gotoxy(70, 21 - (*tope) * 2);
        printf("  ");

        gotoxy(63, 21 - (*tope) * 2);
        printf("      ");

        gotoxy(63, 23 - (*tope) * 2);
        printf("Tope->");
    }
    return dat;
}

int pila_llena(int tope)
{
    return tope == MAX;
}

int pila_vacia(int tope)
{
    return tope == 0;
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

void imprime(int c, int f)
{
    int i;
    gotoxy(c, f);
    printf("%c", 218);
    gotoxy(c + 1, f);
    printf("%c%c", 196, 196);
    gotoxy(c + 3, f);
    printf("%c", 191);

    for (i = 0; i < MAX - 1; i++)
    {
        gotoxy(c, f + (i * 2) + 1);
        printf("%c", 179);
        gotoxy(c + 3, f + (i * 2) + 1);
        printf("%c", 179);
        gotoxy(c, f + (i * 2) + 2);
        printf("%c%c%c", 195, 196, 196);
        gotoxy(c + 3, f + (i * 2) + 2);
        printf("%c", 180);
    }
    gotoxy(c, f + (i * 2) + 1);
    printf("%c", 179);
    gotoxy(c + 3, f + (i * 2) + 1);
    printf("%c", 179);
    gotoxy(c, f + (i * 2) + 2);
    printf("%c%c%c%c", 192, 196, 196, 217);
    gotoxy(c + 3, f + (i * 2) + 2);
    printf("%c", 217);
}

void limpiar_pila(int *tope)
{
    *tope = 0;
}

int balanceo_parentesis(char *dat, char pila[MAX], int *tope)
{
    int i;

    for (i = 0; dat[i] != '\0'; i++)
    {
        if (dat[i] == '(')
        {
            push(pila, tope, dat[i]);
        }
        else
        {
            if (dat[i] == ')')
            {
                if (pila_vacia(*tope) || pop(pila, tope) != '(')
                {
                	gotoxy(7, 13);
                    printf("Expresion no valida");
                    return 0;
                }
            }
        }
    }
    if (pila_vacia(*tope))
    {
    	gotoxy(7, 13);
        printf("Expresion valida");
        return 1;
    }
    else
    {
    	gotoxy(7, 13);
        printf("Expresion no valida");
        return 0;
    }
    
}

