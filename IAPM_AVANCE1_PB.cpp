/*
  AVANCE 1. Itzel Anahí Pérez Morales.
*/
#include <iostream>
#include <string>

using namespace std;

int numero_articulo = 1;

int main() {
	int op, opcasouno;
	float precio, impuesto = 1.16;
	char nombre[100], descripcion[100], consola[100];

	cout << "\t °*| MENU DE OPCIONES |*° \n 1. Alta de articulos\n 2. Baja de articulos\n 3. Modificacion de articulos\n 4. Lista de productos\n 5. Limpiar pantalla\n 6. Salir\n"; cin >> op;

	switch (op) {
	case 1: //ALTA DE PRODUCTO
		cout << "| Ingrese el nombre del articulo: "; cin >> nombre;
		cout << "| Describa el juego (Categoria): "; cin >> descripcion; //Aún no puede tomarse una descripción ya que la variable está definida como char
		cout << "| Consola compatible: "; cin >> consola;
		cout << "| Precio unitario: "; cin >> precio;

	regresar:
		cout << " Desea guardar lo siguiente?:" << endl;
		cout << "Numero de articulo: " << numero_articulo << endl << nombre << endl << descripcion << endl;
		cout << " - Consolas compatibles: " << consola << endl << " - Precio unitario: $" << precio << endl << " - Precio final: $" << precio * impuesto << endl;
		cout << "\n (1) Si | (2) No " << endl;  cin >> opcasouno;
		switch (opcasouno) {
		case 1:
			numero_articulo += 1;
			cout << " *** Los datos se han guardado exitosamente ***" << endl;
			return main();
			break;

		case 2:
			return main();
			break;

		default:
			cout << "(!) ERROR: Opcion invalida" << endl;
			goto regresar;
				break;
		}
		break;

	case 2: //BAJA DE PRODUCTO 
		break;

	case 3: //MODIFICACIÓN DE PRODUCTO
		break;

	case 4: //LISTA DE PRODUCTOS
		break;

	case 5: //LIMPIAR PANTALLA
		system("cls");
		return main();
		break;

	case 6: //SALIR DEL PROGRAMA
		exit(1);
		break;

	default: //NÚMERO INVÁLIDO INGRESADO
		cout << "(!) ERROR: Opcion invalida\n";
		return main();
		break;

	}

}
