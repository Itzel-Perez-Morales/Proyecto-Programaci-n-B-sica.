/*
  AVANCE 2. Itzel Anahí Pérez Morales. 2001877
*/

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct informacion //Guardará los datos solicitados en el punto 1
{
	int numeroarticulo = 0;
	char nombre[100];
	string descripcion, consola;
	float precio;

} articulo; // articulo es la variable que llamará y almacenará las variables de la estructura

int opcionuno(informacion articulo[3], float impuesto);



int main()
{
	float impuesto = 1.16;
	int op = 0;
	int numeroarticuloaux = 0; //Esta es para llevar un conteo de la variable "numeroarticulo" que está en información, sin esta numero de articulo siempre sería uno
	int opcasouno = 0; 

	informacion articulo[3]; //llamada a la estructura y asignación del número de datos que guardará
	do 
	{
		printf("\t *.-| MENU DE OPCIONES |-.* \n 1. Alta de articulos\n 2. Baja de articulos\n 3. Modificacion de articulos\n 4. Lista de productos\n 5. Limpiar pantalla\n 6. Salir\n"); scanf_s("%d", &op); 

		switch (op)
		{
		case 1: //A L T A  D E  P R O D U C T O
			for (int i = 0; i < 3; i++) 
			{
				printf("\n| Ingrese el nombre del articulo: \n"); cin.ignore(); gets_s(articulo[i].nombre); //cin.ignore es para que "separar" las lecturas
				printf("| Describa el juego: \n"); getline(cin, articulo[i].descripcion);
				printf("| Consolas compatibles: \n"); getline(cin, articulo[i].consola);
				printf("| Precio unitario: \n"); scanf_s("%f", &articulo[i].precio);
				articulo[i].numeroarticulo = numeroarticuloaux + 1; numeroarticuloaux += 1;
			}

			do
			{
				opcasouno=opcionuno(articulo, impuesto); //funcion (1) para mantener un bucle en caso de que se ingrese un valor invalido
				switch (opcasouno)
				{
				case 1:
					printf(" *** Los datos se han guardado exitosamente *** \n\n");
					break;

				case 2:
					for (int i = 0; i < 3; i++)
					{
						articulo[i].numeroarticulo = articulo[i].numeroarticulo - 3; //se borraran los datos ingresados 
					}
					break;

				default:
					printf("(!) ERROR: Opcion invalida \n");
					break;
				}
			} while (opcasouno != 1 && opcasouno != 2);
			break;

		case 2: //BAJA DE PRODUCTO 
			break;

		case 3: //MODIFICACIÓN DE PRODUCTO
			break;

		case 4: //LISTA DE PRODUCTOS

			for (int i = 0; i < 3; i++)
			{
				printf(" \n -------------------------------\n\t %d \n", articulo[i].numeroarticulo);
				printf("\t %s \n", articulo[i].nombre);
				printf("%s \n- Consolas compatibles: %s \n", articulo[i].descripcion.c_str(), articulo[i].consola.c_str());
				printf("- Precio unitario: $%5.2f \n - Precio final: $%5.2f \n\n", articulo[i].precio, articulo[i].precio * impuesto);
			}
			break;

		case 5: //LIMPIAR PANTALLA
			system("cls");
			break;

		case 6: //SALIR DEL PROGRAMA
			exit(0);
			break;

		default: //NÚMERO INVÁLIDO INGRESADO
			printf("(!) ERROR: Opcion invalida \n\n");
			break;

		}
	} while (op != 6);

}

//funcion para que se repita en caso de que el usuario ingrese un valor fuera del rango del caso 1
int opcionuno(informacion articulo[3], float impuesto)
{
	printf(" Desea guardar lo siguiente? : \n");
	for (int i = 0; i < 3; i++)
	{
		printf(" \n -------------------------------\n\t Numero de articulo: %d \n", articulo[i].numeroarticulo);
		printf("\t %s \n", articulo[i].nombre);
		printf("%s \n- Consolas compatibles: %s \n", articulo[i].descripcion.c_str(), articulo[i].consola.c_str());
		printf("- Precio unitario: $%5.2f \n - Precio final: $%5.2f \n", articulo[i].precio, articulo[i].precio * impuesto);
	}
	int opcasouno = 0;
	printf("\n (1) Si | (2) No \n"); scanf_s("%d", &opcasouno);
	return opcasouno;
}
