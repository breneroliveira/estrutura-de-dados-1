#include <iostream>

using namespace std;

#include "listaDupla1.hpp"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int contCodigo = 0;
    No* aux = nullptr;

    Lista *lista = new Lista(); /// Executa o construtor (inicializa a lista)
    Animal a;

    insereInicioL(lista, Animal(++contCodigo, 3, 12.78));
    insereInicioL(lista, Animal(++contCodigo, 2, 7.23));

    mostraDescritorL(lista); /// Mostra os descritores (tamanho, inicio e fim)
    
    cout << "Animal[" << lista->tamanho << "]:{" << lista << "}" << endl;

    delete(lista); /// Executa desconstrutor (apaga todos os nos)

    return EXIT_SUCCESS;
}