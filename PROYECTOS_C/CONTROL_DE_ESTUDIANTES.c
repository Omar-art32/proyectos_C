#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

#define mat 50
struct nodo
{
	int matricula;
	char nombre[mat];
	int edad;
	float promedio;
	char carrera[mat];
	struct nodo *liga;
};



struct nodo *alta(struct nodo *inicio);
struct nodo *baja(struct nodo *inicio);
struct nodo *buscar(struct nodo *inicio);
struct nodo *modificar(struct nodo *inicio);
struct nodo *ordena(struct nodo *inico);
void guardar(struct nodo *lista);
struct nodo *leer();
void animacion(struct nodo *lista);

struct nodo *crea();

void cuadrito_a(int x,int y);
void cuadrito();
void tabla ();
void margen_total();
void gotoxy(int x, int y);

main()
{
	struct nodo *p=NULL,*q=NULL;
	int desicion;
	
	
	time_t tiempo_actual;
	time(&tiempo_actual);
	struct tm *info_tiempo=localtime(&tiempo_actual);
	
	
	gotoxy(52,16);system("pause");
	
	do
	{
		system("cls");
		margen_total();
		cuadrito();
		gotoxy(61,2);printf("**** Control de Alumnos ****");
        gotoxy(125,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
		animacion(p);
		desicion=menu();
 		
 		
 		
		switch(desicion)
		{
			case 1:
				
				margen_total();
				cuadrito();
				gotoxy(61,2);printf("**** Control de Alumnos ****");
        		gotoxy(125,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
				animacion(p);
				p=alta(p);
				break;
			case 2:
				
				margen_total();
				cuadrito();
				gotoxy(61,2);printf("**** Control de Alumnos ****");
        		gotoxy(125,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
				animacion(p);
				p=baja(p);
				break;
			case 3:
				margen_total();
				cuadrito();
				gotoxy(61,2);printf("**** Control de Alumnos ****");
        		gotoxy(125,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
				animacion(p);
				p=buscar(p);
				break;
			case 4:
				margen_total();
				cuadrito();
				gotoxy(61,2);printf("**** Control de Alumnos ****");
        		gotoxy(125,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
				animacion(p);
				p=modificar(p);
				break;
			case 5:
    			margen_total();
    			cuadrito();
    			gotoxy(61,2);printf("**** Control de Alumnos ****");
    			gotoxy(125,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
				animacion(p);
    			// Llamas a la función ordena para ordenar la lista
    			p = ordena(p);

    			// Imprimir el conjunto ordenado
    			struct nodo *temp = p;
    			while (temp != NULL) {
        			cuadrito_a(20, 7);
        			gotoxy(21, 8); printf("Matricula del Alumno: %d",temp->matricula);
        			tabla();
        			gotoxy(21, 11);printf("Nombre: %s", temp->nombre);
        			gotoxy(21, 13);printf("Edad: %d", temp->edad);
        			gotoxy(71, 11);printf("Carrera: %s", temp->carrera);
        			gotoxy(71, 13);printf("Promedio: %.2f", temp->promedio);
        			gotoxy(105, 33);system("pause");
        			

        			temp = temp->liga;
        			animacion(p);
        			// Limpiar la pantalla antes de mostrar el siguiente alumno
        			system("cls");
        			margen_total();
        			cuadrito();
        			gotoxy(61,2);printf("**** Control de Alumnos ****");
        			gotoxy(125,3);printf(" %02d/%02d/%02d ",info_tiempo->tm_mday,info_tiempo->tm_mon+1,info_tiempo->tm_year+1900);
        			animacion(p);
    			}
    			//gotoxy(105, 33);system("pause");
    			break;
    		case 6:
    			guardar(p);
    			break;
    		case 7:
    			p=leer();
		}
}while(desicion!=8);
	
	
	return 0;
}

struct nodo *crea()
{
	struct nodo *pauX;
	pauX=(struct nodo *) malloc(sizeof(struct nodo));//dterminar cuantos bits ocupa la estructura. determinar el tamaño de mi estructura
	return pauX;
}

struct nodo *alta(struct nodo *inicio)
{
    struct nodo *nuevo = crea();  
    
    gotoxy(20, 5); printf("Matricula del Alumno: ");
    scanf("%d", &nuevo->matricula);  
    
    // Comprobación de duplicados
    struct nodo *temp = inicio;
    while (temp != NULL)
    {
        if (temp->matricula == nuevo->matricula)
        {
        	cuadrito_a(20, 6);
            gotoxy(21, 7);printf("Ya hay alguien registrado con la misma matricula.\n");
            gotoxy(105, 33);system("pause");
            free(nuevo);  // Liberar el nodo creado
            return inicio;  // No se agrega a la lista
        }
        temp = temp->liga;
    }

    getchar();  // Consumir el salto de línea en el buffer

    gotoxy(20, 6); printf("Nombre del Alumno: ");
    fgets(nuevo->nombre, mat, stdin);
    
    gotoxy(20, 7); printf("Edad del Alumno: ");
    scanf("%d", &nuevo->edad);
    getchar();  // Para consumir el '\n' en el buffer
    
    gotoxy(20, 8); printf("Carrera del Alumno: ");
    fgets(nuevo->carrera, mat, stdin);
    
    gotoxy(20, 9); printf("Promedio del Alumno: ");
    scanf("%f", &nuevo->promedio);
    getchar();  // Para consumir el '\n' en el buffer

    nuevo->liga = inicio;  

    return nuevo;
}

struct nodo *baja(struct nodo *inicio)
{
    struct nodo *q, *t;
    int band = 1;
    char res;
    int matricula;
    int x = 20, y = 6;

    if (inicio == NULL)
    {
    	cuadrito_a(x, y);gotoxy(21, 7);printf("La lista esta vacia.\n");
    	gotoxy(105, 33);system("pause");
        return inicio;
    }

    q = inicio;

    cuadrito_a(x, y);

    gotoxy(21, 7);
    printf("Matricula del Alumno: ");
    scanf("%d", &matricula);

    while (q->matricula != matricula && band == 1)
    {
        if (q->liga != NULL)
        {
            t = q;
            q = q->liga;
        }
        else
        {
            band = 0;
        }
    }

    if (band == 0)
    {
        cuadrito_a(20, 12);
        gotoxy(21, 13);
        printf("No se encuentra el Dato");
    }
    else
    {
        tabla();
        
        gotoxy(21,11);printf("Nombre: %s",q->nombre);
        gotoxy(21,13);printf("Edad: %d",q->edad);
        gotoxy(71,11);printf("Carrera: %s",q->carrera);
        gotoxy(71,13);printf("promedio: %.2f",q->promedio);
        gotoxy(21,16);printf("Esta seguro de eliminar los datos? (s/n): ");
        
        while (getchar() != '\n'); // Consumir caracteres hasta encontrar una nueva línea
        scanf(" %c", &res);

        if (res == 's' || res == 'S')
        {
            if (inicio == q)
            {
                inicio = q->liga;
            }
            else
            {
                t->liga = q->liga;
            }

            free(q);
            q = NULL;
            gotoxy(21,16);printf("                                            ");
            gotoxy(21,16);printf("Datos eliminados exitosamente.\n");
        }
        else
        {
        	gotoxy(21,16);printf("                                           ");
            gotoxy(21,16);printf("Operacin cancelada.\n");
        }
    }
	gotoxy(105,33);system("pause");
    return inicio; // Devuelve el nuevo valor de inicio
    
}

struct nodo *buscar(struct nodo *inicio)
{
    int matricula;
    
    if (inicio == NULL)
    {
        cuadrito_a(20, 6);
        gotoxy(21, 7);
        printf("La lista esta vacia.\n");
        gotoxy(105, 33);system("pause");
        return inicio;
    }

    cuadrito_a(20, 6);

    gotoxy(21, 7);
    printf("Matricula del Alumno: ");
    scanf("%d", &matricula);

    struct nodo *q = inicio;  // Utilizamos una variable auxiliar para recorrer la lista

    while (q != NULL && q->matricula != matricula)
    {
        q = q->liga;
    }

    if (q == NULL)
    {
        cuadrito_a(20, 12);
        gotoxy(21, 13);
        printf("No se encuentra el Dato");
    }
    else
    {
        tabla();
        gotoxy(21, 11);
        printf("Nombre: %s", q->nombre);
        gotoxy(21, 13);
        printf("Edad: %d", q->edad);
        gotoxy(71, 11);
        printf("Carrera: %s", q->carrera);
        gotoxy(71, 13);
        printf("promedio: %.2f", q->promedio);
    }

    gotoxy(105, 33);
    system("pause");
    return inicio;
}

struct nodo *modificar(struct nodo *inicio)
{
    struct nodo *q;
    char res;
    char opcionCampo[20];
    int matricula;

    q = inicio;

    if (q == NULL)
    {
        cuadrito_a(20, 6);
        gotoxy(21, 7);
        printf("La lista esta vacia.\n");
        gotoxy(105, 33);
        system("pause");
        return inicio;
    }

    cuadrito_a(20, 6);

    gotoxy(21, 7);
    printf("Matricula del Alumno: ");
    scanf("%d", &matricula);getchar();

    while (q != NULL && q->matricula != matricula)
    {
        q = q->liga;
    }

    if (q == NULL)
    {
        cuadrito_a(20, 12);
        gotoxy(21, 13);
        printf("No se encuentra el Dato");
    }
    else
    {
    	
            tabla();
            gotoxy(21, 11);
            printf("Nombre: %s", q->nombre);
            gotoxy(21, 13);
            printf("Edad: %d", q->edad);
            gotoxy(71, 11);
            printf("Carrera: %s", q->carrera);
            gotoxy(71, 13);
            printf("Promedio: %.2f", q->promedio);

           	gotoxy(21, 16);
        	printf("Modificar algun dato? (s/n): ");
        	fflush(stdin);
        	scanf("%c", &res);
         do
         {
		 
            if (res == 's' || res == 'S')
            {
            	gotoxy(21,16);printf("                                                  ");
                gotoxy(21, 16);
				printf("Ingrese Campo: ");
				scanf("%s",opcionCampo);

				if (strcmp(opcionCampo, "nombre") == 0 || strcmp(opcionCampo, "Nombre") == 0 || strcmp(opcionCampo, "NOMBRE") == 0)
				{
				    gotoxy(21, 11);
    				printf("                                   ");
    				gotoxy(21, 11);
    				printf("Nombre: ");
    				scanf("%s",q->nombre);
				}
				else if (strcmp(opcionCampo, "edad") == 0 || strcmp(opcionCampo, "Edad") == 0 || strcmp(opcionCampo, "EDAD") == 0)
				{
					gotoxy(21, 13);
    				printf("                                   ");
    				gotoxy(21, 13);
    				printf("Edad: ");
    				scanf("%d", &q->edad);
    				getchar(); // Consumir el carácter de nueva línea
				}
				else if (strcmp(opcionCampo, "carrera") == 0 || strcmp(opcionCampo, "Carrera") == 0 || strcmp(opcionCampo, "CARRERA") == 0)
				{
					gotoxy(71, 11);
    				printf("                                   ");
    				gotoxy(71, 11);
    				printf("Carrera: ");
    				scanf("%s",q->carrera);
				}
				else if (strcmp(opcionCampo, "promedio") == 0 || strcmp(opcionCampo, "Promedio") == 0 || strcmp(opcionCampo, "PROMEDIO") == 0)
				{
					gotoxy(71, 13);
    				printf("                                   ");
    				gotoxy(71, 13);
    				printf("Promedio: ");
    				scanf("%f", &q->promedio);
    				getchar(); // Consumir el carácter de nueva línea
				}
				else
				{			
    				printf("Opción no válida. Inténtelo de nuevo.\n");
				}

                gotoxy(21, 18);
                printf("Desea modificar otro campo? (s/n): ");
                fflush(stdin);
                scanf(" %c", &res);
                gotoxy(21, 18);printf("                                     ");
            }
        } while (res == 's' || res == 'S');
    }

    return inicio;
}

struct nodo *ordena(struct nodo *inicio)
{
    if (inicio == NULL || inicio->liga == NULL) {
        // La lista está vacía o tiene un solo elemento, ya está "ordenada"
        return inicio;
    }

    struct nodo *p, *q;
    int intercambio;

    do {
        intercambio = 0;
        p = inicio;
        q = inicio->liga;

        while (q != NULL) {
            if (p->matricula > q->matricula) {
                // Intercambiar los nodos
                struct nodo *temp = crea();
                temp->matricula = p->matricula;
                strcpy(temp->nombre, p->nombre);
                temp->edad = p->edad;
                temp->promedio = p->promedio;
                strcpy(temp->carrera, p->carrera);

                p->matricula = q->matricula;
                strcpy(p->nombre, q->nombre);
                p->edad = q->edad;
                p->promedio = q->promedio;
                strcpy(p->carrera, q->carrera);

                q->matricula = temp->matricula;
                strcpy(q->nombre, temp->nombre);
                q->edad = temp->edad;
                q->promedio = temp->promedio;
                strcpy(q->carrera, temp->carrera);

                intercambio = 1;
            }

            p = p->liga;
            q = q->liga;
        }

    } while (intercambio);

    return inicio;
}

void guardar(struct nodo *lista) {
    FILE *archivo;

    // Abre el archivo para escribir
    archivo = fopen("datos_alumnos.txt", "w+");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Recorrer la lista y escribe los datos en el archivo
    struct nodo *temp = lista;
    while (temp != NULL) {
        fprintf(archivo, "%d %s \n%d %s \n%.2f\n", temp->matricula, temp->nombre, temp->edad, temp->carrera, temp->promedio);
        temp = temp->liga;
    }

    
    fclose(archivo);
}

struct nodo *leer()
{
	FILE*archivo;
	struct nodo*inicio=NULL;
	int matricula,edad;
	float promedio;
	char nombre[mat],carrera[mat];
	
	
	
	
	archivo=fopen("datos_alumnos.txt","r");
	
	if(archivo==NULL)
	{
		printf("No se pudo abrir el archivo");
		return inicio;
	}
	
	//ller datos
	while (fscanf(archivo, "%d %[^\n] %d %[^\n] %f", &matricula, nombre, &edad, carrera, &promedio) == 5)
	{
		struct nodo *nuevo=crea();
		nuevo->matricula=matricula;
		strcpy(nuevo->nombre,nombre);
		nuevo->edad=edad;
		strcpy(nuevo->carrera,carrera);
		nuevo->promedio=promedio;
		
		nuevo->liga=inicio;
		inicio=nuevo;
	}
	fclose(archivo);
	return inicio;
}


int menu()
{
	int opcion = 1;
    char tecla;
	do{
		gotoxy(65,8); printf("ALTA............[ ]");
		gotoxy(65,9); printf("BAJA............[ ]");
		gotoxy(65,10);printf("CONSULTA........[ ]");
		gotoxy(65,11);printf("MODIFICACIONES..[ ]");
		gotoxy(65,12);printf("ORDENAR.........[ ]");
		gotoxy(65,13);printf("GUARDAR.........[ ]");
		gotoxy(65,14);printf("ABRIR...........[ ]");
		gotoxy(65,15);printf("SALIR...........[ ]");
		gotoxy(48,17);printf("Seleccione la Opcion o Ingrese la Inicial para continuar");
		gotoxy(82,7+opcion); printf("");
		tecla = getch();
        switch (tecla) {
            case 72:  
                if (opcion > 1) opcion--;
                break;
            case 80: 
                if (opcion < 8) opcion++;
                break;
            case 'a': 
				opcion = 1;
				tecla = 13;
				break;
            case 'b': 
				opcion = 2;
				tecla = 13;
				break;
            case 'c': 
				opcion = 3;
				tecla = 13;
				break;				
            case 'm': 
				opcion = 4;
				tecla = 13;
				break;
            case 'o': 
				opcion = 5;
				tecla = 13;
				break;
            case 'g': 
				opcion = 6;
				tecla = 13;
				break;
            case 'r': 
				opcion = 7;
				tecla = 13;
				break;
            case 's': 
				opcion = 8;
				tecla = 13;
				break;														
        }
	}while(tecla != 13);
	system("cls");
	return opcion;
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void margen_total() {
	
    int ancho = 148;
    int alto = 34;
    int i, j;

    // Imprimir la parte superior del margen
    for (i = 0; i < ancho; i++) {
        gotoxy(i, 0);
        printf("%c", 219);
    }

    // Imprimir los lados del margen
    for (j = 0; j < alto; j++) {
        gotoxy(0, j);
        printf("%c", 219);

        gotoxy(ancho - 1, j);
        printf("%c", 219);
    }

    // Imprimir la parte inferior del margen
    for (i = 0; i < ancho; i++) {
        gotoxy(i, alto);
        printf("%c", 219);
    }
}
void cuadrito()
{
	int x=59,y=1,k;
	
	gotoxy(x,y);printf("%c",218);
	for(k=0;k<30;k++)
	{
		gotoxy(x+k+1,y);printf("%c",196);
		gotoxy(x+k+1,y+2);printf("%c",196);
	}
	gotoxy(x,y+1);printf("%c",179);
	gotoxy(x+31,y+1);printf("%c",179);
	
	gotoxy(x+31,y);printf("%c",191);
	gotoxy(x,y+2);printf("%c",192);
	gotoxy(x+31,y+2);printf("%c",217);
}
void cuadrito_a(int x,int y)
{
	int k;
	
	gotoxy(x,y);printf("%c",218);
	for(k=0;k<50;k++)
	{
		gotoxy(x+k+1,y);printf("%c",196);
		gotoxy(x+k+1,y+2);printf("%c",196);
	}
	gotoxy(x,y+1);printf("%c",179);
	gotoxy(x+k,y+1);printf("%c",179);
	
	gotoxy(x+k,y);printf("%c",191);
	gotoxy(x,y+2);printf("%c",192);
	gotoxy(x+k,y+2);printf("%c",217);
}
void tabla ()
{
	int x=20,y=10,a,b=100,c;
	
	gotoxy(x,y);printf("%c",218);
	gotoxy(x,y+2);printf("%c",195);
	gotoxy(x,y+4);printf("%c",192);
	
	for(a=0;a<b;a++)
	{
		gotoxy(x+a+1,y);printf("%c",196);
		gotoxy(x+a+1,y+2);printf("%c",196);
		gotoxy(x+a+1,y+4);printf("%c",196);
	}
	
	gotoxy(x,y+1);printf("%c",179);
	gotoxy(x,y+3);printf("%c",179);
	
	gotoxy(x+a/2,y);printf("%c",194);
	gotoxy(x+a/2,y+1);printf("%c",179);
	gotoxy(x+a/2,y+2);printf("%c",197);
	gotoxy(x+a/2,y+3);printf("%c",179);
	gotoxy(x+a/2,y+4);printf("%c",193);
	
	//final
	gotoxy(x+a,y);printf("%c",191);
	gotoxy(x+a,y+1);printf("%c",179);
	gotoxy(x+a,y+2);printf("%c",180);
	gotoxy(x+a,y+3);printf("%c",179);
	gotoxy(x+a,y+4);printf("%c",217);
}


void animacion(struct nodo *lista)
{
	struct nodo *q;
	int x=30,y=24,z=14,j,l=10;
	int i,cont=0;
	
	q=lista;
	while(q!=NULL)
	{
		cont++;
		q=q->liga;
	};
	
	q=lista;
	for(i=0;i<cont;i++)
	{
		gotoxy((x)+(i*z),y);printf("%c",218);
		for(j=0;j<l;j++)
    	{
    		gotoxy((x+j+1)+(i*z),y);printf("%c",196);
    	 	gotoxy((x+j+1)+(i*z),y+2);printf("%c",196);
		}
		//bordes
		gotoxy((x)+(i*z),y+2);printf("%c",192);
    	gotoxy((x+l)+(i*z),y+2);printf("%c",217);
    	gotoxy((x+l)+(i*z),y);printf("%c",191);
    	//lineas del centro
    	gotoxy((x+l)+(i*z),y+1);printf("%c",179);
    	gotoxy((x+1)+(i*z),y+1);printf("%d",q->matricula);
    	gotoxy((x)+(i*z),y+1);printf("%c",179);
    	//conexiones t
    	gotoxy((x+l-2)+(i*z),y);printf("%c",194);
    	gotoxy((x+l-2)+(i*z),y+2);printf("%c",193);
    	gotoxy((x+l-2)+(i*z),y+1);printf("%c",179);
    	
    	if (i < cont - 1)
        {
            gotoxy((x + l + 1) + (i * z), y + 1);
            printf("->");
        }
    	q=q->liga;
	}
	
}


