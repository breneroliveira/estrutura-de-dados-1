#include <iostream>

using namespace std;

#include "listaEncadeada2.hpp"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    No* lista, *lista2, *listaResultante;

    int elemento, posicaoElemento, posicao;

    int menu;
    bool controle = false;

    do {
        cout << "******************************** MENU ********************************" << endl;
        cout << "*                                                                    *" << endl;
        cout << "* 1) Inicializa as filas encadeadas dinamicas;                       *" << endl;
        cout << "* 2) Incluir elemento no inicio da lista encadeada;                  *" << endl;
        cout << "* 3) Incluir elemento na posicao informada;                          *" << endl;
        cout << "* 4) Remover elemento informado;                                     *" << endl;
        cout << "* 5) Buscar elemento informado;                                      *" << endl;
        cout << "* 6) Mostrar listas;                                                 *" << endl;
        cout << "* 7) Incluir elemento no inicio da lista 2;                          *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "****************************** QUESTAO 2 *****************************" << endl;
        cout << "*                                                                    *" << endl;
        cout << "* 8) Verifica se as listas sao iguais;                               *" << endl;
        cout << "* 9) Insere elemento ordenadamente na lista;                         *" << endl;
        cout << "* 10) Insere elemento no inicio da lista;                            *" << endl;
        cout << "* 11) Total de elementos na lista;                                   *" << endl;
        cout << "* 12) Verifica elemento pela posicao;                                *" << endl;
        cout << "* 13) Remover elemento pela posicao informada;                       *" << endl;
        cout << "* 14) Unir lista 1 e lista 2.                                        *" << endl;
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
                
                if(vaziaL(&lista2))
                    destroiL(&lista2);

                inicializaL(&lista);
                inicializaL(&lista2);
                controle = true;
                cout << "Listas inicializadas" << endl << endl;

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
                    cout << "Lista 1: ";
                    mostraL(&lista);

                    cout << "Lista 2: ";
                    mostraL(&lista2);
                }

                break;

            case 7:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira um valor no inicio da fila 2: ";
                    cin >> elemento;
                    fflush(stdin);

                    insereL(&lista2, elemento);
                    cout << "\nValor " << elemento << " inserido na fila 2." << endl << endl;
                }

                break;

            case 8:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    if(igual(&lista, &lista2))
                        cout << "As listas sao iguais." << endl << endl;
                    else
                        cout << "As listas nao sao iguais." << endl << endl;
                }

                break;

            case 9:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira um valor ordenadamante: ";
                    cin >> elemento;
                    fflush(stdin);

                    insereOrdenadoL(&lista, elemento);
                    cout << "\nValor " << elemento << " inserido na fila." << endl << endl;
                }

                break;

            case 10:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira um valor no final da lista: ";
                    cin >> elemento;
                    fflush(stdin);

                    insereFinalL(&lista, elemento);
                    cout << "\nValor " << elemento << " inserido na fila." << endl << endl;
                }

                break;

            case 11:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Total de elementos da lista: " << total(&lista) << endl << endl;
                }

                break;

            case 12:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira uma posicao para verificar o valor contido nela: ";
                    cin >> posicao;
                    fflush(stdin);

                    if(lePosicao(&lista, posicao, &elemento))
                        cout << "\nNa posicao " << posicao << " fica o elemento "<< elemento << "." << endl << endl;
                    else
                        cout << "\nPosicao " << posicao << " nao encontrada." << endl << endl;
                }

                break;

            case 13:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira uma posicao para remover o valor contido nela: ";
                    cin >> posicao;
                    fflush(stdin);

                    if(removePosicaoL(&lista, posicao))
                        cout << "\nElemento " << elemento << " removido da posicao " << posicao << "." << endl << endl;
                    else
                        cout << "\nPosicao " << posicao << " nao encontrada." << endl << endl;
                }

                break;

            case 14:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    uniao(&lista, &lista2, &listaResultante);
                    cout << "Lista resultante: ";
                    mostraL(&listaResultante);
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