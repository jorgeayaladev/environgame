#include "pch.h"

int main(){
    // Reinicializar valores aleatorios
    srand(time(NULL));
    // Cambiar tamaño de la consola y centrarla
    resizeConsole(1200, 650);

    cout << "Hola mundo" << endl;

    return 0;
}
