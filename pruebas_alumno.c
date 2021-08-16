#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

#define TAM 2000

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_ver_tope(pila_t* pila, void* elem){

	print_test("pila ver tope", pila_ver_tope(pila) == elem);
}

void prueba_ver_int_tope(pila_t* pila, int* elem){

	print_test("pila ver tope int", *(int*)pila_ver_tope(pila) == (*elem));
}

void prueba_ver_char_tope(pila_t* pila, char* elem){

	print_test("pila ver tope char", *(char*)pila_ver_tope(pila) == (*elem));
}

void prueba_ver_tope_vacio(pila_t* pila){

	print_test("pila NO hay tope en pila vacía", pila_desapilar(pila) == NULL);
}

void prueba_apilar(pila_t* pila, void* elem){

	print_test("pila se apiló un elem", pila_apilar(pila, elem));
	prueba_ver_tope(pila, elem);
}

void prueba_desapilar(pila_t* pila, void* elem){

	print_test("pila se desapiló un elem", pila_desapilar(pila) == elem);
}

void prueba_desapilar_vacio(pila_t* pila){

	print_test("pila NO se desapiló un elem de pila vacía", pila_desapilar(pila) == NULL);
}

void inicializar_vector(int* vector, int tope){

	int num = 42;

	for(int i = 0; i < tope; i++){
		vector[i] = num;
		num++;
	}
}

void prueba_apilar_y_desapilar_distintos(pila_t* pila){

	int num = 1, num2 = 2, num3 = 198;
	double num4 = 60;
	char letra = 'a', letra2 = 'h', letra3 = 'z', caracter = '@';

	prueba_apilar(pila, &letra3);
	prueba_apilar(pila, &num);
	prueba_apilar(pila, &num2);
	prueba_apilar(pila, &caracter);
	prueba_apilar(pila, &letra2);
	prueba_apilar(pila, &num3);
	prueba_apilar(pila, NULL);
	prueba_apilar(pila, &letra);
	prueba_apilar(pila, &num4);

	prueba_desapilar(pila, &num4);
	prueba_ver_tope(pila, &letra);
	prueba_ver_char_tope(pila, &letra);

	prueba_desapilar(pila, &letra);
	prueba_ver_tope(pila, NULL);

	prueba_desapilar(pila, NULL);
	prueba_ver_tope(pila, &num3);
	prueba_ver_int_tope(pila, &num3);

	prueba_desapilar(pila, &num3);
	prueba_ver_tope(pila, &letra2);
	prueba_ver_char_tope(pila, &letra2);

	prueba_desapilar(pila, &letra2);
	prueba_ver_tope(pila, &caracter);
	prueba_ver_char_tope(pila, &caracter);

	prueba_desapilar(pila, &caracter);
	prueba_ver_tope(pila, &num2);
	prueba_ver_int_tope(pila, &num2);

	prueba_desapilar(pila, &num2);
	prueba_ver_tope(pila, &num);
	prueba_ver_int_tope(pila, &num);

	prueba_desapilar(pila, &num);
	prueba_ver_tope(pila, &letra3);
	prueba_ver_char_tope(pila, &letra3);

	prueba_desapilar(pila, &letra3);
}

void prueba_apilar_y_desapilar(pila_t* pila){

	int num = 0, num2 = 20, num3 = 42, num4 = 7;

	prueba_apilar(pila, &num4);
	prueba_ver_int_tope(pila, &num4);
	prueba_apilar(pila, &num);
	prueba_ver_int_tope(pila, &num);
	prueba_apilar(pila, &num3);
	prueba_ver_int_tope(pila, &num3);
	prueba_apilar(pila, &num2);
	prueba_ver_int_tope(pila, &num2);

	prueba_desapilar(pila, &num2);
	prueba_ver_int_tope(pila, &num3);
	prueba_desapilar(pila, &num3);
	prueba_ver_int_tope(pila, &num);
	prueba_desapilar(pila, &num);
	prueba_ver_int_tope(pila, &num4);
	prueba_desapilar(pila, &num4);

	prueba_desapilar_vacio(pila);
	prueba_ver_tope_vacio(pila);
}

void prueba_desapilar_y_ver_tope(pila_t* pila){

	prueba_desapilar_vacio(pila);
	prueba_ver_tope_vacio(pila);
}

void prueba_apilar_y_desapilar_iterado(pila_t* pila){

	int vector[TAM];
	int tope = 1200;

	inicializar_vector(vector, tope);

	for(int i = 0; i < tope; i++){
		prueba_apilar(pila, &vector[i]);
		prueba_ver_int_tope(pila, &vector[i]);
	}

	for(int j = tope-1; j > 0; j--){
		prueba_desapilar(pila, &vector[j]);
		prueba_ver_tope(pila, &vector[j-1]);
		prueba_ver_int_tope(pila, &vector[j-1]);
	}

	prueba_desapilar(pila, &vector[0]);

	prueba_desapilar_vacio(pila);
	prueba_ver_tope_vacio(pila);
}

void prueba_crear_y_destruir(){

	pila_t* pila_vacia = pila_crear();
	pila_t* pila_nueva = pila_crear();	//APILAR Y DESAPILAR DISTINTOS PUNTEROS DE DISTINTOS TIPOS DE DATOS
	pila_t* pila_nueva2 = pila_crear();	//APILAR Y DESAPILAR DISTINTOS PUNTEROS DE MISMO TIPO DE DATOS
	pila_t* pila_nueva3 = pila_crear();	//DESAPILAR Y VER TOPE EN PILA VACIA
	pila_t* pila_nueva4 = pila_crear();	//APILAR Y SUPERAR CAPACIDAD

	print_test("Se creó pila_vacia", pila_vacia != NULL);
	print_test("Se creó pila_nueva", pila_nueva != NULL);
	print_test("Se creó pila_nueva2", pila_nueva2 != NULL);
	print_test("Se creó pila_nueva3", pila_nueva3 != NULL);
	print_test("Se creó pila_nueva4", pila_nueva4 != NULL);

	printf("\tPRUEBA APILAR Y DESAPILAR\n");
	printf("\tpila_nueva\nPUNTEROS DISTINTOS DE DISTINTOS TIPOS DE DATOS\n");
	prueba_apilar_y_desapilar_distintos(pila_nueva);
	printf("\tpila_nueva2\nPUNTEROS DISTINTOS DE MISMO TIPO DE DATO\n");
	prueba_apilar_y_desapilar(pila_nueva2);
	printf("\tpila_nueva3\nDESAPILAR Y VER TOP EN PILA VACIA\n");
	prueba_desapilar_y_ver_tope(pila_nueva3);
	printf("\tpila_nueva4\nAPILAR MISMO PUNTERO Y SUPERAR CAPACIDAD\n");
	prueba_apilar_y_desapilar_iterado(pila_nueva4);

	printf("\tPRUEBA ESTA VACIA\n");
	print_test("pila vacia está vacía", pila_esta_vacia(pila_vacia));
	print_test("pila_nueva está vacía", pila_esta_vacia(pila_nueva));
	print_test("pila_nueva2 está vacía", pila_esta_vacia(pila_nueva2));
	print_test("pila_nueva3 está vacía", pila_esta_vacia(pila_nueva3));
	print_test("pila_nueva4 está vacía", pila_esta_vacia(pila_nueva4));

	printf("\tPRUEBA DESTRUIR\n");
	pila_destruir(pila_vacia);
	print_test("Se destruyó pila vacía", true);
	pila_destruir(pila_nueva);
	print_test("Se destruyó pila_nueva", true);
	pila_destruir(pila_nueva2);
	print_test("Se destruyó pila_nueva2", true);
	pila_destruir(pila_nueva3);
	print_test("Se destruyó pila_nueva3", true);
	pila_destruir(pila_nueva4);
	print_test("Se destruyó pila_nueva4", true);
}

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);

    prueba_crear_y_destruir();

}
