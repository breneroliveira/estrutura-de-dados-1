#include <iostream>

using namespace std;

#include "listaEncadeada4.hpp"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    int elemento, posicaoElemento;

    int menu, leu = 0;
    bool controle = false;

    while(menu != 0){
        cout << "######################## MENU ########################" << endl;
        cout << "#                                                    #" << endl;
        cout << "# 0 - Sair                                           #" << endl;
        cout << "# 1 - Inicializa a fila encadeada dinamica           #" << endl;
        cout << "# 2 - Incluir elemento no inicio da lista encadeada  #" << endl;
        cout << "# 3 - Mostrar lista inversa                          #" << endl;
        cout << "# 4 - Mostrar lista                                  #" << endl;
        cout << "#                                                    #" << endl;
        cout << "######################################################" << endl << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 0:
                system("cls");
                cout << "Programa encerrado." << endl << endl;
                break;

            case 1:
                system("cls");
                cout << "\t1 - INICIALIZAR LISTA" << endl << endl;

                if(vaziaL(&lista))
                    destroiL(&lista);

                inicializaL(&lista);
                leu = 1;
                cout << "Lista inicializada." << endl << endl;

                break;

            case 2:
                system("cls");
                cout << "\t2 - INCLUIR NA LISTA" << endl << endl;

                if(leu == 0) {
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
                cout << "\t3 - MOSTRAR LISTA INVERSA" << endl << endl;

                if(leu == 0) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    mostraLInversa(&lista);
                }

                break;

            case 4:
                system("cls");
                cout << "\t4 - MOSTRAR LISTA" << endl << endl;

                if(leu == 0) {
                    system("cls");

                    cout << "Escolha a opcao 1 antes de continuar." << endl << endl;
                } else {
                    mostraL(&lista);
                }

                break;

            default:
                system("cls");
                cout << "Opção inválida." << endl << endl;
                break;
        }

        system("pause");
        system("cls");
    }

    destroiL(&lista);
}