#include <iostream>

using namespace std;

#include "filaCircular2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Aviao a;
    int tamFila, codigoAviao, numeroPassageiros;
    string empresaAviao;
    bool resultado;
    bool repetido;

    int menu;
    bool controle = false;

    do {
        cout << "******************************* MENU ********************************" << endl;
        cout << "*                                                                   *" << endl;
        cout << "* 1. Nº de aviões à espera de decolar                               *" << endl;
        cout << "* 2. Entrada de um novo avião para decolar (incluir na fila)        *" << endl;
        cout << "* 3. Descolagem de um avião (retirar da fila)                       *" << endl;
        cout << "* 4. Listar todos os aviões à espera para decolagem (mostrar fila)  *" << endl;
        cout << "* 5. Listar as características do próximo avião a decolar (peek)    *" << endl;
        cout << "* 6. Sair                                                           *" << endl;
        cout << "*                                                                   *" << endl;
        cout << "*********************************************************************" << endl << endl;

        cout << "Escolha uma opção: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {

            case 1:
                system("cls");

                /*if(controle == true) {
                    for(int i = 0; i <= tamPilha; i++)
                        desempilhar(&p1, codigoCaixa, pesoCaixa);
                    desalocar(&p1);
                }*/

                destroiF(&f1);

                cout << "Tamanho da fila: ";
                cin >> tamFila;

                inicializaF(&f1, tamFila);

                cout << "\nFila criada." << endl << endl;

                controle = true;

                break;

            case 2:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira o código do avião: ";
                    cin >> codigoAviao;

                    /*if(buscar(&f1, codigoAviao)) {
                        cout << "\nEste avião já consta na fila." << endl << endl;
                        break;
                    }*/

                    cout << "Número de passageiros: ";
                    cin >> numeroPassageiros;

                    cout << "Empresa do avião: ";
                    cin >> empresaAviao;

                    if(enfileiraF(&f1, codigoAviao, numeroPassageiros, empresaAviao))
                        cout << "\nAvião inserido." << endl << endl;
                    else
                        cout << "\nFila cheia." << endl << endl;
                }
                break;

            case 3:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else {
                    if(desenfileiraF(&f1, &a))
                        cout << "Avião removido." << endl << endl;
                    else
                        cout << "Fila vazia." << endl << endl;
                }
                break;

            case 4:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else
                    mostraF(&f1);

                break;

            case 5:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else {
                    if(espiarF(&f1, &a)) {
                        cout << "Próximo avião a decolar: " << endl << endl;
                        cout << "Avião de código " << a.codigo << ", com " << a.passageiros << " passageiros e da empresa "
                        << a.empresa << "." << endl << endl;
                    } else
                        cout << "Nenhum avião na fila para decolagem." << endl << endl;
                }

                break;

            case 6:
                system("cls");

                cout << "Programa encerrado." << endl << endl;
                break;

            default:
                system("cls");

                cout << "Opção inválida." << endl << endl;

                break;
        }

        system("pause");
        system("cls");

    } while(menu != 6);
}
