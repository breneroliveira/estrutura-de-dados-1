#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

#include "filaCircular3.hpp"
#include "pilha3.hpp"

#define TAM_PILHA 50

int main(){
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    Fila f1;

    char texto[TAM_PILHA];
    int tamTexto;
    char auxPilha;
    char auxFila;
    bool teste;

    cout << "Informe o texto: ";
    cin.getline(texto, sizeof(texto));

    /// Passa todo o texto para minúsculo
    for(int i = 0; i <= sizeof(texto); i++)
        texto[i] = tolower(texto[i]);

    tamTexto = strlen(texto);

    /// Cria a PILHA e a FILA, respectivamente
    inicializa(&p1, tamTexto);
    inicializaF(&f1, tamTexto);

    /// Passa os valores para a PILHA
    for(int i = 0; i < tamTexto; i++)
        empilhar(&p1, texto[i]);

    /// Passa os valores para a FILA
    for(int i = 0; i < tamTexto; i++)
        enfileiraF(&f1, texto[i]);

    /// Compara ao DESEMPILHAR e DESENFILEIRAR
    for(int i = 0; i < tamTexto; i++) {
        desempilhar(&p1, &auxPilha);
        desenfileiraF(&f1, &auxFila);

        teste = true;

        if(auxPilha != auxFila) {
            teste = false;
            break;
        }
    }

    if(teste)
        cout << "\nÉ um palíndromo." << endl;
    else
        cout << "\nNão é um palíndromo." << endl;
}
