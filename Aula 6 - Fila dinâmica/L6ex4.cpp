#include <iostream>

using namespace std;

#include "filaDinamica4.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2;
    int valor, nInt;
    int menu;

    do {
        cout << "***************** MENU ******************" << endl;
        cout << "*                                       *" << endl;
        cout << "* 1. Incluir na fila 1                  *" << endl;
        cout << "* 2. Inserir numero para dividir        *" << endl;
        cout << "* 3. Mostrar filas 1 e 2                *" << endl;
        cout << "* 4. Sair                               *" << endl;
        cout << "*                                       *" << endl;
        cout << "*****************************************" << endl << endl;

        cout << "Escolha uma opcao: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {

            case 1:
                system("cls");

                cout << "Insira um valor na fila 1: ";
                cin >> valor;

                if(enfileiraF(&f1, valor))
                    cout << "\nNumero " << valor << " inserido na fila 1." << endl << endl;

                break;

            case 2:
                system("cls");

                cout << "Insira um numero: ";
                cin >> nInt;

                separaF(nInt, &f1, &f2);

                break;

            case 3:
                system("cls");

                cout << "*** FILA 1 ***" << endl;
                mostraF(&f1);

                cout << "*** FILA 2 ***" << endl;
                mostraF(&f2);

                break;

            case 4:
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

    } while(menu != 4);

    return EXIT_SUCCESS;
}