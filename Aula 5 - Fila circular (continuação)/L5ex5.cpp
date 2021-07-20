#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

#include "filaCircular5.hpp"
#include "pilha5.hpp"

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    Fila fPrimo, fPar, fImpar;

    int tam, numero, resultado = 0;
    string empresaAviao;

    int menu;
    bool controle = false;

    do {
        cout << "********************** MENU ***********************" << endl;
        cout << "*                                                 *" << endl;
        cout << "* 1. Inicializa pilha                             *" << endl;
        cout << "* 2. Incluir na pilha                             *" << endl;
        cout << "* 3. Remover da pilha                             *" << endl;
        cout << "* 4. Mostrar pilha                                *" << endl;
        cout << "* 5. Mostrar as filas (Primos/Pares/Ímpares)     *" << endl;
        cout << "* 6. Sair                                         *" << endl;
        cout << "*                                                 *" << endl;
        cout << "***************************************************" << endl << endl;

        cout << "Escolha uma opção: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {

            case 1:
                system("cls");

                desalocar(&p1);

                cout << "Tamanho da pilha: ";
                cin >> tam;

                inicializa(&p1, tam);

                cout << "\nPilha criada." << endl << endl;

                inicializaF(&fPrimo, tam);
                inicializaF(&fPar, tam);
                inicializaF(&fImpar, tam);

                controle = true;

                break;

            case 2:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else {
                    cout << "Insira um número: ";
                    cin >> numero;

                    if(buscar(&p1, numero)) {
                        cout << "\nEste avião já consta na fila." << endl << endl;
                        break;
                    }

                    if(empilhar(&p1, numero))
                        cout << "\nNúmero inserido." << endl << endl;
                    else
                        cout << "\nPilha cheia." << endl << endl;
                }
                break;

            case 3:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else {
                    if(desempilhar(&p1, &numero)) {
                        cout << "Número removido." << endl << endl;

                        for (int i = 2; i <= numero / 2; i++) {
                            if (numero % i == 0) {
                                resultado++;
                                break;
                            }
                        }

                        if (resultado == 0)
                            enfileiraF(&fPrimo, numero);
                        /*else if(numero % 2 == 0)
                            enfileiraF(&fPar, numero);
                        else if(numero % 2 != 0)
                            enfileiraF(&fImpar, numero);*/
                    } else
                        cout << "Fila vazia." << endl << endl;
                }
                break;

            case 4:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else
                    mostrar(&p1);

                break;

            case 5:
                system("cls");

                if(controle == false) {
                    system("cls");

                    cout << "Escolha a opção 1 antes de continuar." << endl << endl;
                } else {
                    mostraF(&fPrimo);
                    mostraF(&fPar);
                    mostraF(&fImpar);
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
