#include <iostream>
#include <cstring>

using namespace std;

#include "listaComDescritor2.hpp"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Lista *lista = new Lista(); /// Executa o construtor (inicializa a lista)
    Funcionario f;

    f.codigo = 1;
    f.nome = "Fulano";
    f.idade = 20;
    f.salario = 3044.52;

    insereInicioL(lista, f);

    f.codigo = 2;
    f.nome = "Ciclano";
    f.idade = 30;
    f.salario = 7054;

    insereInicioL(lista, f);

    f.codigo = 3;
    f.nome = "Beltrano";
    f.idade = 40;
    f.salario = 9123.14;

    insereInicioL(lista, f);

    f.codigo = 4;
    f.nome = "Guria";
    f.idade = 19;
    f.salario = 5000;

    insereFinalL(lista, f);

    f.codigo = 5;
    f.nome = "Guri";
    f.idade = 25;
    f.salario = 8853.14;

    insereInicioL(lista, f);

    f.codigo = 6;
    f.nome = "Lolo";
    f.idade = 40;
    f.salario = 5000;

    insereFinalL(lista, f);

    mostraDescritorL(lista); /// Mostra os descritores (tamanho, inicio e fim)

    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;  /// Mostra a lista

    delete(lista); /// Executa desconstrutor (apaga todos os nos)

    return EXIT_SUCCESS;
}