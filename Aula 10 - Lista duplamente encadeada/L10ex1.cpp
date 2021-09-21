#include <iostream>

using namespace std;

#include "listaDupla1.hpp"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int contCodigo = 0;

    Lista *lista = new Lista(); /// Executa o construtor (inicializa a lista)
    Animal a;

    insereInicioL(lista, Animal(++contCodigo, 3, 12.78));
    insereInicioL(lista, Animal(++contCodigo, 2, 7.23));
    insereInicioL(lista, Animal(++contCodigo, 7, 14.85));

    mostraDescritorL(lista); /// Mostra os descritores (tamanho, inicio e fim)
    cout << "Animal[" << lista->tamanho << "]:{" << lista << "}" << endl;

    cout << "\n==========================================================================================================\n" << endl;

    if(removeL(lista, 2))
        cout << "Animal de codigo **VARIAVEL QUE REPRESENTA O VALOR INSERIDO PELO USUARIO** removido da lista." << endl << endl;
    else
        cout << "Animal de codigo **VARIAVEL QUE REPRESENTA O VALOR INSERIDO PELO USUARIO** nao encontrado." << endl << endl;
    
    mostraDescritorL(lista); /// Mostra os descritores (tamanho, inicio e fim)
    cout << "Animal[" << lista->tamanho << "]:{" << lista << "}" << endl;

    cout << "\n==========================================================================================================\n" << endl;

    insereInicioL(lista, Animal(++contCodigo, 2, 3.05));
    insereInicioL(lista, Animal(++contCodigo, 7, 70));
    insereInicioL(lista, Animal(++contCodigo, 14, 6.05));
    insereInicioL(lista, Animal(++contCodigo, 8, 51));
    
    mostraDescritorL(lista); /// Mostra os descritores (tamanho, inicio e fim)
    mostrarInversoL(lista);

    cout << endl;

    acessaTresUltimos(lista);

    separaPorPeso(lista);

    /// Questão 2 abaixo
    insereFinalL(lista, Animal(++contCodigo, 3, 12.78));
    insereFinalL(lista, Animal(++contCodigo, 2, 7.23));

    mostraDescritorL(lista);
    cout << "Animal[" << lista->tamanho << "]:{" << lista << "}" << endl << endl;

    removeInicioL(lista);

    mostraDescritorL(lista);
    cout << "Animal[" << lista->tamanho << "]:{" << lista << "}" << endl << endl;

    removeUltimoL(lista);

    mostraDescritorL(lista);
    cout << "Animal[" << lista->tamanho << "]:{" << lista << "}" << endl << endl;

    delete(lista); /// Executa desconstrutor (apaga todos os nos)

    return EXIT_SUCCESS;
}