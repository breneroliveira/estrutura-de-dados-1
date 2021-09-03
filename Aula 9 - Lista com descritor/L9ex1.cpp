#include <iostream>
#include <cstring>

using namespace std;

#include "listaComDescritor1.hpp"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Lista *lista = new Lista(); /// Executa o construtor (inicializa a lista)

    insereInicioL(lista, 10);
    insereInicioL(lista, 20);
    insereInicioL(lista, 30);
    insereInicioL(lista, 40);
    insereInicioL(lista, 50);
    mostraDescritorL(lista); /// Mostra os descritores (tamanho, inicio e fim)
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;  /// Mostra a lista

    delete(lista); /// Executa desconstrutor (apaga todos os nos)

    return EXIT_SUCCESS;
}