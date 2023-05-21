/*
PRODUCTO INTEGRADOR DE APRENDIZAJE. Itzel Anah� P�rez Morales. 2001877
*/

#include <iostream> 
#include <string> 
#include <conio.h> 
#include <stdlib.h> 
#include <vector> 
#include <fstream> 
#include <locale.h> 

using namespace std;

struct Informacion
{
	int numeroarticulo = 0, fecha = 0, clasificacion = 0, genero = 0, consola = 0;
	string descripcion, nombre, caracteristicas, genaux, consaux, clasaux;
	bool status = true;
	float precio = 0, total = 0;
};

Informacion* articulo, * articulos_anteriores;

float impuesto = 1.16; 
int registros = 0, numartaux = 0, contador = 0, articuloaux = 0;

bool statusaux, aux = true;

// F U N C I O N E S  Q U E  S E  U S A R � N

void alta(); //C A S O  1
void baja(); //C A S O  2
void modificacion(); //C A S O  3
void lista(); //C A S O  4
void archivos();//C A S O  6

int main()
{
	setlocale(LC_CTYPE, "Spanish"); //Perm�te acentos y la �
	int op = 0;

	do
	{
		printf("\t *.-| D O N K E Y  G A M E S |-.* \n\tSeleccione una opci�n\n (1) Alta de art�culos\n (2) Baja de art�culos\n (3) Modificaci�n de art�culos\n (4) Lista de productos\n (5) Limpiar pantalla\n (6) Salir\n");
		scanf_s("%d", &op);

		switch (op)
		{
		case 1:
			alta();
			break;

		case 2:
			baja();
			break;

		case 3:
			modificacion();
			break;

		case 4:
			lista();
			break;

		case 5:
			system("cls");
			break;

		case 6:
			archivos();
			exit(1);
			break;

		default:
			printf("\n\n(!) ERROR: Opci�n inv�lida \n\n");
			break;
		}
	} while (op != 6);
}

//------------------------- C A S O  1 --------------------------------
void alta()
{
	int opcasouno = 0;
	printf("\t *.| R E G I S T R O |.* \n �Cu�ntos art�culos dar� de alta?\n");
	scanf_s("%d", &registros);

	int total_antes = contador;
	if (aux!= true) 
	{
		articulos_anteriores = new Informacion[contador];//arreglo que llevar� las posiciones anteriores
		for (int i = 0; i < contador; i++) 
		{
			articulos_anteriores[i] = articulo[i]; // se copian los datos de articulo en articulos_anteriores
		}
		delete[] articulo;
	}
	contador = contador + registros; //contador llevar� todos los art�culos registrados 
	articulo = new Informacion[contador]; //define el int como valor que puede cambiar, Informaci�n tendr� x posiciones 

	if (aux!= true) 
	{
		for (int i = 0; i < total_antes; i++) {
			articulo[i] = articulos_anteriores[i];
		}
	}

	for (int i = articuloaux; i < contador; i++) 
	{
		printf("\n--------- A R T � C U L O  %d ---------\n", (i + 1));
		printf("\n| Ingrese el nombre del art�culo: \n");
		while (getchar() != '\n'); //a diferencia del cin.ignore este lee la primera letra
		getline(cin, articulo[i].nombre);

		printf("\n| Ingrese el a�o de lanzamiento: \n");
		scanf_s("%d", &articulo[i].fecha);

		do
		{
			printf("\n| Seleccione la clasificaci�n:\n (1) A: Apto para todo p�blico \n (2) B: Para mayores de 12 a�os\n (3) B15: Para mayores de 15 a�os \n (4) C: Para mayores de 18 a�os\n (5) D: Adultos \n");
			scanf_s("%d", &articulo[i].clasificacion);
		} while (articulo[i].clasificacion < 1 || articulo[i].clasificacion > 5);

		printf("\n| Describa el juego: \n");
		while (getchar() != '\n');
		getline(cin, articulo[i].descripcion);

		do
		{
			printf("\n| Consolas compatibles: \n (1) PS5\n (2) XBOX Series X\n (3) Nintendo Switch\n (4) PS4 Pro\n (5) SNES Classic\n (6) SEGA Genesis\n");
			scanf_s("%d", &articulo[i].consola);
		} while (articulo[i].consola < 1 || articulo[i].consola > 6);

		printf("\n| Caracter�sticas del producto: \n");
		while (getchar() != '\n');
		getline(cin, articulo[i].caracteristicas);

		do
		{
			printf("\n| Especifique el g�nero del videojuego: \n (1) Acci�n\n (2) Aventura\n (3) Arcade\n (4) Carreras\n (5) Deportes\n (6) Estrategia\n (7) Simulaci�n\n (8) Terror\n");
			scanf_s("%d", &articulo[i].genero);
		} while (articulo[i].genero < 1 || articulo[i].genero > 7);

		printf("\n| Precio unitario: \n");
		scanf_s("%f", &articulo[i].precio);
		articulo[i].total = articulo[i].precio * impuesto;
		articulo[i].numeroarticulo = numartaux + 1;
		numartaux += 1;
	}
	articuloaux = registros + articuloaux; // se declara igual que registros para que ah� comience el siguiente registro
	aux = false; // en la siguiente vuelta se entrar� al ciclo del inicio
	printf("\n\n *** Los datos se han guardado exitosamente *** \n\n");
}

//------------------------- C A S O  2 ---------------------------------------------------------------------------------------------------
void baja()
{
	int opcasodos = 0, numregis = 0;
	do
	{
		printf("\n \t * . | B A J A  D E  P R O D U C T O | .*\n �Est� seguro de querer dar de baja un producto? \n \t (1) SI | (2) NO \n");
		scanf_s("%d", &opcasodos);
	} while (opcasodos != 1 && opcasodos != 2);

	if (opcasodos == 1)
	{
		printf("\n| Ingrese el n�mero de registro del art�culo | \n\n (!) UNA VEZ ELIMINADO EL REGISTRO DEL PRODUCTO NO SE PODR�N RECUPERAR LOS DATOS\n");
		scanf_s("%d", &numregis);
		for (int i = 0; i < contador; i++)
		{
			if (i == (numregis - 1))
			{
				articulo[i].status = false;
			}
		}
		printf("\n\n(!) El registro %d ha sido eliminado \n\n", numregis);
	}
}

//------------------------- C A S O  3 -----------------------------------------------------------------------------------------------------

void modificacion()
{
	int opcasotres = 0, numregis = 0;
	do
	{
		printf("\n \t * . | M O D I F I C A C I � N  D E  P R O D U C T O S | .*\n �Desea modificar un producto? \n \t (1) SI | (2) NO \n");
		scanf_s("%d", &opcasotres);
	} while (opcasotres != 1 && opcasotres != 2);
	if (opcasotres == 1)
	{
		do
		{
			printf("\n| Ingrese el n�mero de registro del art�culo | \n");
			scanf_s("%d", &numregis);
			for (int i = (numregis - 1); i == (numregis - 1); i++)
			{
				if (articulo[i].status == false)
				{
					printf("\n\n(!) El registro %d ya ha sido eliminado\n\n", numregis);
					statusaux = false;
				}
				else
				{
					statusaux = true;
				}
			}
		} while (!statusaux);

		do
		{
			printf("| �Qu� desea modificar?\n (1) Nombre\n (2) A�o\n (3) Clasificaci�n\n (4) Descripci�n\n (5) Consolas compatibles\n (6) Caracter�sticas\n (7) G�nero\n (8) Precio Unitario \n");
			scanf_s("%d", &opcasotres);
			for (int i = 0; i < contador; i++)
			{
				if (articulo[i].numeroarticulo == numregis)
				{
					switch (opcasotres)
					{
					case 1:
						printf("\n| Ingrese el nombre del articulo: \n");
						while (getchar() != '\n');
						getline(cin, articulo[i].nombre);
						break;

					case 2:
						printf("\n| Ingrese el a�o de lanzamiento: \n");
						scanf_s("%d", &articulo[i].fecha);
						break;

					case 3:
						do
						{
							printf("\n| Seleccione la clasificaci�n:\n (1) A: Apto para todo p�blico \n (2) B: Para mayores de 12 a�os\n (3) B15: Para mayores de 15 a�os \n (4) C: Para mayores de 18 a�os\n (5) D: Adultos \n");
							scanf_s("%d", &articulo[i].clasificacion);
						} while (articulo[i].clasificacion < 1 || articulo[i].clasificacion > 5);
						break;

					case 4:
						printf("\n| Describa el juego: \n");
						while (getchar() != '\n');
						getline(cin, articulo[i].descripcion);
						break;

					case 5:
						do
						{
							printf("\n| Consolas compatibles: \n (1) PS5\n (2) XBOX Series X\n (3) Nintendo Switch\n (4) PS4 Pro\n (5) SNES Classic\n (6) SEGA Genesis\n");
							scanf_s("%d", &articulo[i].consola);
						} while (articulo[i].consola < 1 || articulo[i].consola > 6);
						break;

					case 6:
						printf("\n| Caracter�sticas del producto: \n");
						while (getchar() != '\n');
						getline(cin, articulo[i].caracteristicas);
						break;

					case 7:
						do
						{
							printf("\n| Especifique el g�nero del videojuego: \n (1) Acci�n\n (2) Aventura\n (3) Arcade\n (4) Carreras\n (5) Deportes\n (6) Estrategia\n (7) Simulaci�n\n (8) Terror\n");
							scanf_s("%d", &articulo[i].genero);
						} while (articulo[i].genero < 1 || articulo[i].genero > 7);
						break;

					case 8:
						printf("\n| Precio unitario: \n");
						scanf_s("%f", &articulo[i].precio);
						articulo[i].total = articulo[i].precio * impuesto;
						break;
					}
				}
			}
		} while (opcasotres < 1 || opcasotres > 8);
		printf("\n\n(!) Los cambios han sido guardados exitosamente\n\n");
	}
}

//------------------------- C A S O  4 ---------------
void lista()
{
	int opcioncasocuatro = 0;
	do
	{
		printf("\n~~~~~~~~~ �C�mo desea que se muestren los art�culos? ~~~~~~~~~\n (1) Por clasificaci�n | (2) Por G�nero | (3) Por Consola | (4) Mostrar todos los art�culos \n");
		scanf_s("%d", &opcioncasocuatro);
	} while (opcioncasocuatro < 1 || opcioncasocuatro > 4);

	switch (opcioncasocuatro)
	{
	case 1:
		do
		{
			printf("\n ~~~~~~~~~ �Qu� clasificaci�n filtrar�? ~~~~~~~~~ \n (1) A: Apto para todo p�blico \n (2) B: Para mayores de 12 a�os\n (3) B15: Para mayores de 15 a�os \n (4) C: Para mayores de 18 a�os\n (5) D: Adultos \n");
			scanf_s("%d", &opcioncasocuatro);
		} while (opcioncasocuatro < 1 || opcioncasocuatro > 5);

		for (int i = 0; i < contador; i++)
		{
			if (articulo[i].status == false)
			{
				printf("\n -------------------------------\n(!) ERROR: El articulo %d ya ha sido eliminado\n\n", (i + 1));
			}
			else
			{
				if (articulo[i].clasificacion == opcioncasocuatro)
				{
					printf(" \n -------------------------------\n\t N�mero de art�culo: %d \n", articulo[i].numeroarticulo);
					printf("\t %s \n", articulo[i].nombre.c_str());
					printf("- A�o de lanzamiento: %d \n", articulo[i].fecha);
					switch (articulo[i].consola)
					{
					case 1:
						articulo[i].consaux = "PS5";
						break;
					case 2:
						articulo[i].consaux = "XBOX Series";
						break;
					case 3:
						articulo[i].consaux = "Nintendo Switch";
						break;
					case 4:
						articulo[i].consaux = "PS4 Pro";
						break;
					case 5:
						articulo[i].consaux = "SNES Classic";
						break;
					case 6:
						articulo[i].consaux = "SEGA GENESIS";
						break;
					}

					switch (articulo[i].clasificacion)
					{
					case 1:
						articulo[i].clasaux = "A: Apto para todo p�blico";
						break;
					case 2:
						articulo[i].clasaux = "B: Para mayores de 12 a�os";
						break;
					case 3:
						articulo[i].clasaux = "B15: Para mayores de 15 a�os";
						break;
					case 4:
						articulo[i].clasaux = "C: Para mayores de 18 a�os";
						break;
					case 5:
						articulo[i].clasaux = "D : Adultos";
						break;
					}

					switch (articulo[i].genero)
					{
					case 1:
						articulo[i].genaux = "Acci�n";
						break;
					case 2:
						articulo[i].genaux = "Aventura";
						break;
					case 3:
						articulo[i].genaux = "Arcade";
						break;
					case 4:
						articulo[i].genaux = "Carreras";
						break;
					case 5:
						articulo[i].genaux = "Deportes";
						break;
					case 6:
						articulo[i].genaux = "Estrategia";
						break;
					case 7:
						articulo[i].genaux = "Simulaci�n";
						break;
					case 8:
						articulo[i].genaux = "Terror";
						break;
					}
					printf("%s \n- Consolas compatibles: %s \n", articulo[i].descripcion.c_str(), articulo[i].consaux.c_str());
					printf("- Caracter�sticas: %s \n", articulo[i].caracteristicas.c_str());
					printf("Clasificaci�n: %s | G�nero: %s \n", articulo[i].clasaux.c_str(), articulo[i].genaux.c_str());
					printf("- Precio unitario: $%5.2f \n- Precio final: $%5.2f \n\n", articulo[i].precio, articulo[i].total);
				}
			}

		}
		break;

	case 2:
		do
		{
			printf("\n ~~~~~~~~~ Seleccione un g�nero ~~~~~~~~~ \n (1) Acci�n\n (2) Aventura \n (3) Arcade\n (4) Carreras\n (5) Deportes\n (6) Estrategia\n (7) Simulaci�n\n (8) Terror\n");
			scanf_s("%d", &opcioncasocuatro);
		} while (opcioncasocuatro < 1 || opcioncasocuatro > 8);
		for (int i = 0; i < contador; i++)
		{
			if (articulo[i].status == false)
			{
				printf("\n\n(!) ERROR: El articulo %d ya ha sido eliminado\n\n", (i + 1));
			}
			else
			{
				if (articulo[i].genero == opcioncasocuatro)
				{
					printf(" \n -------------------------------\n\t N�mero de art�culo: %d \n", articulo[i].numeroarticulo);
					printf("\t %s \n", articulo[i].nombre.c_str());
					printf("- A�o de lanzamiento: %d \n", articulo[i].fecha);
					switch (articulo[i].consola)
					{
					case 1:
						articulo[i].consaux = "PS5";
						break;
					case 2:
						articulo[i].consaux = "XBOX Series";
						break;
					case 3:
						articulo[i].consaux = "Nintendo Switch";
						break;
					case 4:
						articulo[i].consaux = "PS4 Pro";
						break;
					case 5:
						articulo[i].consaux = "SNES Classic";
						break;
					case 6:
						articulo[i].consaux = "SEGA GENESIS";
						break;
					}

					switch (articulo[i].clasificacion)
					{
					case 1:
						articulo[i].clasaux = "A: Apto para todo p�blico";
						break;
					case 2:
						articulo[i].clasaux = "B: Para mayores de 12 a�os";
						break;
					case 3:
						articulo[i].clasaux = "B15: Para mayores de 15 a�os";
						break;
					case 4:
						articulo[i].clasaux = "C: Para mayores de 18 a�os";
						break;
					case 5:
						articulo[i].clasaux = "D : Adultos";
						break;
					}

					switch (articulo[i].genero)
					{
					case 1:
						articulo[i].genaux = "Acci�n";
						break;
					case 2:
						articulo[i].genaux = "Aventura";
						break;
					case 3:
						articulo[i].genaux = "Arcade";
						break;
					case 4:
						articulo[i].genaux = "Carreras";
						break;
					case 5:
						articulo[i].genaux = "Deportes";
						break;
					case 6:
						articulo[i].genaux = "Estrategia";
						break;
					case 7:
						articulo[i].genaux = "Simulaci�n";
						break;
					case 8:
						articulo[i].genaux = "Terror";
						break;
					}
					printf("%s \n- Consolas compatibles: %s \n", articulo[i].descripcion.c_str(), articulo[i].consaux.c_str());
					printf("- Caracter�sticas: %s \n", articulo[i].caracteristicas.c_str());
					printf("Clasificaci�n: %s | G�nero: %s \n", articulo[i].clasaux.c_str(), articulo[i].genaux.c_str());
					printf("- Precio unitario: $%5.2f \n- Precio final: $%5.2f \n\n", articulo[i].precio, articulo[i].total);
				}
			}
		}
		break;

	case 3:
		do
		{
			printf("\n ~~~~~~~~~ Seleccione una consola ~~~~~~~~~ \n (1) PS5\n (2) XBOX Series X\n (3) Nintendo Switch\n (4) PS4 Pro\n (5) SNES Classic\n (6) SEGA Genesis\n");
			scanf_s("%d", &opcioncasocuatro);
		} while (opcioncasocuatro < 1 || opcioncasocuatro > 6);
		for (int i = 0; i < contador; i++)
		{
			if (articulo[i].status == false)
			{
				printf("\n -------------------------------\n(!) ERROR: El articulo %d ya ha sido eliminado\n\n", (i + 1));
			}
			else
			{
				if (articulo[i].consola == opcioncasocuatro)
				{
					printf(" \n -------------------------------\n\t N�mero de art�culo: %d \n", articulo[i].numeroarticulo);
					printf("\t %s \n", articulo[i].nombre.c_str());
					printf("- A�o de lanzamiento: %d \n", articulo[i].fecha);
					switch (articulo[i].consola)
					{
					case 1:
						articulo[i].consaux = "PS5";
						break;
					case 2:
						articulo[i].consaux = "XBOX Series";
						break;
					case 3:
						articulo[i].consaux = "Nintendo Switch";
						break;
					case 4:
						articulo[i].consaux = "PS4 Pro";
						break;
					case 5:
						articulo[i].consaux = "SNES Classic";
						break;
					case 6:
						articulo[i].consaux = "SEGA GENESIS";
						break;
					}

					switch (articulo[i].clasificacion)
					{
					case 1:
						articulo[i].clasaux = "A: Apto para todo p�blico";
						break;
					case 2:
						articulo[i].clasaux = "B: Para mayores de 12 a�os";
						break;
					case 3:
						articulo[i].clasaux = "B15: Para mayores de 15 a�os";
						break;
					case 4:
						articulo[i].clasaux = "C: Para mayores de 18 a�os";
						break;
					case 5:
						articulo[i].clasaux = "D : Adultos";
						break;
					}

					switch (articulo[i].genero)
					{
					case 1:
						articulo[i].genaux = "Acci�n";
						break;
					case 2:
						articulo[i].genaux = "Aventura";
						break;
					case 3:
						articulo[i].genaux = "Arcade";
						break;
					case 4:
						articulo[i].genaux = "Carreras";
						break;
					case 5:
						articulo[i].genaux = "Deportes";
						break;
					case 6:
						articulo[i].genaux = "Estrategia";
						break;
					case 7:
						articulo[i].genaux = "Simulaci�n";
						break;
					case 8:
						articulo[i].genaux = "Terror";
						break;
					}
					printf("%s \n- Consolas compatibles: %s \n", articulo[i].descripcion.c_str(), articulo[i].consaux.c_str());
					printf("- Caracter�sticas: %s \n", articulo[i].caracteristicas.c_str());
					printf("Clasificaci�n: %s | G�nero: %s \n", articulo[i].clasaux.c_str(), articulo[i].genaux.c_str());
					printf("- Precio unitario: $%5.2f \n- Precio final: $%5.2f \n\n", articulo[i].precio, articulo[i].total);
				}
			}
		}
		break;

	case 4:
		for (int i = 0; i < contador; i++)
		{
			if (articulo[i].status == false)
			{
				printf("\n -------------------------------\n(!) ERROR: El articulo %d ya ha sido eliminado\n\n", (i + 1));
			}
			else
			{
				printf(" \n -------------------------------\n\t N�mero de art�culo: %d \n", articulo[i].numeroarticulo);
				printf("\t %s \n", articulo[i].nombre.c_str());
				printf("- A�o de lanzamiento: %d \n", articulo[i].fecha);
				switch (articulo[i].consola)
				{
				case 1:
					articulo[i].consaux = "PS5";
					break;
				case 2:
					articulo[i].consaux = "XBOX Series";
					break;
				case 3:
					articulo[i].consaux = "Nintendo Switch";
					break;
				case 4:
					articulo[i].consaux = "PS4 Pro";
					break;
				case 5:
					articulo[i].consaux = "SNES Classic";
					break;
				case 6:
					articulo[i].consaux = "SEGA GENESIS";
					break;
				}

				switch (articulo[i].clasificacion)
				{
				case 1:
					articulo[i].clasaux = "A: Apto para todo p�blico";
					break;
				case 2:
					articulo[i].clasaux = "B: Para mayores de 12 a�os";
					break;
				case 3:
					articulo[i].clasaux = "B15: Para mayores de 15 a�os";
					break;
				case 4:
					articulo[i].clasaux = "C: Para mayores de 18 a�os";
					break;
				case 5:
					articulo[i].clasaux = "D : Adultos";
					break;
				}

				switch (articulo[i].genero)
				{
				case 1:
					articulo[i].genaux = "Acci�n";
					break;
				case 2:
					articulo[i].genaux = "Aventura";
					break;
				case 3:
					articulo[i].genaux = "Arcade";
					break;
				case 4:
					articulo[i].genaux = "Carreras";
					break;
				case 5:
					articulo[i].genaux = "Deportes";
					break;
				case 6:
					articulo[i].genaux = "Estrategia";
					break;
				case 7:
					articulo[i].genaux = "Simulaci�n";
					break;
				case 8:
					articulo[i].genaux = "Terror";
					break;
				}
				printf("%s \n- Consolas compatibles: %s \n", articulo[i].descripcion.c_str(), articulo[i].consaux.c_str());
				printf("- Caracter�sticas: %s \n", articulo[i].caracteristicas.c_str());
				printf("Clasificaci�n: %s | G�nero: %s \n", articulo[i].clasaux.c_str(), articulo[i].genaux.c_str());
				printf("- Precio unitario: $%5.2f \n- Precio final: $%5.2f \n\n", articulo[i].precio, articulo[i].total);
			}
		}
	}
}

//------------------------- C A S O  6 ---------------
void archivos()
{
	{
		ofstream archivo;
		string nombrearchivo;
		float datosnumeros;
		string cadenas;

		nombrearchivo = "DONKEYGAMES.txt";
		archivo.open(nombrearchivo.c_str(), ios::out);

		if (archivo.fail())
		{
			printf("(!) ERROR: No se pudo crear el archivo \n");
			exit(1);
		}

		archivo << "\t" << " *.| D O N K E Y   G A M E S |.*\n\t~~~~~~~~~~~~~~~~~~~~~~~\n";

		for (int i = 0; i < contador; i++)
		{
			if (!articulo[i].status)
			{
				archivo << "\n\n";
			}
			else
			{
				archivo << "N�M. DE ART�CULO: ";
				datosnumeros = articulo[i].numeroarticulo;
				archivo << datosnumeros;

				archivo << " | ART�CULO: ";
				cadenas = articulo[i].nombre;
				archivo << cadenas << "\n";

				archivo << "A�O: ";
				datosnumeros = articulo[i].fecha;
				archivo << datosnumeros;

				archivo << " | G�NERO: ";
				cadenas = articulo[i].genaux;
				archivo << cadenas;

				archivo << " | CLASIFICACI�N:";
				cadenas = articulo[i].clasaux;
				archivo << cadenas;

				archivo << " | CONSOLA: ";
				cadenas = articulo[i].consaux;
				archivo << cadenas << "\n";

				archivo << "DESCRIPCI�N: ";
				cadenas = articulo[i].descripcion;
				archivo << cadenas << "\n";

				archivo << "CARACTER�STICAS: ";
				cadenas = articulo[i].caracteristicas;
				archivo << cadenas << "\n";

				archivo << "PRECIO: ";
				datosnumeros = articulo[i].precio;
				archivo << datosnumeros;

				archivo << " | PRECIO FINAL: ";
				datosnumeros = articulo[i].total;
				archivo << datosnumeros << "\n\t~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			}
		}
		archivo.close();
	}
}