// pch.h: este es un archivo de encabezado precompilado.
// Los archivos que se muestran a continuación se compilan solo una vez, lo que mejora el rendimiento de la compilación en futuras compilaciones.
// Esto también afecta al rendimiento de IntelliSense, incluida la integridad del código y muchas funciones de exploración del código.
// Sin embargo, los archivos que se muestran aquí se vuelven TODOS a compilar si alguno de ellos se actualiza entre compilaciones.
// No agregue aquí los archivos que se vayan a actualizar con frecuencia, ya que esto invalida la ventaja de rendimiento.

#ifndef PCH_H
#define PCH_H

// agregue aquí los encabezados que desea precompilar
#include <iostream>
#include <string>
#include <Windows.h>
// Librería User32 para resetear el tamaño de la consola
#pragma comment (lib, "User32.lib")

using namespace std;
using namespace System;

// -------------------------------------------
// PARTE 1. FUNCIONES GENERALES
// -------------------------------------------
// 1.1. Función para reconfigurar el tamaño de la consola y ponerla en el centro
void static resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow(); // Obtengo la consola
	RECT rect; // Inicializo las dimensiones

	// Obtengo las dimensiones actuales de la consola
	GetWindowRect(console, &rect);

	// Cálculo la posición donde se encontrará la consola (centro)
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int newX = (screenWidth - width) / 2;
	int newY = (screenHeight - height) / 2;

	// Pinto la consola según los cálculos anteriores
	MoveWindow(console, newX, newY, width, height, TRUE);
}
// 1.2. Función para repetir un string "n" veces
string static n(string str, int times) {
	string result;
	for (int i = 0; i < times; ++i) result += str;
	return result;
}
// 1.3. Función para generar un número aleatorio
int static random(int min, int max) {
	return min + (rand() % (max - min + 1));
}

#endif //PCH_H
