#include <iostream>

using namespace std;

#include "listaEncadeada4.hpp"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    int elemento, posicaoElemento;

    int menu;
    bool controle = false;

    do {
        cout << "******************************** MENU ********************************" << endl;
        cout << "*                                                                    *" << endl;
        cout << "* 1) Inicializa a fila encadeada dinamica;                           *" << endl;
        cout << "* 2) Incluir elemento no inicio da lista encadeada;                  *" << endl;
        cout << "* 3) Incluir elemento na posicao informada;                          *" << endl;
        cout << "* 4) Remover elemento informado;                                     *" << endl;
        cout << "* 5) Buscar elemento informado;                                      *" << endl;
        cout << "* 6) Mostrar lista;                                                  *" << endl;
        cout << "* 0) Encerrar programa.                                              *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "**********************************************************************" << endl << endl;

        cout << "Escolha uma opcao: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 1:
                system("cls");

                if(vaziaL(&lista))
                    destroiL(&lista);

                inicializaL(&lista);
                controle = true;
                cout << "Lista inicializada" << endl << endl;

                break;

            case 2:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira um valor no inicio da fila: ";
                    cin >> elemento;
                    fflush(stdin);

                    insereL(&lista, elemento);
                    cout << "\nValor " << elemento << " inserido na fila." << endl << endl;
                }

                break;

            case 3:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira um valor: ";
                    cin >> elemento;
                    fflush(stdin);

                    cout << "Informe uma posicao da lista: ";
                    cin >> posicaoElemento;
                    fflush(stdin);

                    cout << endl;

                    if(inserePosicaoL(&lista, elemento, posicaoElemento))
                        cout << "Valor " << elemento << " inserido na posicao " << posicaoElemento << " da fila." << endl << endl;
                    else
                        cout << "Posicao " << posicaoElemento << " nao existe." << endl << endl;
                }

                break;

            case 4:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Informe um valor para ser removido da lista: ";
                    cin >> elemento;
                    fflush(stdin);

                    cout << endl;

                    if(removeL(&lista, elemento))
                        cout << elemento << " removido da lista." << endl << endl;
                    else
                        cout << elemento << " nao encontrado." << endl << endl;
                }

                break;

            case 5:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Informe um valor para ser buscado da lista: ";
                    cin >> elemento;
                    fflush(stdin);

                    cout << endl;

                    if(buscaL(&lista, elemento) != nullptr)
                        cout << elemento << " encontrado na lista." << endl << endl;
                    else
                        cout << elemento << " nao encontrado." << endl << endl;
                }

                break;

            case 6:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    mostraL(&lista);
                }

                break;

            case 0:
                system("cls");

                cout << "Programa encerrado." << endl << endl;

                break;

            default:
                system("cls");

                cout << "Opcao invalida." << endl << endl;

                break;
        }

        system("pause");
        system("cls");
    } while(menu != 0);

    destroiL(&lista);
}